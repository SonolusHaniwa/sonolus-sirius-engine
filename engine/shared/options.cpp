string scope = "sirius";

class Options {
    public:

    var Mirror = ToggleOption(
        Text.Mirror,
        "",
        false,
        false,
        scope,
        false
    );
    var NoteSpeed = SliderOption(
        Text.NoteSpeed,
        "",
        false,
        false,
        scope,
        5.0,
        1.0,
        25.0,
        0.1,
        ""
    );
    var Speed = SliderOption(
        Text.Speed,
        "",
        true,
        false,
        scope,
        1.0,
        0.5,
        2.0,
        0.05,
        Text.PercentageUnit
    );
    var Hidden = SliderOption(
        Text.StageCoverVertical,
        "",
        false,
        false,
        scope,
        0.0,
        0.0,
        1.0,
        0.05,
        Text.PercentageUnit
    );
    var AutoSFX = ToggleOption(
        Text.EffectAuto,
        "",
        false,
        false,
        scope,
        false
    );
    var SplitRandom = ToggleOption(
        "Split Random Fall (not implement yet)",
        "",
        false,
        false,
        scope,
        false
    );
    var SplitLine = SliderOption(
        "Split Line Visibility",
        "",
        false,
        false,
        scope,
        1.0,
        0.0,
        1.0,
        0.05,
        Text.PercentageUnit
    );
    var SyncLine = ToggleOption(
        Text.SimlineAlpha,
        "",
        false,
        false,
        scope,
        true
    );
    var LockAspectRatio = ToggleOption(
        Text.StageAspectratioLock,
        "",
        false,
        false,
        scope,
        true
    );
    var ExtraWidth = SliderOption(
        "Stage Width Multiplier",
        "",
        false,
        false,
        scope,
        1.0,
        0.5,
        3.0,
        0.05,
        Text.PercentageUnit
    );
    var StageOpacity = SliderOption(
        Text.StageAlpha,
        "",
        false,
        false,
        scope,
        0.8,
        0.0,
        1.0,
        0.05,
        Text.PercentageUnit
    );
    var JudgeType = SelectOption(
        "Show FAST/SLOW",
        "",
        false,
        false,
        scope,
        2,
        {
            "PERFECT and below",
            "GREAT and below",
            "OFF"
        }
    );
    var Accuracy = ToggleOption(
        "Show Accuracy",
        "",
        false,
        false,
        scope,
        false
    );
    var SonolusCombo = ToggleOption(
        "Use Sonolus Combo",
        "",
        false,
        false,
        scope,
        false
    );
    var SonolusJudgment = ToggleOption(
        "Use Sonolus Judgment",
        "",
        false,
        false,
        scope,
        false
    );
    var Lightweight = ToggleOption(
        "Lightweight Particle",
        "",
        false,
        false,
        scope,
        false
    );
}Options;