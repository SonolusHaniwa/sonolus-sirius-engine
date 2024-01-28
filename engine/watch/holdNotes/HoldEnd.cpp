 class SiriusHoldEnd : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Hold End";
	 bool hasInput = true;
	 
	 defineImports(beat);
	 defineImports(stBeat);
	 defineImports(lane);
	 defineImports(laneLength);
	 Variable<EntityMemoryId> enLane;
     Variable<EntityMemoryId> effectInstanceId;
 
     SonolusApi spawnTime() { return stBeat - appearTime; }
     SonolusApi despawnTime() { return beat; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
 	 	beat = beat / levelSpeed;
 	 	stBeat = stBeat / levelSpeed;
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
        Set(EntityInputId, 0, beat);
        PlayScheduled(Clips.Perfect, beat, minSFXDistance);
		StopLoopedScheduled(
			PlayLoopedScheduled(Clips.Hold, stBeat),
			beat
		);
		Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgeAuto});
 	    return VOID;
 	}

 	SonolusApi initialize() {
 		FUNCBEGIN
        effectInstanceId = 0;
        return VOID;
 	}
 
 	SonolusApi updateSequential() {
 		FUNCBEGIN
 		// 如果没有生成粒子效果，生成一个
		IF (effectInstanceId.get() == 0 && times.now >= stBeat) {
			effectInstanceId.set(spawnHoldEffect(Effects.Hold, lane, enLane));
		} FI

		// 更新(移动)粒子效果
		IF (effectInstanceId.get()) {
			updateHoldEffect(effectInstanceId, lane, enLane);
		} FI
 		return VOID;
 	}

 	SonolusApi terminate() {
 		FUNCBEGIN
 		IF (effectInstanceId.get()) {
   			DestroyParticleEffect(effectInstanceId);
   		} FI
		IF (times.skip) Return(0); FI
		spawnEffect(Effects.HoldLinear, Effects.HoldCircular, lane, enLane);
 		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
		drawHoldEighth(Sprites.Hold, lane, enLane, stBeat, beat, times.now > stBeat && times.now < beat);
		IF (times.now > stBeat && times.now < beat) drawNormalNote(Sprites.HoldNote, lane, enLane, times.now); FI
		IF (times.now > beat - appearTime) drawNormalNote(Sprites.HoldNote, lane, enLane, beat); FI
 		return VOID;
 	}
};
