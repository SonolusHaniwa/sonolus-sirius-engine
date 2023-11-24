class SiriusScratchHoldStart: public SiriusFlatNote {
	public:

	string name = "Sirius Scratch Hold Start";

	var getClip() { return Clips.Perfect; }
	var getLinearEffect() { return Effects.ScratchLinear; }
	var getCircularEffect() { return Effects.ScratchCircular; }

	var updateParallel() {
		return {
			drawNormalNote(Sprites.ScratchNote, lane, enLane, beat)
		};
	}
};
