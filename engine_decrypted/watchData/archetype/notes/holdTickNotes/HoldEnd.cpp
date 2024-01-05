class SiriusHoldEnd: public SiriusHoldTickNote {
	public:

	string name = "Sirius Hold End";
    vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}};

	var getEffect() { return Effects.Hold; }

	var preprocess() {
		return {
			SiriusHoldTickNote::preprocess(),
			PlayScheduled(Clips.Perfect, beat, minSFXDistance)
		};
	}

	var updateParallel() {
		return {
            drawHoldEighth(Sprites.Hold, lane, enLane, lastBeat, beat),
            IF (times.now <= beat) {
                drawNormalNote(Sprites.HoldNote, lane, enLane, beat),
                IF (times.now > lastBeat) { drawNormalNote(Sprites.HoldNote, lane, enLane, times.now) } FI,
            } FI,
		};
	}

	var terminate() {
		return {
			SiriusHoldTickNote::terminate(),
			IF (times.skip) { Return(0) } FI,
			spawnEffect(Effects.HoldLinear, Effects.HoldCircular, lane, enLane),
		};
	}
};
