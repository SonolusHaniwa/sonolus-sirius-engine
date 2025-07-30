class FlatNote : public Archetype {
	public:
	
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
        var thisId = info.index;
		input.time = judgment.bad;
		setBucket(
			getBucket(), 
			-1 * judgment.perfect * 1000, judgment.perfect * 1000, 
			-1 * judgment.great * 1000, judgment.great * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000
		);
		life.miss_increment = -80;
		if (replay == 1) {
        	input.time = beat + accuracy;
        	input.bucketIndex = getBucket();
        	input.bucketValue = accuracy * 1000;
        	if (firstComboTime == 0) firstComboTime = beat + accuracy;
			if (autoSFX) PlayScheduled(getClips().perfect, beat, minSFXDistance); 
			else {
				if (judgeResult == 1) PlayScheduled(getClips().perfect, beat + accuracy, minSFXDistance);
				if (judgeResult == 2) PlayScheduled(getClips().perfect, beat + accuracy, minSFXDistance);
				if (judgeResult == 3) PlayScheduled(getClips().great, beat + accuracy, minSFXDistance);
				if (judgeResult == 4) PlayScheduled(getClips().good, beat + accuracy, minSFXDistance);
				if (judgeResult == 4) PlayScheduled(getClips().bad, beat + accuracy, minSFXDistance);
			}
			if (judgeResult == 0) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 1) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 2) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfect, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 3) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 4) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGood, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 5) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeBad, combo, status, thisId, accuracy, currentAccuracy });
		} else {
			input.time = beat;
			input.bucketIndex = getBucket();
			input.bucketValue = 0;
        	if (firstComboTime == 0) firstComboTime = beat;
			PlayScheduled(getClips().perfect, beat, minSFXDistance);
			Spawn(getAid(UpdateJudgment), { beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0 });
		};
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
