class NontailHoldEnd: public Archetype {
	public:

	string name = "Sirius Nontail Hold End";
	
	defineImport(beat);
	defineImport(stBeat);
	defineImport(lane);
	defineImport(laneLength);
    var enLane;
	var noteId;

    SonolusApi preprocess() {
		duration = Max(duration, beat);
		enLane = lane + laneLength - 1;
    }

    SonolusApi render() {
		drawHoldEighth(Sprites.Hold, stBeat, beat, lane, enLane);
   	}
};
