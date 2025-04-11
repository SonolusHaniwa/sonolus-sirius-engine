// SonolusApi setSplitLine(vector<int> lines) {
// 
// 	for (int i = 0; i < 16; i++) splitLineMemory.set(i, lines[i % lines.size()]);
// 	return VOID;
// }

FuncNode ease(FuncNode x) {
	return Remap(Power({1.06, -45}), 1.06, 0, 1.06, Power({1.06, 45 * (x - 1)}));
}

FuncNode hiddenPercent = ease(hidden);
class line {
    public:

    var offset;
    var lbx, lby, ltx, lty, rbx, rby, rtx, rty;
    line(){}
    line(var offset) {
        lbx = Lerp(stage.l, stage.r, (offset - 1) / 12);
        lby = stage.b;
        ltx = Lerp(stage.l * highWidth, stage.r * highWidth, (offset - 1) / 12);
        lty = stage.t;
        rbx = Lerp(stage.l, stage.r, offset / 12);
        rby = stage.b;
        rtx = Lerp(stage.l * highWidth, stage.r * highWidth, offset / 12);
        rty = stage.t;
    };
    line operator [] (var offset) {
        return line(offset);
    };

    Vec getPosition(var percent) {
    	percent = If(percent <= hiddenPercent, hiddenPercent, percent);
        return {
            Lerp((ltx + rtx) / 2, (lbx + rbx) / 2, percent * (1 - judgelineMarginBottom)),
            Lerp(lty, lby, percent * (1 - judgelineMarginBottom))
        };
    }

    var getWidth(var percent) {
    	percent = If(percent <= hiddenPercent, hiddenPercent, percent);
        return Lerp((rtx - ltx), (rbx - lbx), percent * (1 - judgelineMarginBottom));
    }

    Vec getFullPosition(var percent) {
        return {
            Lerp((ltx + rtx) / 2, (lbx + rbx) / 2, percent),
            Lerp(lty, lby, percent)
        };
    }

    var getFullWidth(var percent) {
        return Lerp((rtx - ltx), (rbx - lbx), percent);
    }
}lines;

Rect getHitbox(var l, var r) {
	var L = lines[l].getPosition(1).x;
	var R = lines[r].getPosition(1).x;
	var width = lines[l].getWidth(1);
	return {
	    L - width / 2,
		-1,
		R + width / 2,
		1
    };
}

Rect getFullHitbox(var l, var r) {
	var L = lines[l].getPosition(1).x;
	var R = lines[r].getPosition(1).x;
	var width = lines[l].getWidth(1) * (maxSize + 1);
	return {
		L - width / 2,
		-1,
		R + width / 2,
		1
	};
}