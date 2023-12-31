class SyncLine: public Archetype {
    public:

    string name = "Sirius Sync Line";
    vector<pair<string, int> > data = {{"beat", 0}, {"left", 1}, {"right", 2}};
    bool input = false;

    var beat = EntityData.get(0);
    var left = EntityData.get(1);
    var right = EntityData.get(2);

    var spawnOrder() { return 1000 + beat; }
    var shouldSpawn() { return times.now > beat - appearTime; }

    var preprocess() {
        return {
            IF (LevelOption.get(Options.Mirror)) {
                playLoopedId.set(left),
                EntityData.set(1, 13 - right),
                EntityData.set(2, 13 - playLoopedId.get())
            } FI
        };
    }

    var updateSequential() {
        return {
            IF (LevelOption.get(Options.SyncLine) == 1) {
                drawSyncLine(beat, left, right)
            } FI
        };
    }

    var updateParallel() {
        return {
            IF (times.now > beat) {
                EntityDespawn.set(0, 1)
            } FI
        };
    }
};