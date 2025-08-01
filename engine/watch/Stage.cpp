SonolusApi getValue(var index) {
    if (EntityInfoArray[index].archetype == getAid(HoldEnd) || EntityInfoArray[index].archetype == getAid(Sound)) 
        return EntityDataArray[index].generic[0] + EntityDataArray[index].generic[5];
    else if (EntityInfoArray[index].archetype == getAid(ScratchHoldEnd) || EntityInfoArray[index].archetype == getAid(FlickNote))
        return EntityDataArray[index].generic[0] + EntityDataArray[index].generic[6];
    else return EntityDataArray[index].generic[0] + EntityDataArray[index].generic[4];
}

#ifndef COMPILE_RUNTIME
SonolusApi calcCombo(){}
#endif

class Stage: public Archetype {
	public:

	string name = "Sirius Stage";
	bool input = false;
	var firstTime;
	var entityNumber;
    var headNoteId;
    var noteNumber;
	defineImport(order0);
	defineImport(order1);
	defineImport(order2);
	defineImport(order3);
	defineImport(order4);
	defineImport(order5);
	defineImport(order6);
	defineImport(order7);
	defineImport(order8);
	defineImport(order9);
	defineImport(order10);
	defineImport(order11);
	defineImport(order12);
	defineImport(order13);
	defineImport(order14);
	defineImport(order15);
	defineImport(order16);
	defineImport(order17);
	defineImport(order18);
	defineImport(order19);
	defineImport(order20);

	SonolusApi spawnTime() { return -999999; }
	SonolusApi despawnTime() { return 999999; }

#define DISABLE_INTERPRETER
    // Inplemented in Preprocess.cpp
    SonolusApi calcCombo(string, string, int, int, string);
    SonolusApi calcCombo();
#undef DISABLE_INTERPRETER

	int preprocessOrder = -2;
	SonolusApi preprocess() {
		calcCombo();
        var head = headNoteId;
		totalAccuracy = noteNumber * 1.01;
        // cout << lastClickMenuTime << " " << headNoteId << " " << noteNumber << endl;
		// DebugLog(headNoteId); DebugLog(noteNumber); DebugLog(1);
        if (replay) {
            for (var i = 0; i < noteNumber; i++) {
				var judgeResult = 0;
				if (EntityInfoArray[head].archetype == getAid(HoldEnd) || EntityInfoArray[head].archetype == getAid(Sound) || EntityInfoArray[head].archetype == getAid(FlickNote)) 
					judgeResult = EntityDataArray[head].generic[4];
				else if (EntityInfoArray[head].archetype == getAid(ScratchHoldEnd)) judgeResult = EntityDataArray[head].generic[5];
				else judgeResult = EntityDataArray[head].generic[3];
				if (judgeResult <= 3 && judgeResult >= 1) comboNumber = comboNumber + 1;
				else comboNumber = 0;
	        	EntitySharedMemoryArray[head].generic[0] = comboNumber;
	        	comboStatus = Max(comboStatus, If(judgeResult == 0, 6, judgeResult));
	        	EntitySharedMemoryArray[head].generic[1] = comboStatus;
				EntitySharedMemoryArray[head].generic[2] = getValue(EntitySharedMemoryArray[head].generic[31]);
				if (judgeResult == 0) currentAccuracy = currentAccuracy - 1.01;
				if (judgeResult == 1) currentAccuracy = currentAccuracy;
				if (judgeResult == 2) currentAccuracy = currentAccuracy - 0.01;
				if (judgeResult == 3) currentAccuracy = currentAccuracy - 0.21;
				if (judgeResult == 4) currentAccuracy = currentAccuracy - 0.51;
				EntitySharedMemoryArray[head].generic[3] = currentAccuracy;
	        	head = EntitySharedMemoryArray[head].generic[31];
	        }
        } else {
            for (var i = 0; i < noteNumber; i++) {
	        	comboNumber++;
	        	EntitySharedMemoryArray[head].generic[0] = comboNumber;
	        	comboStatus = Max(comboStatus, 0);
	        	EntitySharedMemoryArray[head].generic[1] = comboStatus;
				EntitySharedMemoryArray[head].generic[2] = getValue(EntitySharedMemoryArray[head].generic[31]);
				currentAccuracy -= 0;
				EntitySharedMemoryArray[head].generic[3] = currentAccuracy;
	        	head = EntitySharedMemoryArray[head].generic[31];
	        }
	    }

		if (replay) {
			for (var i = 0; i < 21; i++) order[i] = EntityData[i];
		} else {
			for (var i = 0; i < 1; i++) order[i] = i + 1;
			for (var i = 1; i < 3; i++) order[i] = i;
			for (var i = 3; i < 6; i++) order[i] = i - 2;
			for (var i = 6; i < 10; i++) order[i] = i - 5;
			for (var i = 10; i < 15; i++) order[i] = i - 9;
			for (var i = 15; i < 21; i++) order[i] = i - 14;
			if (splitRandom) {
				randomShuffle(order, 0, 1);
				randomShuffle(order, 1, 3);
				randomShuffle(order, 3, 6);
				randomShuffle(order, 6, 10);
				randomShuffle(order, 10, 15);
				randomShuffle(order, 15, 21);
			}
		}
		entityCount = 0;
		while (EntityInfoArray[entityCount].index == entityCount) entityCount++;
	}

