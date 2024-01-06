// SonolusApi setSplitLine(vector<int> lines) {
// 	FUNCBEGIN
// 	for (int i = 0; i < 16; i++) splitLineMemory.set(i, lines[i % lines.size()]);
// 	return VOID;
// }

let ease(let x) {
	return Remap(Power({1.06, -45}), 1.06, 0, 1.06, Power({1.06, 45 * (x - 1)}));
}

let hiddenPercent = ease(LevelOption.get(Options.Hidden));
class line {
    public:

    let offset = 0;
    let lbx, lby, ltx, lty, rbx, rby, rtx, rty;
    line(){}
    line(let offset) {
        lbx = Lerp(stage.l, stage.r, (offset - 1) / 12);
        lby = stage.b;
        ltx = Lerp(stage.l * highWidth, stage.r * highWidth, (offset - 1) / 12);
        lty = stage.t;
        rbx = Lerp(stage.l, stage.r, offset / 12);
        rby = stage.b;
        rtx = Lerp(stage.l * highWidth, stage.r * highWidth, offset / 12);
        rty = stage.t;
    };
    line operator [] (let offset) {
        return line(offset);
    };

    Vec getPosition(let percent) {
    	percent = If(percent <= hiddenPercent, hiddenPercent, percent);
        return Vec(
            Lerp((ltx + rtx) / 2, (lbx + rbx) / 2, percent * (1 - judgelineMarginBottom)),
            Lerp(lty, lby, percent * (1 - judgelineMarginBottom))
        );
    }

    let getWidth(let percent) {
    	percent = If(percent <= hiddenPercent, hiddenPercent, percent);
        return Lerp((rtx - ltx), (rbx - lbx), percent * (1 - judgelineMarginBottom));
    }

    Vec getFullPosition(let percent) {
        return Vec(
            Lerp((ltx + rtx) / 2, (lbx + rbx) / 2, percent),
            Lerp(lty, lby, percent)
        );
    }

    let getFullWidth(let percent) {
        return Lerp((rtx - ltx), (rbx - lbx), percent);
    }

}lines;

Rect getHitbox(let l, let r) {
	let L = lines[l].getPosition(1).x;
	let R = lines[r].getPosition(1).x;
	let width = lines[l].getWidth(1);
	return {
		l: L - width / 2,
		r: R + width / 2,
		b: -1,
		t: 1
	};
}

Rect getFullHitbox(let l, let r) {
	let L = lines[l].getPosition(1).x;
	let R = lines[r].getPosition(1).x;
	let width = lines[l].getWidth(1) * (maxSize + 1);
	return {
		l: L - width / 2,
		r: R + width / 2,
		b: -1,
		t: 1
	};
}

SonolusApi drawNormalNote(let sprite, let lane, let enLane, let beat) {
	FUNCBEGIN
	var p = ease((times.now - beat) / appearTime + 1);
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
    Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 1000 - beat, 1);
    return VOID;
}

SonolusApi drawArrow(let lane, let enLane, let beat) {
	FUNCBEGIN
	var p = ease((times.now - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p);
    auto c2 = line2.getPosition(p);
    auto W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    auto L = c1.x - w / 2, R = c2.x + w / 2;
    auto num = w * (enLane - lane + 1) / 2 * arrowPercent / W;
    IF (p > hiddenPercent) {
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, 
            	L + (i - 1) * W / 2, c1.y, 
            	L + (i - 1) * W / 2, c1.y + H / 2, 
                L + (i + 1) * W / 2, c1.y + H / 2, 
                L + (i + 1) * W / 2, c1.y, 
                1001 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num);
        } DONE
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, 
            	R - (i - 1) * W / 2, c2.y, 
            	R - (i - 1) * W / 2, c2.y + H / 2, 
                R - (i + 1) * W / 2, c2.y + H / 2, 
                R - (i + 1) * W / 2, c2.y, 
                1001 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num);
        } DONE
    } FI
    return VOID;
}

