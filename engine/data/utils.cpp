SonolusApi setSplitLine(vector<int> lines) {
	FUNCBEGIN
	for (int i = 0; i < 16; i++) splitLineMemory.set(i, lines[i % lines.size()]);
	return VOID;
}

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

    pair<let, let> getPosition(let percent) {
        let RealPercent = If(percent <= hiddenPercent, hiddenPercent, percent);
        return {
            Lerp((ltx + rtx) / 2, (lbx + rbx) / 2, RealPercent * (1 - judgelineMarginBottom)),
            Lerp(lty, lby, RealPercent * (1 - judgelineMarginBottom))
        };
    }

    let getWidth(let percent) {
        let RealPercent = If(percent <= hiddenPercent, hiddenPercent, percent);
        return Lerp((rtx - ltx), (rbx - lbx), RealPercent * (1 - judgelineMarginBottom));
    }

    pair<let, let> getFullPosition(let percent) {
        let RealPercent = percent;
        return {
            Lerp((ltx + rtx) / 2, (lbx + rbx) / 2, RealPercent),
            Lerp(lty, lby, RealPercent)
        };
    }

    let getFullWidth(let percent) {
        let RealPercent = percent;
        return Lerp((rtx - ltx), (rbx - lbx), RealPercent);
    }

}lines;

Rect getHitbox(let l, let r) {
	let L = lines[l].getPosition(1).first;
	let R = lines[r].getPosition(1).first;
	let width = lines[l].getWidth(1);
	return {
		l: L - width / 2,
		r: R + width / 2,
		b: -1,
		t: 1
	};
}

Rect getFullHitbox(let l, let r) {
	let L = lines[l].getPosition(1).first;
	let R = lines[r].getPosition(1).first;
	let width = lines[l].getWidth(1) * (1 + maxSize);
	return {
		l: L - width / 2,
		r: R + width / 2,
		b: -1,
		t: 1
	};
}

SonolusApi drawNormalNote(let sprite, let lane, let enLane, let beat) {
	FUNCBEGIN
    auto w = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1));
    auto multiplier = w / lines[lane].getWidth(1);
    auto c1 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) - noteHeight / 2 / stage.h * multiplier);
    auto c2 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) + noteHeight / 2 / stage.h * multiplier);
    auto c3 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) - noteHeight / 2 / stage.h * multiplier);
    auto c4 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) + noteHeight / 2 / stage.h * multiplier);
    auto w1 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) - noteHeight / 2 / stage.h * multiplier);
    auto w2 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) + noteHeight / 2 / stage.h * multiplier);
    auto lb = pair<let, let>{ c2.first + -1 * w2 / 2 + noteMoveLength * w1 / lines[lane].getWidth(1), c2.second };
    auto lt = pair<let, let>{ c1.first + -1 * w1 / 2 + noteMoveLength * w2 / lines[lane].getWidth(1), c1.second };
    auto rb = pair<let, let>{ c4.first + 1 * w2 / 2 - noteMoveLength * w1 / lines[lane].getWidth(1), c4.second };
    auto rt = pair<let, let>{ c3.first + w1 / 2 - noteMoveLength * w2 / lines[lane].getWidth(1), c3.second };
    Draw(sprite, lb.first, lb.second, lt.first, lt.second, rt.first, rt.second, rb.first, rb.second, 1000 - beat, 1);
    return VOID;
}
