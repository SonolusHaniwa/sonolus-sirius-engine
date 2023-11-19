using namespace std;
#ifdef play
class Archetype {
    public:

    string name = "Default Archtype";
    bool hasInput = false;

    int preprocessOrder = 0;
	FuncNode preprocess() {
		return { Return(0) };
	}

    int spawnOrderOrder = 0;
	FuncNode spawnOrder() {
		return { Return(0) };
	}

    int shouldSpawnOrder = 0;
	FuncNode shouldSpawn() {
		return { Return(0) };
	}

    int initializeOrder = 0;
	FuncNode initialize() {
		return { Return(0) };
	}

    int updateSequentialOrder = 0;
	FuncNode updateSequential() {
		return { Return(0) };
	}

    int touchOrder = 0;
	FuncNode touch() {
		return { Return(0) };
	}

    int updateParallelOrder = 0;
	FuncNode updateParallel() {
		return { Return(0) };
	}

    int terminateOrder = 0;
	FuncNode terminate() {
		return { Return(0) };
	}

    vector<pair<string, int> > data;
};
#elif preview
class Archetype {
    public:

    string name = "Default Archtype";

    int preprocessOrder = 0;
	FuncNode preprocess() {
		return { Return(0) };
	}

    int renderOrder = 0;
	FuncNode render() {
		return { Return(0) };
	}

    vector<pair<string, int> > data;
};
#elif watch
class Archetype {
    public:

    string name = "Default Archtype";
    bool hasInput = false;

    int preprocessOrder = 0;
	FuncNode preprocess() {
		return { Return(0) };
	}

    int spawnTimeOrder = 0;
	FuncNode spawnTime() {
		return { Return(0) };
	}

    int despawnTimeOrder = 0;
	FuncNode despawnTime() {
		return { Return(0) };
	}

    int initializeOrder = 0;
	FuncNode initialize() {
		return { Return(0) };
	}

    int updateSequentialOrder = 0;
	FuncNode updateSequential() {
		return { Return(0) };
	}

    int updateParallelOrder = 0;
	FuncNode updateParallel() {
		return { Return(0) };
	}

    int terminateOrder = 0;
	FuncNode terminate() {
		return { Return(0) };
	}

    vector<pair<string, int> > data;
};
#endif