SonolusApi drawLeftArrow(let lane, let enLane, let beat) {
	FUNCBEGIN
	var p = ease((times.now - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p);
    auto c2 = line2.getPosition(p);
    auto W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    auto L = c1.x - w / 2, R = c2.x + w / 2;
    auto num = w * (enLane - lane + 1) * arrowPercent / W;
    IF (p > hiddenPercent) {
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, 
            	L + (i - 1) * W / 2, c1.y, 
            	L + (i - 1) * W / 2, c1.y + H / 2, 
                L + (i + 1) * W / 2, c1.y + H / 2, 
                L + (i + 1) * W / 2, c1.y, 
                1001 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num);
        } DONE
    } FI
    return VOID;
}

SonolusApi drawRightArrow(let lane, let enLane, let beat) {
	FUNCBEGIN
	var p = ease((times.now - beat) / appearTime + 1);
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(p);
    auto multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p);
    auto c2 = line2.getPosition(p);
    auto W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    auto L = c1.x - w / 2, R = c2.x + w / 2;
    auto num = w * (enLane - lane + 1) * arrowPercent / W;
    IF (p > hiddenPercent) {
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, 
            	R - (i - 1) * W / 2, c2.y, 
            	R - (i - 1) * W / 2, c2.y + H / 2, 
                R - (i + 1) * W / 2, c2.y + H / 2, 
                R - (i + 1) * W / 2, c2.y, 
                1001 - beat, 
                1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num);
        } DONE
    } FI
    return VOID;
}

SonolusApi drawHoldEighth(let sprite, let lane, let enLane, let stBeat, let enBeat, let isHolding) {
    FUNCBEGIN
	auto line1 = lines[lane], line2 = lines[enLane];
    auto w = line1.getWidth(1);
    var p1 = ease(Min(1, Min(1, times.now - stBeat) / appearTime + 1)),
        p2 = ease(Min(1, Min(1, times.now - enBeat) / appearTime + 1));
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
	IF (isHolding) {
        let val = Floor(times.now / 0.1) % 2 == 1;
        IF (val == 1) Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 4, 0.85);
        ELSE Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 4, 0.8); FI
    } ELSE Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 4, 0.8); FI
    return VOID;
}

SonolusApi drawTick(let sprite, let beat, let lane, let enLane) {
	FUNCBEGIN
	var p = ease((times.now - beat) / appearTime + 1);
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
	Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 1000 - beat, 0.5);
	return VOID;
}

SonolusApi drawSyncLine(let beat, let lane, let enLane) {
	FUNCBEGIN
	var p = ease((times.now - beat) / appearTime + 1);
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
    Draw(Sprites.SyncLine, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 5, 0.8);
    return VOID;
}

SonolusApi drawHiddenLine() {
	FUNCBEGIN
    let sprite = Sprites.HiddenLine, lane = 1, enLane = 12, beat = times.now + (1 - LevelOption.get(Options.Hidden)) * appearTime;
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
    Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 10, 0.6);
    return VOID;
}

SonolusApi spawnLineEffect(let lane, let enLane) {
	FUNCBEGIN
	let wt = lines[lane].getFullWidth(0), wb = lines[lane].getFullWidth(1);
	auto lb = lines[lane].getFullPosition(1) + Vec(-1 * wb / 2.0, 0), 
		 rb = lines[enLane].getFullPosition(1) + Vec(wb / 2.0, 0);
	auto lt = lines[lane].getFullPosition(0) + Vec(-1 * wt / 2.0, 0), 
		 rt = lines[enLane].getFullPosition(0) + Vec(wt / 2.0, 0);
	SpawnParticleEffect(Effects.Lane, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, effectDurationTime, 0);
	return VOID;
}

SonolusApi spawnEffect(let linear, let circular, let lane, let enLane) {
	FUNCBEGIN
	let w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto lb = c1 + Vec(-1 * w / 2, 0), lt = c1 + Vec(-1 * w / 2, effectLinearHeight);
	auto rb = c2 + Vec(w / 2, 0), rt = c2 + Vec(w / 2, effectLinearHeight);
	auto lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	auto rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	SpawnParticleEffect(linear, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, effectDurationTime, 0);
	SpawnParticleEffect(circular, lb2.x, lb2.y, lt2.x, lt2.y, rt2.x, rt2.y, rb2.x, rb2.y, effectDurationTime, 0);
	spawnLineEffect(lane, enLane);
	return VOID;
}

