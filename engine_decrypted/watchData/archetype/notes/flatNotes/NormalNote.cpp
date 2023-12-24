class SiriusNormalNote: public SiriusFlatNote {
	public:

	string name = "Sirius Normal Note";

	var getClip() { return Clips.Perfect; }
	var getLinearEffect() { return Effects.NormalLinear; }
	var getCircularEffect() { return Effects.NormalCircular; }

	var updateParallel() {
		return {
			drawNormalNote(Sprites.NormalNote, lane, enLane, beat)
		};
	}
};
