double maxSize = 2;                     	 // 额外判定大小
double interfaceGap = 0.05;                  // 组件间距
double targetAspectRatio = 1115.0 / 640.0;   // 目标屏幕宽高比
double highWidth = 0.1;                      // 高位宽度与低位宽度比
double defaultAppearTime = 7.4 / 5.0;        // note 默认出现时间
double minSFXDistance = 0.02;                // 最小音效时间
double judgelineMarginBottom = 0.25;         // 判定线距离底部距离
double judgelineHeight = 0.133;              // 判定线高度
double judglineMoveLength = 0.01;            // judgline 微调距离
double noteMoveLength = 0.02;                // note 微调距离
double splitLineLength = 0.02;               // 分裂线宽度
double arrowPercent = 1.6;                   // 箭头所占比例
double arrowSpeed = 20;                      // 箭头速率常数
double splitLineAnimationStart = 0.75;       // 分裂线起始动画长度, basic: 0.7595
double splitLineAnimationEnd = 0.20;         // 分裂线结束动画长度, basic: 0.7595
double effectLinearHeight = 0.4375;          // 特效高度
double effectCircularHeight = 0.3125;        // 特效 2 高度
double effectDurationTime = 0.5;             // 特效持续时间
double effectDistance = 0.03125;             // 特效微调距离
double hiddenLineHeight = 0.3125;            // 隐藏线高度
double judgePerfectPlusRatio = 332.0 / 76.0; // 判定文字 Perfect+ 比例
double judgePerfectRatio = 307.0 / 76.0;     // 判定文字 Perfect 比例
double judgeGreatRatio = 247.0 / 76.0;       // 判定文字 Great 比例
double judgeGoodRatio = 237.0 / 76.0;        // 判定文字 Good 比例
double judgeBadRatio = 163.0 / 76.0;         // 判定文字 Bad 比例
double judgeMissRatio = 177.0 / 76.0;        // 判定文字 Miss 比例
double judgeAutoRatio = 216.0 / 76.0;        // 判定文字 Auto 比例
double judgeFastRatio = 121.0 / 52.0;        // 判定文字 Fast 比例
double judgeSlowRatio = 143.0 / 52.0;        // 判定文字 Slow 比例
double judgeTextHeight = 0.15;               // 判定文字高度
double judgeText2Height = 0.08;              // 判定文字 2 高度
double judgeTextDistance = 0.0;              // 判定文字间距
double judgeTextDuration = 0.1;			     // 判定文字动画时长
double comboNormalRatio = 154.0 / 37.0;      // 普通 combo 文字比例
double comboNormal0Ratio = 89.0 / 124.0;     // 普通 combo 0 比例
double comboNormal1Ratio = 89.0 / 119.0;     // 普通 combo 1 比例
double comboNormal2Ratio = 94.0 / 121.0;     // 普通 combo 2 比例
double comboNormal3Ratio = 90.0 / 124.0;     // 普通 combo 3 比例
double comboNormal4Ratio = 91.0 / 119.0;     // 普通 combo 4 比例
double comboNormal5Ratio = 89.0 / 122.0;     // 普通 combo 5 比例
double comboNormal6Ratio = 91.0 / 124.0;     // 普通 combo 6 比例
double comboNormal7Ratio = 91.0 / 119.0;     // 普通 combo 7 比例
double comboNormal8Ratio = 90.0 / 124.0;     // 普通 combo 8 比例
double comboNormal9Ratio = 90.0 / 124.0;     // 普通 combo 9 比例
double comboFCRatio = 154.0 / 37.0;          // FC combo 文字比例
double comboFC0Ratio = 89.0 / 124.0;         // FC combo 0 比例
double comboFC1Ratio = 89.0 / 119.0;         // FC combo 1 比例
double comboFC2Ratio = 94.0 / 121.0;         // FC combo 2 比例
double comboFC3Ratio = 90.0 / 124.0;         // FC combo 3 比例
double comboFC4Ratio = 91.0 / 119.0;         // FC combo 4 比例
double comboFC5Ratio = 89.0 / 122.0;         // FC combo 5 比例
double comboFC6Ratio = 91.0 / 124.0;         // FC combo 6 比例
double comboFC7Ratio = 91.0 / 119.0;         // FC combo 7 比例
double comboFC8Ratio = 90.0 / 124.0;         // FC combo 8 比例
double comboFC9Ratio = 90.0 / 124.0;         // FC combo 9 比例
double comboAPRatio = 168.0 / 48.0;          // AP combo 文字比例
double comboAP0Ratio = 118.0 / 148.0;        // AP combo 0 比例
double comboAP1Ratio = 118.0 / 148.0;        // AP combo 1 比例
double comboAP2Ratio = 118.0 / 148.0;        // AP combo 2 比例
double comboAP3Ratio = 118.0 / 148.0;        // AP combo 3 比例
double comboAP4Ratio = 118.0 / 148.0;        // AP combo 4 比例
double comboAP5Ratio = 118.0 / 148.0;        // AP combo 5 比例
double comboAP6Ratio = 118.0 / 148.0;        // AP combo 6 比例
double comboAP7Ratio = 118.0 / 148.0;        // AP combo 7 比例
double comboAP8Ratio = 118.0 / 148.0;        // AP combo 8 比例
double comboAP9Ratio = 118.0 / 148.0;        // AP combo 9 比例
double comboTextHeight = 0.05;               // combo 文字高度
double comboAPTextHeight = 0.066;            // AP combo 文字高度
double comboTextDistance = 0.015;            // combo 文字间距
double comboAPTextDistance = 0.003;          // AP combo 文字间距
double comboNumberHeight = 0.2;              // combo 数字高度
double comboAPNumberHeight = 0.238;          // AP 数字高度
double comboNumberDistance = 0.0;            // combo 数字间距
double comboAPNumberDistance = -0.048;       // AP combo 数字间距
double stageWidth = 0.7;                         // 单个舞台宽度
double stageHeight = 2.0;                        // 单个舞台高度
double stageFullWidth = stageWidth + 0.3;        // 单个舞台占有宽度
double stageTimelineWidth = stageWidth + 0.2;    // 时间线宽度
double stageTimeLength = 2.0;                    // 单个舞台容纳时间
double adjustDistance = 0.002;                   // 按键微调距离
double noteCountDistance = 10;                   // 按键计数长度
double noteBorderPercent = 0.02;             // note 边框比例 (相对于 Stage 大小)
#if play || watch
double noteHeight = 85.0 / 640.0;            // note 高度
double tickWidth = 168.0 / 640.0;            // tick 宽度
double tickHeight = 112.0 / 640.0;           // tick 高度
double arrowWidth = 80.0 / 640.0;            // 箭头宽度
double arrowHeight = 240.0 / 640.0;          // 箭头高度
double syncLineHeight = 5.0 / 640.0;         // 同步线高度
double lineHeight = 114514;                  // 时间线高度(没用)
#elif preview
double noteHeight = 0.04;                    // 按键高度
double tickWidth = 0.03;                     // tick 宽度
double tickHeight = 0.045;				     // tick 高度
double arrowWidth = 0.03;				     // 箭头宽度
double arrowHeight = 0.06;					 // 箭头高度
double syncLineHeight = 0.003; 				 // 同步线高度
double lineHeight = 0.008;                   // 时间线高度
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
let judgeType = LevelOption.get(Options.JudgeType);
#elif preview
let mirror, speed, hidden, splitRandom, splitLine, syncLine, lockAspectRatio, extraWidth, levelSpeed, opacity, judgeType;
#endif

let hasJudgment = HasSkinSprite(Sprites.JudgePerfectPlus);
let hasCombo = HasSkinSprite(Sprites.ComboNormalText);

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
Variable<LevelMemoryId> currentJudgeDeltaTime;
Variable<LevelMemoryId> currentJudgeStartTime;
Array<LevelMemoryId, let> splitLineMemory(16);
Variable<LevelMemoryId> comboNumber;
Variable<LevelMemoryId> comboStatus;
let duration, noteCount, noteId;
#elif preview
Variable<PreviewDataId> duration;                   // 谱面时长
Variable<PreviewDataId> noteCount;                  // note 数量
Variable<EntitySharedMemoryId> noteId;              // note 编号
Array<TemporaryMemoryId, let> splitLineMemory(16);
let currentJudge, currentJudgeStartTime, currentJudgeDeltaTime, comboNumber, comboStatus;
#endif
