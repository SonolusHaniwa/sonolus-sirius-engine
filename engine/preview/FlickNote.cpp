class FlickNote : public Archetype {
    public:

	static constexpr const char* name = "Sirius Flick Note";

	defineImports(beat);
	defineImports(lane);
	defineImports(laneLength);
	Variable<EntitySharedMemoryId> enLane;

	SonolusApi preprocess() {
		FUNCBEGIN
		duration = Max(duration.get(), beat);
		noteCount = noteCount + 1;
		noteId = noteCount.get();
		enLane = lane + laneLength - 1;
		return VOID;
	}

	SonolusApi render() {
		FUNCBEGIN
		IF (noteId % noteCountDistance == 0) { drawNoteCount(beat, noteId); } FI;
		drawPreviewNormalNote(Sprites.ScratchNote, beat, lane, enLane);
		drawPreviewArrow(beat, lane, enLane);
		return VOID;
	}
};