	SonolusApi initialize() {
		firstTime = firstComboTime;
		entityNumber = currentJudgeStartTime;
	}

    SonolusApi drawJudgeText() {
		var H = judgeTextHeight * configuration.judgment.scale;
		var H2 = judgeText2Height * configuration.judgment.scale;
		var D = judgeTextDistance * configuration.judgment.scale;
        var T = H / 2.0, B = -1 * T;
		var B2 = T + D, T2 = B2 + H2;
        var W = H * SwitchWithDefault(currentJudge, {
            {Sprites.JudgePerfectPlus, judgePerfectPlusRatio},
            {Sprites.JudgePerfect, judgePerfectRatio},
            {Sprites.JudgeGreat, judgeGreatRatio},
            {Sprites.JudgeGood, judgeGoodRatio},
            {Sprites.JudgeBad, judgeBadRatio},
            {Sprites.JudgeMiss, judgeMissRatio},
            {Sprites.JudgeAuto, judgeAutoRatio}
        }, 0);
		var W2 = H2 * If(currentJudgeDeltaTime < 0, judgeFastRatio, judgeSlowRatio);
        var R = W / 2.0, L = -1 * R;
		var R2 = W2 / 2.0, L2 = -1 * R2;
        var scale = 0.6 + 0.4 * EaseInSine(Min(1, (times.now - currentJudgeStartTime) / judgeTextDuration));
        var a = 0.6 + 0.4 * EaseInSine(Min(1, (times.now - currentJudgeStartTime) / judgeTextDuration));
        L *= scale, R *= scale, T *= scale, B *= scale;
		L2 *= scale, R2 *= scale, T2 *= scale, B2 *= scale;
        Draw(currentJudge, { L, B }, { L, T }, { R, T }, { R, B }, 1e8, a * configuration.judgment.alpha);
		if (
			Abs(currentJudgeDeltaTime) > Switch(judgeType, {
				{0, judgment.perfectPlus},
				{1, judgment.perfect},
				{2, judgment.bad}
			}) && Abs(currentJudgeDeltaTime) <= judgment.bad && 
			currentJudge != Sprites.JudgeMiss
		) {
			Draw(
				If(currentJudgeDeltaTime < 0, Sprites.JudgeFast, Sprites.JudgeSlow), 
				{ L2, B2 }, 
				{ L2, T2 }, 
				{ R2, T2 }, 
				{ R2, B2 }, 
				1e8, 
				a * configuration.judgment.alpha
			); 
		}
    }

