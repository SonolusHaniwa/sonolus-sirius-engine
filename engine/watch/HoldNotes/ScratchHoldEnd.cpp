Bucket ScratchHoldEndBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Scratch, 0, -0.6, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.ScratchNote, 0, 2.4, 0.0, 2.0, 1.0, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.8, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.6, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.4, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.2, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.8, 0.4, 1.2, 90),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.6, 0.4, 1.2, 90),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.4, 0.4, 1.2, 90),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.2, 0.4, 1.2, 90)
}, Text.MillisecondUnit);

class ScratchHoldEnd : public Archetype {
	public:
	
	string name = "Sirius Scratch Hold End";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(stBeat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(scratchLength);
	defineImport(judgeResult);
	defineImportDetailed(accuracy, "#ACCURACY");
	defineImport(time1);
	defineImport(time2);
	defineImport(time3);
	defineImport(time4);
	defineImport(time5);
	defineImport(time6);
	defineImport(time7);
	defineImport(time8);
	defineImport(time9);
	defineImport(time10);
	defineImport(time11);
	defineImport(time12);
	defineImport(time13);
	defineImport(time14);
	defineImport(time15);
	defineImport(time16);
	defineImport(time17);
	defineImport(time18);
	defineImport(time19);
	defineImport(time20);
	defineImport(time21);
	defineImport(time22);
	defineImport(time23);
	defineImport(time24);
	defineImport(time25);
	var enLane;
	var effectInstanceId;
	var scratchLane;
	var scratchEnLane;
	var combo = EntitySharedMemory[0];
	var status = EntitySharedMemory[1];
	var nextNoteTime = EntitySharedMemory[2];

	SonolusApi spawnTime() { return TimeToScaledTime(stBeat) - appearTime; }
	SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }

	SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
 	 	stBeat = stBeat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength, scratchLength = -1 * scratchLength; 
        enLane = lane + laneLength - 1;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
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
        	input.bucketIndex = int(ScratchHoldEndBucket);
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
			if (autoSFX) StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			else
				for (var i = time1.index; i <= time25.index; i += 2) {
					var startTime = stBeat + EntityData[i];
					var endTime = If(EntityData[i + 1] == 0, beat + accuracy, stBeat + EntityData[i + 1]);
					if (EntityData[i] == 0) break; 
					if (startTime < endTime) {
						StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, startTime), endTime);
					} 
				}
        } else {
			comboNumber = comboNumber + 1;
			combo = comboNumber;
			comboStatus = 0;
			status = comboStatus;
        	input.time = beat;
        	input.bucketIndex = int(ScratchHoldEndBucket);
        	input.bucketValue = 0;
        	EntitySharedMemoryArray[id].generic[2] = beat;
        	if (firstComboTime == 0) firstComboTime = beat; 
	        PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			Spawn(getAid(UpdateJudgment), { beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0 });
		} 
		lastNoteId = info.index;
 	}

 	SonolusApi initialize() {
        effectInstanceId = 0;
 	}
 
 	SonolusApi updateSequential() {
 		if (replay) {
 			var active = false;
			for (var i = time1.index; i <= time25.index; i += 2) {
				var startTime = stBeat + EntityData[i];
				var endTime = If(EntityData[i + 1] == 0, beat + accuracy, stBeat + EntityData[i + 1]);
				if (EntityData[i] == 0) break; 
				active = active || (startTime <= times.now && times.now <= endTime);
			}
			if (active) {
				if (effectInstanceId == 0) {
					effectInstanceId = spawnHoldEffect(Effects.Scratch, lane, enLane);
				} else {
					updateHoldEffect(effectInstanceId, lane, enLane);
				} 
			} else {
		 		if (effectInstanceId) {
		   			DestroyParticleEffect(effectInstanceId);
   					effectInstanceId = 0;
		   		} 
			} 
 		} else {
 			if (times.now >= stBeat) {
				if (effectInstanceId == 0) {
					effectInstanceId = spawnHoldEffect(Effects.Scratch, lane, enLane);
				} else {
					updateHoldEffect(effectInstanceId, lane, enLane);
				} 
			} 
		} 
 	}

 	SonolusApi terminate() {
 		if (effectInstanceId) {
   			DestroyParticleEffect(effectInstanceId);
   			effectInstanceId = 0;
   		} 
		if (skip) return;
		if (replay == 1 && judgeResult == 0) return;
		spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane);
 	}

 	SonolusApi updateParallel() {
 		if (replay) {
 			var active = false;
 			for (var i = time1.index; i <= time25.index; i += 2) {
				var startTime = stBeat + EntityData[i];
				var endTime = If(EntityData[i + 1]== 0, beat + accuracy, stBeat + EntityData[i + 1]);
				if (EntityData[i] == 0) break; 
				active = active || (startTime <= times.now && times.now <= endTime);
			}
			drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), active);
 		} else {
			drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), stBeat <= times.now && times.now <= beat);
		} 
		if (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, times.scaled); 
		if (times.scaled > TimeToScaledTime(beat) - appearTime) 
			drawNormalNote(Sprites.ScratchNoteLeft, scratchLane, scratchEnLane, TimeToScaledTime(beat)); 
		if (times.scaled > TimeToScaledTime(beat) - appearTime) {
			if (scratchLength > 0) drawRightArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); 
			if (scratchLength < 0) drawLeftArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); 
			if (scratchLength == 0) drawArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); 
		} 
 	}
};