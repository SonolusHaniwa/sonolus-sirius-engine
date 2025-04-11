class FlatNote: public Archetype {
    public:

    bool hasInput = true;

	defineImport(beat);
	defineImport(lane);
	defineImport(laneLength);
	defineExport(judgeResult);
    var enLane;
    var inputTimeMin;
    var inputTimeMax;
    var touchTime;
    var played;
#define DISABLE_INTERPRETER
    virtual var getSprite() = 0;
    virtual var getBucket() = 0;
	virtual ClipsArray getClips() = 0;
	virtual EffectsArray getEffects() = 0;
#undef DISABLE_INTERPRETER

    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

	SonolusApi preprocess() {
		beat = beat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + offsets.input;
		inputTimeMax = beat + judgment.bad + offsets.input;
		touchTime = -1;
		played = false;
		totalAccuracy += 1.01;
		currentAccuracy += 1.01;
        input.accuracy = judgment.bad;
		if (autoSFX) PlayScheduled(getClips().perfect, beat, minSFXDistance);
		life.miss_increment = -80;
		setBucket(
			getBucket(), 
			-1 * judgment.perfect * 1000, judgment.perfect * 1000, 
			-1 * judgment.great * 1000, judgment.great * 1000, 
			-1 * judgment.good * 1000, judgment.good * 1000
		);
		// beat.set(Buckets.NormalNote)
	}

	SonolusApi complete(var t = times.now) {
		var res = 0, res2 = 0;
		if (Abs(t - beat) <= judgment.bad) res = 5, res2 = 3;
		if (Abs(t - beat) <= judgment.good) res = 4, res2 = 3;
		if (Abs(t - beat) <= judgment.great) res = 3, res2 = 2;
		if (Abs(t - beat) <= judgment.perfect) res = 2, res2 = 1;
		if (Abs(t - beat) <= judgment.perfectPlus) res = 1, res2 = 1;
        input.judgment = res2;
		if (res2 != 0) {
            input.accuracy = t - beat;
            input.bucketIndex = getBucket();
            input.bucketValue = (t - beat) * 1000;
			ExportValue(judgeResult, res);
		}

		// if (res2 == 0) DebugPause();
		if (!autoSFX) {
			if (res == 1 || res == 2) Play(getClips().perfect, minSFXDistance);
			if (res == 3) Play(getClips().great, minSFXDistance);
			if (res == 4) Play(getClips().good, minSFXDistance);
			if (res == 5) Play(getClips().bad, minSFXDistance);	
		}
		if (res2 != 0) spawnEffect(getEffects().linear, getEffects().circular, lane, enLane);
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
			// PlayScheduled(getClips().perfect, beat, minSFXDistance);
			played = true;
		}
		if (times.now < inputTimeMin) return;
		if (times.now > inputTimeMax) {
			Rect hitbox = getFullHitbox(lane, enLane);
			// DebugLog(lane); DebugLog(enLane);
			// DebugLog(hitbox.l); DebugLog(hitbox.r);
			// DebugLog(hitbox.t); DebugLog(hitbox.b);
			// DebugPause();
			complete(-1);
		}
		claimStart(info.index);
		// if (mapId != -1 && inputList_old.getValById(mapId) != -1) complete();
		// mapId = inputList.size;
		// inputList.add(EntityInfo.get(0), -1);
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
		// Debuglog(index);
		// Debuglog(getHitbox(lane, enLane).l);
		// Debuglog(getHitbox(lane, enLane).r);
		// for (var i = 0; i < touchCount; i++) {
		// 	if (touches[i].id != index) continue;
		// 	DebugLog(touches[i].x);
		// 	DebugLog(touches[i].y);
		// }
		complete(times.now);
	}

	SonolusApi updateParallel() {
		drawNormalNote(getSprite(), lane, enLane, TimeToScaledTime(beat));
		// Rect hitbox = getFullHitbox(lane, enLane);
		// hitbox.b = -0.2, hitbox.t = 0.2;
		// Draw(Sprites.SyncLine, hitbox.lb(), hitbox.lt(), hitbox.rt(), hitbox.rb(), 100000, 1);
		// let index = getTouch(lane, enLane);
		// touchIndex = index;
	}	
};
