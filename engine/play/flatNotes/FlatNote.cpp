class FlatNote : public Archetype {
    public:

    bool hasInput = true;

	defineImports(beat);
	defineImports(lane);
	defineImports(laneLength);
	defineExports(judgeResult);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
    Variable<EntityMemoryId> touchTime;
    Variable<EntityMemoryId> played;
    virtual let getSprite() { return -1; }
    virtual let getBucket() { return -1; }
    virtual ClipsArray getClips() { return {}; }
    virtual EffectsArray getEffects() { return {}; }

    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

	SonolusApi preprocess() {
		FUNCBEGIN
		beat = beat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + RuntimeEnvironment.get(3);
		inputTimeMax = beat + judgment.bad + RuntimeEnvironment.get(3);
		touchTime = -1;
		played = false;
		EntityInput.set(1, judgment.bad);
        return VOID;
		// beat.set(Buckets.NormalNote),
	}

	SonolusApi complete(let t = times.now) {
		FUNCBEGIN
		var res = 0, res2 = 0;
		IF (Abs(t - beat) <= judgment.bad) res = 5, res2 = 3; FI
		IF (Abs(t - beat) <= judgment.good) res = 4, res2 = 3; FI
		IF (Abs(t - beat) <= judgment.great) res = 3, res2 = 2; FI
		IF (Abs(t - beat) <= judgment.perfect) res = 2, res2 = 1; FI
		IF (Abs(t - beat) <= judgment.perfectPlus) res = 1, res2 = 1; FI
		EntityInput.set(0, res2);
		IF (res2 != 0) {
			EntityInput.set(1, t - beat);
			EntityInput.set(2, getBucket());
			EntityInput.set(3, (t - beat) * 1000);
			ExportValue(judgeResult, res);
		} FI

		// IF (res2 == 0) DebugPause(); FI
		IF (!autoSFX) {
			IF (res == 1 || res == 2) Play(getClips().perfect, minSFXDistance); FI
			IF (res == 3) Play(getClips().great, minSFXDistance); FI
			IF (res == 4) Play(getClips().good, minSFXDistance); FI
			IF (res == 5) Play(getClips().bad, minSFXDistance); FI	
		} FI		
		IF (res2 != 0) spawnEffect(getEffects().linear, getEffects().circular, lane, enLane); FI
		IF (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss, t - beat); FI
		IF (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus, t - beat); FI
		IF (res == 2) SpawnSubJudgeText(Sprites.JudgePerfect, t - beat); FI
		IF (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat, t - beat); FI
		IF (res == 4) SpawnSubJudgeText(Sprites.JudgeGood, t - beat); FI
		IF (res == 5) SpawnSubJudgeText(Sprites.JudgeBad, t - beat); FI
		EntityDespawn.set(0, 1);
		return VOID;
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (!played && autoSFX) {
			PlayScheduled(getClips().perfect, beat, minSFXDistance);
			played = true;
		} FI
		IF (times.now < inputTimeMin) Return(0); FI
		IF (times.now > inputTimeMax) complete(-1); FI
		claimStart(EntityInfo.get(0));
		// IF (mapId != -1 && inputList_old.getValById(mapId) != -1) complete(); FI
		// mapId = inputList.size;
		// inputList.add(EntityInfo.get(0), -1);
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
		// Debuglog(index);
		// Debuglog(getHitbox(lane, enLane).l);
		// Debuglog(getHitbox(lane, enLane).r);
		complete(times.now);
		return VOID;
	}

	SonolusApi updateParallel() {
		FUNCBEGIN
		drawNormalNote(getSprite(), lane, enLane, TimeToScaledTime(beat));
		Rect hitbox = getFullHitbox(lane, enLane);
		hitbox.b = -0.2, hitbox.t = 0.2;
		// Draw(Sprites.SyncLine, hitbox.l, hitbox.b, hitbox.l, hitbox.t, hitbox.r, hitbox.t, hitbox.r, hitbox.b, 100000, 1);
		// let index = getTouch(lane, enLane);
		// touchIndex = index;
		return VOID;
	}	
};
