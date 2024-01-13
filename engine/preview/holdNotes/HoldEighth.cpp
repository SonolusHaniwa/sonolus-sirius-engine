class SiriusHoldEighth: public Archetype {
	public:

	static constexpr const char* name = "Sirius Hold Eighth";
	
	defineEntityData(beat);
	defineEntityData(lane);
	defineEntityData(laneLength);

	SonolusApi preprocess() {
		FUNCBEGIN
		duration = Max(duration.get(), beat);
		noteCount = noteCount + 1;
		noteId = noteCount.get();
		return VOID;
	}

	SonolusApi render() {
		FUNCBEGIN
		IF (noteId % noteCountDistance == 0) { drawNoteCount(beat, noteId); } FI;
		return VOID;
	}
};
