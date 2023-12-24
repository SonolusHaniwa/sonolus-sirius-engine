class SiriusFlickNote: public SiriusFlatNote {
	public:

	string name = "Sirius Flick Note";

	var getClip() { return Clips.Scratch; }
	var getLinearEffect() { return Effects.ScratchLinear; }
	var getCircularEffect() { return Effects.ScratchCircular; }

	var updateParallel() {
		return {
	        drawNormalNote(Sprites.ScratchNote, lane, enLane, beat),
		    drawArrow(lane, enLane, beat),
		};
	}
};
