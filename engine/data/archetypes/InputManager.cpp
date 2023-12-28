// class ClaimManager {
// 	public:
// 	
// 	class ClaimInfo {
// 		CLASSBEGIN
// 
// 		defineVar(var, index, var());
// 		defineVar(var, time, var());
// 		defineVar(Rect, hitbox, Rect());
// 		defineVar(Rect, fullHitbox, Rect());
// 	};
// 
// 	Map<LevelMemoryId, var, ClaimInfo> claimed = Map<LevelMemoryId, var, ClaimInfo>(16);
// 
// 	SonolusApi findBestTouchIndex(var time, Rect hitbox, Rect fullHitbox, function<SonolusApi(Touch)> checkTouch) {
// 		FUNCBEGIN
// 		var x = (hitbox.l + hitbox.r) / 2;
// 		var res = -1, minDis = 1e9;
// 		FOR (i, 0, touches.size, 1) {
// 			IF (checkTouch(touches[i]) == 0) CONTINUE; FI
// 			IF (fullHitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
// 
// 			var dis = Abs(touches[i].x - x);
// 			IF (res != -1 && minDis <= dis) CONTINUE; FI
// 
// 			var claimIndex = claimed.indexOf(touches[i].id);
// 			IF (claimIndex == -1) {
// 				res = touches[i].id; minDis = dis;
// 				CONTINUE;
// 			} FI
// 
// 			ClaimInfo claim = claimed.getValById(claimIndex);
// 			IF (time > claim.time) CONTINUE; FI
// 			IF (time < claim.time) {
// 				res = touches[i].id; minDis = dis;
// 				CONTINUE;
// 			} FI
// 
// 			IF (claim.hitbox.contain(touches[i].x, touches[i].y) == 1) CONTINUE; FI
// 			IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
// 			res = touches[i].id; minDis = dis;
// 		} DONE
// 		Return(res);
// 		return VAR;
// 	}
// 
// 	SonolusApi claim(var index, var time, Rect hitbox, Rect fullHitbox, function<SonolusApi(Touch)> checkTouch) {
// 		FUNCBEGIN
// 		ClaimInfo info = {
// 			index: index,
// 			time: time,
// 			hitbox: hitbox,
// 			fullHitbox: fullHitbox
// 		};
// 		WHILE (true) {
// 			var touchIndex = findBestTouchIndex(time, hitbox, fullHitbox, checkTouch);
// 			IF (touchIndex == -1) BREAK; FI
// 			
// 			var claimIndex = claimed.indexOf(touchIndex);
// 			Debuglog(touchIndex); Debuglog(info.index); Debuglog(info.time); Debuglog(claimIndex);
// 			IF (claimIndex == -1) {
// 				claimed.set(touchIndex, info); 
// 				Debuglog(claimed.indexOf(touchIndex));
// 				Debuglog(claimed.size);
// 				BREAK;
// 			} FI
// 
// 			ClaimInfo replaced = claimed.getValById(claimIndex);
// 			claimed.set(touchIndex, info);
// 			info = replaced;
// 		} DONE
// 		return VOID;
// 	}
// 
// 	SonolusApi getClaimedTouchIndex(var index) {
// 		FUNCBEGIN
// 		FOR (i, 0, claimed.size, 1) {
// 			IF (claimed.val[i].index == index) Return(claimed.key[i]); FI
// 		} DONE Return(-1);
// 		return VAR;
// 	}
// 
// 	SonolusApi clear() {
// 		FUNCBEGIN
// 		claimed.clear();
// 		return VOID;
// 	}
// };
// 
// Map<LevelMemoryId, var, var> disallowEmptiesNow = Map<LevelMemoryId, var, var>(16);
// Map<LevelMemoryId, var, var> disallowEmptiesOld = Map<LevelMemoryId, var, var>(16);
// SonolusApi canEmpty(var index) {
// 	FUNCBEGIN
// 	Return(disallowEmptiesNow.indexOf(index) == -1);
// 	return VAR;
// }
// SonolusApi disallowEmpty(var index) {
// 	FUNCBEGIN
// 	disallowEmptiesNow.set(index, 1);
// 	Debuglog(disallowEmptiesNow[index]);
// 	return VOID;
// }
// 
// ClaimManager claimStartManager = ClaimManager();
// SonolusApi claimStart(var index, var time, Rect hitbox, Rect fullHitbox) {
// 	FUNCBEGIN
// 	claimStartManager.claim(index, time, hitbox, fullHitbox, [](Touch touch){ return touch.started; });
// 	return VOID
// }
// SonolusApi getClaimedStart(var index) {
// 	FUNCBEGIN
// 	Return(claimStartManager.getClaimedTouchIndex(index));
// 	return VOID;
// }

Map<LevelMemoryId, let, let> disabledList(16);

SonolusApi getTouch(let lane, let enLane) {
	FUNCBEGIN
	Rect hitbox = getFullHitbox(lane, enLane);
	let x = (hitbox.l + hitbox.r) / 2;
	var id = -1, minDis = 9999;
	FOR (i, 0, touches.size, 1) {
		IF (touches[i].started == false) CONTINUE; FI
		IF (!hitbox.contain(touches[i].x, touches[i].y)) CONTINUE; FI
		IF (disabledList.indexOf(touches[i].id) != -1) CONTINUE; FI
		let dis = Abs(touches[i].x - x);
		IF (id != -1 && dis > minDis) CONTINUE; FI
		id = touches[i].id; minDis = dis;
	} DONE
	Return(id);
	return VAR;
}

SonolusApi addTouch(var id) {
	FUNCBEGIN
	disabledList.set(id, 1);
	return VOID;
}

class InputManager: public Archetype {
	public:

	static constexpr const char* name = "Sirius Input Manager";

	SonolusApi spawnOrder() { return 1; }
	SonolusApi shouldSpawn() { return 1; }
	SonolusApi touch() {
		FUNCBEGIN
		disabledList.clear();
		return VOID;
	}
};
