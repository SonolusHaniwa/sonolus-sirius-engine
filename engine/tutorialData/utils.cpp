var drawStage() {
    return {
        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1),
        Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, 0.6),
        Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1),
    };
}

var nextTutorial() {
	return {
		instruction.set(-1),
		tutorialStartTime.set(times.now),
		tutorialNavigation.add(1)
	};
}

var drawFrozenHand(var lane, var enLane, var percent, bool in = true, bool out = true) {
	var angle = IF (percent < 25) {
		handStartAngle,
	} ELSE {
		IF (percent < 75) {
			(percent - 25) / 50 * (handEndAngle - handStartAngle) + handStartAngle
		} ELSE {
			handEndAngle
		} FI
	} FI;
	var goalX = (lines[lane].getPosition(1).x + lines[enLane].getPosition(1).x) / 2;
	var goalY = lines[lane].getPosition(1).y;
	var centerX = goalX + handCircleR * Sin(handEndAngle / 180 * acos(-1));
	var centerY = goalY - handCircleR * Cos(handEndAngle / 180 * acos(-1));
	var x = centerX - handCircleR * Sin(angle / 180 * acos(-1));
	var y = centerY + handCircleR * Cos(angle / 180 * acos(-1));
	var a = IF (percent < 25) {
		(!in) ? 1 : 1.0 * percent / 25
	} ELSE {
		IF (percent < 75) {
			1
		} ELSE {
			(!out) ? 1 : 1.0 - 1.0 * (percent - 75) / 25
		} FI
	} FI;
	return Paint(Icons.hand, x, y, handSize, angle, 2000, a);
}

var drawUpperHand(var lane, var enLane, var percent, var angle, bool in = false, bool out = true) {
	var goalX = (lines[lane].getPosition(1).x + lines[enLane].getPosition(1).x) / 2;
	var goalY = lines[lane].getPosition(1).y;
	var x = goalX;
	var y = goalY + IF (percent < 25) {
		0
	} ELSE {
		IF (percent < 75) {
			(percent - 25) / 50 * handUpperLength
		} ELSE {
			handUpperLength
		} FI
	} FI;
	var a = IF (percent < 25) {
		(!in) ? 1 : 1.0 * percent / 25
	} ELSE {
		IF (percent < 75) {
			1
		} ELSE {
			(!out) ? 1 : 1.0 - 1.0 * (percent - 75) / 25
		} FI
	} FI;
	return Paint(Icons.hand, x, y, handSize, angle, 2000, a);
}


var drawHorizontalHand(var lane, var enLane, var lane2, var enLane2, var percent, var angle, bool in = false, bool out = true) {
	var stX = (lines[lane].getPosition(1).x + lines[enLane].getPosition(1).x) / 2;
	var goalX =  (lines[lane2].getPosition(1).x + lines[enLane2].getPosition(1).x) / 2;
	var goalY = lines[lane].getPosition(1).y;
	var y = goalY;
	var x = stX + IF (percent < 25) {
		0
	} ELSE {
		IF (percent < 75) {
			(percent - 25) / 50 * (goalX - stX)
		} ELSE {
			goalX - stX
		} FI
	} FI;
	var a = IF (percent < 25) {
		(!in) ? 1 : 1.0 * percent / 25
	} ELSE {
		IF (percent < 75) {
			1
		} ELSE {
			(!out) ? 1 : 1.0 - 1.0 * (percent - 75) / 25
		} FI
	} FI;
	return Paint(Icons.hand, x, y, handSize, angle, 2000, a);
}

var spawnLineEffect(var lane, var enLane) {
	var wt = lines[lane].getFullWidth(0), wb = lines[lane].getFullWidth(1);
	Vec lb = lines[lane].getFullPosition(1) + Vec(-1 * wb / 2.0, 0), rb = lines[enLane].getFullPosition(1) + Vec(wb / 2.0, 0);
	Vec lt = lines[lane].getFullPosition(0) + Vec(-1 * wt / 2.0, 0), rt = lines[enLane].getFullPosition(0) + Vec(wt / 2.0, 0);
	return SpawnParticleEffect(Effects.Lane, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, effectDurationTime, 0);
}

var spawnEffect(var linear, var circular, var lane, var enLane) {
	var w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec lb = c1 + Vec(-1 * w / 2, 0), lt = c1 + Vec(-1 * w / 2, effectLinearHeight);
	Vec rb = c2 + Vec(w / 2, 0), rt = c2 + Vec(w / 2, effectLinearHeight);
	Vec lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	Vec rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	return Execute({
		SpawnParticleEffect(linear, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, effectDurationTime, 0),
		SpawnParticleEffect(circular, lb2.x, lb2.y, lt2.x, lt2.y, rt2.x, rt2.y, rb2.x, rb2.y, effectDurationTime, 0),
		spawnLineEffect(lane, enLane)
	});
}