	SonolusApi drawCombo() {
		if (comboNumber <= 0) return 0;
		var comboHeight = If(comboStatus <= 2, comboAPNumberHeight, comboNumberHeight);
		var comboDistance = If(comboStatus <= 2, comboAPNumberDistance, comboNumberDistance);
		var comboHeight2 = If(comboStatus <= 2, comboAPTextHeight, comboTextHeight);
		var comboDistance2 = If(comboStatus <= 2, comboAPTextDistance, comboTextDistance);
		var status = If(comboStatus <= 2, 0, If(comboStatus <= 3, 1, 2));
		var H = comboHeight * configuration.combo.scale;
		var H2 = comboHeight2 * configuration.combo.scale;
		var W = -1 * comboDistance, tmpNumber = comboNumber;
		var W2 = H2 * Switch(status, {
			{0, comboAPRatio},
			{1, comboFCRatio},
			{2, comboNormalRatio}
		});
		while (tmpNumber) {
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
		}
        var scale = 0.8 + 0.2 * EaseInSine(Min(1, (times.now - currentJudgeStartTime) / judgeTextDuration));
        var a = 0.8 + 0.2 * EaseInSine(Min(1, (times.now - currentJudgeStartTime) / judgeTextDuration));
		W = W * scale; H = H * scale; W2 = W2 * scale; H2 = H2 * scale;
		var cx = screen.w * 0.4;
		var R = cx + W / 2.0; var B = 0.2 - 1 * H / 2.0;
		var L2 = cx - W2 / 2.0; var B2 = 0.2 + H / 2.0 + comboDistance2 * scale;
		tmpNumber = comboNumber;
		while (tmpNumber) {
			var L = R - H * Switch(tmpNumber % 10, {
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
			Draw(
				Switch(status, {
					{0, Sprites.ComboAP0 + tmpNumber % 10},
					{1, Sprites.ComboFC0 + tmpNumber % 10},
					{2, Sprites.ComboNormal0 + tmpNumber % 10}
				}), 
				{ L, B },
				{ L, B + H }, 
				{ R, B + H }, 
				{ R, B }, 
				1e8, 
				a * configuration.combo.alpha
			);
			R = L - comboDistance * scale;
			tmpNumber = Floor(tmpNumber / 10);
		}
		Draw(
			Switch(status, {
				{0, Sprites.ComboAPText},
				{1, Sprites.ComboFCText},
				{2, Sprites.ComboNormalText}
			}), 
			{ L2, B2 }, 
			{ L2, B2 + H2 }, 
			{ L2 + W2, B2 + H2 }, 
			{ L2 + W2, B2 }, 
			1e8, 
			a * configuration.combo.alpha
		);
	}

	SonolusApi drawAccuracy() {
		if (totalAccuracy <= 0) return;
		var a = currentAccuracy / totalAccuracy * 101;
		var b = Floor(a), c = a - Floor(a);
		var scale = configuration.combo.scale;
		var accuracyHeight = If(comboStatus <= 2, comboAPNumberHeight2, comboNumberHeight2);
		var accuracyDistance = If(comboStatus <= 2, comboAPNumberDistance2, comboNumberDistance2) * scale;
		var accuracyHeight2 = If(comboStatus <= 2, comboAPNumberHeight3, comboNumberHeight3);
		var accuracyDistance2 = If(comboStatus <= 2, comboAPNumberDistance3, comboNumberDistance3) * scale;
		var pointHeight = If(comboStatus <= 2, comboAPPointHeight, comboPointHeight) * scale;
		var percentHeight = If(comboStatus <= 2, comboAPPercentHeight, comboPercentHeight) * scale;
		var distance = If(comboStatus <= 2, comboAPAccuracyDistance, comboAccuracyDistance) * scale;
		var status = If(comboStatus <= 2, 0, If(comboStatus <= 3, 1, 2));
		var W = -1 * accuracyDistance, tmp = b;
		while (tmp) {
			var v = tmp % 10;
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
		}
		var W1 = W;
		W = W + pointHeight * SwitchInteger(status, { comboAPPointRatio, comboFCPointRatio, comboNormalPointRatio });
		tmp = c; W = W - accuracyDistance2;
		for (var i = 1; i < 4; i++) {
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
		}
		W = W + percentHeight * SwitchInteger(status, { comboAPPercentRatio, comboFCPercentRatio, comboNormalPercentRatio });
		W = W + accuracyDistance - accuracyDistance2 / 2;
		var cx = screen.w * 0.4;
		var R = cx - W / 2 + W1;
		var L = R + accuracyDistance / 2;
		var T = 0.2 + If(
			comboStatus <= 2, 
			comboAPNumberHeight / 2.0 + comboAPTextDistance + comboAPTextHeight, 
			comboNumberHeight / 2.0 + comboTextDistance + comboTextHeight
		) * scale + distance;
		tmp = b;
		while (tmp) {
			var v = tmp % 10;
			var w = accuracyHeight * scale * Switch(v, {
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
			Draw(
				Switch(status, {
					{0, Sprites.ComboAP0 + v},
					{1, Sprites.ComboFC0 + v},
					{2, Sprites.ComboNormal0 + v}
				}), 
				{ R - w, T }, 
				{ R - w, T + accuracyHeight * scale }, 
				{ R, T + accuracyHeight * scale }, 
				{ R, T }, 
				1e8, 
				1
			);
			R = R - w - accuracyDistance;
			tmp = Floor(tmp / 10);
		}
		var pointWidth = pointHeight * SwitchInteger(status, { comboAPPointRatio, comboFCPointRatio, comboNormalPointRatio });
		Draw(
			Switch(status, {
				{0, Sprites.ComboAPPoint},
				{1, Sprites.ComboFCPoint},
				{2, Sprites.ComboNormalPoint}
			}), 
			{ L, T }, 
			{ L, T + pointHeight }, 
			{ L + pointWidth, T + pointHeight }, 
			{ L + pointWidth, T }, 
			1e8, 
			1
		);
		L = L + pointWidth + accuracyDistance / 2;
		tmp = c;
		for (var i = 0; i < 4; i++) {
			tmp = tmp * 10;
			var v = Floor(tmp);
			tmp = tmp - v;
			var h = If(i >= 2, accuracyHeight2, accuracyHeight);
			var w = h * scale * Switch(v, {
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
			Draw(
				Switch(status, {
					{0, Sprites.ComboAP0 + v},
					{1, Sprites.ComboFC0 + v},
					{2, Sprites.ComboNormal0 + v}
				}), 
				{ L, T }, 
				{ L, T + h * scale }, 
				{ L + w, T + h * scale }, 
				{ L + w, T }, 
				1e8, 
				1
			);
			L = L + w + If(i >= 1, accuracyDistance2, accuracyDistance);
		}
		L = L - accuracyDistance2 / 2;
		var percentWidth = percentHeight * SwitchInteger(status, { comboAPPercentRatio, comboFCPercentRatio, comboNormalPercentRatio });
		Draw(
			Switch(status, {
				{0, Sprites.ComboAPPercent},
				{1, Sprites.ComboFCPercent},
				{2, Sprites.ComboNormalPercent}
			}), 
			{ L, T }, 
			{ L, T + percentHeight }, 
			{ L + percentWidth, T + percentHeight }, 
			{ L + percentWidth, T }, 
			1e8, 
			1
		);
	}

    SonolusApi updateParallel() {
        Draw(Sprites.Stage, { stage.l, stage.b }, { stage.l * highWidth, stage.t }, { stage.r * highWidth, stage.t }, { stage.r, stage.b }, 1, 1);
	    Draw(Sprites.StageBackground, { stage.l, stage.b }, { stage.l * highWidth, stage.t }, { stage.r * highWidth, stage.t }, { stage.r, stage.b }, 2, opacity);
		if (Options.Hidden != 0) drawHiddenLine();
		Draw(Sprites.Judgeline, { judgline.lbX, judgline.lbY }, { judgline.ltX, judgline.ltY }, { judgline.rtX, judgline.rtY }, { judgline.rbX, judgline.rbY }, 3, 1);
		if (!sonolusJudgment) drawJudgeText();
		if (!sonolusCombo) drawCombo();
		if (showAccuracy && HasSkinSprite(Sprites.ComboNormal0)) drawAccuracy();
    }

	int updateSequentialOrder = 2;
	SonolusApi updateSequential() {
		if (times.now < firstTime) {
			comboNumber = 0;
			comboStatus = 0;
			currentAccuracy = totalAccuracy;
			currentJudge = 0;
			currentJudgeStartTime = 0;
			currentJudgeDeltaTime = 9999;
		}
		/*IF (!times.skip) Return(0); FI
		currentJudge.set(0);
		currentJudgeStartTime.set(0);
        currentJudgeDeltaTime.set(0);
        comboNumber = 0;*/
        lastUpdatedId = 0;
	}
};
