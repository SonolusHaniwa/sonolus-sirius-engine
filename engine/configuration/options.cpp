using namespace std;

class Options {
    public:
    
    int Autoplay = 0;
    int Mirror = 1;
    int SplitRandom = 2;
    int NoteSpeed = 3;
    int NoteSize = 4;
    int SyncLine = 5;
    int LockAspectRatio = 6;
    int SplitLine = 7;
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
        name: "Split Random Fall",
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
        name: NameText.NoteSize,
        scope: Scope,
        standard: 0,
        type: OptionType.Slider,
        def: 1,
        min: 0.5,
        max: 2.0,
        step: 0.1,
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
        name: "Split Line Visibility",
        scope: Scope,
        standard: 0,
        type: OptionType.Slider,
        def: 1,
        min: 0,
        max: 1,
        step: 0.01,
        unit: UnitText.Percentage,
    }
});