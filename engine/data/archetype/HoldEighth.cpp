class SiriusHoldEighth : public Archetype {
    public:

    string name = "Sirius Hold Eighth";
    vector<pair<string, int> > data = {{"beat", 0}, {"lastBeat", 1}, {"lane", 2}, {"laneLength", 3}, {"holdType", 4}};
    bool hasInput = true;

    var beat = EntityData.get(0);
	var lastBeat = EntityData.get(1);
    var lane = EntityData.get(2);
    var laneLength = EntityData.get(3);
	var holdType = EntityData.get(4);
    var enLane = lane + laneLength - 1;

    var spawnOrder = 1000 + lastBeat;
    var shouldSpawn = times.now > lastBeat - appearTime;

    var updateSequential = {
		drawHoldEighth(Switch(holdType, {
			{100, Sprites.Hold},
			{101, Sprites.Hold},
			{110, Sprites.Scratch}
		}), lane, enLane, lastBeat, beat),
/*        IF (LevelOption.get(Options.Autoplay) && times.now > beat) {
            EntityInput.set(0, 1),
            EntityInput.set(1, 0),
            Play(Clips.Perfect, minSFXDistance),
            EntityDespawn.set(0, 1)
        } FI*/
    };
/*
    var touch = {
        IF (LevelOption.get(Options.Autoplay) || times.now < beat - judgment.good) { Return(0) } FI,
        FOR (i, 0, touches.size, 1) {
            IF (touches[i].started == false) { CONTINUE } FI,
            IF (!lines.inClickBox(touches[i], lane, enLane)) { CONTINUE } FI,
            IF (isUsed(touches[i])) { CONTINUE } FI,
            markAsUsed(touches[i]),
            JudgeNote(times.now, beat),
            EntityDespawn.set(0, 1),
        } DONE
    };*/

    var updateParallel =  {
        IF (times.now > beat + judgment.good) {
            EntityInput.set(0, 0),
            EntityInput.set(1, 0),
            EntityDespawn.set(0, 1)
        } FI
    };
};
