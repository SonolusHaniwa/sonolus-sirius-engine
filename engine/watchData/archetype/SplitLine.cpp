class SiriusSplitLine: public Archetype {
    public:

    string name = "Sirius Split Line";
    vector<pair<string, int> > data = {{"beat", 0}, {"endBeat", 1}, {"split", 2}, {"color", 3}};
    bool input = false;

    var beat = EntityData.get(0);
    var endBeat = EntityData.get(1);
    var split = EntityData.get(2);
    var color = EntityData.get(3);

    var spawnTime() { return beat - splitLineAnimationStart; }
    var despawnTime() { return endBeat + splitLineAnimationEnd; }

    var updateSequential() {
		return {
	        getSplitLine(color),
	        IF (times.now > endBeat) {
	            drawDisappearLine(times.now - endBeat, split)
	        } ELSE {
		        IF (times.now < beat) {
		            drawAppearLine(splitLineAnimationStart - beat + times.now, split)
		        } ELSE {
		            drawSplitLine(split)
		        } FI
		    } FI
		};
	}
};
