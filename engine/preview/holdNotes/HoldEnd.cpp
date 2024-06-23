class SiriusHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Hold End";
	
	defineImports(beat);
	defineImports(stBeat);
	defineImports(lane);
	defineImports(laneLength);
	defineImports(nonTail);
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
		drawPreviewHoldEighth(Sprites.Hold, stBeat, beat, lane, enLane);
		IF (nonTail) Return(0); FI
   		drawPreviewNormalNote(Sprites.HoldNoteLeft, beat, lane, enLane);
   		return VOID;
   	}
};
