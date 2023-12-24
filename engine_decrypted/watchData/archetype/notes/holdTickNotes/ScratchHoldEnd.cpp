class SiriusScratchHoldEnd: public SiriusHoldTickNote {
	public:

	string name = "Sirius Scratch Hold End";
    vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}, {"scratchLength", 4}};

	var scratchLength = EntityData.get(4);
	var scratchLane = IF (scratchLength >= 0) { lane } ELSE { enLane + scratchLength + 1 } FI;
	var scratchEnLane = IF (scratchLength <= 0) { enLane } ELSE { lane + scratchLength - 1 } FI;

	var getEffect() { return Effects.Scratch; }

	var preprocess() {
		return {
			SiriusHoldTickNote::preprocess(),
			PlayScheduled(Clips.Scratch, beat, minSFXDistance)
		};
	}

	var updateParallel() {
		return {
            drawHoldEighth(Sprites.Scratch, lane, enLane, lastBeat, beat),
            IF (times.now <= beat) {
                drawNormalNote(Sprites.ScratchNote, scratchLane, scratchEnLane, beat),
                IF (scratchLength > 0) { drawRightArrow(scratchLane, scratchEnLane, beat) } ELSE {
                    IF (scratchLength < 0) { drawLeftArrow(scratchLane, scratchEnLane, beat) } 
                    ELSE { drawArrow(scratchLane, scratchEnLane, beat) } FI
                } FI,
                IF (times.now > lastBeat) { drawNormalNote(Sprites.ScratchNote, lane, enLane, times.now) } FI,
            } FI,
		};
	}

	var terminate() {
		return {
			SiriusHoldTickNote::terminate(),
			IF (times.skip) { Return(0) } FI,
			spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane),
		};
	}
};
