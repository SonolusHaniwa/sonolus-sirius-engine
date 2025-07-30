SonolusApi inSplitLine(var split, var lane, var laneLength) {
	if (split == 1) return lane == 1 && laneLength == 12;
	if (split == 2) return (lane == 1 || lane == 7) && laneLength == 6;
	if (split == 3) return (lane == 1 || lane == 5 || lane == 9) && laneLength == 4;
	if (split == 4) return (lane == 1 || lane == 4 || lane == 7 || lane == 10) && laneLength == 3;
	if (split == 5) return (lane == 1 || lane == 10) && laneLength == 3 || (lane == 4 || lane == 6 || lane == 8) && laneLength == 2;
	if (split == 6) return (lane == 1 || lane == 3 || lane == 5 || lane == 7 || lane == 9 || lane == 11) && laneLength == 2;
	return false;
}

SonolusApi getSplitLineId(var split, var lane) {
	if (split == 1) return 1;
	if (split == 2) return (lane - 1) / 6 + 1;
	if (split == 3) return (lane - 1) / 4 + 1;
	if (split == 4) return (lane - 1) / 3 + 1;
	if (split == 5) {
		if (lane == 1) return 1;
		else return lane / 2;
	}
	if (split == 6) return (lane - 1) / 2 + 1;
}

SonolusApi getSplitLine(var split, var id, var& lane, var& laneLength) {
	if (split == 1) lane = 1, laneLength = 12;
	if (split == 2) lane = (id - 1) * 6 + 1, laneLength = 6;
	if (split == 3) lane = (id - 1) * 4 + 1, laneLength = 4;
	if (split == 4) lane = (id - 1) * 3 + 1, laneLength = 3;
	if (split == 5) {
		if (id == 1) lane = 1, laneLength = 3;
		else if (id == 5) lane = 10, laneLength = 3;
		else lane = (id - 2) * 2 + 4, laneLength = 2;
	}
	if (split == 6) lane = (id - 1) * 2 + 1, laneLength = 2;
}

SonolusApi getOrderId(var split, var id) {
	if (split == 1) return 0;
	if (split == 2) return id;
	if (split == 3) return id + 2;
	if (split == 4) return id + 5;
	if (split == 5) return id + 9;
	if (split == 6) return id + 14;
	return -1; // Invalid split
}

class SplitLine: public Archetype {
    public:

    string name = "Sirius Split Line";
    bool input = false;

	defineImport(beat);
	defineImport(endBeat);
	defineImport(split);
	defineImport(color);

    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat - splitLineAnimationStart) + appearTime; }
    SonolusApi shouldSpawn() { return times.now > beat - splitLineAnimationStart; }

	double preprocessOrder = -1;
    SonolusApi preprocess() {
		if (splitRandom) for (var i = 0; i < entityCount; i++) {
			if (
				(
					EntityInfoArray[i].archetype == getAid(CriticalHoldStart) ||
					EntityInfoArray[i].archetype == getAid(CriticalNote) ||
					EntityInfoArray[i].archetype == getAid(CriticalScratchHoldStart) ||
					EntityInfoArray[i].archetype == getAid(HoldStart) ||
					EntityInfoArray[i].archetype == getAid(NormalNote) ||
					EntityInfoArray[i].archetype == getAid(ScratchHoldStart) ||
					EntityInfoArray[i].archetype == getAid(HoldEighth) ||
					EntityInfoArray[i].archetype == getAid(Sound) ||
					EntityInfoArray[i].archetype == getAid(FlickNote)
				) &&
				inSplitLine(split, EntityDataArray[i].generic[1], EntityDataArray[i].generic[2]) &&
				beat <= EntityDataArray[i].generic[0] && EntityDataArray[i].generic[0] <= endBeat
			) {
				var lane, laneLength;
				var id = getSplitLineId(split, EntityDataArray[i].generic[1]);
				getSplitLine(split, order[getOrderId(split, id)], lane, laneLength);
				// DebugLog(lane), DebugLog(laneLength);
				EntityDataArray[i].generic[1] = lane;
				EntityDataArray[i].generic[2] = laneLength;
			}
			else if (
				(
					EntityInfoArray[i].archetype == getAid(HoldEnd) ||
					EntityInfoArray[i].archetype == getAid(NontailHoldEnd) ||
					EntityInfoArray[i].archetype == getAid(NontailScratchHoldEnd) ||
					EntityInfoArray[i].archetype == getAid(ScratchHoldEnd)
				) &&
				inSplitLine(split, EntityDataArray[i].generic[2], EntityDataArray[i].generic[3]) &&
				beat <= EntityDataArray[i].generic[1] && EntityDataArray[i].generic[1] <= endBeat
			) {
				var lane, laneLength;
				var id = getSplitLineId(split, EntityDataArray[i].generic[2]);
				getSplitLine(split, order[getOrderId(split, id)], lane, laneLength);
				EntityDataArray[i].generic[2] = lane;
				EntityDataArray[i].generic[3] = laneLength;
			}
		}
		beat = beat / levelSpeed;
		endBeat = endBeat / levelSpeed;
    }
   
    SonolusApi updateSequential() {
    	if (split < 1 && split > 6) return;
        getSplitLine(color);
        if (times.now > endBeat) {
            drawDisappearLine(times.now - endBeat, split);
        } else {
	        if (times.now < beat) {
	            drawAppearLine(splitLineAnimationStart - beat + times.now, split);
	        } else {
	            drawSplitLine(split);
	        }
	    }
	}

    SonolusApi updateParallel() {
        if (times.now > endBeat + splitLineAnimationEnd) {
			despawn.despawn = true;
        }
	}
};
