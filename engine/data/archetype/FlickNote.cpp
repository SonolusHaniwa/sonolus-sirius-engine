class FlickNote : public Archetype {
    public:

    string name = "Sirius Flick Note";
    vector<pair<string, int> > data = {{"beat", 0}, {"lane", 1}, {"laneLength", 2}};
    bool hasInput = true;

    var beat = EntityData.get(0);
    var lane = EntityData.get(1);
    var laneLength = EntityData.get(2);
    var enLane = lane + laneLength - 1;

    var spawnOrder() { return 1000 + beat; }
    var shouldSpawn() { return times.now > beat - appearTime; }

	var preprocess() {
		return {
			trackTouchId.set(0),
	        IF (LevelOption.get(Options.Mirror)) {
	            EntityData.set(1, 13 - enLane)
	        } FI,
			EntityInput.set(2, Buckets.FlickNote)
		};
	}

	var updateSequential() {
		return {
	        drawNormalNote(Sprites.ScratchNote, lane, enLane, beat),
		    drawArrow(lane, enLane, beat),
	        IF (times.now > beat + judgment.good) {
                SpawnSubJudgeText(Sprites.JudgeMiss)
	        } FI,
	        IF (times.now > beat + judgment.good) {
				IF (trackTouchId.get() != 0) {
	                SpawnJudgeText(judgeText.great, beat, true),
				} FI
			} FI
	    };
	}
	
	var touch() {
		return {
			IF (times.now < beat - judgment.good) { Return(0) } FI,
	        FOR (i, 0, touches.size, 1) {
	            IF (!lines.inClickBox(touches[i], lane, enLane)) { CONTINUE } FI,
		        IF (isUsed(touches[i])) { CONTINUE } FI,
				IF (trackTouchId.get() == 0 && touches[i].started == 1) {
		            markAsUsed(touches[i]),
					trackTouchId.set(touches[i].id),
				} ELSE {
					IF (trackTouchId.get() != touches[i].id) { CONTINUE } FI,
					IF (!movedLast(touches[i])) { CONTINUE } FI,
					markAsUsed(touches[i]),
					JudgeFlickNote(times.now, beat),
	                SpawnFlickJudgeText(times.now, beat), 
					spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane),
					EntityDespawn.set(0, 1),
				} FI
	        } DONE
	    };
	}

	var updateParallel() {
		return {
	        IF (times.now > beat + judgment.good) {
				IF (trackTouchId.get() != 0) {
					EntityInput.set(0, 2),
					EntityInput.set(1, 0),
					EntityInput.set(3, 0),
					Play(Clips.Scratch, minSFXDistance),
					spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane),
					EntityDespawn.set(0, 1),
				} ELSE {
					EntityInput.set(0, 0),
					EntityInput.set(1, 0),
					EntityDespawn.set(0, 1)		
				} FI
			} FI
		};
	}
};
