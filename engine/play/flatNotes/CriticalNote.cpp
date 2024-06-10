class CriticalNote: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Critical Note";

	let getSprite() { return Sprites.CriticalNoteLeft; }
	let getBucket() { return Buckets.CriticalNote; }
	ClipsArray getClips() { return {
		perfect: Clips.Critical,
		great: Clips.Great,
		good: Clips.Good,
		bad: Clips.Bad
	}; }
	EffectsArray getEffects() { return {
		linear: Effects.CriticalLinear,
		circular: Effects.CriticalCircular
	}; };
};
