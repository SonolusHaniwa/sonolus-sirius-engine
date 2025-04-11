class SplitLine: public Archetype {
    public:

    string name = "Sirius Split Line";
    bool input = false;

	defineImport(beat);
	defineImport(endBeat);
	defineImport(split);
	defineImport(color);

    SonolusApi spawnTime() { return TimeToScaledTime(beat - splitLineAnimationStart); }
    SonolusApi despawnTime() { return TimeToScaledTime(endBeat + splitLineAnimationEnd); }

    SonolusApi preprocess() {
 	 	beat = beat / levelSpeed;
 	 	endBeat = endBeat / levelSpeed;
    }
   
    SonolusApi updateSequential() {
		if (split < 1 || split > 6) return;
        getSplitLine(color);
        if (times.now > endBeat) {
            drawDisappearLine(times.now - endBeat, split);
        } else {
	        if (times.now < beat) {
	            drawAppearLine(splitLineAnimationStart - beat + times.now, split);
	        } else {
	            drawSplitLine(split);
	        }
	    }
	}
};
