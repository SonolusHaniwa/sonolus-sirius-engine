class FlatNote: public Archetype {
	public:

	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	var enLane;
	var noteId;
#define DISABLE_INTERPRETER
	virtual var getSprite() { return -1; }
#undef DISABLE_INTERPRETER

	SonolusApi preprocess() {
		duration = Max(duration, beat);
		noteCount = noteCount + 1;
		noteId = noteCount;
		enLane = lane + laneLength - 1;
	}

	SonolusApi render() {
		if (noteId % noteCountDistance == 0) drawNoteCount(beat, noteId);
		drawNormalNote(getSprite(), beat, lane, enLane);
	}
};
