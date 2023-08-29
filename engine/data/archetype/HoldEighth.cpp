class SiriusHoldEighth : public Archetype {
    public:

    string name = "Sirius Hold Eighth";
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
		isHighlighted.set(0),
        IF (LevelOption.get(Options.Mirror)) {
            EntityData.set(2, 13 - enLane)
        } FI
	};

    var updateSequential = {
		drawHoldEighth(SwitchWithDefault(holdType, {
			{100, Sprites.Hold},
			{101, Sprites.Hold},
			{110, Sprites.Scratch},
		}, Sprites.Hold), lane, enLane, lastBeat, beat),
		IF (times.now > lastBeat && playLoopedId.get() == 0) {
			playLoopedId.set(PlayLooped(Clips.Hold)),
			isHighlighted.set(spawnHoldEffect(SwitchWithDefault(holdType, {
				{100, Effects.Hold},
				{101, Effects.Hold},
				{110, Effects.Scratch}
			}, Effects.Hold), lane, enLane))
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
			DestroyParticleEffect(isHighlighted.get()),
            EntityDespawn.set(0, 1)
        } FI
    };
};
