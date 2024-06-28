class SiriusNontailScratchHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Nontail Scratch Hold End";
	
	defineImports(beat);
	defineImports(stBeat);
	defineImports(lane);
	defineImports(laneLength);
	defineImports(scratchLength)
    Variable<EntitySharedMemoryId> enLane;
    Variable<EntitySharedMemoryId> scratchLane;
    Variable<EntitySharedMemoryId> scratchEnLane;

    SonolusApi preprocess() {
   		FUNCBEGIN
		duration = Max(duration.get(), beat);
		enLane = lane + laneLength - 1;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
        return VOID;
    }

    SonolusApi render() {
   		FUNCBEGIN
		drawPreviewHoldEighth(Sprites.Scratch, stBeat, beat, lane, enLane);
   		return VOID;
   	}
};
