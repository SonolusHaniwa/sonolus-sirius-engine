class FlatNote: public Archetype {
	public:

	defineEntityData(beat);
	defineEntityData(lane);
	defineEntityData(laneLength);
	Variable<EntitySharedMemoryId> enLane;
	virtual let getSprite() { return -1; }

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
		drawPreviewNormalNote(getSprite(), beat, lane, enLane);
		return VOID;
	}
};
