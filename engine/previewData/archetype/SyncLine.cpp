class SiriusSyncLine: public Archetype {
    public:

    string name = "Sirius Sync Line";
	vector<pair<string, int> > data = {{"beat", 0}, {"left", 1}, {"right", 2}};
	var maxTime = 0;
	var beat = EntityData.get(0);
	var left = EntityData.get(1);
	var right = EntityData.get(2);

    var preprocess = {
		
    };

	var render = {
		drawSyncLine(beat, left, right)
	};
};
