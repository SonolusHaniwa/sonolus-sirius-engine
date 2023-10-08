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

	Variable<EntityMemoryId> hasHold;

	var preprocess = {
		playLoopedId.set(0),
		trackTouchId.set(0),
        IF (LevelOption.get(Options.Mirror)) {
            EntityData.set(2, 13 - enLane),
            EntityData.set(4, -1 * scratchLength)
        } FI,
		EntityInput.set(2, Buckets.ScratchHoldEnd)
	};

    var updateSequential = {
		drawHoldEighth(Sprites.Scratch, lane, enLane, lastBeat, beat),
		drawNormalNote(Sprites.ScratchNote, scratchLane, scratchEnLane, beat),
        IF (times.now > lastBeat) { drawNormalNote(Sprites.ScratchNote, lane, enLane, times.now) } FI,
        IF (scratchLength > 0) { drawRightArrow(scratchLane, scratchEnLane, beat) } ELSE {
            IF (scratchLength < 0) { drawLeftArrow(scratchLane, scratchEnLane, beat) } 
            ELSE { drawArrow(scratchLane, scratchEnLane, beat) } FI
        } FI,
        IF (LevelOption.get(Options.Autoplay)) {
            trackTouchId.set(beat)
        } FI
    };

    var touch = {
        IF (LevelOption.get(Options.Autoplay) || times.now < lastBeat) { Return(0) } FI,
		hasHold.set(0),
		FOR (i, 0, touches.size, 1) {
			IF (!lines.inClickBox(touches[i], lane, enLane)) { CONTINUE } FI,
			hasHold.set(1)
		} DONE, 
        FOR (i, 0, touches.size, 1) {
            IF (!lines.inClickBox(touches[i], scratchLane, scratchEnLane)) { CONTINUE } FI,
            trackTouchId.set(Max(trackTouchId.get(), beat - judgment.great)),
			IF (!movedLast(touches[i])) { CONTINUE } FI,
            trackTouchId.set(beat)
        } DONE,
		IF (hasHold.get() == 1 && playLoopedId.get() == 0) {
			playLoopedId.set(PlayLooped(Clips.Hold)),
			isHighlighted.set(spawnHoldEffect(Effects.Scratch, lane, enLane))
		} FI, IF (hasHold.get() == 0 && playLoopedId.get() != 0) {
			StopLooped(playLoopedId.get()),
			playLoopedId.set(0),
			DestroyParticleEffect(isHighlighted.get()),
			isHighlighted.set(0)
		} FI,
    };

    var updateParallel = {
        IF ((times.now > beat && trackTouchId.get() != 0) || times.now > beat + judgment.good) {
            JudgeFlickNote(trackTouchId.get(), beat),
			DestroyParticleEffect(isHighlighted.get()),
			IF (EntityInput.get(0) != 0) {
				spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane)
			} FI,
			StopLooped(playLoopedId.get()),
            EntityDespawn.set(0, 1)
        } FI
    };
};
