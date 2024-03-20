class SyncLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Sync Line";

    defineImports(beat);
    defineImports(left);
    defineImports(right);

    SonolusApi render() {
    	FUNCBEGIN
		drawPreviewSyncLine(beat, left, right);
		return VOID;
	}
};
