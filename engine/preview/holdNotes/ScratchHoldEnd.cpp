class SiriusScratchHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Scratch Hold End";
	
	defineEntityData(beat);
	defineEntityData(stBeat);
	defineEntityData(lane);
	defineEntityData(laneLength);
	defineEntityData(scratchLength)
    Variable<EntitySharedMemoryId> enLane;
    Variable<EntitySharedMemoryId> scratchLane;
    Variable<EntitySharedMemoryId> scratchEnLane;

    SonolusApi preprocess() {
   		FUNCBEGIN
		duration = Max(duration.get(), beat);
		noteCount = noteCount + 1;
		noteId = noteCount.get();
		enLane = lane + laneLength - 1;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
        return VOID;
    }

    SonolusApi render() {
   		FUNCBEGIN
   		IF (noteId % noteCountDistance == 0) { drawNoteCount(beat, noteId); } FI;
   		drawPreviewNormalNote(Sprites.ScratchNote, beat, lane, enLane);
		drawPreviewHoldEighth(Sprites.Scratch, stBeat, beat, lane, enLane);
		IF (scratchLength > 0) { drawPreviewRightArrow(beat, scratchLane, scratchEnLane); }
		ELSE {
			IF (scratchLength < 0) { drawPreviewLeftArrow(beat, scratchLane, scratchEnLane); }
			ELSE { drawPreviewArrow(beat, scratchLane, scratchEnLane); } FI
		} FI
   		return VOID;
   	}
};
