class FlatNote : public Archetype {
    public:

    bool hasInput = true;

	defineEntityData(beat);
	defineEntityData(lane);
	defineEntityData(laneLength);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
    virtual let getSprite() { return -1; }

    SonolusApi spawnOrder() { return 1000 + beat; }
    SonolusApi shouldSpawn() { return times.now > beat - appearTime; }

	SonolusApi preprocess() {
		FUNCBEGIN
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.good;
		inputTimeMax = beat + judgment.good;
		touchIndex = -1;
        IF (LevelOption.get(Options.Mirror)) lane.set(13 - enLane); FI
        return VOID;
		// beat.set(Buckets.NormalNote),
	}

	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) EntityDespawn.set(0, 1); FI
		return VOID;
	}

 //    var updateSequential() {
	// 	return {
	//         drawNormalNote(Sprites.NormalNote, lane, enLane, beat),
	// 		IF (times.now > beat + judgment.good) {
 //                SpawnSubJudgeText(Sprites.JudgeMiss)
	// 		} FI
	// 	};
	// }

	SonolusApi updateParallel() {
		FUNCBEGIN
		drawNormalNote(getSprite(), lane, enLane, beat);
		// let index = getTouch(lane, enLane);
		// touchIndex = index;
		return VOID;
	}

 //    var updateParallel() {
	// 	return {
	//         IF (times.now > beat + judgment.good) {
	//             EntityInput.set(0, 0),
	//             EntityInput.set(1, 0),
	//             EntityDespawn.set(0, 1),
	//         } FI
	//     };	
	// }
};
