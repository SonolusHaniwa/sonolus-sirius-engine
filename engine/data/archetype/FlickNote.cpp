class FlickNote : public Archetype {
    public:

    string name = "Sirius Flick Note";
    vector<pair<string, int> > data = {{"beat", 0}, {"lane", 1}, {"laneLength", 2}};
    bool hasInput = true;

    var beat = EntityData.get(0);
    var lane = EntityData.get(1);
    var laneLength = EntityData.get(2);
    var enLane = lane + laneLength - 1;

    var spawnOrder = 1000 + beat;
    var shouldSpawn = times.now > beat - appearTime;

    var updateSequential = {
        drawNormalNote(Sprites.ScratchNote, lane, enLane, beat),
        drawArrow(lane, enLane, beat),
        IF (LevelOption.get(Options.Autoplay) && times.now > beat) {
            EntityInput.set(0, 1),
            EntityInput.set(1, 0),
            Play(Clips.HoldStart, minSFXDistance),
            EntityDespawn.set(0, 1)
        } FI
    };

    var touch = {
        IF (LevelOption.get(Options.Autoplay) || times.now < beat - judgment.good) { Return(0) } FI,
        FOR (i, 0, touches.size, 1) {
            IF (!lines.inClickBox(touches[i], lane, enLane)) { CONTINUE } FI,
            IF (isUsed(touches[i])) { CONTINUE } FI,
            markAsUsed(touches[i].id),
            IF (!movedLast(touches[i])) { CONTINUE } FI,
            JudgeFlickNote(times.now, beat),
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
