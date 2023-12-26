let maxSize = 0.5;                     	  // 判定大小
let interfaceGap = 0.05;                  // 组件间距
let targetAspectRatio = 1115.0 / 640.0;   // 目标屏幕宽高比
let highWidth = 0.1;                      // 高位宽度与低位宽度比
let defaultAppearTime = 7.4 / 5.0;        // note 默认出现时间
let minSFXDistance = 0.02;                // 最小音效时间
let judgelineMarginBottom = 0.25;         // 判定线距离底部距离
let judgelineHeight = 85.0 / 640.0;       // 判定线高度
let noteHeight = 85.0 / 640.0;            // note 高度
let judglineMoveLength = 0.01;            // judgline 微调距离
let noteMoveLength = 0.02;                // note 微调距离
let splitLineLength = 0.01;               // 分裂线宽度
let arrowWidth = 80.0 / 640.0;            // 箭头宽度
let arrowHeight = 240.0 / 640.0;          // 箭头高度
let arrowPercent = 1.6;                   // 箭头所占比例
let arrowSpeed = 20;                      // 箭头速率常数
let tickWidth = 168.0 / 640.0;            // tick 宽度
let tickHeight = 112.0 / 640.0;           // tick 高度
let syncLineHeight = 5.0 / 640.0;         // 同步线高度
let splitLineAnimationStart = 0.75;       // 分裂线起始动画长度, basic: 0.7595
let splitLineAnimationEnd = 0.20;         // 分裂线结束动画长度, basic: 0.7595
let effectLinearHeight = 280.0 / 640.0;   // 特效高度
let effectCircularHeight = 200.0 / 640.0; // 特效 2 高度
let effectDurationTime = 0.5;             // 特效持续时间
let effectDistance = 20.0 / 640.0;        // 特效微调距离
let hiddenLineHeight = 200.0 / 640.0;     // 隐藏线高度
let judgePerfectPlusRatio = 332.0 / 76.0; // 判定文字 Perfect+ 比例
let judgePerfectRatio = 307.0 / 76.0;     // 判定文字 Perfect 比例
let judgeGreatRatio = 247.0 / 76.0;       // 判定文字 Great 比例
let judgeGoodRatio = 237.0 / 76.0;        // 判定文字 Good 比例
let judgeBadRatio = 163.0 / 76.0;         // 判定文字 Bad 比例
let judgeMissRatio = 177.0 / 76.0;        // 判定文字 Miss 比例
let judgeAutoRatio = 216.0 / 76.0;        // 判定文字 Auto 比例
let judgeTextHeight = 0.15;               // 判定文字高度
let judgeTextDuration = 0.2;			  // 判定文字动画时长

class stage {
	public:

	let w = If(LevelOption.get(Options.LockAspectRatio) == 0 || screen.aspectRatio < targetAspectRatio,
        screen.w * LevelOption.get(Options.ExtraWidth),
        screen.h * targetAspectRatio);
    let h = If(LevelOption.get(Options.LockAspectRatio) == 0 || screen.aspectRatio > targetAspectRatio,
        screen.h,
        screen.w / targetAspectRatio);
    let l = -1 * w / 2;
    let r = w / 2;
    let t = h / 2;
    let b = -1 * h / 2;
}stage;

class judgline {
    public:

    // 需要微调
    let lbX = Lerp(stage.l, stage.l * highWidth, judgelineMarginBottom - judgelineHeight / stage.h / 2) - judglineMoveLength;
    let lbY = stage.b + stage.h * judgelineMarginBottom - judgelineHeight / 2;
    let ltX = Lerp(stage.l, stage.l * highWidth, judgelineMarginBottom + judgelineHeight / stage.h / 2) - judglineMoveLength;
    let ltY = lbY + judgelineHeight;
    let rbX = Lerp(stage.r, stage.r * highWidth, judgelineMarginBottom - judgelineHeight / stage.h / 2) + judglineMoveLength;
    let rbY = lbY;
    let rtX = Lerp(stage.r, stage.r * highWidth, judgelineMarginBottom + judgelineHeight / stage.h / 2) + judglineMoveLength;
    let rtY = ltY;
}judgline;

let appearTime = (7.4 / LevelOption.get(Options.NoteSpeed));
let noteSpeed = stage.h / appearTime;

let t = If(
	LevelOption.get(Options.LockAspectRatio) && screen.aspectRatio < targetAspectRatio,
	screen.w / targetAspectRatio * 0.5,
	screen.t
);
let b = t - stage.h;

class judgment {
	public:

    let perfectPlus = 0.025;
    let perfect = 0.04;
    let great = 0.07;
    let good = 0.1;
    let bad = 0.125;
}judgment;

class judgeText {
    public:

    let perfectPlus = 0.025;
    let perfect = 0.04;
    let great = 0.07;
    let good = 0.1;
    let bad = 0.125;
}judgeText;

class score {
	public:

	let perfect = 1;
	let great = 0.8;
	let good = 0.5;
}score;

auto splitLineMemory = Array<EntityMemoryId, FuncNode>(16);
Variable<LevelMemoryId> currentJudge;
Variable<LevelMemoryId> currentJudgeStartTime;
