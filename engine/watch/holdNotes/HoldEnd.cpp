 class SiriusHoldEnd : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Hold End";
	 bool hasInput = true;
	 
	 defineImports(beat);
	 defineImports(stBeat);
	 defineImports(lane);
	 defineImports(laneLength);
 	 defineImports(judgeResult);
	 defineImportsDetailed(accuracy, "#ACCURACY");
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
 	 defineImports(time26);
	 Variable<EntityMemoryId> enLane;
     Variable<EntityMemoryId> effectInstanceId;
     Variable<EntitySharedMemoryId> combo;
     Variable<EntitySharedMemoryId> status;
     Variable<EntitySharedMemoryId> nextNoteTime;
 
     SonolusApi spawnTime() { return TimeToScaledTime(stBeat) - appearTime; }
     SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
 	 	stBeat = stBeat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, EntityInfo.get(0));
        nextNoteTime = 99999;
        let id = lastNoteId, thisId = EntityInfo.get(0);
        IF (isReplay) {
			IF (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			ELSE comboNumber = 0; FI
			combo = comboNumber.get();
			comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			status = comboStatus.get();
        	Set(EntityInputId, 0, beat + accuracy);
        	Set(EntityInputId, 1, Buckets.HoldEnd);
        	Set(EntityInputId, 2, accuracy * 1000);
        	EntitySharedMemoryArray[id].set(2, beat + accuracy);
        	IF (firstComboTime == 0) firstComboTime = beat.get(); FI
			IF (autoSFX)
				PlayScheduled(Clips.Perfect, beat, minSFXDistance);
			ELSE {
				IF (judgeResult == 1 || judgeResult == 2) PlayScheduled(Clips.Perfect, beat + accuracy, minSFXDistance); FI
				IF (judgeResult == 3) PlayScheduled(Clips.Great, beat + accuracy, minSFXDistance); FI
				IF (judgeResult == 4) PlayScheduled(Clips.Good, beat + accuracy, minSFXDistance); FI
				IF (judgeResult == 5) PlayScheduled(Clips.Bad, beat + accuracy, minSFXDistance); FI
			} FI
        	IF (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeMiss, combo, status, thisId}); FI
			IF (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId}); FI
			IF (judgeResult == 2) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfect, combo, status, thisId}); FI
			IF (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGreat, combo, status, thisId}); FI
			IF (judgeResult == 4) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGood, combo, status, thisId}); FI
			IF (judgeResult == 5) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeBad, combo, status, thisId}); FI
			IF (autoSFX) 
				StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			ELSE
				FOR (i, time1.offset, time26.offset + 1, 2) {
					var startTime = stBeat + EntityData.get(i);
					var endTime = If(EntityData.get(i + 1) == 0, beat + accuracy, stBeat + EntityData.get(i + 1));
					IF (EntityData.get(i) == 0) BREAK; FI
					IF (startTime < endTime) {
						StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, startTime), endTime);
					} FI
				} DONE
			FI
        } ELSE {
			comboNumber = comboNumber + 1;
			combo = comboNumber.get();
			comboStatus = 0;
			status = comboStatus.get();
        	Set(EntityInputId, 0, beat);
        	Set(EntityInputId, 1, Buckets.HoldEnd);
        	Set(EntityInputId, 2, 0);
        	EntitySharedMemoryArray[id].set(2, beat);
        	IF (firstComboTime == 0) firstComboTime = beat.get(); FI
	        PlayScheduled(Clips.Perfect, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto, combo, status, thisId});
		} FI
		lastNoteId = EntityInfo.get(0);
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
 			FOR (i, time1.offset, time26.offset + 1, 2) {
				var startTime = stBeat + EntityData.get(i);
				var endTime = If(EntityData.get(i + 1) == 0, beat + accuracy, stBeat + EntityData.get(i + 1));
				IF (EntityData.get(i) == 0) BREAK; FI
				active = active || (startTime <= times.now && times.now <= endTime);
			} DONE
			IF (active) {
				IF (effectInstanceId.get() == 0) {
					effectInstanceId.set(spawnHoldEffect(Effects.Hold, lane, enLane));
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
					effectInstanceId.set(spawnHoldEffect(Effects.Hold, lane, enLane));
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
		IF (times.skip) Return(0); FI
		IF (isReplay == 1 && judgeResult == 0) Return(0); FI
		spawnEffect(Effects.HoldLinear, Effects.HoldCircular, lane, enLane);
 		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
 		IF (isReplay) {
 			var active = false;
 			FOR (i, time1.offset, time26.offset + 1, 2) {
				var startTime = stBeat + EntityData.get(i);
				var endTime = If(EntityData.get(i + 1) == 0, beat + accuracy, stBeat + EntityData.get(i + 1));
				IF (EntityData.get(i) == 0) BREAK; FI
				active = active || (startTime <= times.now && times.now <= endTime);
			} DONE
			drawHoldEighth(Sprites.Hold, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), active);
 		} ELSE {
			drawHoldEighth(Sprites.Hold, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), times.now > stBeat && times.now < beat);
		} FI
		IF (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.HoldNoteLeft, lane, enLane, times.scaled); FI
		IF (times.scaled > TimeToScaledTime(beat) - appearTime) 
			drawNormalNote(Sprites.HoldNoteLeft, lane, enLane, TimeToScaledTime(beat)); FI
 		return VOID;
 	}
};