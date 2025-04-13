class HiSpeed : public Archetype {
    public:

	string name = EngineArchetypeName.TimeScaleChange;
	bool hasInput = false;

	defineImportDetailed(beat, EngineArchetypeDataName.Beat);
	defineImportDetailed(value, EngineArchetypeDataName.TimeScale);
	
    SonolusApi spawnOrder() { return 0; }
    SonolusApi shouldSpawn() { return 1; }
};
