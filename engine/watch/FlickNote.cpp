Bucket FlickNoteBucket = defineBucket({
    EngineDataBucketSprite(Sprites.ScratchNote, 0, -0.35, 0.0, 2.0, 1.0, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.8, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.6, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.4, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.2, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.8, 0.4, 1.2, 90),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.6, 0.4, 1.2, 90),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.4, 0.4, 1.2, 90),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.2, 0.4, 1.2, 90),
}, Text.MillisecondUnit);
 
class FlickNote : public Archetype {
	public:

	string name = "Sirius Flick Note";
	bool hasInput = true;

	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(scratchLength);
	defineImport(judgeResult);
	defineImport(activation);
	defineImportDetailed(accuracy, "#ACCURACY");
	var enLane;
	var combo = var(EntitySharedMemoryId, 0);
	var status = var(EntitySharedMemoryId, 1);
	var nextNoteTime = var(EntitySharedMemoryId, 2);
	var currentAccuracy = var(EntitySharedMemoryId, 3);

	SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
	SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }

	SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength, scratchLength = -1 * scratchLength;
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, info.index);
        var thisId = info.index;
		input.time = judgment.bad;
		life.miss_increment = -80;
        if (replay == 1) {
        	input.time = beat + accuracy;
        	input.bucketIndex = int(FlickNoteBucket);
        	input.bucketValue = accuracy * 1000;
        	if (firstComboTime == 0) firstComboTime = beat;
			if (autoSFX)
				PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			else {
				if (judgeResult == 1) PlayScheduled(Clips.Scratch, beat + accuracy, minSFXDistance);
				if (judgeResult == 3) PlayScheduled(Clips.Great, beat + accuracy, minSFXDistance);
			}
			if (judgeResult == 0) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 1) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 3) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy });
        } else {
        	input.time = beat;
        	input.bucketIndex = int(FlickNoteBucket);
        	input.bucketValue = 0;
        	if (firstComboTime == 0) firstComboTime = beat;
	        PlayScheduled(Clips.Scratch, beat, minSFXDistance);
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
		spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane);
 	}

 	SonolusApi updateParallel() {
		drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, TimeToScaledTime(beat));
		if (scratchLength == 0) drawArrow(lane, enLane, TimeToScaledTime(beat));
		else {
			if (scratchLength > 0) drawRightArrow(lane, enLane, TimeToScaledTime(beat));
			else drawLeftArrow(lane, enLane, TimeToScaledTime(beat));
		}
 	}
};
