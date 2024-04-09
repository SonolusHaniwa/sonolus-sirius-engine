class NormalNote: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Normal Note";

	let getSprite() { return Sprites.NormalNote; }
	let getBucket() { return Buckets.NormalNote; }
    ClipsArray getClips() { return {
    	perfect: Clips.Perfect,
    	great: Clips.Perfect,
    	good: Clips.Good
    }; }
    EffectsArray getEffects() { return {
    	linear: Effects.NormalLinear,
    	circular: Effects.NormalCircular,
    }; }
};
