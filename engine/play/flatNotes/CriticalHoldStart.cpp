class SiriusCriticalHoldStart: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Critical Hold Start";

	let getSprite() { return Sprites.CriticalNote; }
	let getBucket() { return Buckets.CriticalHoldStart; }
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
