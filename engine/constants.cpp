double maxSize = 2;                     	 // 额外判定大小
double interfaceGap = 0.05;                  // 组件间距
double targetAspectRatio = 1115.0 / 640.0;   // 目标屏幕宽高比
double highWidth = 0.1;                      // 高位宽度与低位宽度比
double defaultAppearTime = 7.4 / 5.0;        // note 默认出现时间
double minSFXDistance = 0.02;                // 最小音效时间
double judgelineMarginBottom = 0.25;         // 判定线距离底部距离
double judgelineHeight = 85.0 / 640.0;       // 判定线高度
double judglineMoveLength = 0.01;            // judgline 微调距离
double noteMoveLength = 0.02;                // note 微调距离
double splitLineLength = 0.01;               // 分裂线宽度
double arrowPercent = 1.6;                   // 箭头所占比例
double arrowSpeed = 20;                      // 箭头速率常数
double splitLineAnimationStart = 0.75;       // 分裂线起始动画长度, basic: 0.7595
double splitLineAnimationEnd = 0.20;         // 分裂线结束动画长度, basic: 0.7595
double effectLinearHeight = 280.0 / 640.0;   // 特效高度
double effectCircularHeight = 200.0 / 640.0; // 特效 2 高度
double effectDurationTime = 0.5;             // 特效持续时间
double effectDistance = 20.0 / 640.0;        // 特效微调距离
double hiddenLineHeight = 200.0 / 640.0;     // 隐藏线高度
double judgePerfectPlusRatio = 332.0 / 76.0; // 判定文字 Perfect+ 比例
double judgePerfectRatio = 307.0 / 76.0;     // 判定文字 Perfect 比例
double judgeGreatRatio = 247.0 / 76.0;       // 判定文字 Great 比例
double judgeGoodRatio = 237.0 / 76.0;        // 判定文字 Good 比例
double judgeBadRatio = 163.0 / 76.0;         // 判定文字 Bad 比例
double judgeMissRatio = 177.0 / 76.0;        // 判定文字 Miss 比例
double judgeAutoRatio = 216.0 / 76.0;        // 判定文字 Auto 比例
double judgeTextHeight = 0.15;               // 判定文字高度
double judgeTextDuration = 0.1;			     // 判定文字动画时长
double stageWidth = 0.7;                         // 单个舞台宽度
double stageHeight = 2.0;                        // 单个舞台高度
double stageFullWidth = stageWidth + 0.3;        // 单个舞台占有宽度
double stageTimelineWidth = stageWidth + 0.2;    // 时间线宽度
double stageTimeLength = 2.0;                    // 单个舞台容纳时间
double adjustDistance = 0.002;                   // 按键微调距离
double noteCountDistance = 10;                   // 按键计数长度
#if play || watch
double noteHeight = 85.0 / 640.0;            // note 高度
double tickWidth = 168.0 / 640.0;            // tick 宽度
double tickHeight = 112.0 / 640.0;           // tick 高度
double arrowWidth = 80.0 / 640.0;            // 箭头宽度
double arrowHeight = 240.0 / 640.0;          // 箭头高度
double syncLineHeight = 5.0 / 640.0;         // 同步线高度
#elif preview
double noteHeight = 0.04;                        // 按键高度
double tickWidth = 0.03;                         // tick 宽度
double tickHeight = 0.045;						// tick 高度
double arrowWidth = 0.03;						// 箭头宽度
double arrowHeight = 0.06;						// 箭头高度
double syncLineHeight = 0.003; 					// 同步线高度
#endif

#if play || watch
let mirror = LevelOption.get(Options.Mirror);
let speed = LevelOption.get(Options.NoteSpeed);
let hidden = LevelOption.get(Options.Hidden);
let splitRandom = LevelOption.get(Options.SplitRandom);
let splitLine = LevelOption.get(Options.SplitLine);
let syncLine = LevelOption.get(Options.SyncLine);
let lockAspectRatio = LevelOption.get(Options.LockAspectRatio);
let extraWidth = LevelOption.get(Options.ExtraWidth);
let levelSpeed = LevelOption.get(Options.Speed);
let opacity = LevelOption.get(Options.StageOpacity);
#elif preview
let mirror, speed, hidden, splitRandom, splitLine, syncLine, lockAspectRatio, extraWidth, levelSpeed, opacity;
#endif

#if play || watch
class stage {
	public:

	Variable<EntityMemoryId> w = If(lockAspectRatio == 0 || screen.aspectRatio < targetAspectRatio,
        screen.w * extraWidth,
        screen.h * targetAspectRatio);
    Variable<EntityMemoryId> h = If(lockAspectRatio == 0 || screen.aspectRatio > targetAspectRatio,
        screen.h,
        screen.w / targetAspectRatio);
    Variable<EntityMemoryId> l = -1 * w / 2;
    Variable<EntityMemoryId> r = w / 2;
    Variable<EntityMemoryId> t = h / 2;
    Variable<EntityMemoryId> b = -1 * h / 2;
}stage;
#elif preview
class stage {
	public:

	let w, h, l, r, t, b;
}stage;
#endif

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

let appearTime = 7.4 / speed;
let noteSpeed = stage.h / appearTime;

let t = If(
	lockAspectRatio && screen.aspectRatio < targetAspectRatio,
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

#if play || watch
Variable<LevelMemoryId> currentJudge;
Variable<LevelMemoryId> currentJudgeStartTime;
Array<LevelMemoryId, let> splitLineMemory(16);
let duration, noteCount, noteId;
#elif preview
Variable<PreviewDataId> duration;                   // 谱面时长
Variable<PreviewDataId> noteCount;                  // note 数量
Variable<EntitySharedMemoryId> noteId;              // note 编号
Array<TemporaryMemoryId, let> splitLineMemory(16);
let currentJudge, currentJudgeStartTime;
#endif
