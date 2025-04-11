class HoldEighth: public Archetype {
	public:

	string name = "Sirius Hold Eighth";
	
	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	var noteId;

	SonolusApi preprocess() {
		duration = Max(duration, beat);
		noteCount = noteCount + 1;
		noteId = noteCount;
	}

	SonolusApi render() {
		if (noteId % noteCountDistance == 0) drawNoteCount(beat, noteId);
	}
};
