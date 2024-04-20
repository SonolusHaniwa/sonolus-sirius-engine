class FlickNote : public Archetype {
    public:

	static constexpr const char* name = "Sirius Flick Note";

	defineImports(beat);
	defineImports(lane);
	defineImports(laneLength);
	defineImports(scratchLength);
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
		drawPreviewNormalNote(Sprites.ScratchNoteLeft, beat, lane, enLane);
		IF (scratchLength == 0) drawPreviewArrow(beat, lane, enLane);
		ELSE {
			IF (scratchLength > 0) drawPreviewRightArrow(beat, lane, enLane);
			ELSE drawPreviewLeftArrow(beat, lane, enLane); FI
		} FI
		return VOID;
	}
};
