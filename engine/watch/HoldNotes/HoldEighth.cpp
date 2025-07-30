class HoldEighth : public Archetype {
	public:
	
	string name = "Sirius Hold Eighth";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(judgeResult);
	defineImportDetailed(accuracy, "#ACCURACY");
	var enLane;
	var combo = var(EntitySharedMemoryId, 0);
	var status = var(EntitySharedMemoryId, 1);
	var nextNoteTime = var(EntitySharedMemoryId, 2);
	var currentAccuracy = var(EntitySharedMemoryId, 3);

	SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
	SonolusApi despawnTime() { return TimeToScaledTime(beat); }

	SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, info.index);
        var thisId = info.index;
		input.time = judgment.bad;
		life.miss_increment = -40;
        if (replay == 1) {
        	input.time = beat + accuracy;
        	input.bucketValue = accuracy * 1000;
        	if (firstComboTime == 0) firstComboTime = beat;
        	if (judgeResult == 0) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 1) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 2) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfect, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 3) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 4) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGood, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 5) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeBad, combo, status, thisId, accuracy, currentAccuracy });
        } else {
        	input.time = beat;
        	input.bucketValue = 0;
        	if (firstComboTime == 0) firstComboTime = beat;
			Spawn(getAid(UpdateJudgment), { beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0 });
		}
 	}
};
