class SplitLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Split Line";
    bool input = false;

	defineImports(beat);
	defineImports(endBeat);
	defineImports(split);
	defineImports(color);

    SonolusApi spawnTime() { return TimeToScaledTime(beat) - splitLineAnimationStart; }
    SonolusApi despawnTime() { return TimeToScaledTime(endBeat) + splitLineAnimationEnd; }

    SonolusApi preprocess() {
    	FUNCBEGIN
 	 	beat = beat / levelSpeed;
 	 	endBeat = endBeat / levelSpeed;
 	 	return VOID;
    }
   
    SonolusApi updateSequential() {
    	FUNCBEGIN
		IF (split < 1 || split > 6) Return(0); FI
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
};
