 class SiriusScratchHoldEnd : public Archetype {
     public:
     
     static constexpr const char* name = "Sirius Scratch Hold End";
	 bool hasInput = true;
	 
	 defineEntityData(beat);
	 defineEntityData(stBeat);
	 defineEntityData(lane);
	 defineEntityData(laneLength);
	 defineEntityData(scratchLength);
	 Variable<EntityMemoryId> enLane;
     Variable<EntityMemoryId> effectInstanceId;
	 Variable<EntityMemoryId> scratchLane;
	 Variable<EntityMemoryId> scratchEnLane;
 
     SonolusApi spawnTime() { return stBeat - appearTime; }
     SonolusApi despawnTime() { return beat; }
 
 	 SonolusApi preprocess() {
 	 	FUNCBEGIN
        IF (mirror) lane = 14 - lane - laneLength; FI
        enLane = lane + laneLength - 1;
		scratchLane = If(scratchLength >= 0, lane, enLane + scratchLength + 1);
		scratchEnLane = If(scratchLength <= 0, enLane, lane + scratchLength - 1);
        Set(EntityInputId, 0, beat);
        PlayScheduled(Clips.Scratch, beat, minSFXDistance);
		StopLoopedScheduled(
			PlayLoopedScheduled(Clips.Hold, stBeat),
			beat
		);
		Spawn(getArchetypeId(UpdateJudgment), {beat, Sprites.JudgePerfectPlus});
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
			effectInstanceId.set(spawnHoldEffect(Effects.Scratch, lane, enLane));
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
		spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, scratchLane, scratchEnLane);
 		return VOID;
 	}

 	SonolusApi updateParallel() {
 		FUNCBEGIN
		drawHoldEighth(Sprites.Scratch, lane, enLane, stBeat, beat, 1);
		IF (times.now > stBeat && times.now < beat) drawNormalNote(Sprites.ScratchNote, lane, enLane, times.now); FI
		IF (times.now > beat - appearTime) drawNormalNote(Sprites.ScratchNote, scratchLane, scratchEnLane, beat); FI
		IF (times.now > beat - appearTime) {
			IF (scratchLength > 0) drawRightArrow(scratchLane, scratchEnLane, beat); FI
			IF (scratchLength < 0) drawLeftArrow(scratchLane, scratchEnLane, beat); FI
			IF (scratchLength == 0) drawArrow(scratchLane, scratchEnLane, beat); FI
		} FI
 		return VOID;
 	}
};
