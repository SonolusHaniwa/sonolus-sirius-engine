class Stage: public Archetype {
    public:

    string name = "Sirius Stage";

	int preprocessOrder = 1;
    SonolusApi preprocess() {
		scroll = CanvasScroll.LeftToRight;
		canvasSize = Ceil(duration / stageTimeLength) * stageFullWidth;
    }

	SonolusApi render() {
		DebugLog(duration);
		for (var i = 0; i < Ceil(duration / stageTimeLength); i++) drawStage(i);
		for (var i = 0; i <= duration; i++) drawTime(i);
	}
};
