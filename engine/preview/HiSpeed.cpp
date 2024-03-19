class SiriusHiSpeed : public Archetype {
    public:

	static constexpr const char* name = "#TIMESCALE_CHANGE";
	vector<pair<string, int> > imports = {{ "#BEAT", 0 }, { "#TIMESCALE", 1 }};
	Variable<EntityDataId> beat = Variable<EntityDataId>(0, true);
	Variable<EntityDataId> value = Variable<EntityDataId>(1, true);

	SonolusApi preprocess() {
		FUNCBEGIN
		duration = Max(duration.get(), beat);
		return VOID;
	}

	SonolusApi render() {
		FUNCBEGIN
		drawHiSpeed(beat, value);
		drawPreviewLine(Sprites.GridYellow, beat);
		return VOID;
	}
};