SonolusApi drawNormalNote_fallback(var sprite, var lane, var enLane, var beat) {
	var p = ease((times.scaled - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    var multiplier = noteHeight / 2 / stage.h * w / line1.getWidth(1);
    auto c1 = line1.getPosition(p - multiplier);
    auto c2 = line1.getPosition(p + multiplier);
    auto c3 = line2.getPosition(p - multiplier);
    auto c4 = line2.getPosition(p + multiplier);
    auto w1 = line1.getWidth(p - multiplier);
    auto w2 = line1.getWidth(p + multiplier);
    auto lb = c2 - Vec(w2 / 2 - noteMoveLength * w1 / line1.getWidth(1), 0),
    	 lt = c1 - Vec(w1 / 2 - noteMoveLength * w2 / line1.getWidth(1), 0);
    auto rb = c4 + Vec(w2 / 2 - noteMoveLength * w1 / line1.getWidth(1), 0),
    	 rt = c3 + Vec(w1 / 2 - noteMoveLength * w2 / line1.getWidth(1), 0);
    Draw(sprite, lb, lt, rt, rb, 1000 - beat, 1);
}

SonolusApi drawNormalNote(var sprite, var lane, var enLane, var beat) {
	if (!HasSkinSprite(sprite)) {
		drawNormalNote_fallback(sprite - 1, lane, enLane, beat);
        return;
	}
	var p = ease((times.scaled - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    var multiplier = noteHeight / 2 / stage.h * w / line1.getWidth(1);
    auto c1 = line1.getPosition(p - multiplier);
    auto c2 = line1.getPosition(p + multiplier);
    auto c3 = line2.getPosition(p - multiplier);
    auto c4 = line2.getPosition(p + multiplier);
    auto w1 = line1.getWidth(p - multiplier);
    auto w2 = line1.getWidth(p + multiplier);
    auto border_w1 = w1 * 12 * noteBorderPercent;
    auto border_w2 = w2 * 12 * noteBorderPercent;
    auto lb = c2 - Vec(w2 / 2 - noteMoveLength * w1 / line1.getWidth(1), 0),
    	 lt = c1 - Vec(w1 / 2 - noteMoveLength * w2 / line1.getWidth(1), 0);
    auto rb = c4 + Vec(w2 / 2 - noteMoveLength * w1 / line1.getWidth(1), 0),
    	 rt = c3 + Vec(w1 / 2 - noteMoveLength * w2 / line1.getWidth(1), 0);
    Draw(sprite, lb, lt, { lt.x + border_w1, rt.y }, { lb.x + border_w2, rb.y }, 100000 - beat, 1);
    Draw(sprite + 1, { lb.x + border_w2, lb.y }, { lt.x + border_w1, lt.y }, { rt.x - border_w1, rt.y }, { rb.x - border_w2, rb.y }, 100000 - beat, 1);
    Draw(sprite + 2, { rb.x - border_w2, rb.y }, { rt.x - border_w1, rt.y }, rt, rb, 100000 - beat, 1);
}

SonolusApi drawArrow(var lane, var enLane, var beat) {
	var p = ease((times.scaled - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p);
    auto c2 = line2.getPosition(p);
    auto W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    auto L = c1.x - w / 2, R = c2.x + w / 2;
    auto num = w * (enLane - lane + 1) / 2 * arrowPercent / W;
    if (p > hiddenPercent) {
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
            	{ L + (i - 1) * W / 2, c1.y }, 
            	{ L + (i - 1) * W / 2, c1.y + H / 2 }, 
                { L + (i + 1) * W / 2, c1.y + H / 2 }, 
                { L + (i + 1) * W / 2, c1.y }, 
                1000000 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num
            );
        }
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
            	{ R - (i - 1) * W / 2, c2.y }, 
            	{ R - (i - 1) * W / 2, c2.y + H / 2 }, 
                { R - (i + 1) * W / 2, c2.y + H / 2 }, 
                { R - (i + 1) * W / 2, c2.y }, 
                1000000 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num
            );
        }
    }
}

SonolusApi drawLeftArrow(var lane, var enLane, var beat) {
	var p = ease((times.scaled - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p);
    auto c2 = line2.getPosition(p);
    auto W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    auto L = c1.x - w / 2, R = c2.x + w / 2;
    auto num = w * (enLane - lane + 1) * arrowPercent / W;
    if (p > hiddenPercent) {
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
            	{ L + (i - 1) * W / 2, c1.y }, 
            	{ L + (i - 1) * W / 2, c1.y + H / 2 }, 
                { L + (i + 1) * W / 2, c1.y + H / 2 }, 
                { L + (i + 1) * W / 2, c1.y }, 
                1000000 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num
            );
        }
    }
}

