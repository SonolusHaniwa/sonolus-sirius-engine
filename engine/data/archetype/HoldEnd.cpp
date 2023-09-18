class SiriusHoldEnd : public Archetype {
    public:

    string name = "Sirius Hold End";
    vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}};
    bool hasInput = true;

    var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
    var lane = EntityData.get(2);
    var laneLength = EntityData.get(3);
    var enLane = lane + laneLength - 1;

    var spawnOrder = 1000 + lastBeat;
    var shouldSpawn = times.now > lastBeat - appearTime;

	Variable<EntityMemoryId> hasHold;

	var preprocess = {
		playLoopedId.set(0),
		trackTouchId.set(0),
		isHighlighted.set(0),
		hasHold.set(0),
        IF (LevelOption.get(Options.Mirror)) {
            EntityData.set(2, 13 - enLane)
        } FI,
		EntityInput.set(2, Buckets.HoldEnd)
	};

    var updateSequential = {
		drawHoldEighth(Sprites.Hold, lane, enLane, lastBeat, beat),
		drawNormalNote(Sprites.HoldNote, lane, enLane, beat),
        IF (times.now > lastBeat) { drawNormalNote(Sprites.HoldNote, lane, enLane, times.now) } FI,
        IF (LevelOption.get(Options.Autoplay)) {
            trackTouchId.set(beat)
        } FI
    };

    var touch = {
        IF (LevelOption.get(Options.Autoplay) || times.now < lastBeat) { Return(0) } FI,
		hasHold.set(0),
        FOR (i, 0, touches.size, 1) {
            IF (!lines.inClickBox(touches[i], lane, enLane)) { CONTINUE } FI,
            trackTouchId.set(Max(trackTouchId.get(), times.now)),
			hasHold.set(1)
        } DONE,
		IF (hasHold.get() == 1 && playLoopedId.get() == 0) {
			playLoopedId.set(PlayLooped(Clips.Hold)),
			isHighlighted.set(spawnHoldEffect(Effects.Hold, lane, enLane))
		} FI, IF (hasHold.get() == 0 && playLoopedId.get() != 0) {
				StopLooped(playLoopedId.get()),
				playLoopedId.set(0),
				DestroyParticleEffect(isHighlighted.get()),
				isHighlighted.set(0)
		} FI
    };

    var updateParallel ={
        IF (times.now > beat) {
            JudgeNote(trackTouchId.get(), beat),
			StopLooped(playLoopedId.get()),
			DestroyParticleEffect(isHighlighted.get()),
			IF (EntityInput.get(0) != 0) {
				spawnEffect(Effects.HoldLinear, Effects.HoldCircular, lane, enLane)
			} FI,
            EntityDespawn.set(0, 1)
        } FI
    };
};
