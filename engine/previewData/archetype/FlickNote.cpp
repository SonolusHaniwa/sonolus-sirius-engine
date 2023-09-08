class SiriusFlickNote: public Archetype {
    public:

    string name = "Sirius Flick Note";
	vector<pair<string, int> > data = {{"beat", 0}, {"lane", 1}, {"laneLength", 2}};
	var maxTime = 0;
	var beat = EntityData.get(0);
	var lane = EntityData.get(1);
	var laneLength = EntityData.get(2);
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
		drawNote(Sprites.ScratchNote, beat, lane, enLane),
		drawArrow(beat, lane, enLane)
	};
};
