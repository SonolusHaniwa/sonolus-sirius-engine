 class SiriusSound : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Sound";
	 bool hasInput = true;
	 
	 defineImports(beat);
 	 defineImports(lane);
 	 defineImports(laneLength);
	 defineImports(holdType);
	 defineImports(judgeResult);
	 defineImports(accuracy);
     Variable<EntityMemoryId> enLane;
 
     SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
     SonolusApi despawnTime() { return TimeToScaledTime(beat); }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
        IF (isReplay) {
			comboNumber = comboNumber + 1;
			let combo = comboNumber.get();
			comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
			let status = comboStatus.get();
        	Set(EntityInputId, 0, beat + accuracy);
			IF (holdType == 100 || holdType == 101) Set(EntityInputId, 1, Buckets.Sound); FI
			IF (holdType == 110 || holdType == 111) Set(EntityInputId, 1, Buckets.ScratchSound); FI
        	Set(EntityInputId, 2, accuracy);
        	IF (judgeResult != 0) PlayScheduled(Clips.Sound, beat, minSFXDistance); FI
        	IF (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeMiss, combo, status}); FI
			IF (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfectPlus, combo, status}); FI
			IF (judgeResult == 2) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfect, combo, status}); FI
			IF (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGreat, combo, status}); FI
			IF (judgeResult == 4) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGood, combo, status}); FI
			IF (judgeResult == 5) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeBad, combo, status}); FI
        } ELSE {
			comboNumber = comboNumber + 1;
			let combo = comboNumber.get();
			comboStatus = 0;
			let status = comboStatus.get();
        	Set(EntityInputId, 0, beat);
			IF (holdType == 100 || holdType == 101) Set(EntityInputId, 1, Buckets.Sound); FI
			IF (holdType == 110 || holdType == 111) Set(EntityInputId, 1, Buckets.ScratchSound); FI
        	Set(EntityInputId, 2, 0);
	        PlayScheduled(Clips.Sound, beat, minSFXDistance);
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto, combo, status});
		} FI
 	    return VOID;
 	}

 	SonolusApi updateParallel() {
		FUNCBEGIN
		IF (holdType == 100 || holdType == 101) drawTick(Sprites.TouchTick, TimeToScaledTime(beat), lane, enLane); FI
		IF (holdType == 110 || holdType == 111) drawTick(Sprites.TouchScratchTick, TimeToScaledTime(beat), lane, enLane); FI
		return VOID;
	}
};
