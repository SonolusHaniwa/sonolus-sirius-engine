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
	var combo = EntitySharedMemory[0];
	var status = EntitySharedMemory[1];
	var nextNoteTime = EntitySharedMemory[2];

	SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
	SonolusApi despawnTime() { return TimeToScaledTime(beat); }

	SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, info.index);
        nextNoteTime = 99999;
        var id = lastNoteId, thisId = info.index;
		input.time = judgment.bad;
		totalAccuracy = totalAccuracy + 1.01;
		life.miss_increment = -40;
        if (replay == 1) {
			if (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			else comboNumber = 0;
			combo = comboNumber;
			comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			status = comboStatus;
        	input.time = beat + accuracy;
        	input.bucketValue = accuracy * 1000;
        	EntitySharedMemoryArray[id].generic[2] = beat + accuracy;
        	if (firstComboTime == 0) firstComboTime = beat;
        	if (judgeResult == 0) currentAccuracy = currentAccuracy - 1.01, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 1) currentAccuracy = currentAccuracy, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 2) currentAccuracy = currentAccuracy - 0.01, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfect, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 3) currentAccuracy = currentAccuracy - 0.21, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 4) currentAccuracy = currentAccuracy - 0.51, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGood, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 5) currentAccuracy = currentAccuracy - 1.01, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeBad, combo, status, thisId, accuracy, currentAccuracy });
        } else {
			comboNumber = comboNumber + 1;
			combo = comboNumber;
			comboStatus = 0;
			status = comboStatus;
        	input.time = beat;
        	input.bucketValue = 0;
        	EntitySharedMemoryArray[id].generic[2] = beat;
        	if (firstComboTime == 0) firstComboTime = beat;
			Spawn(getAid(UpdateJudgment), { beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0 });
		}
		lastNoteId = info.index;
 	}
};
