#ifndef PreviewBuild_H
#define PreviewBuild_H

class EnginePreviewDataArchetype {
    public:

    string name = "";
    pair<int, double> preprocess = {0, 0};
    pair<int, double> render = {0, 0};
    vector<pair<string, int>> imports = {};

    Json::Value toJsonObject() {
        Json::Value res;
        res["name"] = name;
        res["preprocess"]["index"] = preprocess.first;
        res["preprocess"]["order"] = preprocess.second;
        res["render"]["index"] = render.first;
        res["render"]["order"] = render.second;
        res["imports"].resize(0);
        for (int i = 0; i < imports.size(); i++)
        {
            Json::Value single;
            single["name"] = imports[i].first;
            single["index"] = imports[i].second;
            res["imports"].append(single);
        }
        return res;
    }
};

class EnginePreviewData {
    public:

    string skinRenderMode = "default";
    vector<pair<string, int> > skinSprites = {};
    vector<EnginePreviewDataArchetype> archetypes = {};
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
        res["archetypes"].resize(0);
        for (int i = 0; i < archetypes.size(); i++)
            res["archetypes"].append(archetypes[i].toJsonObject());
        res["nodes"].resize(0);
        for (int i = 0; i < nodes.size(); i++)
            res["nodes"].append(nodes[i].toJsonObject());
        return res;
    }
}enginePreviewData;

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
    BuildPreviewData(); }()
#else
// 供编译器识别的 BuildData 函数
#define BuildData(arg1, arg2, arg3, arg4, arg5, ...) [&]() {\
    allocateArchetypeId(#__VA_ARGS__); \
    BuildArchetypes<__VA_ARGS__>(arg1, arg2, arg3, arg4, arg5); \
    BuildPreviewData(arg1, arg2, arg3, arg4, arg5); }()
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
    EnginePreviewDataArchetype dataArchetype;
    dataArchetype.name = archetype.name;
    dataArchetype.imports = archetype.imports;

    buildCallback(preprocess);
    buildCallback(render);

    enginePreviewData.archetypes.push_back(dataArchetype);
}

template <typename T, typename... Args>
void BuildArchetypes(int aid = 0) {
    defaultAllocatorId = EntitySharedMemoryId;
    SonolusMemoryDelta[EntitySharedMemoryId] = 1;
    T archetype = T();
    archetypeName = archetype.name;
    archetype.id = aid;
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

void BuildPreviewData() {
    enginePreviewData.nodes = dataContainer;
    enginePreviewData.skinSprites.clear();
    for (int i = 0; i < skin_sprites.size(); i++) 
        enginePreviewData.skinSprites.push_back({ skin_sprites[i].first, i });

    string EnginePreviewData = compress_gzip(json_encode(enginePreviewData.toJsonObject()));
    ofstream fout = ofstream(dist + "/EnginePreviewData");
    fout.write(EnginePreviewData.c_str(), EnginePreviewData.size());
}

#endif