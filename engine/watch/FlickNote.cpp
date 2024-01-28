 class FlickNote : public Archetype {
     public:

     static constexpr const char* name = "Sirius Flick Note";
     bool hasInput = true;

     defineImports(beat);
     defineImports(lane);
     defineImports(laneLength);
     Variable<EntityMemoryId> enLane;
 
     SonolusApi spawnTime() { return beat - appearTime; }
     SonolusApi despawnTime() { return beat; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
        PlayScheduled(Clips.Scratch, beat, minSFXDistance);
		Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto});
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
