class SiriusScratchHoldStart: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Scratch Hold Start";

	let getSprite() { return Sprites.NormalNoteLeft; }
	let getBucket() { return Buckets.ScratchHoldStart; }
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
