Bucket NormalNoteBucket = defineBucket({
    EngineDataBucketSprite(Sprites.NormalNote, 0, 0.0, 0.0, 2.0, 1.0, 270)
}, Text.MillisecondUnit);

class NormalNote: public FlatNote {
    public:
    string name = "Sirius Normal Note";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.NormalNoteLeft; }
	var getBucket() { return NormalNoteBucket; }
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