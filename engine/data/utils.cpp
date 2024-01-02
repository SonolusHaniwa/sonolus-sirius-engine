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
