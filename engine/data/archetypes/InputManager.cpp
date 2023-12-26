class ClaimManager {
	public:
	
	class ClaimInfo {
		CLASSBEGIN

		defineVar(var, index, var());
		defineVar(var, time, var());
		defineVar(Rect, hitbox, Rect());
		defineVar(Rect, fullHitbox, Rect());
	};

	Map<LevelMemoryId, var, ClaimInfo> claimed = Map<LevelMemoryId, var, ClaimInfo>(16);

	SonolusApi findBestTouchIndex(var time, Rect hitbox, Rect fullHitbox, function<SonolusApi(Touch)> checkTouch) {
		FUNCBEGIN
		var x = (hitbox.l + hitbox.r) / 2;
		var res = -1, minDis = 1e9;
		FOR (i, 0, touches.size, 1) {
			IF (checkTouch(touches[i]) == 0) CONTINUE; FI
			IF (fullHitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI

			var dis = Abs(touches[i].x - x);
			IF (res != -1 && minDis <= dis) CONTINUE; FI

			var claimIndex = claimed.indexOf(touches[i].id);
			IF (claimIndex == -1) {
				res = touches[i].id; minDis = dis;
				CONTINUE;
			} FI

			ClaimInfo claim = claimed.getValById(claimIndex);
			IF (time > claim.time) CONTINUE; FI
			IF (time < claim.time) {
				res = touches[i].id; minDis = dis;
				CONTINUE;
			} FI

			IF (claim.hitbox.contain(touches[i].x, touches[i].y) == 1) CONTINUE; FI
			IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
			res = touches[i].id; minDis = dis;
		} DONE
		Return(res);
		return VAR;
	}

	SonolusApi claim(var index, var time, Rect hitbox, Rect fullHitbox, function<SonolusApi(Touch)> checkTouch) {
		FUNCBEGIN
		ClaimInfo info = {
			index: index,
			time: time,
			hitbox: hitbox,
			fullHitbox: fullHitbox
		};
		WHILE (true) {
			var touchIndex = findBestTouchIndex(time, hitbox, fullHitbox, checkTouch);
			IF (touchIndex == -1) BREAK; FI
			
			var claimIndex = claimed.indexOf(touchIndex);
			IF (claimIndex == -1) {
				claimed.set(touchIndex, info); 
				BREAK;
			} FI

			ClaimInfo replaced = claimed.getValById(claimIndex);
			claimed.set(touchIndex, info);
			info = replaced;
		} DONE
		return VOID;
	}

	SonolusApi getClaimedTouchIndex(var index) {
		FUNCBEGIN
		FOR (i, 0, claimed.size, 1) {
			IF (claimed.val[i].index == index) Return(claimed.key[i]); FI
		} DONE Return(-1);
		return VAR;
	}

	SonolusApi clear() {
		FUNCBEGIN
		claimed.clear();
		return VOID;
	}
};

Map<LevelMemoryId, var, var> disallowEmptiesNow = Map<LevelMemoryId, var, var>(16);
Map<LevelMemoryId, var, var> disallowEmptiesOld = Map<LevelMemoryId, var, var>(16);
SonolusApi canEmpty(Touch touch) {
	FUNCBEGIN
	Return(disallowEmptiesNow.indexOf(touch.id) == -1);
	return VAR;
}
SonolusApi disallowEmpty(Touch touch) {
	FUNCBEGIN
	disallowEmptiesNow.set(touch.id, 1);
	return VOID;
}

ClaimManager claimStartManager = ClaimManager();
SonolusApi claimStart(var index, var time, Rect hitbox, Rect fullHitbox) {
	FUNCBEGIN
	claimStartManager.claim(index, time, hitbox, fullHitbox, [](Touch touch){ return touch.started; });
	return VOID
}
SonolusApi getClaimedStart(var index) {
	FUNCBEGIN
	Return(claimStartManager.getClaimedTouchIndex(index));
	return VOID;
}

class InputManager: public Archetype {
	public:

	static constexpr const char* name = "Sirius Input Manager";

	SonolusApi spawnOrder() { return 1; }
	SonolusApi shouldSpawn() { return EntityInfoArray.get(2) == EntityState.Despawned; }
	SonolusApi updateSequential() {
		FUNCBEGIN
		claimStartManager.clear();
		disallowEmptiesOld.clear();
		FOR (i, 0, disallowEmptiesNow.size, 1) {
			disallowEmptiesOld.set(
				disallowEmptiesNow.getKeyById(i),
				disallowEmptiesNow.getValById(i)
			);
		} DONE
		disallowEmptiesNow.clear();

		FOR (i, 0, touches.size, 1) {
			IF (disallowEmptiesOld.indexOf(touches[i].id) != -1)
				disallowEmptiesNow.set(touches[i].id, 1);
			FI
		} DONE
		return VOID;
	}
};
