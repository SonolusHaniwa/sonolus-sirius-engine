class SplitLine: public Archetype {
    public:

    string name = "Sirius Split Line";

	defineImport(beat);
	defineImport(endBeat);
	defineImport(split);
	defineImport(color);

	SonolusApi preprocess() {
		duration = Max(duration, beat);
	}

	SonolusApi render() {
		if (split < 1 || split > 6) return;
		getSplitLine(color);
		drawSplitLine(beat - splitLineAnimationStart, beat, 1, split);
		drawSplitLine(beat, endBeat, 0, split);
		drawSplitLine(endBeat, endBeat + splitLineAnimationEnd, 2, split);
	}
};
