 class SiriusHoldEighth : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Hold Eighth";
	 bool hasInput = true;
	 
	 defineEntityData(beat);
 	 defineEntityData(lane);
 	 defineEntityData(laneLength);
     Variable<EntityMemoryId> enLane;
 
     SonolusApi spawnTime() { return beat - appearTime; }
     SonolusApi despawnTime() { return beat; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
		Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto});
 	    return VOID;
 	}
};
