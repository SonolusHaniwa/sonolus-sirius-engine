class NormalNote: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Normal Note";

	let getSprite() { return Sprites.NormalNoteLeft; }
	let getBucket() { return Buckets.NormalNote; }
    ClipsArray getClips() { return {
		perfect: Clips.Perfect,
		great: Clips.Great,
		good: Clips.Good,
		bad: Clips.Bad
    }; }
    EffectsArray getEffects() { return {
    	linear: Effects.NormalLinear,
    	circular: Effects.NormalCircular,
    }; }
};
