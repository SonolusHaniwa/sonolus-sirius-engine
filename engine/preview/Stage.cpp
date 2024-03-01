class Stage: public Archetype {
    public:

    static constexpr const char*  name = "Sirius Stage";
    bool input = false;

	int preprocessOrder = 1;
    SonolusApi preprocess() {
    	FUNCBEGIN
		canvas.set(Scroll.LeftToRight, Ceil(duration.get() / stageTimeLength) * stageFullWidth);
		return VOID;
    }

	SonolusApi render() {
		FUNCBEGIN
		FOR (i, 0, Ceil(duration / stageTimeLength), 1) { drawStage(i); } DONE
		FOR (i, 0, duration + 1, 1) { drawTime(i); } DONE
		return VOID;
	}
};
