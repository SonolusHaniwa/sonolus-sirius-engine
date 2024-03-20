class SiriusHiSpeed : public Archetype {
    public:

	static constexpr const char* name = "#TIMESCALE_CHANGE";
	vector<pair<string, int> > imports = {{ "#BEAT", 0 }, { "#TIMESCALE", 1 }};
	Variable<EntityDataId> beat;
	Variable<EntityDataId> value;
	
    SonolusApi spawnOrder() { return 0; }
    SonolusApi shouldSpawn() { return 1; }
};
