class SyncLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Sync Line";

    defineEntityData(beat);
    defineEntityData(left);
    defineEntityData(right);

    SonolusApi render() {
    	FUNCBEGIN
		drawPreviewSyncLine(beat, left, right);
		return VOID;
	}
};
