class HoldEighth: public Archetype {
	public:

	string name = "Sirius Hold Eighth";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineExport(judgeResult);
    var enLane;
    var inputTimeMin;
    var inputTimeMax;
	var isHolding;
	var lastHoldTime;

    SonolusApi preprocess() {
   		beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + offsets.input;
		inputTimeMax = beat + judgment.bad + offsets.input;
		isHolding = false;
		lastHoldTime = -1;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		input.accuracy = judgment.bad;
		life.miss_increment = -40;
    }
    
    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

	SonolusApi complete(var t) {
		var res = 0, res2 = 0;
		if (Abs(t - beat) <= judgment.bad) res = 5, res2 = 3;
		if (Abs(t - beat) <= judgment.good) res = 4, res2 = 3;
		if (Abs(t - beat) <= judgment.great) res = 3, res2 = 2;
		if (Abs(t - beat) <= judgment.perfect) res = 2, res2 = 1;
		if (Abs(t - beat) <= judgment.perfectPlus) res = 1, res2 = 1;
		input.judgment = res2;
		if (res2 != 0) {
			input.accuracy = t - beat;
			input.bucketValue = (t - beat) * 1000;
			ExportValue(judgeResult, res);
		}

		if (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss);
		if (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus);
		if (res == 2) SpawnSubJudgeText(Sprites.JudgePerfect);
		if (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat);
		if (res == 4) SpawnSubJudgeText(Sprites.JudgeGood);
		if (res == 5) SpawnSubJudgeText(Sprites.JudgeBad);
		despawn.despawn = true;
	}
	SonolusApi updateSequential() {
		if (times.now < beat) return;
		isHolding = findHoldTouch(lane, enLane) != -1;

		// 判定主代码
		if (times.now < inputTimeMin) return;
		if (times.now > inputTimeMax) complete(-1);
		if (isHolding == 1) lastHoldTime = Max(lastHoldTime, times.now);
		if (times.now >= beat && lastHoldTime != -1) complete(lastHoldTime);
	}
};
