class SplitLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Split Line";
    bool input = false;

	defineImports(beat);
	defineImports(endBeat);
	defineImports(split);
	defineImports(color);

    SonolusApi spawnOrder() { return 1000 + beat - splitLineAnimationStart + appearTime; }
    SonolusApi shouldSpawn() { return times.scaled > TimeToScaledTime(beat) - splitLineAnimationStart; }

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
        IF (times.scaled > TimeToScaledTime(endBeat)) {
            drawDisappearLine(times.scaled - TimeToScaledTime(endBeat), split);
        } ELSE {
	        IF (times.scaled < TimeToScaledTime(beat)) {
	            drawAppearLine(splitLineAnimationStart - TimeToScaledTime(beat) + times.scaled, split);
	        } ELSE {
	            drawSplitLine(split);
	        } FI
	    } FI
		return VOID;
	}

    SonolusApi updateParallel() {
    	FUNCBEGIN
        IF (times.now > TimeToScaledTime(endBeat) + splitLineAnimationEnd) {
            EntityDespawn.set(0, 1);
        } FI
	    return VOID;
	}
};
