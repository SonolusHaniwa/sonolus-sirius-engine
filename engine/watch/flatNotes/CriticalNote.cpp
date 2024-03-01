class CriticalNote: public FlatNote {
	public:

	static constexpr const char* name = "Sirius Critical Note";

	let getSprite() { return Sprites.CriticalNote; }
	let getClip() { return Clips.CriticalPerfect; }
	EffectsArray getEffects() {
		return {
			linear: Effects.CriticalLinear,
			circular: Effects.CriticalCircular
		};
	}
};
