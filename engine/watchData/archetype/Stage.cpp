class Stage: public Archetype {
	public:

	string name = "Sirius Stage";
	bool input = false;

	var spawnTime() { return -999999; }
	var despawnTime() { return 999999; }

	var drawJudgeText() {
        var T = judgeTextHeight / 2.0, B = -1 * T;
        var W = judgeTextHeight * SwitchWithDefault(currentJudge.get(), {
            {Sprites.JudgePerfectPlus, judgePerfectPlusRatio},
            {Sprites.JudgePerfect, judgePerfectRatio},
            {Sprites.JudgeGreat, judgeGreatRatio},
            {Sprites.JudgeGood, judgeGoodRatio},
            {Sprites.JudgeBad, judgeBadRatio},
            {Sprites.JudgeMiss, judgeMissRatio},
            {Sprites.JudgeAuto, judgeAutoRatio}
        }, 0);
        var R = W / 2.0, L = -1 * R;
        var scale = 0.4 + 0.6 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
        var a = 0.4 + 0.6 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
        L *= scale, R *= scale, T *= scale, B *= scale;
        return Draw(currentJudge.get(), L, B, L, T, R, T, R, B, 1e8, a);
    }

    var updateParallel() {
		return {
	        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1),
		    Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, 0.6),
			IF (LevelOption.get(Options.Hidden) != 0) { drawHiddenLine() } FI, 
			Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1),
			drawJudgeText()
		};
	}

	var updateSequential() {
		return {
			IF (!times.skip) { Return(0) } FI,
			currentJudge.set(0),
			currentJudgeStartTime.set(0)
		};
	}
};
