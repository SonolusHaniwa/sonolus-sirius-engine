using namespace std;

const double maxSize = 0.5;                     // 判定大小
const var interfaceGap = 0.05;                  // 组件间距
const var targetAspectRatio = 1115.0 / 640.0;   // 目标屏幕宽高比
const var highWidth = 0.1;                      // 高位宽度与低位宽度比
const var defaultAppearTime = 3.0;              // note 默认出现时间
const var minSFXDistance = 0.02;                // 最小音效时间
const var judgelineMarginBottom = 0.25;         // 判定线距离底部距离
const var judgelineHeight = 85.0 / 640.0;       // 判定线高度
const var noteHeight = 85.0 / 640.0;            // note 高度
const var judglineMoveLength = 0.01;            // judgline 微调距离
const var noteMoveLength = 0.02;                // note 微调距离
const var splitLineLength = 0.01;               // 分裂线宽度
const var arrowWidth = 80.0 / 640.0;            // 箭头宽度
const var arrowHeight = 240.0 / 640.0;          // 箭头高度
const var arrowPercent = 1.6;                   // 箭头所占比例
const var arrowSpeed = 20;                      // 箭头速率常数
const var tickWidth = 168.0 / 640.0;            // tick 宽度
const var tickHeight = 112.0 / 640.0;           // tick 高度
const var syncLineHeight = 5.0 / 640.0;         // 同步线高度
const var splitLineAnimationStart = 0.75;       // 分裂线起始动画长度, basic: 0.7595
const var splitLineAnimationEnd = 0.20;         // 分裂线结束动画长度, basic: 0.7595
const var effectLinearHeight = 280.0 / 640.0;   // 特效高度
const var effectCircularHeight = 200.0 / 640.0; // 特效 2 高度
const var effectDurationTime = 0.5;             // 特效持续时间
const var effectDistance = 20.0 / 640.0;        // 特效微调距离
const var hiddenLineHeight = 200.0 / 640.0;     // 隐藏线高度
const var judgePerfectPlusRatio = 332.0 / 76.0; // 判定文字 Perfect+ 比例
const var judgePerfectRatio = 307.0 / 76.0;     // 判定文字 Perfect 比例
const var judgeGreatRatio = 247.0 / 76.0;       // 判定文字 Great 比例
const var judgeGoodRatio = 237.0 / 76.0;        // 判定文字 Good 比例
const var judgeBadRatio = 163.0 / 76.0;         // 判定文字 Bad 比例
const var judgeMissRatio = 177.0 / 76.0;        // 判定文字 Miss 比例
const var judgeAutoRatio = 216.0 / 76.0;        // 判定文字 Auto 比例
const var judgeTextHeight = 0.15;               // 判定文字高度
const var judgeTextDuration = 0.2;				// 判定文字动画时长

class Vec {
    public:

    var x, y;
    Vec(){}
    Vec(var x, var y): x(x), y(y){}

    Vec operator + (Vec v) {
        return Vec(x + v.x, y + v.y);
    };
    Vec operator - (Vec v) {
        return Vec(x - v.x, y - v.y);
    };
    var operator * (Vec v) {
        return x * v.x + y * v.y;
    };
    var operator ^ (Vec v) {
        return x * v.y - y * v.x;
    }
};

class stage {
	public:

	const var w = IF (LevelOption.get(Options.LockAspectRatio) == 0 || screen.aspectRatio < targetAspectRatio) {
        screen.w * LevelOption.get(Options.ExtraWidth)
    } ELSE {
        screen.h * targetAspectRatio
    } FI;
    const var h = IF (LevelOption.get(Options.LockAspectRatio) == 0 || screen.aspectRatio > targetAspectRatio) {
        screen.h
    } ELSE {
        screen.w / targetAspectRatio
    } FI;
    const var l = -1 * w / 2;
    const var r = w / 2;
    const var t = h / 2;
    const var b = -1 * h / 2;
}stage;

class judgline {
    public:

