class SyncLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Sync Line";
    bool input = false;

    defineEntityData(beat);
    defineEntityData(left);
    defineEntityData(right);

    SonolusApi spawnTime() { return beat - appearTime; }
    SonolusApi despawnTime() { return beat; }

    SonolusApi preprocess() {
    	FUNCBEGIN
        IF (LevelOption.get(Options.Mirror)) {
            var tmp = left;
            left = 13 - right;
            right = 13 - tmp;
        } FI
        return VOID;
    }

    SonolusApi updateParallel() {
    	FUNCBEGIN
        IF (LevelOption.get(Options.SyncLine) == 1) {
            drawSyncLine(beat, left, right);
        } FI
        return VOID;
    }
};
