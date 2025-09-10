Bucket HoldEndBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Hold, 0, -0.25, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.HoldNote, 0, 2.75, 0.0, 2.0, 1.0, 270)
}, Text.MillisecondUnit);

class HoldEnd : public Archetype {
	public:
	
	string name = "Sirius Hold End";
	bool hasInput = true;
	
	defineImport(beat);
	defineImport(stBeat);
	defineImport(lane);
	defineImport(laneLength);
	defineImport(judgeResult);
	defineImportDetailed(accuracy, "#ACCURACY");
	defineImport(time1);
	defineImport(time2);
	defineImport(time3);
	defineImport(time4);
	defineImport(time5);
	defineImport(time6);
	defineImport(time7);
	defineImport(time8);
	defineImport(time9);
	defineImport(time10);
	defineImport(time11);
	defineImport(time12);
	defineImport(time13);
	defineImport(time14);
	defineImport(time15);
	defineImport(time16);
	defineImport(time17);
	defineImport(time18);
	defineImport(time19);
	defineImport(time20);
	defineImport(time21);
	defineImport(time22);
	defineImport(time23);
	defineImport(time24);
	defineImport(time25);
	defineImport(time26);
	var enLane;
	var effectInstanceId;
	var combo = var(EntitySharedMemoryId, 0);
	var status = var(EntitySharedMemoryId, 1);
	var nextNoteTime = var(EntitySharedMemoryId, 2);
	var currentAccuracy = var(EntitySharedMemoryId, 3);

	SonolusApi spawnTime() { return TimeToScaledTime(stBeat) - appearTime; }
	SonolusApi despawnTime() { return TimeToScaledTime(beat) + accuracy; }

	SonolusApi preprocess() {
		if (info.index == 1107) DebugLog(stBeat), DebugLog(TimeToScaledTime(stBeat));
 	 	beat = beat / levelSpeed;
 	 	stBeat = stBeat / levelSpeed;
        if (mirror) lane = 14 - lane - laneLength;
        enLane = lane + laneLength - 1;
        currentJudgeStartTime = Max(currentJudgeStartTime, info.index);
        var thisId = info.index;
		input.time = judgment.bad;
		life.miss_increment = -80;
        if (replay) {
        	input.time = beat + accuracy;
        	input.bucketIndex = int(HoldEndBucket);
        	input.bucketValue = accuracy * 1000;
        	if (firstComboTime == 0) firstComboTime = beat;
			if (autoSFX) PlayScheduled(Clips.Perfect, beat, minSFXDistance);
			else {
				if (judgeResult == 1 || judgeResult == 2) PlayScheduled(Clips.Perfect, beat + accuracy, minSFXDistance);
				if (judgeResult == 3) PlayScheduled(Clips.Great, beat + accuracy, minSFXDistance);
				if (judgeResult == 4) PlayScheduled(Clips.Good, beat + accuracy, minSFXDistance);
				if (judgeResult == 5) PlayScheduled(Clips.Bad, beat + accuracy, minSFXDistance);
			}
        	if (judgeResult == 0) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeMiss, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 1) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfectPlus, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 2) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgePerfect, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 3) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGreat, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 4) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeGood, combo, status, thisId, accuracy, currentAccuracy });
			if (judgeResult == 5) Spawn(getAid(UpdateJudgment), { beat + accuracy, Sprites.JudgeBad, combo, status, thisId, accuracy, currentAccuracy });
			if (autoSFX) 
				StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			else
				for (var i = time1.index; i <= time26.index; i += 2) {
					var startTime = stBeat + EntityData[i];
					var endTime = If(EntityData[i + 1] == 0, beat + accuracy, stBeat + EntityData[i + 1]);
					if (EntityData[i] == 0) break;
					if (startTime < endTime) {
						StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, startTime), endTime);
					}
				}
        } else {
        	input.time = beat;
        	input.bucketIndex = int(HoldEndBucket);
        	input.bucketValue = 0;
        	if (firstComboTime == 0) firstComboTime = beat;
	        PlayScheduled(Clips.Perfect, beat, minSFXDistance);
			StopLoopedScheduled(PlayLoopedScheduled(Clips.Hold, stBeat), beat);
			Spawn(getAid(UpdateJudgment), { beat, Sprites.JudgeAuto, combo, status, thisId, 0, 0 });
		}
 	}

 	SonolusApi initialize() {
        effectInstanceId = 0;
 	}
 
 	SonolusApi updateSequential() {
 		if (replay) {
 			var active = false;
			for (var i = time1.index; i <= time26.index; i += 2) {
				var startTime = stBeat + EntityData[i];
				var endTime = If(EntityData[i + 1] == 0, beat + accuracy, stBeat + EntityData[i + 1]);
				if (EntityData[i] == 0) break;
				active = active || (startTime <= times.now && times.now <= endTime);
			}
			if (active) {
				if (effectInstanceId == 0) {
					effectInstanceId = spawnHoldEffect(Effects.Hold, lane, enLane);
				} else {
					updateHoldEffect(effectInstanceId, lane, enLane);
				}
			} else {
		 		if (effectInstanceId) {
		   			DestroyParticleEffect(effectInstanceId);
   					effectInstanceId = 0;
		   		}
			}
 		} else {
 			if (times.now >= stBeat) {
				if (effectInstanceId == 0) {
					effectInstanceId = spawnHoldEffect(Effects.Hold, lane, enLane);
				} else {
					updateHoldEffect(effectInstanceId, lane, enLane);
				}
			}
		}
 	}

 	SonolusApi terminate() {
 		if (effectInstanceId) {
   			DestroyParticleEffect(effectInstanceId);
   			effectInstanceId = 0;
   		}
		if (skip) return;
		if (replay == 1 && judgeResult == 0) return;
		spawnEffect(Effects.HoldLinear, Effects.HoldCircular, lane, enLane);
 	}

 	SonolusApi updateParallel() {
 		if (replay) {
 			var active = false;
 			for (var i = time1.index; i <= time26.index; i += 2) {
				var startTime = stBeat + EntityData[i];
				var endTime = If(EntityData[i + 1] == 0, beat + accuracy, stBeat + EntityData[i + 1]);
				if (EntityData[i] == 0) break;
				active = active || (startTime <= times.now && times.now <= endTime);
			}
			drawHoldEighth(Sprites.Hold, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), active);
 		} else {
			drawHoldEighth(Sprites.Hold, lane, enLane, TimeToScaledTime(stBeat), TimeToScaledTime(beat), times.now > stBeat && times.now < beat);
		}
		if (times.scaled > TimeToScaledTime(stBeat) && times.scaled < TimeToScaledTime(beat)) 
			drawNormalNote(Sprites.HoldNoteLeft, lane, enLane, times.scaled);
		if (times.scaled > TimeToScaledTime(beat) - appearTime) 
			drawNormalNote(Sprites.HoldNoteLeft, lane, enLane, TimeToScaledTime(beat));
 	}
};