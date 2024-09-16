Map<LevelMemoryId, let, let> disallowEmptiesNow(16);
Map<LevelMemoryId, let, let> disallowEmptiesOld(16);

class ClaimManager {
	public:
	
	class ClaimInfo {
		CLASSBEGIN

		defineVar(let, index, 0);
		defineVar(let, time, 0);
		defineVar(Rect, hitbox, Rect());
		defineVar(Rect, fullHitbox, Rect());
	};

	Map<LevelMemoryId, let, let> claimed = Map<LevelMemoryId, let, let>(16);

	ClaimInfo getInfo(let id) {
		let time = EntityDataArray[id].get(0);
		let lane = EntityDataArray[id].get(1);
		let enLane = EntityDataArray[id].get(2) + lane - 1;
		return {
			index: id,
			time: time,
			hitbox: getHitbox(lane, enLane),
			fullHitbox: getFullHitbox(lane, enLane)
		};
	}

	SonolusApi findBestTouchIndex(let index) {
		FUNCBEGIN
		ClaimInfo origin = getInfo(index);
		let x = (origin.hitbox.l + origin.hitbox.r) / 2;
		var res = -1, minDis = 1e9;
		FOR (i, 0, touches.size, 1) {
			IF (touches[i].started == 0) CONTINUE; FI
			// Debuglog(origin.fullHitbox.l); Debuglog(origin.fullHitbox.r);
			IF (origin.fullHitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
			// IF (EntityDataArray[index].get(1) == 4 && EntityDataArray[index].get(2) == 3) 
			// Debuglog(origin.fullHitbox.l);
			// Debuglog(origin.fullHitbox.r);
			// DebugPause(); FI

			let dis = Abs(touches[i].x - x);
			IF (res != -1 && minDis <= dis) CONTINUE; FI

			let claimIndex = claimed.indexOf(touches[i].id);
			IF (claimIndex == -1) {
				res = touches[i].id; minDis = dis;
				CONTINUE;
			} FI

			ClaimInfo claim = getInfo(claimed.getValById(claimIndex));
			IF (origin.time > claim.time) CONTINUE; FI
			IF (origin.time < claim.time) {
				res = touches[i].id; minDis = dis;
				CONTINUE;
			} FI
         
			IF (claim.hitbox.contain(touches[i].x, touches[i].y) == 1) CONTINUE; FI
			IF (origin.hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
			res = touches[i].id; minDis = dis;
		} DONE
		Return(res);
		return VAR;
	}

	SonolusApi claim(let index) {
		FUNCBEGIN
		var currentId = index;
		ClaimInfo info = getInfo(currentId);
		WHILE (true) {
			var touchIndex = findBestTouchIndex(currentId);
			IF (touchIndex == -1) BREAK; FI
			disallowEmptiesNow.set(touchIndex, 1);
			
			let claimIndex = claimed.indexOf(touchIndex);
			// Debuglog(info.fullHitbox.l); Debuglog(info.fullHitbox.r);
			// Debuglog(touchIndex); Debuglog(info.index); Debuglog(info.time); Debuglog(claimIndex);
			IF (claimIndex == -1) {
				claimed.set(touchIndex, currentId); 
				// Debuglog(claimed.indexOf(touchIndex));
				// Debuglog(claimed.size);
				BREAK;
			} FI

			// ClaimInfo replaced = getInfo(cldaimIndex)
			// Debuglog(claimed.indexOf(touchIndex));
			var tmp = currentId;
			currentId = claimed.getValById(claimIndex);
			// Debuglog(claimed.indexOf(touchIndex));
			claimed.set(touchIndex, tmp);
			// DebugPause();
			// claimed.val.set(claimIndex, tmp);
			// Debuglog(touchIndex);
			// Debuglog(claimed.getValById(claimIndex));
			// IF (claimed.getValById(claimIndex) != tmp) DebugPause(); FI
			// Debuglog(claimed.size);
		} DONE
		return VOID;
	}

	SonolusApi getClaimedTouchIndex(let index) {
		FUNCBEGIN
		FOR (i, 0, claimed.size, 1) {
			IF (claimed.getValById(i) == index) 
				// Debuglog(claimed.getValById(i)); Debuglog(index); Debuglog(i); 
				Return(claimed.getKeyById(i)); FI
		} DONE 
		Return(-1);
		return VAR;
	}

	SonolusApi clear() {
		FUNCBEGIN
		claimed.clear();
		return VOID;
	}
};

ClaimManager claimStartManager = ClaimManager();
SonolusApi claimStart(let index) {
	FUNCBEGIN
	claimStartManager.claim(index);
	return VOID;
}
SonolusApi getClaimedStart(let index) {
	FUNCBEGIN
	Return(claimStartManager.getClaimedTouchIndex(index));
	return VAR;
}

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

double minFlickV = 0.1;
// Map<LevelMemoryId, var, var> usedTouchId(16);
SonolusApi findFlickTouch(let lane, let enLane) {
	FUNCBEGIN
	Rect hitbox = getFullHitbox(lane, enLane);
	FOR (i, 0, touches.size, 1) {
		IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
		IF (Power({touches[i].vx * touches[i].vx + touches[i].vy * touches[i].vy, 0.5}) < minFlickV) CONTINUE; FI
		disallowEmptiesNow.set(touches[i].id, 1);
		Return(touches[i].id);
	} DONE
	Return(-1);
	return VAR;
}

SonolusApi findHoldTouch(let lane, let enLane) {
	FUNCBEGIN 
	Rect hitbox = getFullHitbox(lane, enLane);
	FOR (i, 0, touches.size, 1) {
		IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
		disallowEmptiesNow.set(touches[i].id, 1);
		Return(touches[i].id);
	} DONE
	Return(-1);
	return VAR;
}

// Map<LevelMemoryId, var, var> inputList(16), inputList_old(16);
class InputManager: public Archetype {
	public:

	static constexpr const char* name = "Sirius Input Manager";

	SonolusApi spawnOrder() { return 1; }
	SonolusApi shouldSpawn() { return 1; }
	
	SonolusApi updateSequential() {
		FUNCBEGIN
		claimStartManager.clear();
		disallowEmptiesOld.clear();
		FOR (i, 0, disallowEmptiesNow.size, 1) {
			// Debuglog(disallowEmptiesNow.getKeyById(i));
			disallowEmptiesOld.set(
				disallowEmptiesNow.getKeyById(i), 
				disallowEmptiesNow.getValById(i)
			);
		} DONE
		// cout << disallowEmptiesNow.size.offset << endl;
		// Debuglog(disallowEmptiesOld.size);
		// cout << disallowEmptiesOld.size.offset << endl;
		disallowEmptiesNow.clear();
		// Debuglog(disallowEmptiesOld.size);
		FOR (i, 0, touches.size, 1) {
			// IF (touches[i].started) {
			// 	Debuglog(touches[i].id);
			// 	Debuglog(touches[i].x);
			// 	Debuglog(touches[i].y);
			// } FI
			// Debuglog(disallowEmptiesOld.key[0]);
			// Debuglog(touches[i].id);
			IF (disallowEmptiesOld.indexOf(touches[i].id) != -1)
				disallowEmptiesNow.add(touches[i].id, 1); 
			FI
		} DONE
		return VOID;
		// inputList_old.size = 0;
		// FOR (i, 0, touches.size, 1) {
		// 	IF (usedTouchId.indexOf(touches[i].id) != -1) {
		// 		inputList_old.set(touches[i].id, 1);
		// 	} FI
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
		// 		IF (touches[i].started == 0) CONTINUE; FI
		// 		var best = -1, bestDis = 1e9, bestTime = 1e9, bestId = -1;

		// 		IF (inputList_old.getValById(j) != -1) CONTINUE; FI
		// 		let time = EntityDataArray[inputList_old.getKeyById(j)].get(0);
		// 		let lane = EntityDataArray[inputList_old.getKeyById(j)].get(1);
		// 		let enLane = EntityDataArray[inputList_old.getKeyById(j)].get(2) + lane;
				
		// 		Rect hitbox = getHitbox(lane, enLane);
		// 		Rect fullHitbox = getFullHitbox(lane, enLane);
		// 		IF (fullHitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI

		// 		let dis = Abs(touches[i].x - (hitbox.l + hitbox.r) / 2);
		// 		IF (best == -1) {
		// 			best = inputList_old.getKeyById(j); bestDis = dis;
		// 			bestTime = time; bestId = j;
		// 			CONTINUE;
		// 		} FI
		// 		IF (bestDis <= dis) CONTINUE; FI

		// 		IF (time > bestTime) CONTINUE; FI
		// 		IF (time < bestTime) {
		// 			best = inputList_old.getKeyById(j); bestDis = dis;
		// 			bestTime = time; bestId = j;
		// 			CONTINUE;
		// 		} FI

		// 		let lane2 = EntityDataArray[best].get(1);
		// 		let enLane2 = EntityDataArray[best].get(2) + lane2;
		// 		Rect hitbox2 = getHitbox(lane2, enLane2);
		// 		IF (hitbox2.contain(touches[i].x, touches[i].y) == 1) CONTINUE; FI
		// 		IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI
		// 		best = inputList_old.getKeyById(j); bestDis = dis;
		// 		bestTime = time; bestId = j;
		// 	} DONE
		// 	IF (best != -1) {
		// 		inputList_old.val.set(bestId, touches[i].id);
		// 		usedTouchId.set(touches[i].id, 1);
		// 	} FI
		// 	// IF (best == -1) Debuglog(touches[i].id); Debuglog(best); FI
		// } DONE
		// return VOID;
	}

	// SonolusApi touch() {
	// 	FUNCBEGIN
	// 	Rect hitbox = getFullHitbox(4, 6);
		// FOR (i, 0, touches.size, 1) {
		// 	IF (touches[i].started == 0) CONTINUE; FI
		// 	Debuglog(hitbox.l); Debuglog(hitbox.r);
		// 	Debuglog(touches[i].x); Debuglog(hitbox.contain(touches[i].x, touches[i].y));
		// } DONE
		// return VOID;
	// }
};
