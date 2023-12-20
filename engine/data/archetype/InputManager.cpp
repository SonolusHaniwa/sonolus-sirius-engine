using namespace std;

auto usedTouchIds = Map<LevelMemoryId, FuncNode, FuncNode>(16);
auto isUsed = [](Touch touch){return Execute({usedTouchIds.indexOf(touch.id) != -1});};
auto markAsUsed = [](Touch touch){return Execute({usedTouchIds.add(touch.id, 1)});};
    
class InputManager: public Archetype {
    public:

    string name = "Sirius Input Manager";

    var spawnOrder() { return 1; }
    
    var shouldSpawn() { return EntityInfoArray.get(2) == EntityState.Despawned; }

    var touch() { return usedTouchIds.clear(); }
};	
