class SiriusHoldStart: public SiriusFlatNote {
	public:

	string name = "Sirius Hold Start";

	var getClip() { return Clips.Perfect; }
	var getLinearEffect() { return Effects.HoldLinear; }
	var getCircularEffect() { return Effects.HoldCircular; }

	var updateParallel() {
		return {
			drawNormalNote(Sprites.HoldNote, lane, enLane, beat)
		};
	}
};
