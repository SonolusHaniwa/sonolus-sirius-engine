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

    var spawnOrder() { return 1000 + lastBeat; }
    var shouldSpawn() { return times.now > lastBeat - appearTime; }
	Variable<EntityMemoryId> hasHold;

	var preprocess() {
		return {
			playLoopedId.set(0),
			trackTouchId.set(0),
			isHighlighted.set(0),
			hasHold.set(0),
			IF (LevelOption.get(Options.Mirror)) {
				EntityData.set(2, 13 - enLane)
			} FI,
			IF (holdType == 110 || holdType == 111) { EntityInput.set(2, Buckets.ScratchHoldEighth) } 
			ELSE { EntityInput.set(2, Buckets.NormalHoldEighth) } FI
		};
	}

    var updateSequential() {
		return {
			drawHoldEighth(SwitchWithDefault(holdType, {
				{100, Sprites.Hold},
				{101, Sprites.Hold},
				{110, Sprites.Scratch},
				{111, Sprites.Scratch}
			}, Sprites.Hold), lane, enLane, lastBeat, beat),
			IF (times.now > lastBeat) { drawNormalNote(SwitchWithDefault(holdType, {
				{100, Sprites.HoldNote},
				{101, Sprites.HoldNote},
				{110, Sprites.ScratchNote},
				{111, Sprites.ScratchNote}
			}, Sprites.HoldNote), lane, enLane, times.now) } FI,
			IF (hasHold.get() == 1 && playLoopedId.get() == 0) {
				playLoopedId.set(PlayLooped(Clips.Hold)),
				isHighlighted.set(spawnHoldEffect(SwitchWithDefault(holdType, {
					{100, Effects.Hold},
					{101, Effects.Hold},
					{110, Effects.Scratch},
					{111, Effects.Scratch}
				}, Effects.Hold), lane, enLane))
			} FI, 
			IF (hasHold.get() == 0 && playLoopedId.get() != 0) {
				StopLooped(playLoopedId.get()),
				playLoopedId.set(0),
				DestroyParticleEffect(isHighlighted.get()),
				isHighlighted.set(0)
			} FI,
			IF (LevelOption.get(Options.Autoplay)) {
				trackTouchId.set(beat)
			} FI,
			IF (times.now > beat + judgment.good) {
                SpawnSubJudgeText(Sprites.JudgeMiss)
			} FI,
			IF (times.now > beat) {
				IF (LevelOption.get(Options.Autoplay)) {
					currentJudge.set(Sprites.JudgeAuto),
					currentJudgeStartTime.set(times.now),
				} ELSE {
					SpawnJudgeText(trackTouchId.get(), beat)
				} FI,
			} FI
		};
	}

    var touch() {
		return {
			IF (LevelOption.get(Options.Autoplay) || times.now < lastBeat) { Return(0) } FI,
			hasHold.set(0),
			FOR (i, 0, touches.size, 1) {
				IF (!lines.inClickBox(touches[i], lane, enLane)) { CONTINUE } FI,
				trackTouchId.set(Max(trackTouchId.get(), times.now)),
				hasHold.set(1)
			} DONE
		};
	}

    var updateParallel() {
		return {
			IF (times.now > beat) {
				JudgeNoteMuted(trackTouchId.get(), beat),
				StopLooped(playLoopedId.get()),
				DestroyParticleEffect(isHighlighted.get()),
				EntityDespawn.set(0, 1)
			} FI
		};
	}
};
