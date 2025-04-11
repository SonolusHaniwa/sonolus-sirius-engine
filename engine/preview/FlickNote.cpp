class FlickNote : public Archetype {
    public:

	string name = "Sirius Flick Note";

	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(scratchLength);
	var enLane;
	var noteId;

	SonolusApi preprocess() {
		duration = Max(duration, beat);
		noteCount = noteCount + 1;
		noteId = noteCount;
		enLane = lane + laneLength - 1;
	}

	SonolusApi render() {
		if (noteId % noteCountDistance == 0) drawNoteCount(beat, noteId);
		drawNormalNote(Sprites.ScratchNoteLeft, beat, lane, enLane);
		if (scratchLength == 0) drawArrow(beat, lane, enLane);
		else {
			if (scratchLength > 0) drawRightArrow(beat, lane, enLane);
			else drawLeftArrow(beat, lane, enLane);
		}
	}
};
