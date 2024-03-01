class SiriusScratchHoldStart: public FlatNote {
	public:

	static constexpr const char* name = "Sirius Scratch Hold Start";

	let getSprite() { return Sprites.ScratchNote; }
	let getClip() { return Clips.Perfect; }
	EffectsArray getEffects() {
		return {
			linear: Effects.ScratchLinear,
			circular: Effects.ScratchCircular
		};
	}
};
