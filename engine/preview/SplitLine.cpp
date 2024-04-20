class SplitLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Split Line";

	defineImports(beat);
	defineImports(endBeat);
	defineImports(split);
	defineImports(color);

	SonolusApi preprocess() {
		FUNCBEGIN
		duration = Max(duration.get(), beat);
		return VOID;
	}

	SonolusApi render() {
		FUNCBEGIN
		IF (split < 1 || split > 6) Return(0); FI
		getSplitLine(color);
		drawPreviewSplitLine(beat - splitLineAnimationStart, beat, 1, split);
		drawPreviewSplitLine(beat, endBeat, 0, split);
		drawPreviewSplitLine(endBeat, endBeat + splitLineAnimationEnd, 2, split);
		return VOID;
	}
};
