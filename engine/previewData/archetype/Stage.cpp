class Stage: public Archetype {
    public:

    string name = "Sirius Stage";
	var maxTime = 0;

	int preprocessOrder = 1;
    var preprocess = {
		canvas.set(Scroll.LeftToRight, Ceil(duration.get() / stageTimeLength) * stageFullWidth),
    };

	var render = {
		FOR (i, 0, Ceil(duration.get() / stageTimeLength), 1) { drawStage(i) } DONE,
		FOR (i, 0, duration.get() + 1, 1) { drawTime(i) } DONE
	};
};
