 class SiriusHoldEighth : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Hold Eighth";
	 bool hasInput = true;
	 
	 defineImports(beat);
 	 defineImports(lane);
 	 defineImports(laneLength);
 	 defineImports(judgeResult);
	 defineImportsDetailed(accuracy, "#ACCURACY");
     Variable<EntityMemoryId> enLane;
     Variable<EntitySharedMemoryId> combo;
     Variable<EntitySharedMemoryId> status;
     Variable<EntitySharedMemoryId> nextNoteTime;
 
     SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
     SonolusApi despawnTime() { return TimeToScaledTime(beat); }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
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
        	Set(EntityInputId, 2, accuracy * 1000);
        	EntitySharedMemoryArray[id].set(2, beat + accuracy);
        	IF (firstComboTime == 0) firstComboTime = beat.get(); FI
        	IF (judgeResult == 0) currentAccuracy = currentAccuracy - 1.01; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy}); FI
			IF (judgeResult == 1) currentAccuracy = currentAccuracy; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy}); FI
			IF (judgeResult == 2) currentAccuracy = currentAccuracy - 0.01; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfect, combo, status, thisId, accuracy, currentAccuracy}); FI
			IF (judgeResult == 3) currentAccuracy = currentAccuracy - 0.21; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy}); FI
			IF (judgeResult == 4) currentAccuracy = currentAccuracy - 0.51; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGood, combo, status, thisId, accuracy, currentAccuracy}); FI
			IF (judgeResult == 5) currentAccuracy = currentAccuracy - 1.01; Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeBad, combo, status, thisId, accuracy, currentAccuracy}); FI
        } ELSE {
			comboNumber = comboNumber + 1;
			combo = comboNumber.get();
			comboStatus = 0;
			status = comboStatus.get();
        	Set(EntityInputId, 0, beat);
        	Set(EntityInputId, 2, 0);
        	EntitySharedMemoryArray[id].set(2, beat);
        	IF (firstComboTime == 0) firstComboTime = beat.get(); FI
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0});
		} FI
		lastNoteId = EntityInfo.get(0);
 	    return VOID;
 	}
};