var spawnHoldEffect(var effect, var lane, var enLane) {
	var w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	Vec rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	return Execute({
		SpawnParticleEffect(effect, lb2.x, lb2.y, lt2.x, lt2.y, rt2.x, rt2.y, rb2.x, rb2.y, effectDurationTime, 1),
	});
}

var drawArrow(var lane, var enLane, var p) {
    var w = lines[lane].getWidth(ease(p + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease(p + 1));
    Vec c2 = lines[enLane].getPosition(ease(p + 1));
    var W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    var L = c1.x - w / 2, R = c2.x + w / 2;
    var num = w * (enLane - lane + 1) / 2 * arrowPercent / W;
    return {
        Execute({
            FOR (i, 1, num, 1) {
                Draw(Sprites.ScratchArrow, L + (i - 1) * W / 2, c1.y, L + (i - 1) * W / 2, c1.y + H / 2, 
                    L + (i + 1) * W / 2, c1.y + H / 2, L + (i + 1) * W / 2, c1.y, 1001, 1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num)
            } DONE, 
            FOR (i, 1, num, 1) {
                Draw(Sprites.ScratchArrow, R - (i - 1) * W / 2, c2.y, R - (i - 1) * W / 2, c2.y + H / 2, 
                    R - (i + 1) * W / 2, c2.y + H / 2, R - (i + 1) * W / 2, c2.y, 1001, 1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num)
            } DONE
        })
	};
}

var drawLeftArrow(var lane, var enLane, var p) {
    var w = lines[lane].getWidth(ease(p + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease(p + 1));
    Vec c2 = lines[enLane].getPosition(ease(p + 1));
    var W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    var L = c1.x - w / 2, R = c2.x + w / 2;
    var num = w * (enLane - lane + 1) * arrowPercent / W;
    return {
        Execute({
            FOR (i, 1, num, 1) {
                Draw(Sprites.ScratchArrow, L + (i - 1) * W / 2, c1.y, L + (i - 1) * W / 2, c1.y + H / 2, 
                    L + (i + 1) * W / 2, c1.y + H / 2, L + (i + 1) * W / 2, c1.y, 1001, 1 - 0.8 * Mod({i + times.now * arrowSpeed * 2, num}) / num)
            } DONE,
        })
    };
}

var drawRightArrow(var lane, var enLane, var p) {
    var w = lines[lane].getWidth(ease(p + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease(p + 1));
    Vec c2 = lines[enLane].getPosition(ease(p + 1));
    var W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    var L = c1.x - w / 2, R = c2.x + w / 2;
    var num = w * (enLane - lane + 1) * arrowPercent / W;
    return {
        Execute({
            FOR (i, 1, num, 1) {
                Draw(Sprites.ScratchArrow, R - (i - 1) * W / 2, c2.y, R - (i - 1) * W / 2, c2.y + H / 2, 
                    R - (i + 1) * W / 2, c2.y + H / 2, R - (i + 1) * W / 2, c2.y, 1001, 1 - 0.8 * Mod({i + times.now * arrowSpeed * 2, num}) / num)
            } DONE
        })
    };
}

var drawNormalNote(var sprite, var lane, var enLane, var percent) {
    var w = lines[lane].getWidth(ease(percent + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease(percent + 1) - noteHeight / 2 / stage.h * multiplier);
    Vec c2 = lines[lane].getPosition(ease(percent + 1) + noteHeight / 2 / stage.h * multiplier);
    Vec c3 = lines[enLane].getPosition(ease(percent + 1) - noteHeight / 2 / stage.h * multiplier);
    Vec c4 = lines[enLane].getPosition(ease(percent + 1) + noteHeight / 2 / stage.h * multiplier);
    var w1 = lines[lane].getWidth(ease(percent + 1) - noteHeight / 2 / stage.h * multiplier);
    var w2 = lines[lane].getWidth(ease(percent + 1) + noteHeight / 2 / stage.h * multiplier);
    Vec lb = c2 + Vec(-1 * w2 / 2 + noteMoveLength * w1 / lines[lane].getWidth(1), 0), lt = c1 + Vec(-1 * w1 / 2 + noteMoveLength * w2 / lines[lane].getWidth(1), 0);
    Vec rb = c4 + Vec(1 * w2 / 2 - noteMoveLength * w1 / lines[lane].getWidth(1), 0), rt = c3 + Vec(w1 / 2 - noteMoveLength * w2 / lines[lane].getWidth(1), 0);
    return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 1000, 1);
}

var drawHoldEighth(var sprite, var lane, var enLane, var p1, var p2) {
    var w = lines[lane].getWidth(1);
	Vec c1 = lines[lane].getPosition(ease(Min(1, p1 + 1)));
	Vec c2 = lines[lane].getPosition(ease(Min(1, p2 + 1)));
	Vec c3 = lines[enLane].getPosition(ease(Min(1, p1 + 1)));
	Vec c4 = lines[enLane].getPosition(ease(Min(1, p2 + 1)));
	var w1 = lines[lane].getWidth(ease(Min(1, p1 + 1)));
	var w2 = lines[lane].getWidth(ease(Min(1, p2 + 1)));
	Vec lb = c1 + Vec(-1 * w1 / 2 + noteMoveLength * w1 / w, 0), lt = c2 + Vec(-1 * w2 / 2 + noteMoveLength * w2 / w, 0);
	Vec rb = c3 + Vec(w1 / 2 - noteMoveLength * w1 / w, 0), rt = c4 + Vec(w2 / 2 - noteMoveLength * w2 / w, 0);
	return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 4, 0.8);
}

var drawTick(var sprite, var p, var lane, var enLane) {
    var w = lines[lane].getWidth(ease(p + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease(p + 1) - tickHeight / 2 / stage.h * multiplier);
    Vec c2 = lines[lane].getPosition(ease(p + 1) + tickHeight / 2 / stage.h * multiplier);
    Vec c3 = lines[enLane].getPosition(ease(p + 1) - tickHeight / 2 / stage.h * multiplier);
    Vec c4 = lines[enLane].getPosition(ease(p + 1) + tickHeight / 2 / stage.h * multiplier);
    var m1 = lines[lane].getWidth(ease(p + 1) - tickHeight / 2 / stage.h * multiplier) / lines[lane].getWidth(1);
    var m2 = lines[lane].getWidth(ease(p + 1) + tickHeight / 2 / stage.h * multiplier) / lines[lane].getWidth(1);
	Vec cb = Vec((c2.x + c4.x) / 2, (c2.y + c4.y) / 2), ct = Vec((c1.x + c3.x) / 2, (c1.y + c3.y) / 2);
	Vec lb = cb + Vec(-1 * m2 * tickWidth / 2, 0), lt = ct + Vec(-1 * m1 * tickWidth / 2, 0);
	Vec rb = cb + Vec(m2 * tickWidth / 2, 0), rt = ct + Vec(m1 * tickWidth / 2, 0);
	return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 1000, 0.5);
}

// 上面为 0，下面为 1
var drawLine(var id, var st, var en, var a, var sprite) {
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
	return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 10000, a);
}

var drawEndLine(var st, var en, var a, var sprite) {
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
	return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 10000, a);
}

