class SiriusScratchHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Scratch Hold End";
	
	defineImports(beat);
	defineImports(stBeat);
	defineImports(lane);
	defineImports(laneLength);
	defineImports(scratchLength)
	defineImports(nonTail)
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
		drawPreviewHoldEighth(Sprites.Scratch, stBeat, beat, lane, enLane);
		IF (nonTail) Return(0); FI
   		drawPreviewNormalNote(Sprites.ScratchNoteLeft, beat, scratchLane, scratchEnLane);
		IF (scratchLength > 0) { drawPreviewRightArrow(beat, scratchLane, scratchEnLane); }
		ELSE {
			IF (scratchLength < 0) { drawPreviewLeftArrow(beat, scratchLane, scratchEnLane); }
			ELSE { drawPreviewArrow(beat, scratchLane, scratchEnLane); } FI
		} FI
   		return VOID;
   	}
};
