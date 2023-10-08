class SiriusSound : public Archetype {
    public:

    string name = "Sirius Sound";
    vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}, {"holdType", 4}};
    bool hasInput = true;

    var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
    var lane = EntityData.get(2);
    var laneLength = EntityData.get(3);
	var holdType = EntityData.get(4);
    var enLane = lane + laneLength - 1;

    var spawnOrder = 1000 + lastBeat;
    var shouldSpawn = times.now > lastBeat - appearTime;

	var preprocess = {
		playLoopedId.set(0),
		trackTouchId.set(0),
        IF (LevelOption.get(Options.Mirror)) {
            EntityData.set(2, 13 - enLane)
        } FI,
		IF (holdType == 110) { EntityInput.set(2, Buckets.ScratchSound) }
		ELSE { EntityInput.set(2, Buckets.Sound) } FI
	};

    var updateSequential = {
		drawHoldEighth(SwitchWithDefault(holdType, {
			{100, Sprites.Hold},
			{101, Sprites.Hold},
			{110, Sprites.Scratch},
            {111, Sprites.Scratch}
		}, Sprites.Hold), lane, enLane, lastBeat, beat),
        drawTick(SwitchWithDefault(holdType, {
			{100, Sprites.TouchTick},
			{101, Sprites.TouchTick},
			{110, Sprites.TouchScratchTick},
            {111, Sprites.TouchScratchTick}
		}, Sprites.TouchTick), beat, lane, enLane),
        IF (times.now > lastBeat) { drawNormalNote(SwitchWithDefault(holdType, {
			{100, Sprites.HoldNote},
			{101, Sprites.HoldNote},
			{110, Sprites.ScratchNote},
            {111, Sprites.ScratchNote}
		}, Sprites.HoldNote), lane, enLane, times.now) } FI,
		IF (times.now > lastBeat && playLoopedId.get() == 0) {
			playLoopedId.set(PlayLooped(Clips.Hold)),
		} FI,
        IF (LevelOption.get(Options.Autoplay)) {
			trackTouchId.set(beat)
        } FI
    };

    var touch = {
        IF (LevelOption.get(Options.Autoplay) || times.now < beat - judgment.good) { Return(0) } FI,
        FOR (i, 0, touches.size, 1) {
            IF (!lines.inClickBox(touches[i], lane, enLane)) { CONTINUE } FI,
            trackTouchId.set(Max(trackTouchId.get(), times.now))
        } DONE
    };

    var updateParallel ={
        IF (times.now > beat) {
            JudgeNoteMuted(trackTouchId.get(), beat),
			StopLooped(playLoopedId.get()),
            EntityDespawn.set(0, 1)
        } FI
    };
};