SonolusApi spawnHoldEffect(let effect, let lane, let enLane) {
	FUNCBEGIN
	let w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	auto lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	auto rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	SpawnParticleEffect(effect, lb2.x, lb2.y, lt2.x, lt2.y, rt2.x, rt2.y, rb2.x, rb2.y, effectDurationTime, 1);
	return VAR;
}

SonolusApi SpawnSubJudgeText(let sprite) {
	FUNCBEGIN
    IF (currentJudgeStartTime.get() == times.now) {
        currentJudge.set(Max(currentJudge.get(), sprite));
    } ELSE {
        currentJudge.set(sprite);
        currentJudgeStartTime.set(times.now);
    } FI
    return VOID;
}

// 上面为 0，下面为 1
SonolusApi drawLine(let id, let st, let en, let a, let sprite) {
	FUNCBEGIN
    let w = lines[id + 1].getWidth(1);
    Vec c1 = lines[id + 1].getFullPosition(ease(st));
    Vec c2 = lines[id + 1].getFullPosition(ease(en));
	let w1 = lines[id + 1].getFullWidth(ease(st));
	let w2 = lines[id + 1].getFullWidth(ease(en));
    let move = splitLineLength / 2;
	Vec c3 = c1 + Vec(-1 * w1 / 2, 0);
	Vec c4 = c2 + Vec(-1 * w2 / 2, 0);
	Vec lb = c4 + Vec(-1 * move * w2 / w, 0), lt = c3 + Vec(-1 * move * w1 / w, 0);
	Vec rb = c4 + Vec(move * w2 / w, 0), rt = c3 + Vec(move * w1 / w, 0);
	Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 10000, a * LevelOption.get(Options.SplitLine));
	return VAR;
}

SonolusApi drawEndLine(let st, let en, let a, let sprite) {
	FUNCBEGIN
    let w = lines[12].getWidth(1);
    Vec c1 = lines[12].getFullPosition(ease(st));
    Vec c2 = lines[12].getFullPosition(ease(en));
	let w1 = lines[12].getFullWidth(ease(st));
	let w2 = lines[12].getFullWidth(ease(en));
    let move = splitLineLength / 2;
	Vec c3 = c1 + Vec(1 * w1 / 2, 0);
	Vec c4 = c2 + Vec(1 * w2 / 2, 0);
	Vec lb = c4 + Vec(-1 * move * w2 / w, 0), lt = c3 + Vec(-1 * move * w1 / w, 0);
	Vec rb = c4 + Vec(move * w2 / w, 0), rt = c3 + Vec(move * w1 / w, 0);
	Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 10000, a * LevelOption.get(Options.SplitLine));
	return VOID;
}

SonolusApi drawSplitLine(let split) {
	FUNCBEGIN
    Run(drawLine(0, 0, 1, 1, splitLineMemory[0]));
    drawEndLine(0, 1, 1, splitLineMemory[split]);
    Run(Switch(split, {
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
    }));
    return VOID;
}

SonolusApi drawDisappearLine(let t, let split) {
	FUNCBEGIN
    let p = 1;
    let a = 1 - t / splitLineAnimationEnd;
    Run(drawLine(0, 0, p, a, splitLineMemory[0]));
    drawEndLine(0, p, a, splitLineMemory[split]);
    Run(Switch(split, {
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
    }));
    return VOID;
}

SonolusApi drawAppearLine(let t, let split) {
	FUNCBEGIN
    let p = 1 - t / splitLineAnimationStart;
    let a = 1;
    Run(drawLine(0, p, 1, a, splitLineMemory[0]));
    drawEndLine(p, 1, a, splitLineMemory[split]);
    Run(Switch(split, {
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
            drawLine(10, p, 1, a, splitLineMemory[5])
        }}
    }));
    return VOID;
}

SonolusApi setSplitLine(vector<let> lines) {
	FUNCBEGIN
    for (int i = 0; i < 16; i++)
        splitLineMemory.set(i, lines[i % lines.size()]);
    return VOID;
}
