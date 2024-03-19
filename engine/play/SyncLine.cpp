class SyncLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Sync Line";
    bool input = false;

    defineImports(beat);
    defineImports(left);
    defineImports(right);

    SonolusApi spawnOrder() { return 1000 + beat; }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

    SonolusApi preprocess() {
    	FUNCBEGIN
		beat = beat / levelSpeed;
        IF (mirror) {
            var tmp = left;
            left = 13 - right;
            right = 13 - tmp;
        } FI
        return VOID;
    }

    SonolusApi updateParallel() {
    	FUNCBEGIN
        IF (LevelOption.get(Options.SyncLine) == 1) {
            drawSyncLine(TimeToScaledTime(beat), left, right);
        } FI
        return VOID;
    }

    SonolusApi updateSequential() {
        FUNCBEGIN
        IF (times.now > beat) {
            EntityDespawn.set(0, 1);
        } FI
        return VOID;
    }
};
