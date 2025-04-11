Bucket ScratchHoldStartBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Scratch, 0, 0.25, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.ScratchNote, 0, -2.75, 0.0, 2.0, 1.0, 270)
}, Text.MillisecondUnit);

class ScratchHoldStart: public FlatNote {
	public:
	string name = "Sirius Scratch Hold Start";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.NormalNoteLeft; }
	var getBucket() { return ScratchHoldStartBucket; }
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
#undef DISABLE_INTERPRETER
};