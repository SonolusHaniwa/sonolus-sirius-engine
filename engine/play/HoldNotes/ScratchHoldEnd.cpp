Bucket ScratchHoldEndBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Scratch, 0, -0.6, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.ScratchNote, 0, 2.4, 0.0, 2.0, 1.0, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.8, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.6, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.4, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, 0.2, 0.4, 1.2, 270),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.8, 0.4, 1.2, 90),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.6, 0.4, 1.2, 90),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.4, 0.4, 1.2, 90),
	EngineDataBucketSprite(Sprites.ScratchArrow, 0, 3.0, -0.2, 0.4, 1.2, 90)
}, Text.MillisecondUnit);

class ScratchHoldEnd: public Archetype {
	public:

	string name = "Sirius Scratch Hold End";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(stBeat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(scratchLength);
	defineExport(judgeResult);
	defineExport(time1);
	defineExport(time2);
	defineExport(time3);
	defineExport(time4);
	defineExport(time5);
	defineExport(time6);
	defineExport(time7);
	defineExport(time8);
	defineExport(time9);
	defineExport(time10);
	defineExport(time11);
	defineExport(time12);
	defineExport(time13);
	defineExport(time14);
	defineExport(time15);
	defineExport(time16);
	defineExport(time17);
	defineExport(time18);
	defineExport(time19);
	defineExport(time20);
	defineExport(time21);
	defineExport(time22);
	defineExport(time23);
	defineExport(time24);
	defineExport(time25);
    var enLane;
    var inputTimeMin;
    var inputTimeMax;
	var isHolding;
	var lastHoldTime;
	var playId;
	var effectId;
	var scratchLane;
	var scratchEnLane;
	var exportId;
	var played;

    SonolusApi preprocess() {
   		beat = beat / levelSpeed;
   		stBeat = stBeat / levelSpeed;
        if (mirror) { lane = 14 - lane - laneLength; scratchLength = -1 * scratchLength; }
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + offsets.input;
		inputTimeMax = beat + judgment.bad + offsets.input;
		isHolding = false;
		lastHoldTime = -1;
		playId = 0;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
		exportId = time1;
		played = false;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		input.accuracy = judgment.bad;
		if (autoSFX) PlayScheduled(Clips.Scratch, beat, minSFXDistance);
		life.miss_increment = -80;
		setBucket(
			ScratchHoldEndBucket, 
			-1 * judgment.perfect * 1000, judgment.perfect * 1000, 
			-1 * judgment.great * 1000, judgment.great * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000
		);
    }
    
    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(stBeat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(stBeat) - appearTime; }

	SonolusApi complete(var t) {
		if (playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
		}
		var res = 0, res2 = 0;
		if (t == inputTimeMin) res = 3, res2 = 2;
		if (t > inputTimeMin) res = 1, res2 = 1;
		input.judgment = res2;
		if (res2 != 0) {
			input.accuracy = t - beat;
			input.bucketIndex = int(ScratchHoldEndBucket);
			input.bucketValue = (t - beat) * 1000;
			ExportValue(judgeResult, res);
		}

		if (!autoSFX) {
			if (res2 == 1) Play(Clips.Scratch, minSFXDistance);
			if (res2 == 2) Play(Clips.Great, minSFXDistance);
		}
		if (res2 != 0) spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane);
		if (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss, t - beat);
		if (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus, t - beat);
		if (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat, t - beat);
		despawn.despawn = true;
	}
	SonolusApi updateSequential() {
		if (!played && autoSFX) {
			played = true;
			// PlayScheduled(Clips.Scratch, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
		}
		if (times.now < stBeat) return;
		isHolding = findHoldTouch(lane, enLane) != -1;
		if (isHolding && playId == 0) {
			if (HasEffectClip(Clips.Hold) && !autoSFX) playId = PlayLooped(Clips.Hold);
			else playId = 1;
			effectId = spawnHoldEffect(Effects.Scratch, lane, enLane);
			if (exportId <= time25) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			}
		}
		if (!isHolding && playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
			if (exportId <= time25) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			}
		}

		// 判定主代码
		if (times.now < inputTimeMin) return;
		if (times.now > inputTimeMax) complete(lastHoldTime);
		if (isHolding == 1) lastHoldTime = Max(lastHoldTime, inputTimeMin);
		isHolding = findFlickTouch(scratchLane, scratchEnLane) != -1;
		if (isHolding == 1) lastHoldTime = Max(lastHoldTime, times.now);
		if (times.now >= beat && lastHoldTime > inputTimeMin) complete(lastHoldTime);
	}

    SonolusApi updateParallel() {
		drawHoldEighth(Sprites.Scratch, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), isHolding);
		if (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.ScratchNoteLeft, lane, enLane, times.scaled);
		if (times.scaled > TimeToScaledTime(beat) - appearTime) 
			drawNormalNote(Sprites.ScratchNoteLeft, scratchLane, scratchEnLane, TimeToScaledTime(beat));
		if (times.scaled > TimeToScaledTime(beat) - appearTime) {
			if (scratchLength > 0) drawRightArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat));
			if (scratchLength < 0) drawLeftArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat));
			if (scratchLength == 0) drawArrow(scratchLane, scratchEnLane, TimeToScaledTime(beat));
		}
	}
};