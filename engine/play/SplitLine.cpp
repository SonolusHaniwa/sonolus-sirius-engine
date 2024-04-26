class SplitLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Split Line";
    bool input = false;

	defineImports(beat);
	defineImports(endBeat);
	defineImports(split);
	defineImports(color);

    SonolusApi spawnOrder() { return 1000 + beat - splitLineAnimationStart + appearTime; }
    SonolusApi shouldSpawn() { return times.scaled > beat - splitLineAnimationStart; }

    SonolusApi preprocess() {
    	FUNCBEGIN
		beat = beat / levelSpeed;
		endBeat = endBeat / levelSpeed;
    	return VOID;
    }
   
    SonolusApi updateSequential() {
    	FUNCBEGIN
    	IF (split < 1 && split > 6) Return(0); FI
        getSplitLine(color);
        IF (times.scaled > endBeat) {
            drawDisappearLine(times.scaled - endBeat, split);
        } ELSE {
	        IF (times.scaled < beat) {
	            drawAppearLine(splitLineAnimationStart - beat + times.scaled, split);
	        } ELSE {
	            drawSplitLine(split);
	        } FI
	    } FI
		return VOID;
	}

    SonolusApi updateParallel() {
    	FUNCBEGIN
        IF (times.scaled > endBeat + splitLineAnimationEnd) {
            EntityDespawn.set(0, 1);
        } FI
	    return VOID;
	}
};
