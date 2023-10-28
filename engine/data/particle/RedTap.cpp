class RedTap: public Archetype {
	public:

	string name = "Sirius RedTap Particle";
	bool hasInput = false;

	var shouldSpawn = true;
	var lane = EntityMemory.get(0);
	var enLane = EntityMemory.get(1);
	Variable<EntityMemoryId> SpawnTime;

	var initialize = {
		SpawnTime.set(times.now)
	};

	const var ParticleLength = 0.5;
	var wt = judgline.rtX - judgline.ltX, wb = judgline.rbX - judgline.lbX - 2 * judglineMoveLength;
	var lbx = (lane - 1) / 12 * wb + judgline.lbX + judglineMoveLength, lby = judgline.lbY;
	var ltx = (lane - 1) / 12 * wt + judgline.ltX, lty = judgline.ltY;
	var rtx = enLane / 12 * wt + judgline.ltX, rty = lty;
	var rbx = enLane / 12 * wb + judgline.lbX + judglineMoveLength, rby = lby;
	var mt = JudgelineTopHeight / 2, mb = JudgelineBottomHeight / 2;
	
	var inCubic(var x) { return Ease(x, RuntimeFunction.EaseInCubic); };
	var outCubic(var x) { return Ease(x, RuntimeFunction.EaseOutCubic); };
	var aInCubic = inCubic(1 - (times.now - SpawnTime.get()) / ParticleLength);
	var aOutCubic = outCubic(1 - (times.now - SpawnTime.get()) / ParticleLength);

	var updateSequential = {
		Draw(Sprites.HorizontalLine, ltx, lty - 2 * mt, ltx, lty, rtx, rty, rtx, rty - 2 * mt, 1e6, aInCubic),
		Draw(Sprites.HorizontalLine, lbx, lby, lbx, lby + 2 * mb, rbx, rby + 2 * mb, rbx, rby, 1e6, aInCubic),
		Draw(Sprites.VerticalLine, lbx - mb, lby, ltx - mt, lty, ltx + mt, lty, lbx + mb, lby, 1e6, aInCubic)
	};

	var updateParallel = {
		IF (times.now > SpawnTime.get() + ParticleLength) { EntityDespawn.set(0, 1) } FI
	};
};
