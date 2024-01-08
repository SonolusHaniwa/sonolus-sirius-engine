class FlatNote : public Archetype {
    public:

    bool hasInput = true;

	defineEntityData(beat);
	defineEntityData(lane);
	defineEntityData(laneLength);
    Variable<EntityMemoryId> enLane;
    Variable<EntityMemoryId> inputTimeMin;
    Variable<EntityMemoryId> inputTimeMax;
    Variable<EntityMemoryId> touchTime;
    virtual let getSprite() { return -1; }
    virtual let getBucket() { return -1; }
    virtual ClipsArray getClips() { return {}; }
    virtual EffectsArray getEffects() { return {}; }

    SonolusApi spawnOrder() { return 1000 + beat; }
    SonolusApi shouldSpawn() { return times.now > beat - appearTime; }

	SonolusApi preprocess() {
		FUNCBEGIN
        IF (mirror) lane = 14 - lane - laneLength; FI
		// cout << lane.offset << endl;
		enLane = lane + laneLength - 1;
		inputTimeMin = beat - judgment.bad + RuntimeEnvironment.get(3);
		inputTimeMax = beat + judgment.bad + RuntimeEnvironment.get(3);
		touchTime = -1;
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
		EntityInput.set(1, t - beat);
		EntityInput.set(3, t - beat);
		IF (res2 == 1) Play(getClips().perfect, minSFXDistance); FI
		IF (res2 == 2) Play(getClips().great, minSFXDistance); FI
		IF (res2 == 3) Play(getClips().good, minSFXDistance); FI
		IF (res2 != 0) spawnEffect(getEffects().linear, getEffects().circular, lane, enLane); FI
		IF (res == 0) SpawnSubJudgeText(Sprites.JudgeMiss); FI
		IF (res == 1) SpawnSubJudgeText(Sprites.JudgePerfectPlus); FI
		IF (res == 2) SpawnSubJudgeText(Sprites.JudgePerfect); FI
		IF (res == 3) SpawnSubJudgeText(Sprites.JudgeGreat); FI
		IF (res == 4) SpawnSubJudgeText(Sprites.JudgeGood); FI
		IF (res == 5) SpawnSubJudgeText(Sprites.JudgeBad); FI
		EntityDespawn.set(0, 1);
		return VOID;
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
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
		complete(times.now);
		return VOID;
	}

	SonolusApi updateParallel() {
		FUNCBEGIN
		drawNormalNote(getSprite(), lane, enLane, beat);
		Rect hitbox = getFullHitbox(lane, enLane);
		hitbox.b = -0.2, hitbox.t = 0.2;
		// Draw(Sprites.SyncLine, hitbox.l, hitbox.b, hitbox.l, hitbox.t, hitbox.r, hitbox.t, hitbox.r, hitbox.b, 100000, 1);
		// let index = getTouch(lane, enLane);
		// touchIndex = index;
		return VOID;
	}	
};
