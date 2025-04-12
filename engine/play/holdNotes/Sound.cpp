class SiriusSound: public Archetype {
	public:

	static constexpr const char* name = "Sirius Sound";
	bool hasInput = true;
	
	defineImports(beat);
	defineImports(lane);
	defineImports(laneLength);
	defineImports(holdType);
	defineExports(judgeResult);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
	Variable<EntityMemoryId> isHolding;
	Variable<EntityMemoryId> lastHoldTime;
	Variable<EntityMemoryId> played;

    SonolusApi preprocess() {
   		FUNCBEGIN
   		beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + RuntimeEnvironment.get(3);
		inputTimeMax = beat + judgment.bad + RuntimeEnvironment.get(3);
		isHolding = false;
		lastHoldTime = -1;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		EntityInput.set(1, judgment.bad);
		IF (autoSFX) PlayScheduled(Clips.Sound, beat, minSFXDistance); FI
        return VOID;
    }
    
    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

	SonolusApi complete(let t) {
		FUNCBEGIN
		var res = 0, res2 = 0;
		IF (Abs(t - beat) <= judgment.bad) res = 5, res2 = 3; FI
		IF (Abs(t - beat) <= judgment.good) res = 4, res2 = 3; FI
		IF (Abs(t - beat) <= judgment.great) res = 3, res2 = 2; FI
		IF (Abs(t - beat) <= judgment.perfect) res = 2, res2 = 1; FI
		IF (Abs(t - beat) <= judgment.perfectPlus) res = 1, res2 = 1; FI
		EntityInput.set(0, res2);
		IF (res2 != 0) {
			EntityInput.set(1, t - beat);
			EntityInput.set(2, If(holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101 , Buckets.Sound, Buckets.ScratchSound));
			EntityInput.set(3, (t - beat) * 1000);
			ExportValue(judgeResult, res);
		} FI

		IF (res != 0 && !autoSFX) Play(Clips.Sound, minSFXDistance); FI
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
		IF (!played && autoSFX) {
			played = true;
			// PlayScheduled(Clips.Sound, beat, minSFXDistance);
		} FI
		IF (times.now < beat) Return(0); FI
		isHolding = findHoldTouch(lane, enLane) != -1;

		// 判定主代码
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) complete(-1); FI
		IF (isHolding == 1) lastHoldTime = Max(lastHoldTime, times.now); FI
		IF (times.now >= beat && lastHoldTime != -1) complete(lastHoldTime); FI
		return VOID;
	}

	SonolusApi updateParallel() {
		FUNCBEGIN
		IF (holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101) drawTick(Sprites.TouchTick, TimeToScaledTime(beat), lane, enLane); FI
		IF (holdType == 110 || holdType == 111 || holdType == 1110 || holdType == 1111) drawTick(Sprites.TouchScratchTick, TimeToScaledTime(beat), lane, enLane); FI
		return VOID;
	}
};
