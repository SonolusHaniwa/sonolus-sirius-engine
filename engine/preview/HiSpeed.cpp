class HiSpeed : public Archetype {
    public:

	string name = "#TIMESCALE_CHANGE";

	defineImportDetailed(beat, "#BEAT");
	defineImportDetailed(value, "#TIMESCALE");

	SonolusApi preprocess() {
		duration = Max(duration, beat);
	}

	SonolusApi render() {
		drawHiSpeed(beat, value);
		drawLine(Sprites.GridYellow, beat);
	}
};