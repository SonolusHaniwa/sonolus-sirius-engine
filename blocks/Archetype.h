using namespace std;
#ifdef play
class Archetype {
    public:

	static constexpr const char* name = "Default Archetype";
    bool hasInput = false;

    int preprocessOrder = 0;
    SonolusApi preprocess() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
    }

    int spawnOrderOrder = 0;
	SonolusApi spawnOrder() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
	}

    int shouldSpawnOrder = 0;
	SonolusApi shouldSpawn() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
	}

    int initializeOrder = 0;
	SonolusApi initialize() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
	}

    int updateSequentialOrder = 0;
	SonolusApi updateSequential() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
	}

    int touchOrder = 0;
	SonolusApi touch() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
	}

    int updateParallelOrder = 0;
	SonolusApi updateParallel() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
	}

    int terminateOrder = 0;
	SonolusApi terminate() {
    	FUNCBEGIN
    	Return(0);
    	return VOID;
	}

    vector<pair<string, int> > data;
};
#elif preview
class Archetype {
    public:

    string name = "Default Archtype";

    int preprocessOrder = 0;
	SonolusApi preprocess() {
		return { Return(0) };
	}

    int renderOrder = 0;
	SonolusApi render() {
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
	SonolusApi preprocess() {
		return { Return(0) };
	}

    int spawnTimeOrder = 0;
	SonolusApi spawnTime() {
		return { Return(0) };
	}

    int despawnTimeOrder = 0;
	SonolusApi despawnTime() {
		return { Return(0) };
	}

    int initializeOrder = 0;
	SonolusApi initialize() {
		return { Return(0) };
	}

    int updateSequentialOrder = 0;
	SonolusApi updateSequential() {
		return { Return(0) };
	}

    int updateParallelOrder = 0;
	SonolusApi updateParallel() {
		return { Return(0) };
	}

    int terminateOrder = 0;
	SonolusApi terminate() {
		return { Return(0) };
	}

    vector<pair<string, int> > data;
};
#endif

#define defineEntityData(name) Variable<EntityDataId> name = Variable<EntityDataId>(0, true); \
	bool unused_##name##_unused = [&](){ \
		name.offset = data.size(); \
		data.push_back({ #name, data.size() }); return true; }(); 
