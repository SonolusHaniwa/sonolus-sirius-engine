class FlatNote : public Archetype {
	public:
	
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
#define DISABLE_INTERPRETER
	virtual var getSprite() = 0;
	virtual var getBucket() = 0;
	virtual ClipsArray getClips() = 0;
	virtual EffectsArray getEffects() = 0;
#undef DISABLE_INTERPRETER
 
    SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
    SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }
 
 	SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, info.index);
        nextNoteTime = 99999;
        var id = lastNoteId, thisId = info.index;
		input.time = judgment.bad;
		totalAccuracy = totalAccuracy + 1.01;
		setBucket(
			getBucket(), 
			-1 * judgment.perfect * 1000, judgment.perfect * 1000, 
			-1 * judgment.great * 1000, judgment.great * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000
		);
		life.miss_increment = -80;
		if (replay == 1) {
			if (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			else comboNumber = 0;
			combo = comboNumber;
			comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			status = comboStatus;
        	input.time = beat + accuracy;
        	input.bucketIndex = getBucket();
        	input.bucketValue = accuracy * 1000;
        	EntitySharedMemoryArray[id].generic[2] = beat + accuracy;
        	if (firstComboTime == 0) firstComboTime = beat + accuracy;
			if (autoSFX) PlayScheduled(getClips().perfect, beat, minSFXDistance); 
			else {
				if (judgeResult == 1) PlayScheduled(getClips().perfect, beat + accuracy, minSFXDistance);
				if (judgeResult == 2) PlayScheduled(getClips().perfect, beat + accuracy, minSFXDistance);
				if (judgeResult == 3) PlayScheduled(getClips().great, beat + accuracy, minSFXDistance);
				if (judgeResult == 4) PlayScheduled(getClips().good, beat + accuracy, minSFXDistance);
				if (judgeResult == 4) PlayScheduled(getClips().bad, beat + accuracy, minSFXDistance);
			}
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
			input.bucketIndex = getBucket();
			input.bucketValue = 0;
        	EntitySharedMemoryArray[id].generic[2] = beat;
        	if (firstComboTime == 0) firstComboTime = beat;
			PlayScheduled(getClips().perfect, beat, minSFXDistance);
			Spawn(getAid(UpdateJudgment), { beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0 });
		};
		lastNoteId = info.index;
 	}
 
 	// int updateSequentialOrder = 1;
 	// SonolusaApi updateSequential() {
 	// 	FUNCBEGIN
		// if (times.now >= beat - 0.03) {
		// 	SpawnSubJudgeText(Sprites.PerfectPlus);
		// }
 	// 	return VOID;
 	// }
 
 	SonolusApi terminate() {
		if (skip) return;
		if (replay == 1 && judgeResult == 0) return;
		spawnEffect(getEffects().linear, getEffects().circular, lane, enLane);
 	}

 	SonolusApi updateParallel() {
 		drawNormalNote(getSprite(), lane, enLane, TimeToScaledTime(beat));
		return;
 	}
};
