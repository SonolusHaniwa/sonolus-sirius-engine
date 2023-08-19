class Stage: public Archetype {
    public:

    string name = "Sirius Stage";
    bool input = false;

    var spawnOrder = 2;

    var shouldSpawn = 1;

    var drawJudgeline() {
        // 需要微调
        var moveLength = 0.01;
        var lbX = Lerp(stage.l, stage.l * highWidth, judgelineMarginBottom) - moveLength;
        var lbY = stage.b + stage.h * judgelineMarginBottom;
        var ltX = Lerp(stage.l, stage.l * highWidth, judgelineMarginBottom + judgelineHeight / stage.h) - moveLength;
        var ltY = lbY + judgelineHeight;
        var rbX = Lerp(stage.r, stage.r * highWidth, judgelineMarginBottom) + moveLength;
        var rbY = lbY;
        var rtX = Lerp(stage.r, stage.r * highWidth, judgelineMarginBottom + judgelineHeight / stage.h) + moveLength;
        var rtY = ltY;
        return Draw(Sprites.Judgeline, lbX, lbY, ltX, ltY, rtX, rtY, rbX, rbY, 3, 1);
    }

    var updateSequential = {
        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1),
        Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, 0.6),
        drawJudgeline(),
    }; 
};