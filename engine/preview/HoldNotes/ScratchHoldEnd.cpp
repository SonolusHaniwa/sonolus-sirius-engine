class ScratchHoldEnd: public Archetype {
	public:

	string name = "Sirius Scratch Hold End";
	
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
		noteCount = noteCount + 1;
		noteId = noteCount;
		enLane = lane + laneLength - 1;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
    }

    SonolusApi render() {
   		if (noteId % noteCountDistance == 0) drawNoteCount(beat, noteId);
		drawHoldEighth(Sprites.Scratch, stBeat, beat, lane, enLane);
   		drawNormalNote(Sprites.ScratchNoteLeft, beat, scratchLane, scratchEnLane);
		if (scratchLength > 0) { drawRightArrow(beat, scratchLane, scratchEnLane); }
		else {
			if (scratchLength < 0) { drawLeftArrow(beat, scratchLane, scratchEnLane); }
			else { drawArrow(beat, scratchLane, scratchEnLane); }
		}
   	}
};