var drawSplitLine(var split) {
	return Execute({
        drawLine(0, 0, 1, 1, splitLineMemory[0]),
        drawEndLine(0, 1, 1, splitLineMemory[split]),
        Switch(split, {
            {1, {}},
            {2, drawLine(6, 0, 1, 1, splitLineMemory[1])},
            {3, {
                drawLine(4, 0, 1, 1, splitLineMemory[1]), 
                drawLine(8, 0, 1, 1, splitLineMemory[2])
            }}, {4, {
                drawLine(3, 0, 1, 1, splitLineMemory[1]), 
                drawLine(6, 0, 1, 1, splitLineMemory[2]), 
                drawLine(9, 0, 1, 1, splitLineMemory[3])
            }}, {5, {
                drawLine(3, 0, 1, 1, splitLineMemory[1]), 
                drawLine(5, 0, 1, 1, splitLineMemory[2]), 
                drawLine(7, 0, 1, 1, splitLineMemory[3]), 
                drawLine(9, 0, 1, 1, splitLineMemory[4])
            }}, {6, {
                drawLine(2, 0, 1, 1, splitLineMemory[1]), 
                drawLine(4, 0, 1, 1, splitLineMemory[2]), 
                drawLine(6, 0, 1, 1, splitLineMemory[3]), 
                drawLine(8, 0, 1, 1, splitLineMemory[4]), 
                drawLine(10, 0, 1, 1, splitLineMemory[5])
            }}
        })
    });
}

