class SiriusHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Hold End";
	bool hasInput = true;
	
	defineImports(beat);
	defineImports(stBeat);
	defineImports(lane);
	defineImports(laneLength);
	defineExports(judgeResult);
	defineExports(accuracy);
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
	defineExports(time26);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
	Variable<EntityMemoryId> isHolding;
	Variable<EntityMemoryId> lastHoldTime;
	Variable<EntityMemoryId> playId;
	Variable<EntityMemoryId> effectId;
	Variable<EntityMemoryId> exportId;

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
		exportId = time1;
        return VOID;
    }
    
    SonolusApi spawnOrder() { return 1000 + stBeat; }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(stBeat) - appearTime; }

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
		IF (res2 != 0) {
			EntityInput.set(1, t - beat);
			EntityInput.set(2, Buckets.HoldEnd);
			EntityInput.set(3, t - beat);
			ExportValue(judgeResult, res);
			ExportValue(accuracy, t - beat);
		} FI

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
			IF (exportId <= time26) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			} FI
		} FI
		IF (!isHolding && playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
			IF (exportId <= time26) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			} FI
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
		drawHoldEighth(Sprites.Hold, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), isHolding);
		IF (times.now > stBeat && times.now < beat) drawNormalNote(Sprites.HoldNote, lane, enLane, times.scaled); FI
		IF (times.now > beat - appearTime) drawNormalNote(Sprites.HoldNote, lane, enLane, TimeToScaledTime(beat)); FI
		return VOID;
	}
};
