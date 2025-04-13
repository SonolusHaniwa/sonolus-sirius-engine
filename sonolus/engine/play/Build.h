#ifndef PlayBuild_H
#define PlayBuild_H

class EnginePlayDataArchetype {
    public:

    string name = "";
    bool hasInput = false;
    pair<int, double> preprocess = {0, 0};
    pair<int, double> spawnOrder = {0, 0};
    pair<int, double> shouldSpawn = {0, 0};
    pair<int, double> initialize = {0, 0};
    pair<int, double> updateSequential = {0, 0};
    pair<int, double> touch = {0, 0};
    pair<int, double> updateParallel = {0, 0};
    pair<int, double> terminate = {0, 0};
    vector<pair<string, int>> imports = {};
    vector<string> exports = {};

    Json::Value toJsonObject() {
        Json::Value res;
        res["name"] = name;
        res["hasInput"] = hasInput;
        res["preprocess"]["index"] = preprocess.first;
        res["preprocess"]["order"] = preprocess.second;
        res["spawnOrder"]["index"] = spawnOrder.first;
        res["spawnOrder"]["order"] = spawnOrder.second;
        res["shouldSpawn"]["index"] = shouldSpawn.first;
        res["shouldSpawn"]["order"] = shouldSpawn.second;
        res["initialize"]["index"] = initialize.first;
        res["initialize"]["order"] = initialize.second;
        res["updateSequential"]["index"] = updateSequential.first;
        res["updateSequential"]["order"] = updateSequential.second;
        res["touch"]["index"] = touch.first;
        res["touch"]["order"] = touch.second;
        res["updateParallel"]["index"] = updateParallel.first;
        res["updateParallel"]["order"] = updateParallel.second;
        res["terminate"]["index"] = terminate.first;
        res["terminate"]["order"] = terminate.second;
        res["imports"].resize(0);
        for (int i = 0; i < imports.size(); i++)
        {
            Json::Value single;
            single["name"] = imports[i].first;
            single["index"] = imports[i].second;
            res["imports"].append(single);
        }
        res["exports"].resize(0);
        for (int i = 0; i < exports.size(); i++)
            res["exports"].append(exports[i]);
        return res;
    }
};

class EnginePlayData {
    public:

    string skinRenderMode = "default";
    vector<pair<string, int> > skinSprites = {};
    vector<pair<string, int> > effectClips = {};
    vector<pair<string, int> > particleEffects = {};
    vector<EngineDataBucket> buckets = {};
    vector<EnginePlayDataArchetype> archetypes = {};
    vector<DataNode> nodes = {};

    Json::Value toJsonObject() {
        Json::Value res;
        SonolusAssert(
            set<string>({"default", "standard", "lightweight"}).count(skinRenderMode),
            "`skinRenderMode` must be `default`, `standard` or `lightweight`!"
        );
        res["skin"]["renderMode"] = skinRenderMode;
        res["skin"]["sprites"].resize(0);
        for (int i = 0; i < skinSprites.size(); i++) {
            Json::Value single;
            single["name"] = skinSprites[i].first;
            single["id"] = skinSprites[i].second;
            res["skin"]["sprites"].append(single);
        }
        res["effect"]["clips"].resize(0);
        for (int i = 0; i < effectClips.size(); i++) {
            Json::Value single;
            single["name"] = effectClips[i].first;
            single["id"] = effectClips[i].second;
            res["effect"]["clips"].append(single);
        }
        res["particle"]["effects"].resize(0);
        for (int i = 0; i < particleEffects.size(); i++) {
            Json::Value single;
            single["name"] = particleEffects[i].first;
            single["id"] = particleEffects[i].second;
            res["particle"]["effects"].append(single);
        }
        res["buckets"].resize(0);
        for (int i = 0; i < buckets.size(); i++)
            res["buckets"].append(buckets[i].toJsonObject());
        res["archetypes"].resize(0);
        for (int i = 0; i < archetypes.size(); i++)
            res["archetypes"].append(archetypes[i].toJsonObject());
        res["nodes"].resize(0);
        for (int i = 0; i < nodes.size(); i++)
            res["nodes"].append(nodes[i].toJsonObject());
        return res;
    }
}enginePlayData;

