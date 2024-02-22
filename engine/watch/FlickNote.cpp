 class FlickNote : public Archetype {
     public:

     static constexpr const char* name = "Sirius Flick Note";
     bool hasInput = true;

     defineImports(beat);
     defineImports(lane);
     defineImports(laneLength);
     defineImports(judgeResult);
     defineImports(activation);
     defineImports(accuracy);
     Variable<EntityMemoryId> enLane;
 
     SonolusApi spawnTime() { return beat - appearTime; }
     SonolusApi despawnTime() { return beat + accuracy; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
        IF (isReplay == 1) {
   			IF (judgeResult == 1) PlayScheduled(Clips.Scratch, beat + accuracy, minSFXDistance); FI
			IF (judgeResult == 3) PlayScheduled(Clips.CriticalGood, beat + accuracy, minSFXDistance); FI
			IF (judgeResult == 0) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeMiss}); FI
			IF (judgeResult == 1) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgePerfectPlus}); FI
			IF (judgeResult == 3) Spawn(getArchetypeId(UpdateJudgment), {beat + accuracy, Sprites.JudgeGreat}); FI
        } ELSE {
	        PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto});
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
		spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane);
		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
		drawNormalNote(Sprites.ScratchNote, lane, enLane, beat);
		drawArrow(lane, enLane, beat);
 		return VOID;
 	}
};
