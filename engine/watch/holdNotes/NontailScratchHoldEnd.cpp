class SiriusNontailScratchHoldEnd : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Nontail Scratch Hold End";
	 bool hasInput = false;
	 
	 defineImports(beat);
	 defineImports(stBeat);
	 defineImports(lane);
	 defineImports(laneLength);
	 defineImports(scratchLength);
 	 defineImports(judgeResult);
 	 defineImports(accuracy);
 	 defineImports(time1);
 	 defineImports(time2);
 	 defineImports(time3);
 	 defineImports(time4);
 	 defineImports(time5);
 	 defineImports(time6);
 	 defineImports(time7);
 	 defineImports(time8);
 	 defineImports(time9);
 	 defineImports(time10);
 	 defineImports(time11);
 	 defineImports(time12);
 	 defineImports(time13);
 	 defineImports(time14);
 	 defineImports(time15);
 	 defineImports(time16);
 	 defineImports(time17);
 	 defineImports(time18);
 	 defineImports(time19);
 	 defineImports(time20);
 	 defineImports(time21);
 	 defineImports(time22);
 	 defineImports(time23);
 	 defineImports(time24);
 	 defineImports(time25);
	 Variable<EntityMemoryId> enLane;
     Variable<EntityMemoryId> effectInstanceId;
	 Variable<EntityMemoryId> scratchLane;
	 Variable<EntityMemoryId> scratchEnLane;
     Variable<EntitySharedMemoryId> combo;
     Variable<EntitySharedMemoryId> status;
 
     SonolusApi spawnTime() { return TimeToScaledTime(stBeat) - appearTime; }
     SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
 	 	stBeat = stBeat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; scratchLength = -1 * scratchLength; FI
        enLane = lane + laneLength - 1;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
        currentJudgeStartTime = Max(currentJudgeStartTime, EntityInfo.get(0));
        IF (isReplay == 1) {
			// IF (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			// ELSE comboNumber = 0; FI
			// combo = comboNumber.get();
			// comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			// status = comboStatus.get();
        	// Set(EntityInputId, 0, beat + accuracy);
        	// Set(EntityInputId, 1, Buckets.ScratchHoldEnd);
        	// Set(EntityInputId, 2, accuracy);
	        // PlayScheduled(Clips.Perfect, beat + accuracy, minSFXDistance);
        	// IF (judgeResult == 1) PlayScheduled(Clips.Scratch, beat + accuracy, minSFXDistance); FI
			// IF (judgeResult == 3) PlayScheduled(Clips.Great, beat + accuracy, minSFXDistance); FI
        	// IF (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeMiss, combo, status}); FI
			// IF (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfectPlus, combo, status}); FI
			// IF (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGreat, combo, status}); FI
			FOR (i, time1.offset, time25.offset + 1, 2) {
				var startTime = stBeat + EntityData.get(i);
				var endTime = If(EntityData.get(i + 1) == 0, beat + accuracy, stBeat + EntityData.get(i + 1));
				IF (EntityData.get(i) == 0) BREAK; FI
				IF (startTime < endTime) {
					StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, startTime), endTime);
				} FI
			} DONE
        } ELSE {
			// comboNumber = comboNumber + 1;
			// combo = comboNumber.get();
			// comboStatus = 0;
			// status = comboStatus.get();
        	// Set(EntityInputId, 0, beat);
        	// Set(EntityInputId, 1, Buckets.ScratchHoldEnd);
        	// Set(EntityInputId, 2, 0);
	        // PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			// Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto, combo, status});
		} FI
 	    return VOID;
 	}

 	SonolusApi initialize() {
 		FUNCBEGIN
        effectInstanceId = 0;
        return VOID;
 	}
 
 	SonolusApi updateSequential() {
 		FUNCBEGIN
 		IF (isReplay) {
 			var active = false;
 			FOR (i, time1.offset, time25.offset + 1, 2) {
				var startTime = stBeat + EntityData.get(i);
				var endTime = If(EntityData.get(i + 1) == 0, beat + accuracy, stBeat + EntityData.get(i + 1));
				IF (EntityData.get(i) == 0) BREAK; FI
				active = active || (startTime <= times.now && times.now <= endTime);
			} DONE
			IF (active) {
				IF (effectInstanceId.get() == 0) {
					effectInstanceId.set(spawnHoldEffect(Effects.Scratch, lane, enLane));
				} ELSE {
					updateHoldEffect(effectInstanceId, lane, enLane);
				} FI
			} ELSE {
		 		IF (effectInstanceId.get()) {
		   			DestroyParticleEffect(effectInstanceId);
   					effectInstanceId = 0;
		   		} FI
			} FI
 		} ELSE {
 			IF (times.now >= stBeat) {
				IF (effectInstanceId.get() == 0) {
					effectInstanceId.set(spawnHoldEffect(Effects.Scratch, lane, enLane));
				} ELSE {
					updateHoldEffect(effectInstanceId, lane, enLane);
				} FI
			} FI
		} FI
 		return VOID;
 	}

 	SonolusApi terminate() {
 		FUNCBEGIN
 		IF (effectInstanceId.get()) {
   			DestroyParticleEffect(effectInstanceId);
   			effectInstanceId = 0;
   		} FI
		// IF (times.skip) Return(0); FI
		// IF (isReplay == 1 && judgeResult == 0) Return(0); FI
		// spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane);
 		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
 		IF (isReplay) {
 			var active = false;
 			FOR (i, time1.offset, time25.offset + 1, 2) {
				var startTime = stBeat + EntityData.get(i);
				var endTime = If(EntityData.get(i + 1) == 0, beat + accuracy, stBeat + EntityData.get(i + 1));
				IF (EntityData.get(i) == 0) BREAK; FI
				active = active || (startTime <= times.now && times.now <= endTime);
			} DONE
			drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), active);
 		} ELSE {
			drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), stBeat <= times.now && times.now <= beat);
		} FI
		IF (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, times.scaled); FI
		// IF (times.scaled > TimeToScaledTime(beat) - appearTime) 
		// 	drawNormalNote(Sprites.ScratchNoteLeft, scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
		// IF (times.scaled > TimeToScaledTime(beat) - appearTime) {
		// 	IF (scratchLength > 0) drawRightArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
		// 	IF (scratchLength < 0) drawLeftArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
		// 	IF (scratchLength == 0) drawArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat)); FI
		// } FI
 		return VOID;
 	}
};