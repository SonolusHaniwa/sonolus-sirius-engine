class NormalNote : public Archetype {
    public:

    string name = "Sirius Normal Note";
    vector<pair<string, int> > data = {{"beat", 0}, {"lane", 1}, {"laneLength", 2}};
    bool hasInput = true;

    var beat = EntityData.get(0);
    var lane = EntityData.get(1);
    var laneLength = EntityData.get(2);
    var enLane = lane + laneLength - 1;

    var spawnTime() { return beat - appearTime; }
    var despawnTime() { return beat; }

	var preprocess() {
		return {
	        IF (LevelOption.get(Options.Mirror)) {
	            EntityData.set(1, 13 - enLane)
	        } FI,
	        EntityInput.set(0, beat),
	        PlayScheduled(Clips.Perfect, beat, minSFXDistance)
	    };
	}

    var updateParallel() {
		return {
	        drawNormalNote(Sprites.NormalNote, lane, enLane, beat)
	    };
	}

	int updateSequentialOrder = 1;
	var updateSequential() {
		return {
			IF (times.now >= beat - 0.03) {
				currentJudge.set(Sprites.JudgeAuto),
				currentJudgeStartTime.set(Max(currentJudgeStartTime.get(), beat - 0.03)),
			} FI
		};
	}

	var terminate() {
		return {
			IF (times.skip) { Return(0) } FI,
			spawnEffect(Effects.NormalLinear, Effects.NormalCircular, lane, enLane),
		};
	}
};
