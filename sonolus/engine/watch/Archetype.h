#ifndef WatchArchetype_H
#define WatchArchetype_H

class Archetype {
    public:
    // Archetype id
    int id = 0;

    // Entity Memory block is used as generic memory storage.
    VariablesArray<EntityMemoryId> &memory = EntityMemory;
    // Entity Shared Memory block is used as generic memory storage that are accessible by other entities.
    VariablesArray<EntitySharedMemoryId> &sharedMemory = EntitySharedMemory;
    // Entity Info block contains state information of the entity.
    EntityInfoGroup &info = EntityInfo;
    // Entity Input block is used by entities to pass input information back to Sonolus.
    EntityInputGroup &input = EntityInput;

    public:
    // Archetype Life block contains life configuration of each archetype.
    ArchetypeLifeGroup life = ArchetypeLife[id];

    // Name of this archetype, which will be referenced by entities in level data.
    // Special archetype names will have its effect applied automatically:
    // `#BPM_CHANGE`: Signals a BPM change and will affect BPM change related functions. Entity with this archetype must also provide data named `#BEAT` and `#BPM`.
    // `#TIMESCALE_CHANGE`: Signals a time scale change and will affect time scale change related functions. Entity with this archetype must also provide data named `#BEAT` and `#TIMESCALE`.
    string name = "Default Archetype";
    // If true, Sonolus will treat entities with this archetype to be playable entities, and will contribute to judgment, combo, life, score, etc.
    bool hasInput = false;
    // Imported data to be inject into Entity Data block.
    // Imported data with matching `name` will be injected at `index` of Entity Data block.
    vector<pair<string, int> > imports;

    double preprocessOrder = 0;
    SonolusApi preprocess() { return 0; }

    double spawnTimeOrder = 0;
    SonolusApi spawnTime() { return 0; }

    double despawnTimeOrder = 0;
    SonolusApi despawnTime() { return 0; }

    double initializeOrder = 0;
    SonolusApi initialize() { return 0; }

    double updateSequentialOrder = 0;
    SonolusApi updateSequential() { return 0; }

    double updateParallelOrder = 0;
    SonolusApi updateParallel() { return 0; }

    double terminateOrder = 0;
    SonolusApi terminate() { return 0; }
};

#define defineImport(name) bool unused_##name##_unused = [&](){ \
        FuncNode id = imports.size(); \
        imports.push_back({ #name, imports.size() }); \
        return true; \
    }(); \
    Variable name = Variable(EntityDataId, imports.size() - 1)
#define defineImportDetailed(varName, jsonName) bool unused_##varName##_unused = [&](){ \
        FuncNode id = imports.size(); \
		imports.push_back({ jsonName, imports.size() }); \
        return true; \
    }(); \
    Variable varName = Variable(EntityDataId, imports.size() - 1)

#endif