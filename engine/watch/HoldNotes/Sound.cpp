Bucket SoundBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Hold, 0, 0.0, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.TouchTick, 0, 0.0, 0.0, 1.0, 1.0, 270)
}, Text.MillisecondUnit);
Bucket ScratchSoundBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Scratch, 0, 0.0, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.TouchScratchTick, 0, 0.0, 0.0, 1.0, 1.0, 270)
}, Text.MillisecondUnit);

class Sound : public Archetype {
	public:
	
	string name = "Sirius Sound";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(holdType);
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
        input.time = beat;
        currentJudgeStartTime = Max(currentJudgeStartTime, info.index);
        var thisId = info.index;
		input.time = judgment.bad;
		life.miss_increment = -40;
        if(replay) {
        	input.time = beat + accuracy;
			if(holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101) input.bucketIndex = int(SoundBucket);
			if(holdType == 110 || holdType == 111 || holdType == 1110 || holdType == 1111) input.bucketIndex = int(ScratchSoundBucket);
        	input.bucketValue = accuracy * 1000;
        	if(firstComboTime == 0) firstComboTime = beat;
			if(autoSFX) PlayScheduled(Clips.Sound, beat, minSFXDistance);
        	if(judgeResult != 0 && !autoSFX) PlayScheduled(Clips.Sound, beat, minSFXDistance);
        	if(judgeResult == 0) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy });
			if(judgeResult == 1) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy });
			if(judgeResult == 2) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfect, combo, status, thisId, accuracy, currentAccuracy });
			if(judgeResult == 3) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy });
			if(judgeResult == 4) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGood, combo, status, thisId, accuracy, currentAccuracy });
			if(judgeResult == 5) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeBad, combo, status, thisId, accuracy, currentAccuracy });
        } else {
        	input.time = beat;
			if(holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101) input.bucketIndex = int(SoundBucket);
			if(holdType == 110 || holdType == 111 || holdType == 1110 || holdType == 1111) input.bucketIndex = int(ScratchSoundBucket);
        	input.bucketValue = 0;
        	if(firstComboTime == 0) firstComboTime = beat;
	        PlayScheduled(Clips.Sound, beat, minSFXDistance);
			Spawn(getAid(UpdateJudgment), { beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0 });
		}
 	}

 	SonolusApi updateParallel() {
		if(holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101) 
			drawTick(Sprites.TouchTick, TimeToScaledTime(beat), lane, enLane);
		if(holdType == 110 || holdType == 111 || holdType == 1110 || holdType == 1111) 
			drawTick(Sprites.TouchScratchTick, TimeToScaledTime(beat), lane, enLane);
	}
};
