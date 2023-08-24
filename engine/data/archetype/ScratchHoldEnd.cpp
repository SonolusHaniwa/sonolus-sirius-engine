class SiriusScratchHoldEnd : public Archetype {
    public:

    string name = "Sirius Scratch Hold End";
    vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}, {"scratchLength", 4}};
    bool hasInput = true;

    var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
    var lane = EntityData.get(2);
    var laneLength = EntityData.get(3);
	var scratchLength = EntityData.get(4);
    var enLane = lane + laneLength - 1;
	var scratchLane = IF (scratchLength >= 0) { lane } ELSE { enLane + scratchLength + 1 } FI;
	var scratchEnLane = IF (scratchLength <= 0) { enLane } ELSE { lane + scratchLength - 1 } FI;

    var spawnOrder = 1000 + lastBeat;
    var shouldSpawn = times.now > lastBeat - appearTime;

	var preprocess = {
		playLoopedId.set(0),
		trackTouchId.set(0)
	};

    var updateSequential = {
		drawHoldEighth(Sprites.Scratch, lane, enLane, lastBeat, beat),
		drawNormalNote(Sprites.ScratchNote, scratchLane, scratchEnLane, beat),
		drawArrow(scratchLane, scratchEnLane, beat),
		IF (times.now > lastBeat && playLoopedId.get() == 0) {
			playLoopedId.set(PlayLooped(Clips.Hold)),
		} FI,
        IF (LevelOption.get(Options.Autoplay)) {
            trackTouchId.set(beat)
        } FI
    };

    var touch = {
        IF (LevelOption.get(Options.Autoplay) || times.now < lastBeat) { Return(0) } FI,
        FOR (i, 0, touches.size, 1) {
            IF (!lines.inClickBox(touches[i], scratchLane, scratchEnLane)) { CONTINUE } FI,
			IF (!movedLast(touches[i])) { CONTINUE } FI,
            trackTouchId.set(beat)
        } DONE
    };

    var updateParallel = {
        IF ((times.now > beat && trackTouchId.get() != 0) || times.now > beat + judgment.good) {
            JudgeFlickNote(trackTouchId.get(), beat),
			StopLooped(playLoopedId.get()),
            EntityDespawn.set(0, 1)
        } FI
    };
};
