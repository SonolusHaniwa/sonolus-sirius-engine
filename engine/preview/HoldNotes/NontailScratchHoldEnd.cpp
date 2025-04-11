class NontailScratchHoldEnd: public Archetype {
	public:

	string name = "Sirius Nontail Scratch Hold End";
	
	defineImport(beat);
	defineImport(stBeat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(scratchLength);
    var enLane;
    var scratchLane;
    var scratchEnLane;
	var noteId;

    SonolusApi preprocess() {
		duration = Max(duration, beat);
		enLane = lane + laneLength - 1;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
    }

    SonolusApi render() {
		drawHoldEighth(Sprites.Scratch, stBeat, beat, lane, enLane);
   	}
};