SonolusApi drawRightArrow(var lane, var enLane, var beat) {
	var p = ease((times.scaled - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p);
    auto c2 = line2.getPosition(p);
    auto W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    auto L = c1.x - w / 2, R = c2.x + w / 2;
    auto num = w * (enLane - lane + 1) * arrowPercent / W;
    if (p > hiddenPercent) {
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
            	{ R - (i - 1) * W / 2, c2.y }, 
            	{ R - (i - 1) * W / 2, c2.y + H / 2 }, 
                { R - (i + 1) * W / 2, c2.y + H / 2 }, 
                { R - (i + 1) * W / 2, c2.y }, 
                1000000 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num
            );
        }
    }
}

SonolusApi drawHoldEighth(var sprite, var lane, var enLane, var stBeat, var enBeat, var isHolding) {
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(1);
    var p1 = ease(Min(1, Min(1, times.scaled - stBeat) / appearTime + 1)),
        p2 = ease(Min(1, Min(1, times.scaled - enBeat) / appearTime + 1));
	auto c1 = line1.getPosition(p1);
	auto c2 = line1.getPosition(p2);
	auto c3 = line2.getPosition(p1);
	auto c4 = line2.getPosition(p2);
	auto w1 = line1.getWidth(p1);
	auto w2 = line1.getWidth(p2);
	auto lb = c1 - Vec(w1 / 2 - noteMoveLength * w1 / w, 0), 
         lt = c2 - Vec(w2 / 2 - noteMoveLength * w2 / w, 0);
	auto rb = c3 + Vec(w1 / 2 - noteMoveLength * w1 / w, 0), 
         rt = c4 + Vec(w2 / 2 - noteMoveLength * w2 / w, 0);
#if defined(tutorial)
    var val = 0;
#else
    var val = EntityInfo.index * 1e-5;
#endif
	if (isHolding) {
        var val = Floor(times.now / 0.1) % 2 == 1;
        if (val == 1) Draw(sprite, lb, lt, rt, rb, 50000 - stBeat + val, 0.85);
        else Draw(sprite, lb, lt, rt, rb, 50000 - stBeat + val, 0.8);
    } else Draw(sprite, lb, lt, rt, rb, 50000 - stBeat + val, 0.8);
}

