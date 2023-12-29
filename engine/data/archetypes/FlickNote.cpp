class FlickNote : public Archetype {
    public:

	static constexpr const char* name = "Sirius Flick Note";
    bool hasInput = true;

	defineEntityData(beat);
	defineEntityData(lane);
	defineEntityData(laneLength);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
    Variable<EntityMemoryId> mapId;
    Variable<EntityMemoryId> activate;

    SonolusApi spawnOrder() { return 1000 + beat; }
    SonolusApi shouldSpawn() { return times.now > beat - appearTime; }

	SonolusApi preprocess() {
		FUNCBEGIN
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.good;
		inputTimeMax = beat + judgment.good;
		mapId = -1;
		activate = 0;
        IF (LevelOption.get(Options.Mirror)) lane.set(13 - enLane); FI
        return VOID;
		// beat.set(Buckets.NormalNote),
	}

	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) EntityDespawn.set(0, 1); FI
		IF (activate == 0) {
			IF (mapId != -1 && inputList_old.getValById(mapId) != -1) {
				activate = 1;
			} FI
		} FI
		IF (activate == 1) {
			IF (findFlickTouch(lane, enLane) != -1) {
				EntityDespawn.set(0, 1);
			} FI
		} FI
		mapId = inputList.size;
		inputList.add(EntityInfo.get(0), -1);
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
		drawNormalNote(Sprites.ScratchNote, lane, enLane, beat);
		drawArrow(lane, enLane, beat);
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
