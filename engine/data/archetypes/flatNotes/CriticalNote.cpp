class CriticalNote: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Critical Note";

	let getSprite() { return Sprites.CriticalNote; }
	ClipsArray getClips() { return {
		perfect: Clips.CriticalPerfect,
		great: Clips.CriticalPerfect,
		good: Clips.Good
	}; }
	EffectsArray getEffects() { return {
		linear: Effects.CriticalLinear,
		circular: Effects.CriticalCircular
	}; };
};
