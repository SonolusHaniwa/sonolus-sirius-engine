class SiriusScratchHoldEnd: public Archetype {
    public:

    string name = "Sirius Scratch Hold End";
	vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}, {"scratchLength", 4}};
	var maxTime = 0;
	var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
	var lane = EntityData.get(2);
	var laneLength = EntityData.get(3);
	var scratchLength = EntityData.get(4);
	var enLane = lane + laneLength - 1;
	var scratchLane = IF (scratchLength >= 0) { lane } ELSE { enLane + scratchLength + 1 } FI;
	var scratchEnLane = IF (scratchLength <= 0) { enLane } ELSE { lane + scratchLength - 1 } FI;

    var preprocess() {
		return {
			duration.set(Max(duration.get(), beat)),
			noteCount.add(1),
			noteId.set(noteCount.get())
	    };
	}

	var render() {
		return {
			IF (noteId.get() % noteCountDistance == 0) {
				drawNoteCount(beat, noteId.get())
			} FI,
			drawNote(Sprites.ScratchNote, beat, scratchLane, scratchEnLane),
			drawHold(Sprites.Scratch, lastBeat, beat, lane, enLane),
			IF (scratchLength > 0) { drawRightArrow(beat, scratchLane, scratchEnLane) }
			ELSE {
				IF (scratchLength < 0) { drawLeftArrow(beat, scratchLane, scratchEnLane) }
				ELSE { drawArrow(beat, scratchLane, scratchEnLane) } FI
			} FI
		};
	}
};
