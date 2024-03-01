 class FlatNote : public Archetype {
     public:
     
     bool hasInput = true;

     defineEntityData(beat);
     defineEntityData(lane);
     defineEntityData(laneLength);
     Variable<EntityMemoryId> enLane;
     virtual let getSprite() { return -1; }
     virtual let getClip() { return -1; }
     virtual EffectsArray getEffects() { return {}; }
 
     SonolusApi spawnTime() { return beat - appearTime; }
     SonolusApi despawnTime() { return beat; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
        PlayScheduled(getClip(), beat, minSFXDistance);
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
		spawnEffect(getEffects().linear, getEffects().circular, lane, enLane);
		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
 		drawNormalNote(getSprite(), lane, enLane, beat);
 		return VOID;
 	}
};
