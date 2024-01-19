class SiriusHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Hold End";
	bool hasInput = true;
	
	defineEntityData(beat);
	defineEntityData(stBeat);
	defineEntityData(lane);
	defineEntityData(laneLength);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
	Variable<EntityMemoryId> isHolding;
	Variable<EntityMemoryId> lastHoldTime;
	Variable<EntityMemoryId> playId;
	Variable<EntityMemoryId> effectId;

    SonolusApi preprocess() {
   		FUNCBEGIN
   		beat = beat / levelSpeed;
   		stBeat = stBeat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + RuntimeEnvironment.get(3);
		inputTimeMax = beat + judgment.bad + RuntimeEnvironment.get(3);
		isHolding = false;
		lastHoldTime = -1;
		playId = 0;
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
		IF (Abs(t - beat) <= judgment.bad) res = 5, res2 = 3; FI
		IF (Abs(t - beat) <= judgment.good) res = 4, res2 = 3; FI
		IF (Abs(t - beat) <= judgment.great) res = 3, res2 = 2; FI
		IF (Abs(t - beat) <= judgment.perfect) res = 2, res2 = 1; FI
		IF (Abs(t - beat) <= judgment.perfectPlus) res = 1, res2 = 1; FI
		EntityInput.set(0, res2);
		EntityInput.set(1, t - beat);
		EntityInput.set(2, Buckets.HoldEnd);
		EntityInput.set(3, t - beat);
		IF (res2 == 1) Play(Clips.Perfect, minSFXDistance); FI
		IF (res2 == 2) Play(Clips.Perfect, minSFXDistance); FI
		IF (res2 == 3) Play(Clips.Good, minSFXDistance); FI
		IF (res2 != 0) spawnEffect(Effects.HoldLinear, Effects.HoldCircular, lane, enLane); FI
		IF (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss); FI
		IF (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus); FI
		IF (res == 2) SpawnSubJudgeText(Sprites.JudgePerfect); FI
		IF (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat); FI
		IF (res == 4) SpawnSubJudgeText(Sprites.JudgeGood); FI
		IF (res == 5) SpawnSubJudgeText(Sprites.JudgeBad); FI
		EntityDespawn.set(0, 1);
		return VOID;
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (times.now < stBeat) Return(0); FI
		isHolding = findHoldTouch(lane, enLane) != -1;
		IF (isHolding && playId == 0) {
			playId = PlayLooped(Clips.Hold);
			effectId = spawnHoldEffect(Effects.Hold, lane, enLane);
		} FI
		IF (!isHolding && playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
		} FI

		// 判定主代码
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) complete(-1); FI
		IF (isHolding == 1) lastHoldTime = Max(lastHoldTime, times.now); FI
		IF (times.now >= beat && lastHoldTime != -1) complete(lastHoldTime); FI
		return VOID;
	}

    SonolusApi updateParallel() {
		FUNCBEGIN
		drawHoldEighth(Sprites.Hold, lane, enLane, stBeat, beat, isHolding);
		IF (times.now > stBeat && times.now < beat) drawNormalNote(Sprites.HoldNote, lane, enLane, times.now); FI
		IF (times.now > beat - appearTime) drawNormalNote(Sprites.HoldNote, lane, enLane, beat); FI
		return VOID;
	}
};
