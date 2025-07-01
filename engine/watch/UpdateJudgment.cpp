class UpdateJudgment: public Archetype {
	public:

	string name = "Sirius Update Judgment";
	var beat;
	var judgment;
	var combo;
	var status;
	var entityId;
	var delta;
	var accuracy;

	SonolusApi spawnTime() { 
		return TimeToScaledTime(beat); 
	}
	SonolusApi despawnTime() {
		return TimeToScaledTime(beat) + Max(1, EntitySharedMemoryArray[entityId].generic[2] - TimeToScaledTime(beat));
	}

 	// int updateSequentialOrder = 1;
	SonolusApi updateSequential() {
		if (lastUpdatedId > entityId) return;
		comboStatus = status;
		comboNumber = combo;
		SpawnSubJudgeText(judgment, delta, beat);
		lastUpdatedId = entityId;
		currentAccuracy = accuracy + totalAccuracy;
	}
};
