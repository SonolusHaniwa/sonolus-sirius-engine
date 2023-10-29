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
	var wt = judgline.rtX - judgline.ltX, wb = judgline.rbX - judgline.lbX;
	var jh = judgline.ltY - judgline.lbY, h = 10.0 / 72.0 * jh;
	var lp = 92.5 / 1119.0 * (lane - 1), rp = 92.5 / 1119.0 * enLane + 9.0 / 1119.0;
	var ltx = judgline.ltX + lp * wt, lty = judgline.ltY;
	var lbx = judgline.lbX + lp * wb, lby = judgline.lbY;
	var rtx = judgline.ltX + rp * wt, rty = judgline.rtY;
	var rbx = judgline.lbX + rp * wb, rby = judgline.rbY;
	var adt = 4.0 / 1119.0 * wt, adb = 4.0 / 1119.0 * wb;
	var adh = 4.0 / 72.0 * jh;

	var LinearHeight = 0.5;
	
	var inCubic(var x) { return Ease(x, RuntimeFunction.EaseInCubic); };
	var outCubic(var x) { return Ease(x, RuntimeFunction.EaseOutCubic); };
	var aInCubic = inCubic(1 - (times.now - SpawnTime.get()) / ParticleLength);
	var aOutCubic = outCubic(1 - (times.now - SpawnTime.get()) / ParticleLength);

	var updateSequential = {
		Draw(Sprites.HorizontalLine, ltx + adt, lty - h, ltx + adt, lty, rtx - adt, rty, rtx - adt, rty - h, 1e8, aInCubic),
		Draw(Sprites.HorizontalLine, lbx + adb, lby, lbx + adb, lby + h, rbx - adb, rby + h, rbx - adb, rby, 1e8, aInCubic),
		Draw(Sprites.VerticalLine, lbx, lby + adh, ltx, lty - adh, ltx + h, lty - adh, lbx + h, lby + adh, 1e8, aInCubic),
		Draw(Sprites.VerticalLine, rbx - h, rby + adh, rtx - h, rty - adh, rtx, rty - adh, rbx, rby + adh, 1e8, aInCubic),
		Draw(Sprites.LinearLine, lbx, lby, lbx, lby + LinearHeight, ltx, lty + LinearHeight, ltx, lty, 1e8, aInCubic),
		Draw(Sprites.LinearLine, rbx, rby, rbx, rby + LinearHeight, rtx, rty + LinearHeight, rtx, rty, 1e8, aInCubic),
		Draw(Sprites.LinearLine, ltx, lty, ltx, lty + LinearHeight, rtx, rty + LinearHeight, rtx, rty, 1e8, aInCubic),
	};

	var updateParallel = {
		IF (times.now > SpawnTime.get() + ParticleLength) { EntityDespawn.set(0, 1) } FI
	};
};
