const var interfaceGap = 0.05;                  // 组件间距
const var targetAspectRatio = 1115.0 / 640.0;   // 目标屏幕宽高比
const var highWidth = 0.1;                      // 高位宽度与低位宽度比
const var defaultAppearTime = 3.0;              // note 默认出现时间
const var minSFXDistance = 0.02;                // 最小音效时间
const var judgelineMarginBottom = 0.2;          // 判定线距离底部距离
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
const var splitLineAnimationStart = 0.75;       // 分裂线起始动画长度, basic: 0.7595
const var splitLineAnimationEnd = 0.20;         // 分裂线结束动画长度, basic: 0.7595
const var effectLinearHeight = 280.0 / 640.0;   // 特效高度
const var effectCircularHeight = 200.0 / 640.0; // 特效 2 高度
const var effectDurationTime = 0.5;             // 特效持续时间
const var effectDistance = 20.0 / 640.0;        // 特效微调距离

class stage {
	public:

	const var w = IF (screen.aspectRatio < targetAspectRatio) {
        screen.w
    } ELSE {
        screen.h * targetAspectRatio
    } FI;
    const var h = IF (screen.aspectRatio > targetAspectRatio) {
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