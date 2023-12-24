class SiriusHoldTickNote: public Archetype {
	public:

    vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}, {"holdType", 4}};
    bool hasInput = true;

    var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
    var lane = EntityData.get(2);
    var laneLength = EntityData.get(3);
	var holdType = EntityData.get(4);
    var enLane = lane + laneLength - 1;

    Variable<EntityMemoryId> effectInstanceId;

	virtual var getClip() { return Clips.Hold; }
    virtual var getEffect() { 
    	return SwitchWithDefault(holdType, {
			{100, Effects.Hold},
			{101, Effects.Hold},
			{110, Effects.Scratch},
			{111, Effects.Scratch}
		}, Effects.Hold); 
    }

    var spawnTime() { return lastBeat - appearTime; }
    var despawnTime() { return beat; }

    var preprocess() {
   		return {
   			IF (LevelOption.get(Options.Mirror)) {
   				EntityData.set(2, 13 - enLane)
   			} FI,
   			EntityInput.set(0, beat),
   			StopLoopedScheduled(
   				PlayLoopedScheduled(getClip(), lastBeat),
   				beat
   			),
   		};
   	}

   	int updateSequentialOrder = 1;
   	var updateSequential() {
   		return {
   			// 更新判定文字
   			IF (times.now > beat - 0.03) {
   				SpawnJudgeText(beat)
   			} FI,

   			// 如果没有生成粒子效果，生成一个
   			IF (effectInstanceId.get() == 0 && times.now >= lastBeat) {
   				effectInstanceId.set(spawnHoldEffect(getEffect(), lane, enLane))
   			} FI,

   			// 更新(移动)粒子效果
   			IF (effectInstanceId.get()) {
   				updateHoldEffect(effectInstanceId.get(), lane, enLane)
   			} FI
   		};
   	}

   	var terminate() {
   		return {
   			IF (effectInstanceId.get()) {
   				DestroyParticleEffect(effectInstanceId.get())
   			} FI
   		};
   	}
};
