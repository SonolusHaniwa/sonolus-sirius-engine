class SiriusSound: public SiriusHoldTickNote {
	public:

	string name = "Sirius Sound";

	var preprocess() {
		return {
			SiriusHoldTickNote::preprocess(),
			PlayScheduled(Clips.Sound, beat, minSFXDistance)
		};
	}

	var updateParallel() {
		return {
			drawHoldEighth(SwitchWithDefault(holdType, {
				{100, Sprites.Hold},
				{101, Sprites.Hold},
				{110, Sprites.Scratch},
				{111, Sprites.Scratch}
			}, Sprites.Hold), lane, enLane, lastBeat, beat),
			drawTick(SwitchWithDefault(holdType, {
                {100, Sprites.TouchTick},
                {101, Sprites.TouchTick},
                {110, Sprites.TouchScratchTick},
                {111, Sprites.TouchScratchTick}
            }, Sprites.TouchTick), beat, lane, enLane),
			IF (times.now > lastBeat) { drawNormalNote(SwitchWithDefault(holdType, {
				{100, Sprites.HoldNote},
				{101, Sprites.HoldNote},
				{110, Sprites.ScratchNote},
				{111, Sprites.ScratchNote}
			}, Sprites.HoldNote), lane, enLane, times.now) } FI,
		};
	}
};
