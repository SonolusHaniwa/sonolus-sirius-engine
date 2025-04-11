class SplitLine: public Archetype {
    public:

    string name = "Sirius Split Line";
    bool input = false;

	defineImport(beat);
	defineImport(endBeat);
	defineImport(split);
	defineImport(color);

    SonolusApi spawnOrder() { return 1000 + TimeToScaledTime(beat - splitLineAnimationStart) + appearTime; }
    SonolusApi shouldSpawn() { return times.now > beat - splitLineAnimationStart; }

    SonolusApi preprocess() {
		beat = beat / levelSpeed;
		endBeat = endBeat / levelSpeed;
    }
   
    SonolusApi updateSequential() {
    	if (split < 1 && split > 6) return;
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

    SonolusApi updateParallel() {
        if (times.now > endBeat + splitLineAnimationEnd) {
			despawn.despawn = true;
        }
	}
};
