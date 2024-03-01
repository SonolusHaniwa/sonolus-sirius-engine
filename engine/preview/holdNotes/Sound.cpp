class SiriusSound: public Archetype {
	public:

	static constexpr const char* name = "Sirius Sound";
	
	defineEntityData(beat);
	defineEntityData(lane);
	defineEntityData(laneLength);
	defineEntityData(holdType);
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
		IF (noteId.get() % noteCountDistance == 0) { drawNoteCount(beat, noteId.get()); } FI
		drawPreviewTick(SwitchWithDefault(holdType, {{100, Sprites.TouchTick}, {101, Sprites.TouchTick}, {110, Sprites.TouchScratchTick}, {111, Sprites.TouchScratchTick}}, Sprites.TouchTick), beat, lane, enLane);
		return VOID;
	}
};
