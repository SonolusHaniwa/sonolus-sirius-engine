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
 
     SonolusApi spawnTime() { return beat - appearTime; }
     SonolusApi despawnTime() { return beat; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
        IF (isReplay) {
        	IF (judgeResult != 0) PlayScheduled(Clips.Sound, beat, minSFXDistance); FI
        	IF (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeMiss}); FI
			IF (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfectPlus}); FI
			IF (judgeResult == 2) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfect}); FI
			IF (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGreat}); FI
			IF (judgeResult == 4) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGood}); FI
			IF (judgeResult == 5) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeBad}); FI
        } ELSE {
	        PlayScheduled(Clips.Sound, beat, minSFXDistance);
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto});
		} FI
 	    return VOID;
 	}

 	SonolusApi updateParallel() {
		FUNCBEGIN
		IF (holdType == 100 || holdType == 101) drawTick(Sprites.TouchTick, beat, lane, enLane); FI
		IF (holdType == 110 || holdType == 111) drawTick(Sprites.TouchScratchTick, beat, lane, enLane); FI
		return VOID;
	}
};
