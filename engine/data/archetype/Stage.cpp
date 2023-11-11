class Stage: public Archetype {
    public:

    string name = "Sirius Stage";
    bool input = false;
	Variable<EntityMemoryId> comboWidth;
	Variable<EntityMemoryId> comboTemp;
	Variable<EntityMemoryId> comboDrawR;

    var spawnOrder() { return 2; }

    var shouldSpawn() { return 1; }

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

	var getComboRatio(var type, var number) {
		return Switch(type, {
			{0, Switch(number, {
				{0, comboAP0Ratio},
				{1, comboAP1Ratio},
				{2, comboAP2Ratio},
				{3, comboAP3Ratio},
				{4, comboAP4Ratio},
				{5, comboAP5Ratio},
				{6, comboAP6Ratio},
				{7, comboAP7Ratio},
				{8, comboAP8Ratio},
				{9, comboAP9Ratio}
			})},
			{1, Switch(number, {
				{0, comboFC0Ratio},
				{1, comboFC1Ratio},
				{2, comboFC2Ratio},
				{3, comboFC3Ratio},
				{4, comboFC4Ratio},
				{5, comboFC5Ratio},
				{6, comboFC6Ratio},
				{7, comboFC7Ratio},
				{8, comboFC8Ratio},
				{9, comboFC9Ratio}
			})},
			{2, Switch(number, {
				{0, combo0Ratio},
				{1, combo1Ratio},
				{2, combo2Ratio},
				{3, combo3Ratio},
				{4, combo4Ratio},
				{5, combo5Ratio},
				{6, combo6Ratio},
				{7, combo7Ratio},
				{8, combo8Ratio},
				{9, combo9Ratio}
			})}
		});
	}

	var getComboText(var type) {
		return Switch(type, {
			{0, Sprites.ComboAP},
			{1, Sprites.ComboFC},
			{2, Sprites.Combo}
		});
	}

	var getComboNumber(var type, var number) {
		return Switch(type, {
			{0, Switch(number, {
				{0, Sprites.ComboAP0},
				{1, Sprites.ComboAP1},
				{2, Sprites.ComboAP2},
				{3, Sprites.ComboAP3},
				{4, Sprites.ComboAP4},
				{5, Sprites.ComboAP5},
				{6, Sprites.ComboAP6},
				{7, Sprites.ComboAP7},
				{8, Sprites.ComboAP8},
				{9, Sprites.ComboAP9}
			})},
			{1, Switch(number, {
				{0, Sprites.ComboFC0},
				{1, Sprites.ComboFC1},
				{2, Sprites.ComboFC2},
				{3, Sprites.ComboFC3},
				{4, Sprites.ComboFC4},
				{5, Sprites.ComboFC5},
				{6, Sprites.ComboFC6},
				{7, Sprites.ComboFC7},
				{8, Sprites.ComboFC8},
				{9, Sprites.ComboFC9}
			})},
			{2, Switch(number, {
				{0, Sprites.Combo0},
				{1, Sprites.Combo1},
				{2, Sprites.Combo2},
				{3, Sprites.Combo3},
				{4, Sprites.Combo4},
				{5, Sprites.Combo5},
				{6, Sprites.Combo6},
				{7, Sprites.Combo7},
				{8, Sprites.Combo8},
				{9, Sprites.Combo9}
			})}
		});
	}

	var drawCombo() {
		var combo = currentCombo.get();
		var type = comboType.get();
        var scale = 0.4 + 0.6 * (Min(1, (times.now - currentComboStartTime.get()) / comboDuration));
        var a = 0.4 + 0.6 * (Min(1, (times.now - currentComboStartTime.get()) / comboDuration));
		var h = (comboTextHeight + comboNumberHeight) * scale;
		var tL = screen.w * 0.4 - comboTextHeight * Switch(type, {{0, comboAPRatio}, {1, comboFCRatio}, {2, comboRatio}}) / 2 * scale;
		var tR = screen.w * 0.4 + comboTextHeight * Switch(type, {{0, comboAPRatio}, {1, comboFCRatio}, {2, comboRatio}}) / 2 * scale;
		var tB = 0 - h / 2 * scale;
		var tT = tB + comboTextHeight * scale;
		var nB = tT;
		var nT = nB + comboNumberHeight * scale;
		return Block(Execute({
			IF (combo == 0) { Break(1, 0) } FI,
			comboTemp.set(combo),
			comboWidth.set(0),
			While(comboTemp.get() > 0, {
				comboWidth.set(comboWidth.get() + getComboRatio(type, comboTemp.get() % 10)),
				comboTemp.set(Floor(comboTemp.get() / 10))
			}),
			comboWidth.set(comboWidth.get() * comboNumberHeight * scale),
			comboDrawR.set(screen.w * 0.4 + comboWidth.get() / 2),
			Draw(getComboText(type), tL, tB, tL, tT, tR, tT, tR, tB, 1e8, a),
			comboTemp.set(combo),
			While(comboTemp.get() > 0, {
				Draw(getComboNumber(type, comboTemp.get() % 10), 
					comboDrawR.get() - getComboRatio(type, comboTemp.get() % 10) * comboNumberHeight * scale, nB, 
					comboDrawR.get() - getComboRatio(type, comboTemp.get() % 10) * comboNumberHeight * scale, nT, 
					comboDrawR.get(), nT, 
					comboDrawR.get(), nB, 
					1e8, a),
				comboDrawR.set(comboDrawR.get() - getComboRatio(type, comboTemp.get() % 10) * comboNumberHeight * scale),
				comboTemp.set(Floor(comboTemp.get() / 10))
			})
		}));
	}

    var updateSequential() {
		return {
	        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1),
		    Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, 0.6),
			IF (LevelOption.get(Options.Hidden) != 0) { drawHiddenLine() } FI, 
			Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1),
			drawJudgeText(),
			// drawCombo()
		};
	}

    int touchOrder = 10000;
	var playStageParticle(Touch touch) {
		vector<var> args;
		for (int i = 1; i <= 12; i++) {
			args.push_back(Execute({
				IF (lines.inClickBox(touch, i, i, true)) {
					spawnLineEffect(i, i)
				} FI
			}));
		}; return Execute(args);
	}

    var touch() {
		return {
			IF (LevelOption.get(Options.Autoplay)) { Return(0) } FI,
			FOR (i, 0, touches.size, 1) {
			    IF (touches[i].started == false) { CONTINUE } FI,
			    IF (lines.inClickBox(touches[i], 1, 12) == false) { CONTINUE } FI,
			    IF (isUsed(touches[i])) { CONTINUE } FI,
			    markAsUsed(touches[i]),
			    Play(Clips.Stage, minSFXDistance),
				playStageParticle(touches[i])
			} DONE
		};
	}
};
