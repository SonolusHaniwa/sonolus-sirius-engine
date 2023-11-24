class SiriusFlatNote : public Archetype {
    public:

    vector<pair<string, int> > data = {{"beat", 0}, {"lane", 1}, {"laneLength", 2}};
    bool hasInput = true;

    var beat = EntityData.get(0);
    var lane = EntityData.get(1);
    var laneLength = EntityData.get(2);
    var enLane = lane + laneLength - 1;

    var spawnTime() { return beat - appearTime; }
    var despawnTime() { return beat; }

    virtual var getClip() { return -1; }
    virtual var getLinearEffect() { return -1; }
    virtual var getCircularEffect() { return -1; }

	var preprocess() {
		return {
	        IF (LevelOption.get(Options.Mirror)) {
	            EntityData.set(1, 13 - enLane)
	        } FI,
	        EntityInput.set(0, beat),
	        PlayScheduled(getClip(), beat, minSFXDistance),
	    };
	}

	int updateSequentialOrder = 1;
	var updateSequential() {
		return {
			IF (times.now >= beat - 0.03) {
				SpawnJudgeText(beat)
			} FI
		};
	}

	var terminate() {
		return {
			IF (times.skip) { Return(0) } FI,
			spawnEffect(getLinearEffect(), getCircularEffect(), lane, enLane),
		};
	}
};
