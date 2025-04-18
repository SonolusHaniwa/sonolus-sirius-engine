Bucket SoundBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Hold, 0, 0.0, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.TouchTick, 0, 0.0, 0.0, 1.0, 1.0, 270)
}, Text.MillisecondUnit);
Bucket ScratchSoundBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Scratch, 0, 0.0, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.TouchScratchTick, 0, 0.0, 0.0, 1.0, 1.0, 270)
}, Text.MillisecondUnit);

class Sound: public Archetype {
	public:

	string name = "Sirius Sound";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(holdType);
	defineExport(judgeResult);
    var enLane;
    var inputTimeMin;
    var inputTimeMax;
	var isHolding;
	var lastHoldTime;
	var played;

    SonolusApi preprocess() {
   		beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + offsets.input;
		inputTimeMax = beat + judgment.bad + offsets.input;
		isHolding = false;
		lastHoldTime = -1;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		input.accuracy = judgment.bad;
		if (autoSFX) PlayScheduled(Clips.Sound, beat, minSFXDistance);
		life.miss_increment = -40;
		setBucket(
			If(holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101, SoundBucket, ScratchSoundBucket), 
			-1 * judgment.perfect * 1000, judgment.perfect * 1000, 
			-1 * judgment.great * 1000, judgment.great * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000
		);
    }
    
    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

	SonolusApi complete(var t) {
		var res = 0, res2 = 0;
		if (Abs(t - beat) <= judgment.bad) res = 5, res2 = 3;
		if (Abs(t - beat) <= judgment.good) res = 4, res2 = 3;
		if (Abs(t - beat) <= judgment.great) res = 3, res2 = 2;
		if (Abs(t - beat) <= judgment.perfect) res = 2, res2 = 1;
		if (Abs(t - beat) <= judgment.perfectPlus) res = 1, res2 = 1;
		input.judgment = res2;
		if (res2 != 0) {
			input.accuracy = t - beat;
			input.bucketIndex = If(holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101, SoundBucket, ScratchSoundBucket);
			input.bucketValue = (t - beat) * 1000;
			ExportValue(judgeResult, res);
		}

		if (res != 0 && !autoSFX) Play(Clips.Sound, minSFXDistance);
		if (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss);
		if (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus);
		if (res == 2) SpawnSubJudgeText(Sprites.JudgePerfect);
		if (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat);
		if (res == 4) SpawnSubJudgeText(Sprites.JudgeGood);
		if (res == 5) SpawnSubJudgeText(Sprites.JudgeBad);
		despawn.despawn = true;
	}
	SonolusApi updateSequential() {
		if (!played && autoSFX) {
			played = true;
			// PlayScheduled(Clips.Sound, beat, minSFXDistance);
		}
		if (times.now < beat) return;
		isHolding = findHoldTouch(lane, enLane);

		// 判定主代码
		if (times.now < inputTimeMin) return;
		if (times.now > inputTimeMax) complete(-1);
		if (isHolding != -1) {
			for (var i = 0; i < touchCount; i++) if (touches[i].id == isHolding)
				if (touches[i].ended) lastHoldTime = touches[i].t;
				else lastHoldTime = Max(touches[i].t, beat);
		}
		if (times.now >= beat && lastHoldTime != -1) complete(lastHoldTime);
	}

	SonolusApi updateParallel() {
		if (holdType == 100 || holdType == 101 || holdType == 1100 || holdType == 1101) drawTick(Sprites.TouchTick, TimeToScaledTime(beat), lane, enLane);
		if (holdType == 110 || holdType == 111 || holdType == 1110 || holdType == 1111) drawTick(Sprites.TouchScratchTick, TimeToScaledTime(beat), lane, enLane);
	}
};
