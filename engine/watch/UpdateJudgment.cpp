class UpdateJudgment: public Archetype {
	public:

	static const bool disableGlobalPreprocess = true;
	static constexpr const char* name = "Sirius Update Judgment";
	Variable<EntityMemoryId> beat;
	Variable<EntityMemoryId> judgment;
	Variable<EntityMemoryId> combo;
	Variable<EntityMemoryId> status;
	Variable<EntityMemoryId> delta;
	Variable<EntityMemoryId> updated;

	SonolusApi spawnTime() { return TimeToScaledTime(beat); }
	SonolusApi despawnTime() { return TimeToScaledTime(beat) + 1; }

	SonolusApi initialize() {
		FUNCBEGIN
		updated = false;
		return VOID;
	}

 	// int updateSequentialOrder = 1;
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (updated) Return(0); FI
		SpawnSubJudgeText(judgment, delta);
		comboStatus = status.get();
		comboNumber = combo.get();
		updated = true;
		return VOID;
	}
};