SonolusApi drawTick(var sprite, var beat, var lane, var enLane) {
	var p = ease((times.scaled - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p - tickHeight / 2 / stage.h * multiplier);
    auto c2 = line1.getPosition(p + tickHeight / 2 / stage.h * multiplier);
    auto c3 = line2.getPosition(p - tickHeight / 2 / stage.h * multiplier);
    auto c4 = line2.getPosition(p + tickHeight / 2 / stage.h * multiplier);
    auto m1 = line1.getWidth(p - tickHeight / 2 / stage.h * multiplier) / lines[lane].getWidth(1);
    auto m2 = line1.getWidth(p + tickHeight / 2 / stage.h * multiplier) / lines[lane].getWidth(1);
	auto cb = Vec((c2.x + c4.x) / 2, (c2.y + c4.y) / 2), ct = Vec((c1.x + c3.x) / 2, (c1.y + c3.y) / 2);
	auto lb = cb - Vec(m2 * tickWidth / 2, 0), lt = ct - Vec(m1 * tickWidth / 2, 0);
	auto rb = cb + Vec(m2 * tickWidth / 2, 0), rt = ct + Vec(m1 * tickWidth / 2, 0);
	Draw(sprite, lb, lt, rt, rb, 200000 - beat, 0.5);
}

SonolusApi drawSyncLine(var beat, var lane, var enLane) {
	var p = ease((times.scaled - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p - syncLineHeight / 2 / stage.h * multiplier);
    auto c2 = line1.getPosition(p + syncLineHeight / 2 / stage.h * multiplier);
    auto c3 = line2.getPosition(p - syncLineHeight / 2 / stage.h * multiplier);
    auto c4 = line2.getPosition(p + syncLineHeight / 2 / stage.h * multiplier);
    auto w1 = line1.getWidth(p - syncLineHeight / 2 / stage.h * multiplier);
    auto w2 = line1.getWidth(p + syncLineHeight / 2 / stage.h * multiplier);
    auto lb = c2 - Vec(w2 / 2 - noteMoveLength * multiplier, 0), 
    	 lt = c1 - Vec(w1 / 2 - noteMoveLength * multiplier, 0);
    auto rb = c4 + Vec(w2 / 2 - noteMoveLength * multiplier, 0), 
    	 rt = c3 + Vec(w1 / 2 - noteMoveLength * multiplier, 0);
    Draw(Sprites.SyncLine, lb, lt, rt, rb, 5, 0.8);
}

SonolusApi drawHiddenLine() {
    var sprite = Sprites.HiddenLine, lane = 1, enLane = 12, beat = times.now + (1 - hidden) * appearTime;
    var p = ease((times.now - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / lines[lane].getWidth(1);
    auto c1 = line1.getPosition(p - hiddenLineHeight / 2 / stage.h * multiplier);
    auto c2 = line1.getPosition(p + hiddenLineHeight / 2 / stage.h * multiplier);
    auto c3 = line2.getPosition(p - hiddenLineHeight / 2 / stage.h * multiplier);
    auto c4 = line2.getPosition(p + hiddenLineHeight / 2 / stage.h * multiplier);
    auto w1 = line1.getWidth(p - hiddenLineHeight / 2 / stage.h * multiplier);
    auto w2 = line1.getWidth(p + hiddenLineHeight / 2 / stage.h * multiplier);
    auto lb = c2 - Vec(w2 / 2 - noteMoveLength * w1 / line1.getWidth(1), 0), 
    	 lt = c1 - Vec(w1 / 2 - noteMoveLength * w2 / line1.getWidth(1), 0);
    auto rb = c4 + Vec(w2 / 2 - noteMoveLength * w1 / line1.getWidth(1), 0), 
    	 rt = c3 + Vec(w1 / 2 - noteMoveLength * w2 / line1.getWidth(1), 0);
    Draw(sprite, lb, lt, rt, rb, 10, 0.6);
}

SonolusApi spawnLineEffect(var lane, var enLane) {
	var wt = lines[lane].getFullWidth(0), wb = lines[lane].getFullWidth(1);
	auto lb = lines[lane].getFullPosition(1) + Vec(-1 * wb / 2.0, 0), 
		 rb = lines[enLane].getFullPosition(1) + Vec(wb / 2.0, 0);
	auto lt = lines[lane].getFullPosition(0) + Vec(-1 * wt / 2.0, 0), 
		 rt = lines[enLane].getFullPosition(0) + Vec(wt / 2.0, 0);
	SpawnParticleEffect(Effects.Lane, lb, lt, rt, rb, effectDurationTime, 0);
}

SonolusApi spawnEffect(var linear, var circular, var lane, var enLane) {
	var w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto lb = c1 + Vec(-1 * w / 2, 0), lt = c1 + Vec(-1 * w / 2, effectLinearHeight);
	auto rb = c2 + Vec(w / 2, 0), rt = c2 + Vec(w / 2, effectLinearHeight);
	auto lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	auto rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	SpawnParticleEffect(linear, lb, lt, rt, rb, effectDurationTime, 0);
	SpawnParticleEffect(circular, lb2, lt2, rt2, rb2, effectDurationTime, 0);
	// spawnLineEffect(lane, enLane);
}

SonolusApi spawnHoldEffect(var effect, var lane, var enLane) {
	var w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	auto rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	return SpawnParticleEffect2(effect, lb2, lt2, rt2, rb2, effectDurationTime, 1);
}

SonolusApi updateHoldEffect(var effectInstanceId, var lane, var enLane) {
	var w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	auto rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	MoveParticleEffect(effectInstanceId, lb2, lt2, rt2, rb2);
}

SonolusApi SpawnSubJudgeText(var sprite, var delta = 0, var judgeTime = times.now) {
	#ifdef play
    if (sprite <= Sprites.JudgeGreat || sprite == Sprites.JudgeAuto) comboNumber = comboNumber + 1;
    else comboNumber = 0;
    comboStatus = Max(comboStatus, If(sprite == Sprites.JudgeAuto, Sprites.JudgePerfectPlus, sprite));
    #endif
    currentAccuracy = currentAccuracy - Switch(sprite, {
        { Sprites.JudgeMiss, 1.01 },
        { Sprites.JudgePerfectPlus, 0 },
        { Sprites.JudgePerfect, 0.01 },
        { Sprites.JudgeGreat, 0.21 },
        { Sprites.JudgeGood, 0.51 },
        { Sprites.JudgeBad, 1.01 },
        { Sprites.JudgeAuto, 0 }
    });
    if (currentJudgeStartTime == judgeTime) {
        currentJudge = Max(currentJudge, sprite);
        if (Abs(delta) > Abs(currentJudgeDeltaTime)) currentJudgeDeltaTime = delta;
    } else {
        currentJudge = sprite;
        currentJudgeStartTime = judgeTime;
        currentJudgeDeltaTime = delta;
    }
}

// 上面为 0，下面为 1
SonolusApi drawLine(var id, var st, var en, var a, var sprite) {
    var w = lines[id + 1].getWidth(1);
    Vec c1 = lines[id + 1].getFullPosition(ease(st));
    Vec c2 = lines[id + 1].getFullPosition(ease(en));
	var w1 = lines[id + 1].getFullWidth(ease(st));
	var w2 = lines[id + 1].getFullWidth(ease(en));
    var move = splitLineLength / 2;
	Vec c3 = c1 + Vec(-1 * w1 / 2, 0);
	Vec c4 = c2 + Vec(-1 * w2 / 2, 0);
	Vec lb = c4 + Vec(-1 * move * w2 / w, 0), lt = c3 + Vec(-1 * move * w1 / w, 0);
	Vec rb = c4 + Vec(move * w2 / w, 0), rt = c3 + Vec(move * w1 / w, 0);
#if defined(tutorial)
    Draw(sprite, lb, lt, rt, rb, 10000, a * splitLine);
#else
	Draw(sprite, lb, lt, rt, rb, 10000 + EntityData[0], a * splitLine);
#endif
}

SonolusApi drawEndLine(var st, var en, var a, var sprite) {
    var w = lines[12].getWidth(1);
    Vec c1 = lines[12].getFullPosition(ease(st));
    Vec c2 = lines[12].getFullPosition(ease(en));
	var w1 = lines[12].getFullWidth(ease(st));
	var w2 = lines[12].getFullWidth(ease(en));
    var move = splitLineLength / 2;
	Vec c3 = c1 + Vec(1 * w1 / 2, 0);
	Vec c4 = c2 + Vec(1 * w2 / 2, 0);
	Vec lb = c4 + Vec(-1 * move * w2 / w, 0), lt = c3 + Vec(-1 * move * w1 / w, 0);
	Vec rb = c4 + Vec(move * w2 / w, 0), rt = c3 + Vec(move * w1 / w, 0);
#if defined(tutorial)
    Draw(sprite, lb, lt, rt, rb, 10000, a * splitLine);
#else
	Draw(sprite, lb, lt, rt, rb, 10000 + EntityData[0], a * splitLine);
#endif
}

SonolusApi drawSplitLine(var split) {
    drawLine(0, 0, 1, 1, splitLineMemory[0]);
    drawEndLine(0, 1, 1, splitLineMemory[split]);
    switch(split) {
        case 2: {
            drawLine(6, 0, 1, 1, splitLineMemory[1]);
        } break;
        case 3: {
            drawLine(4, 0, 1, 1, splitLineMemory[1]);
            drawLine(8, 0, 1, 1, splitLineMemory[2]);
        } break;
        case 4: {
            drawLine(3, 0, 1, 1, splitLineMemory[1]);
            drawLine(6, 0, 1, 1, splitLineMemory[2]); 
            drawLine(9, 0, 1, 1, splitLineMemory[3]);
        } break;
        case 5: {
            drawLine(3, 0, 1, 1, splitLineMemory[1]);
            drawLine(5, 0, 1, 1, splitLineMemory[2]);
            drawLine(7, 0, 1, 1, splitLineMemory[3]); 
            drawLine(9, 0, 1, 1, splitLineMemory[4]);
        } break;
        case 6: {
            drawLine(2, 0, 1, 1, splitLineMemory[1]);
            drawLine(4, 0, 1, 1, splitLineMemory[2]); 
            drawLine(6, 0, 1, 1, splitLineMemory[3]); 
            drawLine(8, 0, 1, 1, splitLineMemory[4]); 
            drawLine(10, 0, 1, 1, splitLineMemory[5]);
        } break;
    }
}

SonolusApi drawDisappearLine(var t, var split) {
    var p = 1;
    var a = 1 - t / splitLineAnimationEnd;
    drawLine(0, 0, p, a, splitLineMemory[0]);
    drawEndLine(0, p, a, splitLineMemory[split]);
    switch(split) {
        case 2: {
            drawLine(6, 0, p, a, splitLineMemory[1]);
        } break;
        case 3: {
            drawLine(4, 0, p, a, splitLineMemory[1]); 
            drawLine(8, 0, p, a, splitLineMemory[2]);
        } break;
        case 4: {
            drawLine(3, 0, p, a, splitLineMemory[1]); 
            drawLine(6, 0, p, a, splitLineMemory[2]); 
            drawLine(9, 0, p, a, splitLineMemory[3]);
        } break;
        case 5: {
            drawLine(3, 0, p, a, splitLineMemory[1]); 
            drawLine(5, 0, p, a, splitLineMemory[2]); 
            drawLine(7, 0, p, a, splitLineMemory[3]); 
            drawLine(9, 0, p, a, splitLineMemory[4]);
        } break;
        case 6: {
            drawLine(2, 0, p, a, splitLineMemory[1]); 
            drawLine(4, 0, p, a, splitLineMemory[2]); 
            drawLine(6, 0, p, a, splitLineMemory[3]);
            drawLine(8, 0, p, a, splitLineMemory[4]);
            drawLine(10, 0, p, a, splitLineMemory[5]);
        } break;
    }
}

SonolusApi drawAppearLine(var t, var split) {
    var p = 1 - t / splitLineAnimationStart;
    var a = 1;
    drawLine(0, p, 1, a, splitLineMemory[0]);
    drawEndLine(p, 1, a, splitLineMemory[split]);
    switch(split) {
        case 2: {
            drawLine(6, p, 1, a, splitLineMemory[1]);
        } break;
        case 3: {
            drawLine(4, p, 1, a, splitLineMemory[1]); 
            drawLine(8, p, 1, a, splitLineMemory[2]);
        } break;
        case 4: {
            drawLine(3, p, 1, a, splitLineMemory[1]); 
            drawLine(6, p, 1, a, splitLineMemory[2]); 
            drawLine(9, p, 1, a, splitLineMemory[3]);
        } break;
        case 5: {
            drawLine(3, p, 1, a, splitLineMemory[1]); 
            drawLine(5, p, 1, a, splitLineMemory[2]); 
            drawLine(7, p, 1, a, splitLineMemory[3]); 
            drawLine(9, p, 1, a, splitLineMemory[4]);
        } break;
        case 6: {
            drawLine(2, p, 1, a, splitLineMemory[1]); 
            drawLine(4, p, 1, a, splitLineMemory[2]); 
            drawLine(6, p, 1, a, splitLineMemory[3]);
            drawLine(8, p, 1, a, splitLineMemory[4]);
            drawLine(10, p, 1, a, splitLineMemory[5]);
        } break;
    }
}

FuncNode setSplitLine(vector<FuncNode> lines) {
    createNodeContainer();
    for (int i = 0; i < 16; i++) {
        splitLineMemory[i] = lines[i % lines.size()];
		// DebugLog(lines[i % lines.size()]);
	}
    return mergeNodeContainer();
}

SonolusApi randomShuffle(Array<var, 21> &arr, var st, var en) {
    for (var i = st; i < en; i++) {
        var j = RandomInteger(st, en - 1);
        if (i != j) {
            var temp = arr[i];
            var temp2 = arr[j];
            arr[i] = temp2;
            arr[j] = temp;
        }
    }
}