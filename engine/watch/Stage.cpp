class Stage: public Archetype {
	public:

	static constexpr const char* name = "Sirius Stage";
	bool input = false;

	SonolusApi spawnTime() { return -999999; }
	SonolusApi despawnTime() { return 999999; }

    SonolusApi drawJudgeText() {
    	FUNCBEGIN
		let H = judgeTextHeight * ui.judgmentConfiguration.scale;
		let H2 = judgeText2Height * ui.judgmentConfiguration.scale;
		let D = judgeTextDistance * ui.judgmentConfiguration.scale;
        let T = H / 2.0, B = -1 * T;
		let B2 = T + D, T2 = B2 + H2;
        let W = H * SwitchWithDefault(currentJudge.get(), {
            {Sprites.JudgePerfectPlus, judgePerfectPlusRatio},
            {Sprites.JudgePerfect, judgePerfectRatio},
            {Sprites.JudgeGreat, judgeGreatRatio},
            {Sprites.JudgeGood, judgeGoodRatio},
            {Sprites.JudgeBad, judgeBadRatio},
            {Sprites.JudgeMiss, judgeMissRatio},
            {Sprites.JudgeAuto, judgeAutoRatio}
        }, 0);
		let W2 = H2 * If(currentJudgeDeltaTime < 0, judgeFastRatio, judgeSlowRatio);
        let R = W / 2.0, L = -1 * R;
		let R2 = W2 / 2.0, L2 = -1 * R2;
        let scale = 0.6 + 0.4 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
        let a = 0.6 + 0.4 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
        L *= scale, R *= scale, T *= scale, B *= scale;
		L2 *= scale, R2 *= scale, T2 *= scale, B2 *= scale;
        Draw(currentJudge.get(), L, B, L, T, R, T, R, B, 1e8, a * ui.judgmentConfiguration.alpha);
		IF (Abs(currentJudgeDeltaTime) > Switch(judgeType, {
				{0, judgment.perfectPlus},
				{1, judgment.perfect},
				{2, judgment.bad}
			}) && Abs(currentJudgeDeltaTime) <= judgment.bad) {
			Draw(If(currentJudgeDeltaTime < 0, Sprites.JudgeFast, Sprites.JudgeSlow), 
				L2, B2, L2, T2, R2, T2, R2, B2, 1e8, a * ui.judgmentConfiguration.alpha); 
		} FI
        return VOID;
    }

    SonolusApi updateParallel() {
    	FUNCBEGIN
        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1);
	    Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, opacity);
		IF (LevelOption.get(Options.Hidden) != 0) drawHiddenLine(); FI
		Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1);
		drawJudgeText();
		return VOID;
    }

	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (!times.skip) Return(0); FI
		currentJudge.set(0);
		currentJudgeStartTime.set(0);
        currentJudgeDeltaTime.set(0);
		return VOID;
	}
};
