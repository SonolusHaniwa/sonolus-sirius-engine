Bucket HoldStartBucket = defineBucket({
	EngineDataBucketSprite(Sprites.Hold, 0, 0.25, 0.0, 1.8, 6.0, 270),
	EngineDataBucketSprite(Sprites.HoldNote, 0, -2.75, 0.0, 2.0, 1.0, 270)
}, Text.MillisecondUnit);

class HoldStart: public FlatNote {
	public:
	string name = "Sirius Hold Start";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.HoldNoteLeft; }
	var getBucket() { return HoldStartBucket; }
    ClipsArray getClips() { return {
		perfect: Clips.Perfect,
		great: Clips.Great,
		good: Clips.Good,
		bad: Clips.Bad
    }; }
    EffectsArray getEffects() { return {
    	linear: Effects.HoldLinear,
    	circular: Effects.HoldCircular,
    }; }
#undef DISABLE_INTERPRETER
};
