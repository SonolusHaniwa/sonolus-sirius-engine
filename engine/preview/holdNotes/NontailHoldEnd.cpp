class SiriusNontailHoldEnd: public Archetype {
	public:

	static constexpr const char* name = "Sirius Nontail Hold End";
	
	defineImports(beat);
	defineImports(stBeat);
	defineImports(lane);
	defineImports(laneLength);
    Variable<EntitySharedMemoryId> enLane;

    SonolusApi preprocess() {
   		FUNCBEGIN
		duration = Max(duration.get(), beat);
		enLane = lane + laneLength - 1;
        return VOID;
    }

    SonolusApi render() {
   		FUNCBEGIN
		drawPreviewHoldEighth(Sprites.Hold, stBeat, beat, lane, enLane);
   		return VOID;
   	}
};
