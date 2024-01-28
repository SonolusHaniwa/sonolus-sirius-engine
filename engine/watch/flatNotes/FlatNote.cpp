 class FlatNote : public Archetype {
     public:
     
     bool hasInput = true;

     defineImports(beat);
     defineImports(lane);
     defineImports(laneLength);
	 defineImports(judgeResult);
	 defineImports(accuracy);
     Variable<EntityMemoryId> enLane;
     virtual let getSprite() { return -1; }
     virtual let getClip() { return -1; }
     virtual EffectsArray getEffects() { return {}; }
 
     SonolusApi spawnTime() { return beat - appearTime; }
     SonolusApi despawnTime() { return beat + accuracy; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
		IF (isReplay == 1) {
			IF (judgeResult == 1) PlayScheduled(getClips().perfect, beat + accuracy, minSFXDistance); FI
			IF (judgeResult == 2) PlayScheduled(getClips().great, beat + accuracy, minSFXDistance); FI
			IF (judgeResult == 3) PlayScheduled(getClips().good, beat + accuracy, minSFXDistance); FI
			IF (res == 0) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeMiss});
			IF (res == 1) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfectPlus});
			IF (res == 2) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfect});
			IF (res == 3) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGreat});
			IF (res == 4) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeGood});
			IF (res == 5) Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeBad});
		} ELSE {
			PlayScheduled(getClip().perfect, beat, minSFXDistance);
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
		IF (isReplay == 1 && judgeResult == 0) Return(0) FI
		spawnEffect(getEffects().linear, getEffects().circular, lane, enLane);
		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
 		drawNormalNote(getSprite(), lane, enLane, beat);
 		return VOID;
 	}
};
