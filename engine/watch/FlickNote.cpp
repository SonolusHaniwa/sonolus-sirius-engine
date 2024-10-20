 class FlickNote : public Archetype {
     public:

     static constexpr const char* name = "Sirius Flick Note";
     bool hasInput = true;

     defineImports(beat);
     defineImports(lane);
     defineImports(laneLength);
     defineImports(scratchLength);
     defineImports(judgeResult);
     defineImports(activation);
	 defineImportsDetailed(accuracy, "#ACCURACY");
     Variable<EntityMemoryId> enLane;
     Variable<EntitySharedMemoryId> combo;
     Variable<EntitySharedMemoryId> status;
     Variable<EntitySharedMemoryId> nextNoteTime;
 
     SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
     SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; scratchLength = -1 * scratchLength; FI
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, EntityInfo.get(0));
        nextNoteTime = 99999;
        let id = lastNoteId, thisId = EntityInfo.get(0);
		EntityInput.set(0, judgment.bad);
		totalAccuracy = totalAccuracy + 1.01;
        IF (isReplay == 1) {
			IF (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			ELSE comboNumber = 0; FI
			combo = comboNumber.get();
			comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			status = comboStatus.get();
        	Set(EntityInputId, 0, beat + accuracy);
        	Set(EntityInputId, 1, Buckets.FlickNote);
        	Set(EntityInputId, 2, accuracy * 1000);
        	EntitySharedMemoryArray[id].set(2, beat + accuracy);
        	IF (firstComboTime == 0) firstComboTime = beat.get(); FI
			IF (autoSFX)
				PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			ELSE {
				IF (judgeResult == 1) PlayScheduled(Clips.Scratch, beat + accuracy, minSFXDistance); FI
				IF (judgeResult == 3) PlayScheduled(Clips.Great, beat + accuracy, minSFXDistance); FI
			} FI
			IF (judgeResult == 0) currentAccuracy = currentAccuracy - 1.01; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy}); FI
			IF (judgeResult == 1) currentAccuracy = currentAccuracy; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy}); FI
			IF (judgeResult == 3) currentAccuracy = currentAccuracy - 0.21; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy}); FI
        } ELSE {
			comboNumber = comboNumber + 1;
			combo = comboNumber.get();
			comboStatus = 0;
			status = comboStatus.get();
        	Set(EntityInputId, 0, beat);
        	Set(EntityInputId, 1, Buckets.FlickNote);
        	Set(EntityInputId, 2, 0);
        	EntitySharedMemoryArray[id].set(2, beat);
        	IF (firstComboTime == 0) firstComboTime = beat.get(); FI
	        PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0});
		} FI;
		lastNoteId = EntityInfo.get(0);
 	    return VOID;
 	}
 
 	// int updateSequentialOrder = 1;
 	// SonolusaApi updateSequential() {
 	// 	FUNCBEGIN
		// IF (times.now >= beat - 0.03) {
		// 	SpawnSubJudgeText(Sprites.PerfectPlus);
		// } FI
 	// 	return VOID;
 	// }
 
 	SonolusApi terminate() {
 		FUNCBEGIN
		IF (times.skip) Return(0); FI
		IF (isReplay == 1 && judgeResult == 0) Return(0); FI
		spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane);
		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
		drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, TimeToScaledTime(beat));
		IF (scratchLength == 0) drawArrow(lane, enLane, TimeToScaledTime(beat));
		ELSE {
			IF (scratchLength > 0) drawRightArrow(lane, enLane, TimeToScaledTime(beat));
			ELSE drawLeftArrow(lane, enLane, TimeToScaledTime(beat)); FI
		} FI
 		return VOID;
 	}
};
