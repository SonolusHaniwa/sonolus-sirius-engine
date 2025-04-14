Map<var, var, 16> disallowEmptiesNow, disallowEmptiesOld;

class ClaimManager {
	public:
	
	class ClaimInfo {
        public:

        var index = 0;
        var time = 0;
        Rect hitbox = Rect();
        Rect fullHitbox = Rect();
	};

    Map<var, var, 16> claimed;

	ClaimInfo getInfo(var id) {
		var time = EntityDataArray[id].generic[0];
		var lane = EntityDataArray[id].generic[1];
		var enLane = EntityDataArray[id].generic[2] + lane - 1;
		return {
			index: id,
			time: time,
			hitbox: getHitbox(lane, enLane),
			fullHitbox: getFullHitbox(lane, enLane)
		};
	}

	SonolusApi findBestTouchIndex(var index) {
		ClaimInfo origin = getInfo(index);
		var x = (origin.hitbox.l + origin.hitbox.r) / 2;
		var res = -1, minDis = 1e9;
        for (var i = 0; i < touchCount; i++) {
			if (touches[i].started == 0) continue;
			// Debuglog(origin.fullHitbox.l); Debuglog(origin.fullHitbox.r);
			if (origin.fullHitbox.contains({ touches[i].x, touches[i].y }) == 0) continue;
			// if (EntityDataArray[index].get(1) == 4 && EntityDataArray[index].get(2) == 3) 
			// Debuglog(origin.fullHitbox.l);
			// Debuglog(origin.fullHitbox.r);
			// DebugPause();

			var dis = Abs(touches[i].x - x);
			// if (EntityInfo.index == 90 || EntityInfo.index == 91) {
			// 	DebugLog(touches[i].id);
			// 	DebugLog(touches[i].x);
			// 	DebugLog(touches[i].y);
			// 	DebugLog(dis);
			// }
			if (res != -1 && minDis <= dis) continue;

			var claimIndex = claimed.indexOf(touches[i].id);
			if (claimIndex == -1) {
				res = touches[i].id; minDis = dis;
				continue;
			}

			ClaimInfo claim = getInfo(claimed.getValue(claimIndex));
			if (origin.time > claim.time) continue;
			// DebugLog(1919810);
			if (origin.time < claim.time) {
				res = touches[i].id; minDis = dis;
				continue;
			}
			// if (EntityInfo.index == 91) {
			// 	DebugLog(claim.hitbox.contains({ touches[i].x, touches[i].y }));
			// 	DebugLog(origin.hitbox.contains({ touches[i].x, touches[i].y }));
			// }
         
			if (claim.hitbox.contains({ touches[i].x, touches[i].y }) == 1) continue;
			if (origin.hitbox.contains({ touches[i].x, touches[i].y }) == 0) continue;
			res = touches[i].id; minDis = dis;
		}
        return res;
	}

	SonolusApi claim(var index) {
		var currentId = index;
		ClaimInfo info = getInfo(currentId);
		while (true) {
			var touchIndex = findBestTouchIndex(currentId);
			if (touchIndex == -1) break;
			disallowEmptiesNow.set(touchIndex, 1);
			// DebugLog(index); DebugLog(touchIndex);
			// DebugLog(disallowEmptiesNow[touchIndex]);
			
			var claimIndex = claimed.indexOf(touchIndex);
			// Debuglog(info.fullHitbox.l); Debuglog(info.fullHitbox.r);
			// Debuglog(touchIndex); Debuglog(info.index); Debuglog(info.time); Debuglog(claimIndex);
			if (claimIndex == -1) {
				claimed.set(touchIndex, currentId); 
				// Debuglog(claimed.indexOf(touchIndex));
				// Debuglog(claimed.size);
				break;
			}

			// ClaimInfo replaced = getInfo(cldaimIndex)
			// Debuglog(claimed.indexOf(touchIndex));
			var tmp = currentId;
			currentId = claimed[touchIndex];
			// Debuglog(claimed.indexOf(touchIndex));
			claimed[touchIndex] = tmp;
			// DebugPause();
			// claimed.val.set(claimIndex, tmp);
			// Debuglog(touchIndex);
			// Debuglog(claimed.getValById(claimIndex));
			// if (claimed.getValById(claimIndex) != tmp) DebugPause();
			// Debuglog(claimed.size);
		}
	}

	SonolusApi getClaimedTouchIndex(var index) {
        for (var i = 0; i < claimed.count; i++) {
			if (claimed.getValue(i) == index) return claimed.getKey(i);
				// Debuglog(claimed.getValById(i)); Debuglog(index); Debuglog(i); 
				// Return(claimed.getKeyById(i));
		} 
        return -1;
	}

	Blocked SonolusApi clear() {
		claimed.clear();
	}
};

ClaimManager claimStartManager = ClaimManager();
SonolusApi claimStart(var index) {
	claimStartManager.claim(index);
}
SonolusApi getClaimedStart(var index) {
	return claimStartManager.getClaimedTouchIndex(index);
}

// Map<LevelMemoryId, var, var> disabledList(16);

// SonolusApi getTouch(var lane, var enLane) {
// 	FUNCBEGIN
// 	Rect hitbox = getFullHitbox(lane, enLane);
// 	var x = (hitbox.l + hitbox.r) / 2;
// 	var id = -1, minDis = 9999;
// 	FOR (i, 0, touches.size, 1) {
// 		if (touches[i].started == false) CONTINUE;
// 		if (!hitbox.contain(touches[i].x, touches[i].y)) CONTINUE;
// 		if (disabledList.indexOf(touches[i].id) != -1) CONTINUE;
// 		var dis = Abs(touches[i].x - x);
// 		if (id != -1 && dis > minDis) CONTINUE;
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

