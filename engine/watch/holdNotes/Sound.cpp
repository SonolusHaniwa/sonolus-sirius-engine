 class SiriusSound : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Sound";
	 bool hasInput = true;
	 
	 defineEntityData(beat);
 	 defineEntityData(lane);
 	 defineEntityData(laneLength);
	 defineEntityData(holdType);
     Variable<EntityMemoryId> enLane;
 
     SonolusApi spawnTime() { return beat - appearTime; }
     SonolusApi despawnTime() { return beat; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
        PlayScheduled(Clips.Sound, beat, minSFXDistance);
		Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto});
 	    return VOID;
 	}

 	SonolusApi updateParallel() {
		FUNCBEGIN
		IF (holdType == 100 || holdType == 101) drawTick(Sprites.TouchTick, beat, lane, enLane); FI
		IF (holdType == 110 || holdType == 111) drawTick(Sprites.TouchScratchTick, beat, lane, enLane); FI
		return VOID;
	}
};
