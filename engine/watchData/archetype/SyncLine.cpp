class SiriusSyncLine: public Archetype {
    public:

    string name = "Sirius Sync Line";
    vector<pair<string, int> > data = {{"beat", 0}, {"left", 1}, {"right", 2}};
    bool input = false;

    var beat = EntityData.get(0);
    var left = EntityData.get(1);
    var right = EntityData.get(2);

    var spawnTime() { return beat - appearTime; }
    var despawnTime() { return beat; }

    var preprocess() {
        return {
            IF (LevelOption.get(Options.Mirror)) {
                playLoopedId.set(left),
                EntityData.set(1, 13 - right),
                EntityData.set(2, 13 - playLoopedId.get())
            } FI
        };
    }

    var updateParallel() {
        return {
            IF (LevelOption.get(Options.SyncLine) == 1) {
                drawSyncLine(beat, left, right)
            } FI
        };
    }
};
