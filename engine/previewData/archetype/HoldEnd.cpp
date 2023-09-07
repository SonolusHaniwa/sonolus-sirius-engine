class SiriusHoldEnd: public Archetype {
    public:

    string name = "Sirius Hold End";
	vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}};
	var maxTime = 0;
	var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
	var lane = EntityData.get(2);
	var laneLength = EntityData.get(3);
	var enLane = lane + laneLength - 1;

    var preprocess = {
		duration.set(Max(duration.get(), beat)),
		noteCount.add(1),
		noteId.set(noteCount.get())
    };

	var render = {
		IF (noteId.get() % noteCountDistance == 0) {
			drawNoteCount(beat, noteId.get())
		} FI,
		drawNote(Sprites.HoldNote, beat, lane, enLane),
		drawHold(Sprites.Hold, lastBeat, beat, lane, enLane)
	};
};
