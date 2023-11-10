class SplitLine: public Archetype {
    public:

    string name = "Sirius Split Line";
    vector<pair<string, int> > data = {{"beat", 0}, {"endBeat", 1}, {"split", 2}, {"color", 3}};
	var beat = EntityData.get(0);
	var endBeat = EntityData.get(1);
	var split = EntityData.get(2);
	var color = EntityData.get(3);

    var preprocess() {
		return duration.set(Max(duration.get(), beat));
    }

	var render() {
		return {
			getSplitLine(color),
			drawSplitLine(beat - splitLineAnimationStart, beat, 1, split),
			drawSplitLine(beat, endBeat, 0, split),
			drawSplitLine(endBeat, endBeat + splitLineAnimationEnd, 2, split)
		};
	}
};
