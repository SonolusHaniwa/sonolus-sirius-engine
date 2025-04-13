Bucket CriticalScratchHoldStartBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Scratch, 0, 0.25, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.CriticalNote, 0, -2.75, 0.0, 2.0, 1.0, 270)
}, Text.MillisecondUnit);

class CriticalScratchHoldStart: public FlatNote {
	public:
	string name = "Sirius Critical Scratch Hold Start";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.CriticalNoteLeft; }
	var getBucket() { return CriticalScratchHoldStartBucket; }
    ClipsArray getClips() { return {
		perfect: Clips.Critical,
		great: Clips.Great,
		good: Clips.Good,
		bad: Clips.Bad
    }; }
    EffectsArray getEffects() { return {
    	linear: Effects.CriticalLinear,
    	circular: Effects.CriticalCircular,
    }; }
#undef DISABLE_INTERPRETER
};