double minFlickV = 0.1;
// Map<LevelMemoryId, var, var> usedTouchId(16);
SonolusApi findFlickTouch(var lane, var enLane) {
	Rect hitbox = getFullHitbox(lane, enLane);
    for (var i = 0; i < touchCount; i++) {
		if (hitbox.contains({ touches[i].x, touches[i].y }) == 0) continue;
		if (Power({touches[i].vx * touches[i].vx + touches[i].vy * touches[i].vy, 0.5}) < minFlickV) continue;
		disallowEmptiesNow.set(touches[i].id, 1);
		return touches[i].id;
	}
    return -1;
}

SonolusApi findHoldTouch(var lane, var enLane) {
	Rect hitbox = getFullHitbox(lane, enLane);
    for (var i = 0; i < touchCount; i++) {
		if (hitbox.contains({ touches[i].x, touches[i].y }) == 0) continue;
		disallowEmptiesNow.set(touches[i].id, 1);
        return touches[i].id;
	}
    return -1;
}

class InputManager: public Archetype {
	public:

	string name = "Sirius Input Manager";

	SonolusApi spawnOrder() { return 1; }
	SonolusApi shouldSpawn() { return 1; }
	
	SonolusApi updateSequential() {
		// if (disallowEmptiesNow.count != 0) DebugLog(disallowEmptiesNow.count);
		claimStartManager.clear();
		disallowEmptiesOld.clear();
        for (var i = 0; i < disallowEmptiesNow.count; i++)
			// Debuglog(disallowEmptiesNow.getKeyById(i));
			disallowEmptiesOld.set(disallowEmptiesNow.getKey(i), disallowEmptiesNow.getValue(i));
		// cout << disallowEmptiesNow.size.offset << endl;
		// Debuglog(disallowEmptiesOld.size);
		// cout << disallowEmptiesOld.size.offset << endl;
		disallowEmptiesNow.clear();
		// Debuglog(disallowEmptiesOld.size);
        for (var i = 0; i < touchCount; i++) {
			// if (touches[i].started) {
			// 	Debuglog(touches[i].id);
			// 	Debuglog(touches[i].x);
			// 	Debuglog(touches[i].y);
			// }
			// Debuglog(disallowEmptiesOld.key[0]);
			// Debuglog(touches[i].id);
			if (disallowEmptiesOld.indexOf(touches[i].id) != -1)
				disallowEmptiesNow.set(touches[i].id, 1);
		}
		// inputList_old.size = 0;
		// FOR (i, 0, touches.size, 1) {
		// 	if (usedTouchId.indexOf(touches[i].id) != -1) {
		// 		inputList_old.set(touches[i].id, 1);
		// 	}
		// } DONE
		// usedTouchId.size = 0;
		// FOR (i, 0, inputList_old.size, 1) usedTouchId.add(inputList_old.getKeyById(i), 1); DONE

		// inputList_old.size = 0;
		// FOR (i, 0, inputList.size, 1) {
		// 	inputList_old.add(inputList.getKeyById(i), inputList.getValById(i));
		// } DONE
		// inputList.size = 0;

		// FOR (j, 0, inputList_old.size, 1) {
		// 	FOR (i, 0, touches.size, 1) {
		// 		if (touches[i].started == 0) CONTINUE;
		// 		var best = -1, bestDis = 1e9, bestTime = 1e9, bestId = -1;

		// 		if (inputList_old.getValById(j) != -1) CONTINUE;
		// 		var time = EntityDataArray[inputList_old.getKeyById(j)].get(0);
		// 		var lane = EntityDataArray[inputList_old.getKeyById(j)].get(1);
		// 		var enLane = EntityDataArray[inputList_old.getKeyById(j)].get(2) + lane;
				
		// 		Rect hitbox = getHitbox(lane, enLane);
		// 		Rect fullHitbox = getFullHitbox(lane, enLane);
		// 		if (fullHitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE;

		// 		var dis = Abs(touches[i].x - (hitbox.l + hitbox.r) / 2);
		// 		if (best == -1) {
		// 			best = inputList_old.getKeyById(j); bestDis = dis;
		// 			bestTime = time; bestId = j;
		// 			CONTINUE;
		// 		}
		// 		if (bestDis <= dis) CONTINUE;

		// 		if (time > bestTime) CONTINUE;
		// 		if (time < bestTime) {
		// 			best = inputList_old.getKeyById(j); bestDis = dis;
		// 			bestTime = time; bestId = j;
		// 			CONTINUE;
		// 		}

		// 		var lane2 = EntityDataArray[best].get(1);
		// 		var enLane2 = EntityDataArray[best].get(2) + lane2;
		// 		Rect hitbox2 = getHitbox(lane2, enLane2);
		// 		if (hitbox2.contain(touches[i].x, touches[i].y) == 1) CONTINUE;
		// 		if (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE;
		// 		best = inputList_old.getKeyById(j); bestDis = dis;
		// 		bestTime = time; bestId = j;
		// 	} DONE
		// 	if (best != -1) {
		// 		inputList_old.val.set(bestId, touches[i].id);
		// 		usedTouchId.set(touches[i].id, 1);
		// 	}
		// 	// if (best == -1) Debuglog(touches[i].id); Debuglog(best);
		// } DONE
		// return VOID;
	}

	// SonolusApi touch() {
	// 	FUNCBEGIN
	// 	Rect hitbox = getFullHitbox(4, 6);
		// FOR (i, 0, touches.size, 1) {
		// 	if (touches[i].started == 0) CONTINUE;
		// 	Debuglog(hitbox.l); Debuglog(hitbox.r);
		// 	Debuglog(touches[i].x); Debuglog(hitbox.contain(touches[i].x, touches[i].y));
		// } DONE
		// return VOID;
	// }
};
