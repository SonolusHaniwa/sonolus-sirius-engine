using namespace std;

class Options {
    public:
    
    int Mirror = 0;           // Supported
    int NoteSpeed = 1;        // Supported
    int Hidden = 2;
    int SplitRandom = 3;
    int SplitLine = 4;        // Supported
    int SyncLine = 5;         // Supported
    int LockAspectRatio = 6;  // Supported
    int ExtraWidth = 7;
}Options;

auto options = defineOptions<class Options>({
	{
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
