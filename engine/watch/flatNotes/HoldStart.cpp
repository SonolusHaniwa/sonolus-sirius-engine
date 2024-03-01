class SiriusHoldStart: public FlatNote {
	public:

	static constexpr const char* name = "Sirius Hold Start";

	let getSprite() { return Sprites.HoldNote; }
	let getClip() { return Clips.Perfect; }
	EffectsArray getEffects() {
		return {
			linear: Effects.HoldLinear,
			circular: Effects.HoldCircular
		};
	}
};
