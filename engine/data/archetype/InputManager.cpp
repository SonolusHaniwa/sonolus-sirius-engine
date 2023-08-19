using namespace std;

Array<LevelMemoryId> usedTouchIds = Array<LevelMemoryId>(16);
auto isUsed = [](Touch touch){return Execute({usedTouchIds.has(touch.id)});};
auto markAsUsed = [](Touch touch){return Execute({usedTouchIds.add(touch.id)});};
    
class InputManager: public Archetype {
    public:

    string name = "Sirius Input Manager";

    var spawnOrder = 1;
    
    var shouldSpawn = EntityInfoArray.get(2) == EntityState.Despawned;

    var touch = {
        usedTouchIds.clear()
    };
};	