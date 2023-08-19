using namespace std;

const double maxSize = 2.5;                     // 判定大小
const var interfaceGap = 0.05;                  // 组件间距
const var targetAspectRatio = 1115.0 / 640.0;   // 目标屏幕宽高比
const var highWidth = 0.1;                      // 高位宽度与低位宽度比
const var defaultAppearTime = 5.0;              // Note 默认出现时间
const var minSFXDistance = 0.02;                // 最小音效时间
const var judgelineMarginBottom = 0.2;          // 判定线距离底部距离
const var judgelineHeight = 85.0 / 640.0;       // 判定线高度

class stage {
	public:

	const var w = IF (LevelOption.get(Options.LockAspectRatio) == 0 || screen.aspectRatio < targetAspectRatio) {
        screen.w
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

const var t = If(
	LevelOption.get(Options.LockAspectRatio) && screen.aspectRatio < targetAspectRatio,
	screen.w / targetAspectRatio * 0.5,
	screen.t
);
const var b = t - stage.h;

class judgment {
	public:

	var perfect = 0.04;
	var great = 0.07;
	var good = 0.1;
}judgment;

class score {
	public:

	var perfect = 1;
	var great = 0.75;
	var good = 0.5;
}score;