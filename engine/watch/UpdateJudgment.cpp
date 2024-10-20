class UpdateJudgment: public Archetype {
	public:

	static const bool disableGlobalPreprocess = true;
	static constexpr const char* name = "Sirius Update Judgment";
	Variable<EntityMemoryId> beat;
	Variable<EntityMemoryId> judgment;
	Variable<EntityMemoryId> combo;
	Variable<EntityMemoryId> status;
	Variable<EntityMemoryId> entityId;
	Variable<EntityMemoryId> delta;
	Variable<EntityMemoryId> accuracy;

	SonolusApi spawnTime() { return TimeToScaledTime(beat); }
	SonolusApi despawnTime() {
		return TimeToScaledTime(beat) + Max(1, EntitySharedMemoryArray[entityId].get(2));
	}

 	// int updateSequentialOrder = 1;
	SonolusApi updateSequential() {
		FUNCBEGIN
		IF (lastUpdatedId > entityId) Return(0); FI
		comboStatus = status.get();
		comboNumber = combo.get();
		SpawnSubJudgeText(judgment, delta, beat);
		lastUpdatedId = entityId.get();
		currentAccuracy = accuracy + totalAccuracy;
		return VOID;
	}
};
