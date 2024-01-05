class SiriusHoldEighth: public SiriusHoldTickNote {
	public:

	string name = "Sirius Hold Eighth";

	var updateParallel() {
		return {
			drawHoldEighth(SwitchWithDefault(holdType, {
				{100, Sprites.Hold},
				{101, Sprites.Hold},
				{110, Sprites.Scratch},
				{111, Sprites.Scratch}
			}, Sprites.Hold), lane, enLane, lastBeat, beat),
			IF (times.now > lastBeat) { drawNormalNote(SwitchWithDefault(holdType, {
				{100, Sprites.HoldNote},
				{101, Sprites.HoldNote},
				{110, Sprites.ScratchNote},
				{111, Sprites.ScratchNote}
			}, Sprites.HoldNote), lane, enLane, times.now) } FI,
		};
	}
};