var drawDisappearLine(var t, var split) {
    var p = 1;
    var a = 1 - t / splitLineAnimationEnd;
	return Execute({
        drawLine(0, 0, p, a, splitLineMemory[0]),
        drawEndLine(0, p, a, splitLineMemory[split]),
        Switch(split, {
            {1, {}},
            {2, drawLine(6, 0, p, a, splitLineMemory[1])},
            {3, {
                drawLine(4, 0, p, a, splitLineMemory[1]), 
                drawLine(8, 0, p, a, splitLineMemory[2])
            }}, {4, {
                drawLine(3, 0, p, a, splitLineMemory[1]), 
                drawLine(6, 0, p, a, splitLineMemory[2]), 
                drawLine(9, 0, p, a, splitLineMemory[3])
            }}, {5, {
                drawLine(3, 0, p, a, splitLineMemory[1]), 
                drawLine(5, 0, p, a, splitLineMemory[2]), 
                drawLine(7, 0, p, a, splitLineMemory[3]), 
                drawLine(9, 0, p, a, splitLineMemory[4])
            }}, {6, {
                drawLine(2, 0, p, a, splitLineMemory[1]), 
                drawLine(4, 0, p, a, splitLineMemory[2]), 
                drawLine(6, 0, p, a, splitLineMemory[3]), 
                drawLine(8, 0, p, a, splitLineMemory[4]), 
                drawLine(10, 0, p, a, splitLineMemory[5])
            }}
        })
    });
}

var drawAppearLine(var t, var split) {
    var p = 1 - t / splitLineAnimationStart;
    var a = 1;
	return Execute({
        drawLine(0, p, 1, a, splitLineMemory[0]),
        drawEndLine(p, 1, a, splitLineMemory[split]),
        Switch(split, {
            {1, {}},
            {2, drawLine(6, p, 1, a, splitLineMemory[1])},
            {3, {
                drawLine(4, p, 1, a, splitLineMemory[1]), 
                drawLine(8, p, 1, a, splitLineMemory[2])
            }}, {4, {
                drawLine(3, p, 1, a, splitLineMemory[1]), 
                drawLine(6, p, 1, a, splitLineMemory[2]), 
                drawLine(9, p, 1, a, splitLineMemory[3])
            }}, {5, {
                drawLine(3, p, 1, a, splitLineMemory[1]), 
                drawLine(5, p, 1, a, splitLineMemory[2]), 
                drawLine(7, p, 1, a, splitLineMemory[3]), 
                drawLine(9, p, 1, a, splitLineMemory[4])
            }}, {6, {
                drawLine(2, p, 1, a, splitLineMemory[1]), 
                drawLine(4, p, 1, a, splitLineMemory[2]), 
                drawLine(6, p, 1, a, splitLineMemory[3]), 
                drawLine(8, p, 1, a, splitLineMemory[4]), 
                drawLine(10, p, 1, a, splitLineMemory[5])}}
        })
    });
}

var setSplitLine(vector<var> lines) {
    vector<var> args = {splitLineMemory.clear()};
    for (int i = 0; i < 16; i++) {
        args.push_back(splitLineMemory.add(lines[i % lines.size()]));
    } return Execute(args);
}

