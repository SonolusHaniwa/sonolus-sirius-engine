class Sound: public Archetype {
	public:

	string name = "Sirius Sound";
	
	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(holdType);
    var enLane;
	var noteId;

    SonolusApi preprocess() {
		duration = Max(duration, beat);
		noteCount = noteCount + 1;
		noteId = noteCount;
		enLane = lane + laneLength - 1;
    }

	SonolusApi render() {
		if (noteId % noteCountDistance == 0) drawNoteCount(beat, noteId);
		drawTick(SwitchWithDefault(holdType, {
			{100, Sprites.TouchTick}, 
			{101, Sprites.TouchTick}, 
			{1100, Sprites.TouchTick}, 
			{1101, Sprites.TouchTick}, 
			{110, Sprites.TouchScratchTick}, 
			{111, Sprites.TouchScratchTick},
			{1110, Sprites.TouchScratchTick}, 
			{1111, Sprites.TouchScratchTick}
		}, Sprites.TouchTick), beat, lane, enLane);
	}
};
