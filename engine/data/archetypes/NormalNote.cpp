class NormalNote : public Archetype {
    public:

    static constexpr const char* name = "Sirius Normal Note";
    vector<pair<string, int> > data = {{"beat", 0}, {"lane", 1}, {"laneLength", 2}};
    bool hasInput = true;

	defineEntityData(beat);
	defineEntityData(lane);
	defineEntityData(laneLength);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;

    SonolusApi spawnOrder() { return 1000 + beat; }
    SonolusApi shouldSpawn() { return times.now > beat - appearTime; }

	SonolusApi preprocess() {
		FUNCBEGIN
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.good;
		inputTimeMax = beat + judgment.good;
        IF (LevelOption.get(Options.Mirror)) lane.set(13 - enLane); FI
        return VOID;
		// beat.set(Buckets.NormalNote),
	}

	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (times.now < inputTimeMin) Exit(0); FI
		// claimStart(EntityInfo.get(0), beat, getHitbox(lane, enLane), getFullHitbox(lane, enLane));
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

    SonolusApi touch() {
    	FUNCBEGIN
		IF (times.now < inputTimeMin) Exit(0); FI
		var index = getClaimedStart(EntityInfo.get(0));
		IF (index == -1) Exit(0); FI
		EntityDespawn.set(0, 1);
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
