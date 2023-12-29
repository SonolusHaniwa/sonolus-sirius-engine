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
	let width = lines[l].getWidth(1) * maxSize / (r - l + 1);
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
    // Debuglog(w2 / 2 + noteMoveLength * w1 / line1.getWidth(1)); Debuglog(c2.x);
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
    let multiplier = w / line1.getWidth(1);
    auto c1 = line1.getPosition(p);
    auto c2 = line2.getPosition(p);
    let W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    let L = c1.x - w / 2, R = c2.x + w / 2;
    let num = w * (enLane - lane + 1) / 2 * arrowPercent / W;
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
