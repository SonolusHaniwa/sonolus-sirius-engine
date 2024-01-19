class SiriusScratchHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Scratch Hold End";
	bool hasInput = true;
	
	defineEntityData(beat);
	defineEntityData(stBeat);
	defineEntityData(lane);
	defineEntityData(laneLength);
	defineEntityData(scratchLength);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
	Variable<EntityMemoryId> isHolding;
	Variable<EntityMemoryId> lastHoldTime;
	Variable<EntityMemoryId> playId;
	Variable<EntityMemoryId> effectId;
	Variable<EntityMemoryId> scratchLane;
	Variable<EntityMemoryId> scratchEnLane;

    SonolusApi preprocess() {
   		FUNCBEGIN
   		beat = beat / levelSpeed;
   		stBeat = stBeat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; scratchLength = -1 * scratchLength; FI
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + RuntimeEnvironment.get(3);
		inputTimeMax = beat + judgment.bad + RuntimeEnvironment.get(3);
		isHolding = false;
		lastHoldTime = -1;
		playId = 0;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
        return VOID;
    }
    
    SonolusApi spawnOrder() { return 1000 + stBeat; }
    SonolusApi shouldSpawn() { return times.now > stBeat - appearTime; }

	SonolusApi complete(let t = times.now) {
		FUNCBEGIN
		IF (playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
		} FI
		var res = 0, res2 = 0;
		IF (t == inputTimeMin) res = 3, res2 = 2; FI
		IF (t > inputTimeMin) res = 1, res2 = 1; FI
		EntityInput.set(0, res2);
		EntityInput.set(1, t - beat);
		EntityInput.set(2, Buckets.ScratchHoldEnd);
		EntityInput.set(3, t - beat);
		IF (res2 == 1) Play(Clips.Scratch, minSFXDistance); FI
		IF (res2 == 2) Play(Clips.CriticalGood, minSFXDistance); FI
		IF (res2 != 0) spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane); FI
		IF (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss); FI
		IF (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus); FI
		IF (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat); FI
		EntityDespawn.set(0, 1);
		return VOID;
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (times.now < stBeat) Return(0); FI
		isHolding = findHoldTouch(lane, enLane) != -1;
		IF (isHolding && playId == 0) {
			playId = PlayLooped(Clips.Hold);
			effectId = spawnHoldEffect(Effects.Scratch, lane, enLane);
		} FI
		IF (!isHolding && playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
		} FI

		// 判定主代码
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) complete(lastHoldTime); FI
		IF (isHolding == 1) lastHoldTime = Max(lastHoldTime, inputTimeMin); FI
		isHolding = findFlickTouch(lane, enLane) != -1;
		IF (isHolding == 1) lastHoldTime = Max(lastHoldTime, times.now); FI
		IF (times.now >= beat && lastHoldTime > inputTimeMin) complete(lastHoldTime); FI
		return VOID;
	}

    SonolusApi updateParallel() {
		FUNCBEGIN
		drawHoldEighth(Sprites.Scratch, lane, enLane, stBeat, beat, isHolding);
		IF (times.now > stBeat && times.now < beat) drawNormalNote(Sprites.ScratchNote, lane, enLane, times.now); FI
		IF (times.now > beat - appearTime) drawNormalNote(Sprites.ScratchNote, scratchLane, scratchEnLane, beat); FI
		IF (times.now > beat - appearTime) {
			IF (scratchLength > 0) drawRightArrow(scratchLane, scratchEnLane, beat); FI
			IF (scratchLength < 0) drawLeftArrow(scratchLane, scratchEnLane, beat); FI
			IF (scratchLength == 0) drawArrow(scratchLane, scratchEnLane, beat); FI
		} FI
		return VOID;
	}
};
