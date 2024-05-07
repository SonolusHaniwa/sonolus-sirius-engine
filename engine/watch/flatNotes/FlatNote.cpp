 class FlatNote : public Archetype {
     public:
     
     bool hasInput = true;

     defineImports(beat);
     defineImports(lane);
     defineImports(laneLength);
	 defineImports(judgeResult);
	 defineImports(accuracy);
     Variable<EntityMemoryId> enLane;
     Variable<EntitySharedMemoryId> combo;
     Variable<EntitySharedMemoryId> status;
     virtual let getSprite() { return -1; }
     virtual let getBucket() { return -1; }
     virtual ClipsArray getClips() { return {}; }
     virtual EffectsArray getEffects() { return {}; }
 
     SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
     SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, EntityInfo.get(0));
		IF (isReplay == 1) {
			IF (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
			ELSE comboNumber = 0; FI
			combo = comboNumber.get();
			comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			status = comboStatus.get();
        	Set(EntityInputId, 0, beat + accuracy);
        	Set(EntityInputId, 1, getBucket());
        	Set(EntityInputId, 2, accuracy);
			IF (judgeResult == 1 || judgeResult == 2) PlayScheduled(getClips().perfect, beat + accuracy, minSFXDistance); FI
			IF (judgeResult == 3) PlayScheduled(getClips().great, beat + accuracy, minSFXDistance); FI
			IF (judgeResult == 4 || judgeResult == 5) PlayScheduled(getClips().good, beat + accuracy, minSFXDistance); FI
			IF (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeMiss, combo, status, accuracy}); FI
			IF (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfectPlus, combo, status, accuracy}); FI
			IF (judgeResult == 2) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfect, combo, status, accuracy}); FI
			IF (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGreat, combo, status, accuracy}); FI
			IF (judgeResult == 4) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGood, combo, status, accuracy}); FI
			IF (judgeResult == 5) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeBad, combo, status, accuracy}); FI
		} ELSE {
			comboNumber = comboNumber + 1;
			combo = comboNumber.get();
			comboStatus = 0;
			status = comboStatus.get();
        	Set(EntityInputId, 0, beat);
        	Set(EntityInputId, 1, getBucket());
        	Set(EntityInputId, 2, 0);
			PlayScheduled(getClips().perfect, beat, minSFXDistance);
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto, combo, status});
		} FI;
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
		spawnEffect(getEffects().linear, getEffects().circular, lane, enLane);
		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
 		drawNormalNote(getSprite(), lane, enLane, TimeToScaledTime(beat));
 		return VOID;
 	}
};
