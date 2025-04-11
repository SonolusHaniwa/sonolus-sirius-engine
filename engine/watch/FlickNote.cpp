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
	var combo = EntitySharedMemory[0];
	var status = EntitySharedMemory[1];
	var nextNoteTime = EntitySharedMemory[2];

	SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
	SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }

	SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength, scratchLength = -1 * scratchLength;
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, info.index);
        nextNoteTime = 99999;
        var id = lastNoteId, thisId = info.index;
		input.time = judgment.bad;
		totalAccuracy = totalAccuracy + 1.01;
		life.miss_increment = -80;
        if (replay == 1) {
			if (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			else comboNumber = 0;
			combo = comboNumber;
			comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			status = comboStatus;
        	input.time = beat + accuracy;
        	input.bucketIndex = FuncNode(FlickNoteBucket);
        	input.bucketValue = accuracy * 1000;
        	EntitySharedMemoryArray[id].generic[2] = beat + accuracy;
        	if (firstComboTime == 0) firstComboTime = beat;
			if (autoSFX)
				PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			else {
				if (judgeResult == 1) PlayScheduled(Clips.Scratch, beat + accuracy, minSFXDistance);
				if (judgeResult == 3) PlayScheduled(Clips.Great, beat + accuracy, minSFXDistance);
			}
			if (judgeResult == 0) currentAccuracy = currentAccuracy - 1.01, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 1) currentAccuracy = currentAccuracy, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 3) currentAccuracy = currentAccuracy - 0.21, Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy });
        } else {
			comboNumber = comboNumber + 1;
			combo = comboNumber;
			comboStatus = 0;
			status = comboStatus;
        	input.time = beat;
        	input.bucketIndex = FuncNode(FlickNoteBucket);
        	input.bucketValue = 0;
        	EntitySharedMemoryArray[id].generic[2] = beat;
        	if (firstComboTime == 0) firstComboTime = beat;
	        PlayScheduled(Clips.Scratch, beat, minSFXDistance);
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
