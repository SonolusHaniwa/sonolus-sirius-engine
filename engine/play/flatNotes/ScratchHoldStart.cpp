class SiriusScratchHoldStart: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Scratch Hold Start";

	let getSprite() { return Sprites.NormalNote; }
	let getBucket() { return Buckets.ScratchHoldStart; }
    ClipsArray getClips() { return {
    	perfect: Clips.Perfect,
    	great: Clips.Perfect,
    	good: Clips.Good
    }; }
    EffectsArray getEffects() { return {
    	linear: Effects.ScratchLinear,
    	circular: Effects.ScratchCircular,
    }; }
};
