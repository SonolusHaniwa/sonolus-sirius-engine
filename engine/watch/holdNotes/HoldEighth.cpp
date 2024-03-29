 class SiriusHoldEighth : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Hold Eighth";
	 bool hasInput = true;
	 
	 defineImports(beat);
 	 defineImports(lane);
 	 defineImports(laneLength);
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
        IF (isReplay == 1) {
        	Set(EntityInputId, 0, beat + accuracy);
        	Set(EntityInputId, 2, accuracy);
        	IF (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeMiss}); FI
			IF (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfectPlus}); FI
			IF (judgeResult == 2) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfect}); FI
			IF (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGreat}); FI
			IF (judgeResult == 4) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGood}); FI
			IF (judgeResult == 5) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeBad}); FI
        } ELSE {
        	Set(EntityInputId, 0, beat);
        	Set(EntityInputId, 2, 0);
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto});
		} FI
 	    return VOID;
 	}
};
