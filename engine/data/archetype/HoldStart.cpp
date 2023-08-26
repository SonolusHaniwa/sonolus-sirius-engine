class SiriusHoldStart : public Archetype {
    public:

    string name = "Sirius Hold Start";
    vector<pair<string, int> > data = {{"beat", 0}, {"lane", 1}, {"laneLength", 2}};
    bool hasInput = true;

    var beat = EntityData.get(0);
    var lane = EntityData.get(1);
    var laneLength = EntityData.get(2);
    var enLane = lane + laneLength - 1;

    var spawnOrder = 1000 + beat;
    var shouldSpawn = times.now > beat - appearTime;

    var preprocess = {
        IF (LevelOption.get(Options.Mirror)) {
            EntityData.set(1, 13 - enLane)
        } FI
    };

    var updateSequential = {
        drawNormalNote(Sprites.HoldNote, lane, enLane, beat),
        IF (LevelOption.get(Options.Autoplay) && times.now > beat) {
            JudgeNote(beat, beat),
            EntityDespawn.set(0, 1)
        } FI
    };

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
    };

    var updateParallel =  {
        IF (times.now > beat + judgment.good) {
            EntityInput.set(0, 0),
            EntityInput.set(1, 0),
            EntityDespawn.set(0, 1)
        } FI
    };
};