#if false
// 用宏定义定义一个虚假函数，让解释器识别到这个函数并自动加到 UserDefined 函数列表中
void BuildData() {}
#endif
// BuildData 宏定义一定要禁止解释器解析，不然解释器会识别到两个同名的宏定义然后出现错误
#define DISABLE_INTERPRETER
#ifndef COMPILE_RUNTIME
// 供 IDE 识别的 BuildData 函数
#define BuildData(...) [&]() {\
    allocateArchetypeId(#__VA_ARGS__); \
    BuildArchetypes<__VA_ARGS__>(); \
    BuildPlayData(); }()
#else
// 供编译器识别的 BuildData 函数
#define BuildData(arg1, arg2, arg3, arg4, arg5, ...) [&]() {\
    allocateArchetypeId(#__VA_ARGS__); \
    BuildArchetypes<__VA_ARGS__>(arg1, arg2, arg3, arg4, arg5); \
    BuildPlayData(arg1, arg2, arg3, arg4, arg5); }()
#endif
#undef DISABLE_INTERPRETER

map<string, int> archetypeId;
int archetypeNumber = 0;
Blocked void allocateArchetypeId(string archetypeList) {
    string tmp = "";
    int id = 0;
    for (int i = 0; i < archetypeList.size(); i++) {
        if (archetypeList[i] == ',') archetypeId[tmp] = id++, tmp = "";
        else if (isalnum(archetypeList[i])) tmp += archetypeList[i];
    }
    if (tmp != "") archetypeId[tmp] = id++;
    archetypeNumber = id;
}

#define getAid(archetype) (archetypeId.find(#archetype) == archetypeId.end() ? -1 : archetypeId[#archetype])
#define buildCallback(name) [&]() { \
    createNodeContainer(); \
    defaultAllocatorId = TemporaryMemoryId; \
    callbackName = #name; \
    archetype.name(); \
    dataArchetype.name.first = mergeNodeContainer().getNodeId(); \
    dataArchetype.name.second = archetype.name##Order; }()

template <typename T>
void BuildArchetype(T &archetype) {
    EnginePlayDataArchetype dataArchetype;
    dataArchetype.name = archetype.name;
    dataArchetype.hasInput = archetype.hasInput;
    dataArchetype.imports = archetype.imports;
    dataArchetype.exports = archetype.exports;

    buildCallback(preprocess);
    buildCallback(spawnOrder);
    buildCallback(shouldSpawn);
    buildCallback(initialize);
    buildCallback(updateSequential);
    buildCallback(touch);
    buildCallback(updateParallel);
    buildCallback(terminate);

    enginePlayData.archetypes.push_back(dataArchetype);
}

template <typename T, typename... Args>
void BuildArchetypes(int aid = 0) {
    defaultAllocatorId = EntityMemoryId;
    SonolusMemoryDelta[EntityMemoryId] = 1;
    T archetype = T();
    archetypeName = archetype.name;
    archetype.id = aid;
    archetype.life.perfect_increment.reallocate(4 * aid + 0);
    archetype.life.great_increment.reallocate(4 * aid + 1);
    archetype.life.good_increment.reallocate(4 * aid + 2);
    archetype.life.miss_increment.reallocate(4 * aid + 3);
    BuildArchetype(archetype);

#define DISABLE_INTERPRETER
#ifdef COMPILE_RUNTIME
    if constexpr (sizeof...(Args))
        BuildArchetypes<Args...>(callFromFuncParam, callFromFunc, callFromLine, callFromColumn, callFromFile, aid + 1);
#else
    if constexpr (sizeof...(Args))
        BuildArchetypes<Args...>();
#endif
#undef DISABLE_INTERPRETER
}

void BuildPlayData() {
    enginePlayData.nodes = dataContainer;
    enginePlayData.skinSprites.clear();
    for (int i = 0; i < skin_sprites.size(); i++) 
        enginePlayData.skinSprites.push_back({ skin_sprites[i].first, i });
    enginePlayData.effectClips.clear();
    for (int i = 0; i < effect_clips.size(); i++) 
        enginePlayData.effectClips.push_back({ effect_clips[i].first, i });
    enginePlayData.particleEffects.clear();
    for (int i = 0; i < particle_effects.size(); i++) 
        enginePlayData.particleEffects.push_back({ particle_effects[i].first, i });
    enginePlayData.buckets.clear();
    for (int i = 0; i < data_buckets.size(); i++) 
        enginePlayData.buckets.push_back(data_buckets[i]);

    string EnginePlayData = compress_gzip(json_encode(enginePlayData.toJsonObject()));
    ofstream fout = ofstream(dist + "/EnginePlayData");
    fout.write(EnginePlayData.c_str(), EnginePlayData.size());
}

#endif