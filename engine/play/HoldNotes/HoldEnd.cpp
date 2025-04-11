Bucket HoldEndBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Hold, 0, -0.25, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.HoldNote, 0, 2.75, 0.0, 2.0, 1.0, 270)
}, Text.MillisecondUnit);

class HoldEnd: public Archetype {
	public:

	string name = "Sirius Hold End";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(stBeat);
	defineImport(lane);
	defineImport(laneLength);
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
	defineExport(time26);
    var enLane;
    var inputTimeMin;
    var inputTimeMax;
	var isHolding;
	var lastHoldTime;
	var playId;
	var effectId;
	var exportId;
	var played;

    SonolusApi preprocess() {
   		beat = beat / levelSpeed;
   		stBeat = stBeat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + offsets.input;
		inputTimeMax = beat + judgment.bad + offsets.input;
		isHolding = false;
		lastHoldTime = -1;
		playId = 0;
		exportId = time1;
		played = false;
		totalAccuracy = totalAccuracy + 1.01;
		currentAccuracy = currentAccuracy + 1.01;
		input.accuracy = judgment.bad;
		if (autoSFX) PlayScheduled(Clips.Perfect, beat, minSFXDistance);
		life.miss_increment = -80;
		setBucket(
			HoldEndBucket, 
			-1 * judgment.perfect * 1000, judgment.perfect * 1000, 
			-1 * judgment.great * 1000, judgment.great * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000
		);
    }
    
    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(stBeat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(stBeat) - appearTime; }

	SonolusApi complete(var t = times.now) {
		if (playId != 0) {
			StopLooped(playId); playId = 0;
			
			DestroyParticleEffect(effectId); effectId = 0;
		}
		var res = 0, res2 = 0;
		if (Abs(t - beat) <= judgment.bad) res = 5, res2 = 3;
		if (Abs(t - beat) <= judgment.good) res = 4, res2 = 3;
		if (Abs(t - beat) <= judgment.great) res = 3, res2 = 2;
		if (Abs(t - beat) <= judgment.perfect) res = 2, res2 = 1;
		if (Abs(t - beat) <= judgment.perfectPlus) res = 1, res2 = 1;
		input.judgment = res2;
		if (res2 != 0) {
			input.accuracy = t - beat;
			input.bucketIndex = FuncNode(HoldEndBucket);
			input.bucketValue = (t - beat) * 1000;
			ExportValue(judgeResult, res);
		}

		if (!autoSFX) {
			if (res == 1 || res == 2) Play(Clips.Perfect, minSFXDistance);
			if (res == 3) Play(Clips.Great, minSFXDistance);
			if (res == 4) Play(Clips.Good, minSFXDistance);
			if (res == 5) Play(Clips.Bad, minSFXDistance);
		}
		if (res2 != 0) spawnEffect(Effects.HoldLinear, Effects.HoldCircular, lane, enLane);
		if (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss, t - beat);
		if (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus, t - beat);
		if (res == 2) SpawnSubJudgeText(Sprites.JudgePerfect, t - beat);
		if (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat, t - beat);
		if (res == 4) SpawnSubJudgeText(Sprites.JudgeGood, t - beat);
		if (res == 5) SpawnSubJudgeText(Sprites.JudgeBad, t - beat);
		despawn.despawn = true;
	}
	SonolusApi updateSequential() {
		if (!played && autoSFX) {
			played = true;
			// PlayScheduled(Clips.Perfect, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
		}
		if (times.now < stBeat) return;
		isHolding = findHoldTouch(lane, enLane) != -1;
		if (isHolding && playId == 0) {
			if (HasEffectClip(Clips.Hold) && !autoSFX) playId = PlayLooped(Clips.Hold);
			else playId = 1;
			effectId = spawnHoldEffect(Effects.Hold, lane, enLane);
			if (exportId <= time26) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			}
		}
		if (!isHolding && playId != 0) {
			StopLooped(playId); playId = 0;
			DestroyParticleEffect(effectId); effectId = 0;
			if (exportId <= time26) {
				ExportValue(exportId, times.now - stBeat);
				exportId = exportId + 1;
			}
		}

		// 判定主代码
		if (times.now < inputTimeMin) return;
		if (times.now > inputTimeMax) complete(-1);
		if (isHolding == 1) lastHoldTime = Max(lastHoldTime, times.now);
		if (times.now >= beat && lastHoldTime != -1) complete(lastHoldTime);
	}

    SonolusApi updateParallel() {
		drawHoldEighth(Sprites.Hold, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), isHolding);
		if (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.HoldNoteLeft, lane, enLane, times.scaled);
		if (times.scaled > TimeToScaledTime(beat) - appearTime) 
			drawNormalNote(Sprites.HoldNoteLeft, lane, enLane, TimeToScaledTime(beat));
	}
};