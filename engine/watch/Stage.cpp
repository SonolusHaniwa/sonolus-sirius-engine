class Stage: public Archetype {
	public:

	static constexpr const char* name = "Sirius Stage";
	bool input = false;
	Variable<EntityMemoryId> firstTime;
	Variable<EntityMemoryId> entityNumber;

	SonolusApi spawnTime() { return -999999; }
	SonolusApi despawnTime() { return 999999; }

	int preprocessOrder = 1;
	SonolusApi preprocess() {
		FUNCBEGIN
		firstTime = firstComboTime.get();
		entityNumber = currentJudgeStartTime.get();
		return VOID;
	}

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

	SonolusApi drawCombo() {
		FUNCBEGIN
		IF (comboNumber <= 0) Return(0); FI
		let comboHeight = If(comboStatus <= 2, comboAPNumberHeight, comboNumberHeight);
		let comboDistance = If(comboStatus <= 2, comboAPNumberDistance, comboNumberDistance);
		let comboHeight2 = If(comboStatus <= 2, comboAPTextHeight, comboTextHeight);
		let comboDistance2 = If(comboStatus <= 2, comboAPTextDistance, comboTextDistance);
		let status = If(comboStatus <= 2, 0, If(comboStatus <= 3, 1, 2));
		let H = comboHeight * ui.comboConfiguration.scale;
		let H2 = comboHeight2 * ui.comboConfiguration.scale;
		var W = -1 * comboDistance, tmpNumber = comboNumber.get();
		let W2 = H2 * Switch(status, {
			{0, comboAPRatio},
			{1, comboFCRatio},
			{2, comboNormalRatio}
		});
		WHILE (tmpNumber) {
			W = W + H * Switch(tmpNumber % 10, {
				{0, SwitchInteger(status, { comboAP0Ratio, comboFC0Ratio, comboNormal0Ratio })},
				{1, SwitchInteger(status, { comboAP1Ratio, comboFC1Ratio, comboNormal1Ratio })},
				{2, SwitchInteger(status, { comboAP2Ratio, comboFC2Ratio, comboNormal2Ratio })},
				{3, SwitchInteger(status, { comboAP3Ratio, comboFC3Ratio, comboNormal3Ratio })},
				{4, SwitchInteger(status, { comboAP4Ratio, comboFC4Ratio, comboNormal4Ratio })},
				{5, SwitchInteger(status, { comboAP5Ratio, comboFC5Ratio, comboNormal5Ratio })},
				{6, SwitchInteger(status, { comboAP6Ratio, comboFC6Ratio, comboNormal6Ratio })},
				{7, SwitchInteger(status, { comboAP7Ratio, comboFC7Ratio, comboNormal7Ratio })},
				{8, SwitchInteger(status, { comboAP8Ratio, comboFC8Ratio, comboNormal8Ratio })},
				{9, SwitchInteger(status, { comboAP9Ratio, comboFC9Ratio, comboNormal9Ratio })}
			}) + comboDistance;
			tmpNumber = Floor(tmpNumber / 10);
		} DONE
        let scale = 0.8 + 0.2 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
        let a = 0.8 + 0.2 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
		W = W * scale; H = H * scale; W2 = W2 * scale; H2 = H2 * scale;
		let cx = screen.w * 0.4;
		var R = cx + W / 2.0; let B = 0.2 - 1 * H / 2.0;
		let L2 = cx - W2 / 2.0; let B2 = 0.2 + H / 2.0 + comboDistance2 * scale;
		tmpNumber = comboNumber.get();
		WHILE (tmpNumber) {
			let L = R - H * Switch(tmpNumber % 10, {
				{0, SwitchInteger(status, { comboAP0Ratio, comboFC0Ratio, comboNormal0Ratio })},
				{1, SwitchInteger(status, { comboAP1Ratio, comboFC1Ratio, comboNormal1Ratio })},
				{2, SwitchInteger(status, { comboAP2Ratio, comboFC2Ratio, comboNormal2Ratio })},
				{3, SwitchInteger(status, { comboAP3Ratio, comboFC3Ratio, comboNormal3Ratio })},
				{4, SwitchInteger(status, { comboAP4Ratio, comboFC4Ratio, comboNormal4Ratio })},
				{5, SwitchInteger(status, { comboAP5Ratio, comboFC5Ratio, comboNormal5Ratio })},
				{6, SwitchInteger(status, { comboAP6Ratio, comboFC6Ratio, comboNormal6Ratio })},
				{7, SwitchInteger(status, { comboAP7Ratio, comboFC7Ratio, comboNormal7Ratio })},
				{8, SwitchInteger(status, { comboAP8Ratio, comboFC8Ratio, comboNormal8Ratio })},
				{9, SwitchInteger(status, { comboAP9Ratio, comboFC9Ratio, comboNormal9Ratio })}
			});
			Draw(Switch(status, {
				{0, Sprites.ComboAP0 + tmpNumber % 10},
				{1, Sprites.ComboFC0 + tmpNumber % 10},
				{2, Sprites.ComboNormal0 + tmpNumber % 10}
			}), L, B, L, B + H, R, B + H, R, B, 1e8, a * ui.comboConfiguration.alpha);
			R = L - comboDistance * scale;
			tmpNumber = Floor(tmpNumber / 10);
		} DONE
		Draw(Switch(status, {
			{0, Sprites.ComboAPText},
			{1, Sprites.ComboFCText},
			{2, Sprites.ComboNormalText}
		}), L2, B2, L2, B2 + H2, L2 + W2, B2 + H2, L2 + W2, B2, 1e8, a * ui.comboConfiguration.alpha);
		return VOID;
	}

	SonolusApi drawAccuracy() {
		FUNCBEGIN
		let a = currentAccuracy / totalAccuracy * 101;
		let b = Floor(a), c = a - Floor(a);
		let scale = ui.comboConfiguration.scale;
		let accuracyHeight = If(comboStatus <= 2, comboAPNumberHeight2, comboNumberHeight2);
		let accuracyDistance = If(comboStatus <= 2, comboAPNumberDistance2, comboNumberDistance2) * scale;
		let accuracyHeight2 = If(comboStatus <= 2, comboAPNumberHeight3, comboNumberHeight3);
		let accuracyDistance2 = If(comboStatus <= 2, comboAPNumberDistance3, comboNumberDistance3) * scale;
		let pointHeight = If(comboStatus <= 2, comboAPPointHeight, comboPointHeight) * scale;
		let percentHeight = If(comboStatus <= 2, comboAPPercentHeight, comboPercentHeight) * scale;
		let distance = If(comboStatus <= 2, comboAPAccuracyDistance, comboAccuracyDistance) * scale;
		let status = If(comboStatus <= 2, 0, If(comboStatus <= 3, 1, 2));
		var W = -1 * accuracyDistance, tmp = b;
		WHILE (tmp) {
			let v = tmp % 10;
			W = W + accuracyHeight * scale * Switch(v, {
				{0, SwitchInteger(status, { comboAP0Ratio, comboFC0Ratio, comboNormal0Ratio })},
				{1, SwitchInteger(status, { comboAP1Ratio, comboFC1Ratio, comboNormal1Ratio })},
				{2, SwitchInteger(status, { comboAP2Ratio, comboFC2Ratio, comboNormal2Ratio })},
				{3, SwitchInteger(status, { comboAP3Ratio, comboFC3Ratio, comboNormal3Ratio })},
				{4, SwitchInteger(status, { comboAP4Ratio, comboFC4Ratio, comboNormal4Ratio })},
				{5, SwitchInteger(status, { comboAP5Ratio, comboFC5Ratio, comboNormal5Ratio })},
				{6, SwitchInteger(status, { comboAP6Ratio, comboFC6Ratio, comboNormal6Ratio })},
				{7, SwitchInteger(status, { comboAP7Ratio, comboFC7Ratio, comboNormal7Ratio })},
				{8, SwitchInteger(status, { comboAP8Ratio, comboFC8Ratio, comboNormal8Ratio })},
				{9, SwitchInteger(status, { comboAP9Ratio, comboFC9Ratio, comboNormal9Ratio })}
			}) + accuracyDistance;
			tmp = Floor(tmp / 10);
		} DONE
		var W1 = W;
		W = W + pointHeight * SwitchInteger(status, { comboAPPointRatio, comboFCPointRatio, comboNormalPointRatio });
		tmp = c; W = W - accuracyDistance2;
		FOR (i, 0, 4, 1) {
			tmp = tmp * 10;
			var v = Floor(tmp);
			tmp = tmp - v;
			W = W + If(i >= 2, accuracyHeight2, accuracyHeight) * scale * Switch(v, {
				{0, SwitchInteger(status, { comboAP0Ratio, comboFC0Ratio, comboNormal0Ratio })},
				{1, SwitchInteger(status, { comboAP1Ratio, comboFC1Ratio, comboNormal1Ratio })},
				{2, SwitchInteger(status, { comboAP2Ratio, comboFC2Ratio, comboNormal2Ratio })},
				{3, SwitchInteger(status, { comboAP3Ratio, comboFC3Ratio, comboNormal3Ratio })},
				{4, SwitchInteger(status, { comboAP4Ratio, comboFC4Ratio, comboNormal4Ratio })},
				{5, SwitchInteger(status, { comboAP5Ratio, comboFC5Ratio, comboNormal5Ratio })},
				{6, SwitchInteger(status, { comboAP6Ratio, comboFC6Ratio, comboNormal6Ratio })},
				{7, SwitchInteger(status, { comboAP7Ratio, comboFC7Ratio, comboNormal7Ratio })},
				{8, SwitchInteger(status, { comboAP8Ratio, comboFC8Ratio, comboNormal8Ratio })},
				{9, SwitchInteger(status, { comboAP9Ratio, comboFC9Ratio, comboNormal9Ratio })}
			}) + If(i >= 1, accuracyDistance2, accuracyDistance);
		} DONE
		W = W + percentHeight * SwitchInteger(status, { comboAPPercentRatio, comboFCPercentRatio, comboNormalPercentRatio });
		W = W + accuracyDistance - accuracyDistance2 / 2;
		let cx = screen.w * 0.4;
		var R = cx - W / 2 + W1;
		var L = R + accuracyDistance / 2;
		let T = 0.2 + If(
			comboStatus <= 2, 
			comboAPNumberHeight / 2.0 + comboAPTextDistance + comboAPTextHeight, 
			comboNumberHeight / 2.0 + comboTextDistance + comboTextHeight
		) * scale + distance;
		tmp = b;
		WHILE (tmp) {
			let v = tmp % 10;
			let w = accuracyHeight * scale * Switch(v, {
				{0, SwitchInteger(status, { comboAP0Ratio, comboFC0Ratio, comboNormal0Ratio })},
				{1, SwitchInteger(status, { comboAP1Ratio, comboFC1Ratio, comboNormal1Ratio })},
				{2, SwitchInteger(status, { comboAP2Ratio, comboFC2Ratio, comboNormal2Ratio })},
				{3, SwitchInteger(status, { comboAP3Ratio, comboFC3Ratio, comboNormal3Ratio })},
				{4, SwitchInteger(status, { comboAP4Ratio, comboFC4Ratio, comboNormal4Ratio })},
				{5, SwitchInteger(status, { comboAP5Ratio, comboFC5Ratio, comboNormal5Ratio })},
				{6, SwitchInteger(status, { comboAP6Ratio, comboFC6Ratio, comboNormal6Ratio })},
				{7, SwitchInteger(status, { comboAP7Ratio, comboFC7Ratio, comboNormal7Ratio })},
				{8, SwitchInteger(status, { comboAP8Ratio, comboFC8Ratio, comboNormal8Ratio })},
				{9, SwitchInteger(status, { comboAP9Ratio, comboFC9Ratio, comboNormal9Ratio })}
			});
			Draw(Switch(status, {
				{0, Sprites.ComboAP0 + v},
				{1, Sprites.ComboFC0 + v},
				{2, Sprites.ComboNormal0 + v}
			}), R - w, T, R - w, T + accuracyHeight * scale, R, T + accuracyHeight * scale, R, T, 1e8, 1);
			R = R - w - accuracyDistance;
			tmp = Floor(tmp / 10);
		} DONE
		let pointWidth = pointHeight * SwitchInteger(status, { comboAPPointRatio, comboFCPointRatio, comboNormalPointRatio });
		Draw(Switch(status, {
			{0, Sprites.ComboAPPoint},
			{1, Sprites.ComboFCPoint},
			{2, Sprites.ComboNormalPoint}
		}), L, T, L, T + pointHeight, L + pointWidth, T + pointHeight, L + pointWidth, T, 1e8, 1);
		L = L + pointWidth + accuracyDistance / 2;
		tmp = c;
		FOR (i, 0, 4, 1) {
			tmp = tmp * 10;
			var v = Floor(tmp);
			tmp = tmp - v;
			let h = If(i >= 2, accuracyHeight2, accuracyHeight);
			let w = h * scale * Switch(v, {
				{0, SwitchInteger(status, { comboAP0Ratio, comboFC0Ratio, comboNormal0Ratio })},
				{1, SwitchInteger(status, { comboAP1Ratio, comboFC1Ratio, comboNormal1Ratio })},
				{2, SwitchInteger(status, { comboAP2Ratio, comboFC2Ratio, comboNormal2Ratio })},
				{3, SwitchInteger(status, { comboAP3Ratio, comboFC3Ratio, comboNormal3Ratio })},
				{4, SwitchInteger(status, { comboAP4Ratio, comboFC4Ratio, comboNormal4Ratio })},
				{5, SwitchInteger(status, { comboAP5Ratio, comboFC5Ratio, comboNormal5Ratio })},
				{6, SwitchInteger(status, { comboAP6Ratio, comboFC6Ratio, comboNormal6Ratio })},
				{7, SwitchInteger(status, { comboAP7Ratio, comboFC7Ratio, comboNormal7Ratio })},
				{8, SwitchInteger(status, { comboAP8Ratio, comboFC8Ratio, comboNormal8Ratio })},
				{9, SwitchInteger(status, { comboAP9Ratio, comboFC9Ratio, comboNormal9Ratio })}
			});
			Draw(Switch(status, {
				{0, Sprites.ComboAP0 + v},
				{1, Sprites.ComboFC0 + v},
				{2, Sprites.ComboNormal0 + v}
			}), L, T, L, T + h * scale, L + w, T + h * scale, L + w, T, 1e8, 1);
			L = L + w + If(i >= 1, accuracyDistance2, accuracyDistance);
		} DONE
		L = L - accuracyDistance2 / 2;
		let percentWidth = percentHeight * SwitchInteger(status, { comboAPPercentRatio, comboFCPercentRatio, comboNormalPercentRatio });
		Draw(Switch(status, {
			{0, Sprites.ComboAPPercent},
			{1, Sprites.ComboFCPercent},
			{2, Sprites.ComboNormalPercent}
		}), L, T, L, T + percentHeight, L + percentWidth, T + percentHeight, L + percentWidth, T, 1e8, 1);
		return VOID;
	}

    SonolusApi updateParallel() {
    	FUNCBEGIN
        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1);
	    Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, opacity);
		IF (LevelOption.get(Options.Hidden) != 0) drawHiddenLine(); FI
		Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1);
		IF (!sonolusJudgment) drawJudgeText(); FI
		IF (!sonolusCombo) drawCombo(); FI
		IF (showAccuracy && HasSkinSprite(Sprites.ComboNormal0)) drawAccuracy(); FI
		return VOID;
    }

	int updateSequentialOrder = 2;
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (times.now < firstTime) {
			comboNumber = 0;
			comboStatus = 0;
			currentAccuracy = totalAccuracy.get();
			currentJudge = 0;
			currentJudgeStartTime = 0;
			currentJudgeDeltaTime = 9999;
		} FI
		/*IF (!times.skip) Return(0); FI
		currentJudge.set(0);
		currentJudgeStartTime.set(0);
        currentJudgeDeltaTime.set(0);
        comboNumber = 0;*/
        lastUpdatedId = 0;
		return VOID;
	}
};
