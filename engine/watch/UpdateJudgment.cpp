class UpdateJudgment: public Archetype {
	public:

	static const bool disableGlobalPreprocess = true;
	static constexpr const char* name = "Sirius Update Judgment";
	Variable<EntityMemoryId> beat;
	Variable<EntityMemoryId> judgment;
	Variable<EntityMemoryId> updated;

	SonolusApi spawnTime() { return beat; }
	SonolusApi despawnTime() { return beat + 1; }

	SonolusApi initialize() {
		FUNCBEGIN
		updated = false;
		return VOID;
	}

 	// int updateSequentialOrder = 1;
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (updated) Return(0); FI
		SpawnSubJudgeText(judgment);
		updated = true;
		return VOID;
	}
};
