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

Rect getHitbox(var l, var r) {
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

Rect getFullHitbox(var l, var r) {
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
