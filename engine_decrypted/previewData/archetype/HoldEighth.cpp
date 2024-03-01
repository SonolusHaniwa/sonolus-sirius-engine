class SiriusHoldEighth: public Archetype {
    public:

    string name = "Sirius Hold Eighth";
	vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}, {"holdType", 4}};
	var maxTime = 0;
	var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
	var lane = EntityData.get(2);
	var laneLength = EntityData.get(3);
	var holdType = EntityData.get(4);
	var enLane = lane + laneLength - 1;

    var preprocess() {
		return {
			duration.set(Max(duration.get(), beat)),
			noteCount.add(1),
			noteId.set(noteCount.get())
	    };
	}

	var render() {
		return {
			IF (noteId.get() % noteCountDistance == 0) {
				drawNoteCount(beat, noteId.get())
			} FI,
			drawHold(SwitchWithDefault(holdType, {{100, Sprites.Hold}, {101, Sprites.Hold}, {110, Sprites.Scratch}, {111, Sprites.Scratch}}, Sprites.Hold), lastBeat, beat, lane, enLane)
		};	
	}
};
