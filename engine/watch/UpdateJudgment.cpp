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
	    IF (currentJudgeStartTime == times.now) {
			comboStatus = Max(comboStatus, status);
			comboNumber = If(combo == 0, 0, Max(comboNumber, combo));
	    } ELSE {
			comboStatus = status.get();
			comboNumber = combo.get();
	    } FI
		SpawnSubJudgeText(judgment, delta);
		updated = true;
		return VOID;
	}
};
