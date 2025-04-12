class SiriusScratchHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Scratch Hold End";
	bool hasInput = true;
	
	defineImports(beat);
	defineImports(stBeat);
	defineImports(lane);
	defineImports(laneLength);
	defineImports(scratchLength);
	defineExports(judgeResult);
	defineExports(time1);
	defineExports(time2);
	defineExports(time3);
	defineExports(time4);
	defineExports(time5);
	defineExports(time6);
	defineExports(time7);
	defineExports(time8);
	defineExports(time9);
	defineExports(time10);
	defineExports(time11);
	defineExports(time12);
	defineExports(time13);
	defineExports(time14);
	defineExports(time15);
	defineExports(time16);
	defineExports(time17);
	defineExports(time18);
	defineExports(time19);
	defineExports(time20);
	defineExports(time21);
	defineExports(time22);
	defineExports(time23);
	defineExports(time24);
	defineExports(time25);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
	Variable<EntityMemoryId> isHolding;
	Variable<EntityMemoryId> lastHoldTime;
	Variable<EntityMemoryId> playId;
	Variable<EntityMemoryId> effectId;
	Variable<EntityMemoryId> scratchLane;
	Variable<EntityMemoryId> scratchEnLane;
	Variable<EntityMemoryId> exportId;
	Variable<EntityMemoryId> played;

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
		exportId = time1;
		played = false;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		EntityInput.set(1, judgment.bad);
		IF (autoSFX) PlayScheduled(Clips.Scratch, beat, minSFXDistance); FI
        return VOID;
    }
    
    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(stBeat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(stBeat) - appearTime; }

	SonolusApi complete(let t) {
		FUNCBEGIN
		IF (playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
		} FI
		var res = 0, res2 = 0;
		IF (t == inputTimeMin) res = 3, res2 = 2; FI
		IF (t > inputTimeMin) res = 1, res2 = 1; FI
		EntityInput.set(0, res2);
		IF (res2 != 0) {
			EntityInput.set(1, t - RuntimeEnvironment.get(3) - beat);
			EntityInput.set(2, Buckets.ScratchHoldEnd);
			EntityInput.set(3, (t - RuntimeEnvironment.get(3) - beat) * 1000);
			ExportValue(judgeResult, res);
		} FI

		IF (!autoSFX) {
			IF (res2 == 1) Play(Clips.Scratch, minSFXDistance); FI
			IF (res2 == 2) Play(Clips.Great, minSFXDistance); FI
		} FI
		IF (res2 != 0) spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane); FI
		IF (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss, t - RuntimeEnvironment.get(3) - beat); FI
		IF (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus, t - RuntimeEnvironment.get(3) - beat); FI
		IF (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat, t - RuntimeEnvironment.get(3) - beat); FI
		EntityDespawn.set(0, 1);
		return VOID;
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (!played && autoSFX) {
			played = true;
			// PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
		} FI
		IF (times.now < stBeat) Return(0); FI
		isHolding = findHoldTouch(lane, enLane) != -1;
		IF (isHolding && playId == 0) {
			IF (HasEffectClip(Clips.Hold) && !autoSFX) playId = PlayLooped(Clips.Hold);
			ELSE playId = 1; FI
			effectId = spawnHoldEffect(Effects.Scratch, lane, enLane);
			IF (exportId <= time25) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			} FI
		} FI
		IF (!isHolding && playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
			IF (exportId <= time25) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			} FI
		} FI

		// 判定主代码
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) complete(lastHoldTime); FI
		IF (isHolding == 1) lastHoldTime = Max(lastHoldTime, inputTimeMin); FI
		isHolding = findFlickTouch(scratchLane, scratchEnLane) != -1;
		IF (isHolding == 1) lastHoldTime = Max(lastHoldTime, times.now); FI
		IF (times.now >= beat && lastHoldTime > inputTimeMin) complete(lastHoldTime); FI
		return VOID;
	}

    SonolusApi updateParallel() {
		FUNCBEGIN
		drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), isHolding);
		IF (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, times.scaled); FI
		IF (times.scaled > TimeToScaledTime(beat) - appearTime) 
			drawNormalNote(Sprites.ScratchNoteLeft, scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
		IF (times.scaled > TimeToScaledTime(beat) - appearTime) {
			IF (scratchLength > 0) drawRightArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
			IF (scratchLength < 0) drawLeftArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
			IF (scratchLength == 0) drawArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
		} FI
		return VOID;
	}
};