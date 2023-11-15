using namespace std;

class Options {
    public:
    
    int Autoplay = 0;         // Supported
    int Mirror = 1;           // Supported
    int NoteSpeed = 2;        // Supported
    int Hidden = 3;
    int SplitRandom = 4;
    int SplitLine = 5;        // Supported
    int SyncLine = 6;         // Supported
    int LockAspectRatio = 7;  // Supported
    int ExtraWidth = 8;
}Options;

auto options = defineOptions<class Options>({
    {
        name: NameText.AutoPlay,
        scope: Scope,
        standard: 1,
        type: OptionType.Toggle,
        def: 0,
    }, {
        name: NameText.MirrorLevel,
        scope: Scope,
        standard: 0,
        type: OptionType.Toggle,
        def: 0
    }, {
        name: NameText.NoteSpeed,
        scope: Scope,
        standard: 0,
        type: OptionType.Slider,
        def: 5,
        min: 1,
        max: 20,
        step: 0.1,
    }, {
        name: NameText.VerticalStageCover,
        scope: Scope,
        standard: 0,
        type: OptionType.Slider,
        def: 0,
        min: 0,
        max: 1,
        step: 0.05,
        unit: UnitText.Percentage,
    }, {
        name: "Split Random Fall (not implement yet)",
        scope: Scope,
        standard: 0,
        type: OptionType.Toggle,
        def: 0
    }, {
        name: "Split Line Visibility",
        scope: Scope,
        standard: 0,
        type: OptionType.Slider,
        def: 1,
        min: 0,
        max: 1,
        step: 0.05,
        unit: UnitText.Percentage,
    }, {
        name: NameText.SimultaneousLineVisibility,
        scope: Scope,
        standard: 0,
        type: OptionType.Toggle,
        def: 1,
    }, {
        name: NameText.LockStageAspectRatio,
        scope: Scope,
        standard: 0,
        type: OptionType.Toggle,
        def: 1,
	}, {
		name: "Stage Width Multiplier",
		scope: Scope,
		standard: 0,
		type: OptionType.Slider,
		def: 1.0,
		min: 0.5,
		max: 3.0,
		step: 0.05,
		unit: UnitText.Percentage
	}
});
