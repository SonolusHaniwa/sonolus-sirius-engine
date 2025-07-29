class SyncLine: public Archetype {
    public:

    string name = "Sirius Sync Line";
    bool input = false;

    defineImport(beat);
    defineImport(left);
    defineImport(right);

    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat); }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - appearTime; }

    SonolusApi preprocess() {
		beat = beat / levelSpeed;
        if (mirror) {
            var tmp = left;
            left = 13 - right;
            right = 13 - tmp;
        }
    }

    SonolusApi updateParallel() {
        if (syncLine) {
            drawSyncLine(TimeToScaledTime(beat), left, right);
        }
    }

    SonolusApi updateSequential() {
        if (times.now > beat) {
            despawn.despawn = true;
        }
    }
};
