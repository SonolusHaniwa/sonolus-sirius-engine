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
