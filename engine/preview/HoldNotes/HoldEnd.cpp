class HoldEnd: public Archetype {
	public:

	string name = "Sirius Hold End";
	
	defineImport(beat);
	defineImport(stBeat);
	defineImport(lane);
	defineImport(laneLength);
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
		drawHoldEighth(Sprites.Hold, stBeat, beat, lane, enLane);
   		drawNormalNote(Sprites.HoldNoteLeft, beat, lane, enLane);
   	}
};
