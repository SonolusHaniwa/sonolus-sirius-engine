const var RedTapType = 0;
const var RedTapDuration = 0.5;
const var JudgelineTopHeight = 0.015;
const var JudgelineBottomHeight = 0.05;

class ParticleFactory {
	public:
	
	Variable<EntityMemoryId> type;
	Variable<EntityMemoryId> start;
	Variable<EntityMemoryId> dat[4];
	Variable<EntityMemoryId> duration;
	Variable<EntityMemoryId> isLooped;
	
	var SpawnRedTap(var lane, var enLane) {
		return Execute({
			type.set(RedTapType),
			start.set(times.now),
			dat[0].set(lane),
			dat[1].set(enLane),
			duration.set(RedTapDuration),
			isLooped.set(0)
		});
	}

	var Run() {
		return Execute({
			Switch(type.get(), {
				{RedTapType, Run_RedTap()}
			})
		});
	}

	private: 
	var Run_RedTap() {
		var lane = dat[0].get(), enLane = dat[1].get();
		var wt = judgline.rtX - judgline.ltX, wb = judgline.rbX - judgline.lbX;
		var lbx = (lane - 1) / 12 * wb + judgline.lbX, lby = judgline.lbY;
		var ltx = (lane - 1) / 12 * wt + judgline.ltX, lty = judgline.ltY;
		var rtx = enLane / 12 * wt + judgline.ltX, rty = lty;
		var rbx = enLane / 12 * wb + judgline.lbX, rby = lby;
		var mt = JudgelineTopHeight / 2, mb = JudgelineBottomHeight / 2;
		return Block(Execute({
			IF (start.get() + RedTapDuration < times.now) { Break(1, 0) } FI,
			Draw(Sprites.HorizontalLine, ltx, lty - 2 * mt, ltx, lty, rtx, rty, rtx, rty - 2 * mt, 1e6, 1 - (times.now - start.get()) / duration.get())
		}));
	}
}ParticleFactory;
