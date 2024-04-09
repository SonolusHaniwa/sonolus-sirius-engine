class SplitLine: public Archetype {
    public:

    static constexpr const char* name = "Sirius Split Line";
    bool input = false;

	defineImports(beat);
	defineImports(endBeat);
	defineImports(split);
	defineImports(color);

    SonolusApi spawnTime() { return beat - splitLineAnimationStart; }
    SonolusApi despawnTime() { return endBeat + splitLineAnimationEnd; }

    SonolusApi preprocess() {
    	FUNCBEGIN
 	 	beat = beat / levelSpeed;
 	 	endBeat = endBeat / levelSpeed;
 	 	return VOID;
    }
   
    SonolusApi updateSequential() {
    	FUNCBEGIN
        getSplitLine(color);
        IF (times.now > endBeat) {
            drawDisappearLine(times.now - endBeat, split);
        } ELSE {
	        IF (times.now < beat) {
	            drawAppearLine(splitLineAnimationStart - beat + times.now, split);
	        } ELSE {
	            drawSplitLine(split);
	        } FI
	    } FI
		return VOID;
	}
};
