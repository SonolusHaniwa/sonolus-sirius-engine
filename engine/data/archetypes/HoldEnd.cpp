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
	Variable<EntityMemoryId> isHolding;

    SonolusApi preprocess() {
   		FUNCBEGIN
        IF (LevelOption.get(Options.Mirror)) lane.set(13 - enLane); FI
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.good;
		inputTimeMax = beat + judgment.good;
		isHolding = false;
        return VOID;
    }
    
    SonolusApi spawnOrder() { return 1000 + stBeat; }
    SonolusApi shouldSpawn() { return times.now > stBeat - appearTime; }

	SonolusApi complete(let t = times.now) {
		FUNCBEGIN
		EntityDespawn.set(0, 1);
		return VOID;
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (times.now < stBeat) Return(0); FI
		isHolding = findHoldTouch(lane, enLane) != -1;

		// 判定主代码
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) complete(-1); FI
		return VOID;
	}

    SonolusApi updateParallel() {
		FUNCBEGIN
		drawHoldEighth(Sprites.Hold, lane, enLane, stBeat, beat, isHolding);
		IF (times.now > beat - appearTime) drawNormalNote(Sprites.HoldNote, lane, enLane, beat); FI
		return VOID;
	}
};
