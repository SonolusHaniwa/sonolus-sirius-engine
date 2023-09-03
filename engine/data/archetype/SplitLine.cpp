class SplitLine: public Archetype {
    public:

    string name = "Sirius Split Line";
    vector<pair<string, int> > data = {{"beat", 0}, {"endBeat", 1}, {"split", 2}};
    bool input = false;

    var beat = EntityData.get(0);
    var endBeat = EntityData.get(1);
    var split = EntityData.get(2);

    var spawnOrder = 1000 + beat - splitLineAnimationStart + appearTime;
    var shouldSpawn = times.now > beat - splitLineAnimationStart;

    var updateSequential = {
        IF (times.now > endBeat) {
            drawDisappearLine(times.now - endBeat, split)
        } ELSE {
            IF (times.now < beat) {
                drawAppearLine(splitLineAnimationStart - beat + times.now, split)
            } ELSE {
                drawSplitLine(split)
            } FI
        } FI
    };

    var updateParallel = {
        IF (times.now > endBeat + splitLineAnimationEnd) {
            EntityDespawn.set(0, 1)
        } FI
    };
};