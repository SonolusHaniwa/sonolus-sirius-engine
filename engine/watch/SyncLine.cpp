class SyncLine: public Archetype {
    public:

    string name = "Sirius Sync Line";
    bool input = false;

    defineImport(beat);
    defineImport(left);
    defineImport(right);

    SonolusApi spawnTime() { return TimeToScaledTime(beat) - appearTime; }
    SonolusApi despawnTime() { return TimeToScaledTime(beat); }

    SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
        if (Options.Mirror) {
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
};
