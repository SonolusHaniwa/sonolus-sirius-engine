class FlickNote : public Archetype {
    public:

	static constexpr const char* name = "Sirius Flick Note";
    bool hasInput = true;

	defineImports(beat);
	defineImports(lane);
	defineImports(laneLength);
	defineImports(scratchLength);
	defineExports(judgeResult);
	defineExports(activation);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
    Variable<EntityMemoryId> activate;
    Variable<EntityMemoryId> played;

    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

	SonolusApi preprocess() {
		FUNCBEGIN
		beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; scratchLength = -1 * scratchLength; FI
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + RuntimeEnvironment.get(3);
		inputTimeMax = beat + judgment.bad + RuntimeEnvironment.get(3);
		activate = 0;
		played = false;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		EntityInput.set(1, judgment.bad);
		IF (autoSFX) PlayScheduled(Clips.Scratch, beat, minSFXDistance); FI
        return VOID;
		// beat.set(Buckets.NormalNote),
	}

	SonolusApi complete(let t = times.now) {
		FUNCBEGIN
		var res = 0, res2 = 0;
		IF (t == inputTimeMax) res = 3, res2 = 2; FI
		IF (t != -1 && t != inputTimeMax) res = 1, res2 = 1; FI
		EntityInput.set(0, res2);
		IF (res2 != 0) {
			EntityInput.set(1, t - beat);
			EntityInput.set(2, Buckets.FlickNote);
			EntityInput.set(3, (t - beat) * 1000);
			ExportValue(judgeResult, res);
		} FI

		IF (!autoSFX) {
			IF (res2 == 1) Play(Clips.Scratch, minSFXDistance); FI
			IF (res2 == 2) Play(Clips.Great, minSFXDistance); FI
		} FI
		IF (res2 != 0) spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane); FI
		IF (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss); FI
		IF (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus); FI
		IF (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat); FI
		EntityDespawn.set(0, 1);
		return VOID;
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (!played && autoSFX) {
			// PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			played = true;
		} FI
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) {
			IF (activate == 1) complete(inputTimeMax);
			ELSE complete(-1); FI
		} FI
		IF (activate == 0) claimStart(EntityInfo.get(0)); FI
		IF (activate == 1) {
			IF (findFlickTouch(lane, enLane) != -1) complete(); FI
		} FI
		return VOID;
	}

 //    var updateSequential() {
	// 	return {
	//         drawNormalNote(Sprites.NormalNote, lane, enLane, beat),
	// 		IF (times.now > beat + judgment.good) {
 //                SpawnSubJudgeText(Sprites.JudgeMiss)
	// 		} FI
	// 	};
	// }

	SonolusApi touch() {
		FUNCBEGIN
		IF (times.now < inputTimeMin) Return(0); FI
		// IF (touchTime != -1) Return(0); FI
		let index = getClaimedStart(EntityInfo.get(0));
		IF (index == -1) Return(0); FI
		activate = 1; ExportValue(activation, times.now - beat);
		return VOID;
	}

	SonolusApi updateParallel() {
		FUNCBEGIN
		drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, TimeToScaledTime(beat));
		IF (scratchLength == 0) drawArrow(lane, enLane, TimeToScaledTime(beat));
		ELSE {
			IF (scratchLength > 0) drawRightArrow(lane, enLane, TimeToScaledTime(beat));
			ELSE drawLeftArrow(lane, enLane, TimeToScaledTime(beat)); FI
		} FI
		// let index = getTouch(lane, enLane);
		// touchIndex = index;
		return VOID;
	}

 //    var updateParallel() {
	// 	return {
	//         IF (times.now > beat + judgment.good) {
	//             EntityInput.set(0, 0),
	//             EntityInput.set(1, 0),
	//             EntityDespawn.set(0, 1),
	//         } FI
	//     };	
	// }
};
