Bucket CriticalNoteBucket = defineBucket({
	EngineDataBucketSprite(Sprites.CriticalNote, 0, 0.0, 0.0, 2.0, 1.0, 270)
}, Text.MillisecondUnit);

class CriticalNote: public FlatNote {
	public:
	string name = "Sirius Critical Note";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.CriticalNoteLeft; }
	var getBucket() { return CriticalNoteBucket; }
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
#undef DISABLE_INTERPRETER
};
