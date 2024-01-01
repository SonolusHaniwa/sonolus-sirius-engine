class SiriusHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Hold End";
	defineEntityData(beat);
	defineEntityData(stBeat);
	defineEntityData(lane);
	defineEntityData(laneLength);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;

    SonolusApi preprocess() {
   		FUNCBEGIN
        IF (LevelOption.get(Options.Mirror)) lane.set(13 - enLane); FI
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.good;
		inputTimeMax = beat + judgment.good;
        return VOID;
    }
    
    SonolusApi spawnOrder() { return 1000 + stBeat; }
    SonolusApi shouldSpawn() { return times.now > stBeat - appearTime; }

    
};
