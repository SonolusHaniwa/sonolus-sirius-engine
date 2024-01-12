class NormalNote: public FlatNote {
	public:

	static constexpr const char* name = "Sirius Normal Note";

	let getSprite() { return Sprites.NormalNote; }
	let getClip() { return Clips.Perfect; }
	EffectsArray getEffects() {
		return {
			linear: Effects.NormalLinear,
			circular: Effects.NormalCircular
		};
	}
};
