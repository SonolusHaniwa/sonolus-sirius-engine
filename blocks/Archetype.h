using namespace std;
#ifdef play
class Archetype {
    public:

    string name = "Default Archtype";
    bool hasInput = false;

    int preprocessOrder = 0;
    FuncNode preprocess = {Return(0)};

    int spawnOrderOrder = 0;
    FuncNode spawnOrder = {Return(0)};

    int shouldSpawnOrder = 0;
    FuncNode shouldSpawn = {Return(0)};

    int initializeOrder = 0;
    FuncNode initialize = {Return(0)};

    int updateSequentialOrder = 0;
    FuncNode updateSequential = {Return(0)};

    int touchOrder = 0;
    FuncNode touch = {Return(0)};

    int updateParallelOrder = 0;
    FuncNode updateParallel = {Return(0)};

    int terminateOrder = 0;
    FuncNode terminate = {Return(0)};

    vector<pair<string, int> > data;
};
#elif preview

class Archetype {
    public:

    string name = "Default Archtype";

    int preprocessOrder = 0;
    FuncNode preprocess = { Return(0) };

    int renderOrder = 0;
    FuncNode render = { Return(0) };

    vector<pair<string, int> > data;
};
#endif