var getSplitLine(var id) {
    return Switch(id, {
        {1, setSplitLine({Sprites.SplitLine_1})},
        {2, setSplitLine({Sprites.SplitLine_2})},
        {3, setSplitLine({Sprites.SplitLine_3})},
        {4, setSplitLine({Sprites.SplitLine_4})},
        {5, setSplitLine({Sprites.SplitLine_5})},
        {6, setSplitLine({Sprites.SplitLine_6})},
        {7, setSplitLine({Sprites.SplitLine_7})},
        {8, setSplitLine({Sprites.SplitLine_8})},
        {9, setSplitLine({Sprites.SplitLine_9})},
        {1010, setSplitLine({Sprites.SplitLine_1010})},
        {1020, setSplitLine({Sprites.SplitLine_1020})},
        {1030, setSplitLine({Sprites.SplitLine_1030})},
        {1040, setSplitLine({Sprites.SplitLine_1040})},
        {1050, setSplitLine({Sprites.SplitLine_1050})},
        {1060, setSplitLine({Sprites.SplitLine_1060a, Sprites.SplitLine_1060b})},
        {2010, setSplitLine({Sprites.SplitLine_2010})},
        {2020, setSplitLine({Sprites.SplitLine_2020})},
        {2030, setSplitLine({Sprites.SplitLine_2030})},
        {2040, setSplitLine({Sprites.SplitLine_2040a, Sprites.SplitLine_2040b})},
        {2050, setSplitLine({Sprites.SplitLine_2050})},
        {3010, setSplitLine({Sprites.SplitLine_3010})},
        {3020, setSplitLine({Sprites.SplitLine_3020})},
        {3030, setSplitLine({Sprites.SplitLine_3030})},
        {3040, setSplitLine({Sprites.SplitLine_3040})},
        {3050, setSplitLine({Sprites.SplitLine_3050})},
        {4010, setSplitLine({Sprites.SplitLine_4010})},
        {4020, setSplitLine({Sprites.SplitLine_4020})},
        {4030, setSplitLine({Sprites.SplitLine_4030})},
        {4040, setSplitLine({Sprites.SplitLine_4040})},
        {4050, setSplitLine({Sprites.SplitLine_4050})},
        {10010, setSplitLine({Sprites.SplitLine_10010})},
        {10020, setSplitLine({Sprites.SplitLine_10020})},
        {10030, setSplitLine({Sprites.SplitLine_10030})},
        {10040, setSplitLine({Sprites.SplitLine_10040})},
        {10050, setSplitLine({Sprites.SplitLine_10050})},
        {10060, setSplitLine({Sprites.SplitLine_10060})},
        {10070, setSplitLine({Sprites.SplitLine_10070})},
        {10100, setSplitLine({Sprites.SplitLine_10100})},
        {10110, setSplitLine({Sprites.SplitLine_10110})},
        {10120, setSplitLine({Sprites.SplitLine_10120})},
        {10130, setSplitLine({Sprites.SplitLine_10130})},
        {10140, setSplitLine({Sprites.SplitLine_10140})},
        {10150, setSplitLine({Sprites.SplitLine_10150})},
        {10160, setSplitLine({Sprites.SplitLine_10160})},
        {10161, setSplitLine({Sprites.SplitLine_10161})},
        {10162, setSplitLine({Sprites.SplitLine_10162})},
        {10170, setSplitLine({Sprites.SplitLine_10170})},
        {10180, setSplitLine({Sprites.SplitLine_10180})},
        {10190, setSplitLine({Sprites.SplitLine_10190})},
        {10191, setSplitLine({Sprites.SplitLine_10191})},
        {10200, setSplitLine({Sprites.SplitLine_10200})},
        {10220, setSplitLine({Sprites.SplitLine_10220})},
        {10230, setSplitLine({Sprites.SplitLine_10230})},
        {10240, setSplitLine({Sprites.SplitLine_10240})},
        {10250, setSplitLine({Sprites.SplitLine_10250})},
        {10260, setSplitLine({Sprites.SplitLine_10260})},
        {10320, setSplitLine({Sprites.SplitLine_10320})},
        {10321, setSplitLine({Sprites.SplitLine_10321_1, Sprites.SplitLine_10321_2, Sprites.SplitLine_10321_3, Sprites.SplitLine_10321_4, Sprites.SplitLine_10321_5})},
        {10322, setSplitLine({Sprites.SplitLine_10322_1, Sprites.SplitLine_10322_2, Sprites.SplitLine_10322_3, Sprites.SplitLine_10322_4, Sprites.SplitLine_10322_5})},
        {10323, setSplitLine({Sprites.SplitLine_10323_1, Sprites.SplitLine_10323_2, Sprites.SplitLine_10323_3, Sprites.SplitLine_10323_4, Sprites.SplitLine_10323_5})},
        {10324, setSplitLine({Sprites.SplitLine_10324_1, Sprites.SplitLine_10324_2, Sprites.SplitLine_10324_3})},
        {10325, setSplitLine({Sprites.SplitLine_10325_1, Sprites.SplitLine_10325_2, Sprites.SplitLine_10325_3, Sprites.SplitLine_10325_4})},
        {10326, setSplitLine({Sprites.SplitLine_10326_1, Sprites.SplitLine_10326_2, Sprites.SplitLine_10326_3, Sprites.SplitLine_10326_4, Sprites.SplitLine_10326_5})},
        {10327, setSplitLine({Sprites.SplitLine_10327_1, Sprites.SplitLine_10327_2, Sprites.SplitLine_10327_3, Sprites.SplitLine_10327_4})},
        {10328, setSplitLine({Sprites.SplitLine_10328_1, Sprites.SplitLine_10328_2, Sprites.SplitLine_10328_3, Sprites.SplitLine_10328_4, Sprites.SplitLine_10328_5})},
        {10340, setSplitLine({Sprites.SplitLine_10340})},
        {10350, setSplitLine({Sprites.SplitLine_10350})},
        {10360, setSplitLine({Sprites.SplitLine_10360})},
        {10361, setSplitLine({Sprites.SplitLine_10361})},
        {10390, setSplitLine({Sprites.SplitLine_10390})},
        {10391, setSplitLine({Sprites.SplitLine_10391})},
        {10392, setSplitLine({Sprites.SplitLine_10392})},
        {10393, setSplitLine({Sprites.SplitLine_10393})},
    });
}
