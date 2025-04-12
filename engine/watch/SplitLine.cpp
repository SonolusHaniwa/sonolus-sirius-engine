class SplitLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Split Line";
    bool input = false;

	defineImports(beat);
	defineImports(endBeat);
	defineImports(split);
	defineImports(color);

    SonolusApi spawnTime() { return TimeToScaledTime(beat - splitLineAnimationStart); }
    SonolusApi despawnTime() { return TimeToScaledTime(endBeat + splitLineAnimationEnd); }

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
        IF (times.now > endBeat) {
            drawDisappearLine(times.now - endBeat, split);
        } ELSE {
	        IF (times.now < beat) {
	            drawAppearLine(splitLineAnimationStart - RuntimeEnvironment.get(3) - beat + times.now, split);
	        } ELSE {
	            drawSplitLine(split);
	        } FI
	    } FI
		return VOID;
	}
};
