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

// Map<LevelMemoryId, let, let> disabledList(16);

// SonolusApi getTouch(let lane, let enLane) {
// 	FUNCBEGIN
// 	Rect hitbox = getFullHitbox(lane, enLane);
// 	let x = (hitbox.l + hitbox.r) / 2;
// 	var id = -1, minDis = 9999;
// 	FOR (i, 0, touches.size, 1) {
// 		IF (touches[i].started == false) CONTINUE; FI
// 		IF (!hitbox.contain(touches[i].x, touches[i].y)) CONTINUE; FI
// 		IF (disabledList.indexOf(touches[i].id) != -1) CONTINUE; FI
// 		let dis = Abs(touches[i].x - x);
// 		IF (id != -1 && dis > minDis) CONTINUE; FI
// 		id = touches[i].id; minDis = dis;
// 	} DONE
// 	Return(id);
// 	return VAR;
// }
// 
// SonolusApi addTouch(var id) {
// 	FUNCBEGIN
// 	disabledList.set(id, 1);
// 	return VOID;
// }

double minFlickVR = 0.5;
SonolusApi findFlickTouch(let lane, let enLane) {
	FUNCBEGIN
	Rect hitbox = getFullHitbox(lane, enLane);
	FOR (i, 0, touches.size, 1) {
		IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
		IF (touches[i].vr < minFlickVR) CONTINUE; FI
		Return(touches[i].id);
	} DONE
	Return(-1);
	return VAR;
}

Map<LevelMemoryId, var, var> inputList(16), inputList_old(16);
class InputManager: public Archetype {
	public:

	static constexpr const char* name = "Sirius Input Manager";

	SonolusApi spawnOrder() { return 1; }
	SonolusApi shouldSpawn() { return 1; }

	int updateSequentialOrder = 1;
	SonolusApi updateSequential() {
		FUNCBEGIN
		inputList_old.size = 0;
		FOR (i, 0, inputList.size, 1) {
			inputList_old.add(inputList.getKeyById(i), inputList.getValById(i));
		} DONE
		inputList.size = 0;

		FOR (i, 0, touches.size, 1) {
			IF (touches[i].started == 0) CONTINUE; FI
			var best = -1, bestDis = 1e9, bestTime = 1e9, bestId = -1;
			// cout << best.offset << endl;
			FOR (j, 0, inputList_old.size, 1) {
				let time = EntityDataArray[inputList_old.getKeyById(j)].get(0);
				let lane = EntityDataArray[inputList_old.getKeyById(j)].get(1);
				let enLane = EntityDataArray[inputList_old.getKeyById(j)].get(2) + lane;
				
				Rect hitbox = getHitbox(lane, enLane);
				Rect fullHitbox = getFullHitbox(lane, enLane);
				IF (fullHitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI

				let dis = Abs(touches[i].x - (hitbox.l + hitbox.r) / 2);
				IF (best == -1) {
					var id = inputList_old.getKeyById(j);
					best = FuncNode(id); bestDis = dis;
					// cout << id.offset << " " << best.offset << endl;
					bestTime = time; bestId = j;
					CONTINUE;
				} FI
				IF (bestDis <= dis) CONTINUE; FI

				IF (time > bestTime) CONTINUE; FI
				IF (time < bestTime) {
					best = inputList_old.getKeyById(j); bestDis = dis;
					// cout << best.offset << endl;
					bestTime = time; bestId = j;
					CONTINUE;
				} FI

				Debuglog(best);
				let lane2 = EntityDataArray[best].get(1);
				let enLane2 = EntityDataArray[best].get(2) + lane2;
				Rect hitbox2 = getHitbox(lane2, enLane2);
				IF (hitbox2.contain(touches[i].x, touches[i].y) == 1) CONTINUE; FI
				IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
				best = inputList_old.getKeyById(j); bestDis = dis;
				// cout << best.offset << endl;
				bestTime = time; bestId = j;
			} DONE
			IF (best != -1) inputList_old.val.set(bestId, touches[i].id); FI
			// Debuglog(touches[i].id); Debuglog(best);
		} DONE
		return VOID;
	}
};
