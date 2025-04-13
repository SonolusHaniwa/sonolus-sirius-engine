class SyncLine: public Archetype {
    public:

    string name = "Sirius Sync Line";

    defineImport(beat);
    defineImport(left);
    defineImport(right);

    SonolusApi render() {
      drawSyncLine(beat, left, right);
    }
};
