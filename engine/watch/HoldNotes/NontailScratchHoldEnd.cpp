class NontailScratchHoldEnd : public Archetype {
	public:
	
	string name = "Sirius Nontail Scratch Hold End";
	bool hasInput = false;
	
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
	var combo = var(EntitySharedMemoryId, 0);
	var status = var(EntitySharedMemoryId, 1);
	var nextNoteTime = var(EntitySharedMemoryId, 2);
	var currentAccuracy = var(EntitySharedMemoryId, 3);

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
        if (replay == 1) {
			// if (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			// else comboNumber = 0;
			// combo = comboNumber;
			// comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			// status = comboStatus;
        	// input.time = beat + accuracy;
        	// input.bucketIndex = int(Buckets.ScratchHoldEnd);
        	// input.bucketValue = accuracy;
	        // PlayScheduled(Clips.Perfect, beat + accuracy, minSFXDistance);
        	// if (judgeResult == 1) PlayScheduled(Clips.Scratch, beat + accuracy, minSFXDistance);
			// if (judgeResult == 3) PlayScheduled(Clips.Great, beat + accuracy, minSFXDistance);
        	// if (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeMiss, combo, status});
			// if (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfectPlus, combo, status});
			// if (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGreat, combo, status});
			if (autoSFX) 
				StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
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
			// comboNumber = comboNumber + 1;
			// combo = comboNumber;
			// comboStatus = 0;
			// status = comboStatus;
        	// input.time = beat;
        	// input.bucketIndex = int(Buckets.ScratchHoldEnd);
        	// input.bucketValue = 0;
	        // PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			// Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto, combo, status});
		}
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
		// if (times.skip) Return(0);
		// if (replay == 1 && judgeResult == 0) Return(0);
		// spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane);
 	}

 	SonolusApi updateParallel() {
 		if (replay) {
 			var active = false;
 			for (var i = time1.index; i <= time25.index; i += 2) {
				var startTime = stBeat + EntityData[i];
				var endTime = If(EntityData[i + 1] == 0, beat + accuracy, stBeat + EntityData[i + 1]);
				if (EntityData[i] == 0) break;
				active = active || (startTime <= times.now && times.now <= endTime);
			}
			drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), active);
 		} else {
			drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), stBeat <= times.now && times.now <= beat);
		}
		if (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, times.scaled);
		// if (times.scaled > TimeToScaledTime(beat) - appearTime) 
		// 	drawNormalNote(Sprites.ScratchNoteLeft, scratchLane, scratchEnLane, TimeToScaledTime(beat));
		// if (times.scaled > TimeToScaledTime(beat) - appearTime) {
		// 	if (scratchLength > 0) drawRightArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat));
		// 	if (scratchLength < 0) drawLeftArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat));
		// 	if (scratchLength == 0) drawArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat));
		// }
 	}
};