    // 需要微调
    var lbX = Lerp(stage.l, stage.l * highWidth, judgelineMarginBottom - judgelineHeight / stage.h / 2) - judglineMoveLength;
    var lbY = stage.b + stage.h * judgelineMarginBottom - judgelineHeight / 2;
    var ltX = Lerp(stage.l, stage.l * highWidth, judgelineMarginBottom + judgelineHeight / stage.h / 2) - judglineMoveLength;
    var ltY = lbY + judgelineHeight;
    var rbX = Lerp(stage.r, stage.r * highWidth, judgelineMarginBottom - judgelineHeight / stage.h / 2) + judglineMoveLength;
    var rbY = lbY;
    var rtX = Lerp(stage.r, stage.r * highWidth, judgelineMarginBottom + judgelineHeight / stage.h / 2) + judglineMoveLength;
    var rtY = ltY;
}judgline;

var ease(var x) {
    return Remap(Power({1.06, -45}), 1.06, 0, 1.06, Power({1.06, 45 * (x - 1)}));
}

const var noteSpeed = stage.h / defaultAppearTime * Power({1.3, LevelOption.get(Options.NoteSpeed) - 5});
const var appearTime = stage.h / noteSpeed;
const var hiddenPercent = ease(LevelOption.get(Options.Hidden));

const var t = If(
	LevelOption.get(Options.LockAspectRatio) && screen.aspectRatio < targetAspectRatio,
	screen.w / targetAspectRatio * 0.5,
	screen.t
);
const var b = t - stage.h;

class judgment {
	public:

    var perfectPlus = 0.025;
    var perfect = 0.04;
    var great = 0.07;
    var good = 0.1;
    var bad = 0.125;
}judgment;

class judgeText {
    public:

    var perfectPlus = 0.025;
    var perfect = 0.04;
    var great = 0.07;
    var good = 0.1;
    var bad = 0.125;
}judgeText;

class score {
	public:

	var perfect = 1;
	var great = 0.8;
	var good = 0.5;
}score;

class line {
    public:

    var offset = 0;
    Vec lb, lt, rb, rt;
    line(){}
    line(var offset) {
        lb.x = Lerp(stage.l, stage.r, (offset - 1) / 12);
        lb.y = stage.b;
        lt.x = Lerp(stage.l * highWidth, stage.r * highWidth, (offset - 1) / 12);
        lt.y = stage.t;
        rb.x = Lerp(stage.l, stage.r, offset / 12);
        rb.y = stage.b;
        rt.x = Lerp(stage.l * highWidth, stage.r * highWidth, offset / 12);
        rt.y = stage.t;
    };
    line operator [] (var offset) {
        return line(offset);
    };

    // var inClickBox(Touch x, var L, var R, bool strict = false) {
    //     Vec P = Vec(x.x, x.y);
    //     Vec lb = line(L).lb, lt = line(L).lt, rb = line(R).rb, rt = line(R).rt;
    //     var judgOffset = maxSize / 2 * (judgline.rbX - judgline.lbX) / 12;
    //     if (!strict) lb.x -= judgOffset, lt.x -= judgOffset, rb.x += judgOffset, rt.x += judgOffset;
    //     return ((P - lb) ^ (lt - lb)) >= 0 && ((P - lt) ^ (rt - lt)) >= 0 && ((P - rt) ^ (rb - rt)) >= 0 && ((P - rb) ^ (lb - rb)) >= 0;
    // }

    Vec getPosition(var percent) {
        var RealPercent = IF (percent <= hiddenPercent) { hiddenPercent } ELSE { percent } FI;
        return Vec(
            Lerp((lt.x + rt.x) / 2, (lb.x + rb.x) / 2, RealPercent * (1 - judgelineMarginBottom)),
            Lerp(lt.y, lb.y, RealPercent * (1 - judgelineMarginBottom))
        );
    }

    var getWidth(var percent) {
        var RealPercent = IF (percent <= hiddenPercent) { hiddenPercent } ELSE { percent } FI;
        return Lerp((rt.x - lt.x), (rb.x - lb.x), RealPercent * (1 - judgelineMarginBottom));
    }

    Vec getFullPosition(var percent) {
        var RealPercent = percent;
        return Vec(
            Lerp((lt.x + rt.x) / 2, (lb.x + rb.x) / 2, RealPercent),
            Lerp(lt.y, lb.y, RealPercent)
        );
    }

    var getFullWidth(var percent) {
        var RealPercent = percent;
        return Lerp((rt.x - lt.x), (rb.x - lb.x), RealPercent);
    }
}lines;

auto splitLineMemory = Array<EntityMemoryId>(16);
Variable<LevelMemoryId> currentJudge;
Variable<LevelMemoryId> currentJudgeStartTime;
Variable<EntityMemoryId> despawned;
