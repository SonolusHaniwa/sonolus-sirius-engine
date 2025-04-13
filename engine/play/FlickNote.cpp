Bucket FlickNoteBucket = defineBucket({
    EngineDataBucketSprite(Sprites.ScratchNote, 0, -0.35, 0.0, 2.0, 1.0, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.8, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.6, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.4, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, 0.2, 0.4, 1.2, 270),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.8, 0.4, 1.2, 90),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.6, 0.4, 1.2, 90),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.4, 0.4, 1.2, 90),
    EngineDataBucketSprite(Sprites.ScratchArrow, 0, 0.25, -0.2, 0.4, 1.2, 90),
}, Text.MillisecondUnit);

class FlickNote: public Archetype {
    public:

	string name = "Sirius Flick Note";
    bool hasInput = true;

	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(scratchLength);
	defineExport(judgeResult);
	defineExport(activation);
    var enLane;
    var inputTimeMin;
    var inputTimeMax;
    var activate;
    var played;

    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

	SonolusApi preprocess() {
		beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength; scratchLength = -1 * scratchLength;
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + offsets.input;
		inputTimeMax = beat + judgment.bad + offsets.input;
		activate = 0;
		played = false;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		input.accuracy = judgment.bad;
		if (autoSFX) PlayScheduled(Clips.Scratch, beat, minSFXDistance);
		life.miss_increment = -80;
		setBucket(
			FlickNoteBucket, 
			-1 * judgment.perfect * 1000, judgment.perfect * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000
		);
		// beat.set(Buckets.NormalNote),
	}

	SonolusApi complete(var t) {
		var res = 0, res2 = 0;
		if (t == inputTimeMax) res = 3, res2 = 2;
		if (t != -1 && t != inputTimeMax) res = 1, res2 = 1;
		input.judgment = res2;
		if (res2 != 0) {
            input.accuracy = t - beat;
            input.bucketIndex = int(FlickNoteBucket);
            input.bucketValue = (t - beat) * 1000;
			ExportValue(judgeResult, res);
		}

		if (!autoSFX) {
			if (res2 == 1) Play(Clips.Scratch, minSFXDistance);
			if (res2 == 2) Play(Clips.Great, minSFXDistance);
		}
		if (res2 != 0) spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane, enLane);
		if (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss);
		if (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus);
		if (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat);
        despawn.despawn = true;
	}
	SonolusApi updateSequential() {
		if (!played && autoSFX) {
			// PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			played = true;
		}
		if (times.now < inputTimeMin) return;
		if (times.now > inputTimeMax) {
			if (activate) complete(inputTimeMax);
			else complete(-1);
		}
		if (activate == 0) claimStart(info.index);
		if (activate) {
			if (findFlickTouch(lane, enLane) != -1) complete(activate);
		}
	}

 //    var updateSequential() {
	// 	return {
	//         drawNormalNote(Sprites.NormalNote, lane, enLane, beat),
	// 		if (times.now > beat + judgment.good) {
 //                SpawnSubJudgeText(Sprites.JudgeMiss)
	// 		}
	// 	};
	// }

	SonolusApi touch() {
		if (times.now < inputTimeMin) return;
		// if (touchTime != -1) Return(0);
		var index = getClaimedStart(info.index);
		if (index == -1) return;
		for (var i = 0; i < touchCount; i++) 
			if (touches[i].id == index) activate = touches[i].st;
		ExportValue(activation, times.now - beat);
	}

	SonolusApi updateParallel() {
		drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, TimeToScaledTime(beat));
		if (scratchLength == 0) drawArrow(lane, enLane, TimeToScaledTime(beat));
		else {
			if (scratchLength > 0) drawRightArrow(lane, enLane, TimeToScaledTime(beat));
			else drawLeftArrow(lane, enLane, TimeToScaledTime(beat));
		}
		// var index = getTouch(lane, enLane);
		// touchIndex = index;
	}

 //    var updateParallel() {
	// 	return {
	//         if (times.now > beat + judgment.good) {
	//             EntityInput.set(0, 0),
	//             EntityInput.set(1, 0),
	//             EntityDespawn.set(0, 1),
	//         }
	//     };	
	// }
};
