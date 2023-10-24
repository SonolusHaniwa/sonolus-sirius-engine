#include"modules/modules.h"

#include"items/Exception.h"
#include"items/EngineEnums.h"
#include"items/FuncNode.h"
#include"items/EngineConfiguration.h"
#include"items/EngineData.h"
#include"items/EngineTutorialData.h"
#include"items/EnginePreviewData.h"

#include"functions/functions.h"
#ifndef DISABLE_REDEFINE
#include"functions/redefine.h"
#endif
#ifndef DISABLE_JSPREFER
typedef FuncNode var;
typedef FuncNode let;
#endif

EngineData engineData;
EngineTutorialData engineTutorialData;
EngineConfiguration engineConfiguration;
EnginePreviewData enginePreviewData;
FuncNode tutorialPreprocess = 0;
FuncNode tutorialNavigate = 0;
FuncNode tutorialUpdate = 0;

#include"blocks/Archetype.h"
#include"blocks/Define.h"
#include"blocks/Pointer.h"

#include"items/PlayData.h"
#include"items/TutorialData.h"
#include"items/PreviewData.h"
#include"items/ParticleData.h"

map<EngineDataNode, int> hashMap;
// 双哈希 + 手动哈希表 O(n)
// const int64_t k1 = 23;
// const int64_t k2 = 55331;
// const int64_t p1 = 1e9 + 7;
// const int64_t p2 = 998244353;
// struct hashMap {
//     int *map1, *map2;
//     hashMap() {
//         map1 = new int[1 << 20];
//         map2 = new int[1 << 20];
//         memset(map1, -1, sizeof(map1));
//         memset(map2, -1, sizeof(map2));
//     }
//     int64_t getHash(EngineDataNode v, bool hashType) {
//         string tmp = v.type;
//         if (v.type == "value") tmp += to_string(v.value.value);
//         else {
//             tmp += v.func.func;
//             for (int i = 0; i < v.func.args.size(); i++) tmp += to_string(v.func.args[i]);
//         } int64_t hash = 0;
//         for (int i = 0; i < tmp.size(); i++) 
//             hash *= hashType ? k1 : k2, hash %= hashType ? p1 : p2,
//             hash += tmp[i], hash %= hashType ? p1 : p2;
//         return hash;
//     }
//     void insert(EngineDataNode key, int value) {
//         int64_t hash1 = getHash(key, 0);
//         int64_t hash2 = getHash(key, 1);
//         hash1 %= (1 << 20); hash2 %= (1 << 20);
//         map1[hash1] = value; map2[hash2] = value;
//     }
//     int get(EngineDataNode key) {
//         int64_t hash1 = getHash(key, 0);
//         int64_t hash2 = getHash(key, 1);
//         hash1 %= (1 << 20); hash2 %= (1 << 20);
//         if (map1[hash1] != map2[hash2]) throw runtime_error("Hash Collision!");
//         return map1[hash1];
//     }
//     bool exist(EngineDataNode key) {
//         int64_t hash1 = getHash(key, 0);
//         int64_t hash2 = getHash(key, 1);
//         hash1 %= (1 << 20); hash2 %= (1 << 20);
//         if (map1[hash1] != map2[hash2]) throw runtime_error("Hash Collision!");
//         return map1[hash1] != -1;
//     }
// }hashMap;

int globalCounter = 0;
int lastGlobalCounter = 0;

template<typename T>
int buildScript(FuncNode script, T& nodesContainer, int blockCounter = 0) {
    EngineDataNode res; globalCounter++;
    if (script.isValue == true) res = EngineDataValueNode(script.value);
    else {
        // Return 函数判断
        if (script.func == "Return") {
            script.func = "Break"; FuncNode code = script.args[0];
            script.args = {blockCounter, code};
        }
        // 其余函数
        vector<double> args;
        for (int i = 0; i < script.args.size(); i++) 
            args.push_back(buildScript(
                script.args[i],
                nodesContainer,
                blockCounter + (script.func == "Block")));
        res = EngineDataFunctionNode(script.func, args);
    } 
    // if (hashMap.exist(res)) return hashMap.get(res);
    // hashMap.insert(res, nodesContainer.nodes.size()); nodesContainer.nodes.push_back(res);
    // return hashMap.get(res);
    if (hashMap.find(res) != hashMap.end()) return hashMap[res];
    hashMap[res] = nodesContainer.nodes.size(); nodesContainer.nodes.push_back(res);
    return hashMap[res];
}

int buildFuncNode(FuncNode func) {
    FuncNode res = FuncNode("Block", {func});
    return buildScript(res, engineData);
}

int buildFuncNode2(FuncNode func) {
    FuncNode res = FuncNode("Block", {func});
    return buildScript(res, engineTutorialData);
}

int buildFuncNode3(FuncNode func) {
    FuncNode res = FuncNode("Block", {func});
    return buildScript(res, enginePreviewData);
}

time_t millitime() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

template<typename T>
void buildArchetype(T unused) {
    #ifdef play
    time_t st = millitime();
    T archetype; EngineDataArchetype newArchetype;
    cout << "Solving Archetype \"" << archetype.name << "\"..." << endl;
    newArchetype.name = archetype.name;
    newArchetype.hasInput = archetype.hasInput;
    newArchetype.preprocess.order = archetype.preprocessOrder;
    newArchetype.preprocess.index = buildFuncNode(archetype.preprocess);
    newArchetype.spawnOrder.order = archetype.spawnOrderOrder;
    newArchetype.spawnOrder.index = buildFuncNode(archetype.spawnOrder);
    newArchetype.shouldSpawn.order = archetype.shouldSpawnOrder;
    newArchetype.shouldSpawn.index = buildFuncNode(archetype.shouldSpawn);
    newArchetype.initialize.order = archetype.initializeOrder;
    newArchetype.initialize.index = buildFuncNode(archetype.initialize);
    newArchetype.updateSequential.order = archetype.updateSequentialOrder;
    newArchetype.updateSequential.index = buildFuncNode(archetype.updateSequential);
    newArchetype.touch.order = archetype.touchOrder;
    newArchetype.touch.index = buildFuncNode(archetype.touch);
    newArchetype.updateParallel.order = archetype.updateParallelOrder;
    newArchetype.updateParallel.index = buildFuncNode(archetype.updateParallel);
    newArchetype.terminate.order = archetype.terminateOrder;
    newArchetype.terminate.index = buildFuncNode(archetype.terminate);
    newArchetype.data = archetype.data;
    engineData.archetypes.push_back(newArchetype);
    time_t d = millitime() - st;
    cout << "Solved Archetype \"" << archetype.name << "\" in " << d << "ms. Speed: " 
         << fixed << setprecision(0) 
         << 1.0 * (globalCounter - lastGlobalCounter) / (1.0 * d / 1000) << " nodes/s." << endl;
    #elif preview
    time_t st = millitime();
    T archetype; EnginePreviewDataArchetype newArchetype;
    cout << "Solving Archetype \"" << archetype.name << "\"..." << endl;
    newArchetype.name = archetype.name;
    newArchetype.preprocess.order = archetype.preprocessOrder;
    newArchetype.preprocess.index = buildFuncNode3(archetype.preprocess);
    newArchetype.render.order = archetype.renderOrder;
    newArchetype.render.index = buildFuncNode3(archetype.render);
    newArchetype.data = archetype.data;
    enginePreviewData.archetypes.push_back(newArchetype);
    time_t d = millitime() - st;
    cout << "Solved Archetype \"" << archetype.name << "\" in " << d << "ms. Speed: " 
         << fixed << setprecision(0) 
         << 1.0 * (globalCounter - lastGlobalCounter) / (1.0 * d / 1000) << " nodes/s." << endl;
    #endif
}

template<typename T, typename... Args> 
void buildArchetype(T unused, Args... args) {
    buildArchetype<T>(T()); buildArchetype<Args...>(args...);
}

template<typename... Args>
void build(buffer& configurationBuffer, buffer& dataBuffer) {
    Json::Value configuration = engineConfiguration.toJsonObject();
    configurationBuffer = compress_gzip(json_encode(configuration));
#ifdef play
    buildArchetype<Args...>(Args()...);
    dataBuffer = compress_gzip(json_encode(engineData.toJsonObject()));
#elif tutorial
    engineTutorialData.preprocess = buildFuncNode2(tutorialPreprocess);
    engineTutorialData.navigate = buildFuncNode2(tutorialNavigate);
    engineTutorialData.update = buildFuncNode2(tutorialUpdate);
    dataBuffer = compress_gzip(json_encode(engineTutorialData.toJsonObject()));
#elif preview
    buildArchetype<Args...>(Args()...);
    dataBuffer = compress_gzip(json_encode(enginePreviewData.toJsonObject()));
#endif
}

void particleBuild(buffer& data, string texturePath) {
	Json::Value textureInfo = packSprites(texturePath);
	Json::Value res;
	res["width"] = textureInfo["width"];
	res["height"] = textureInfo["height"];
	res["interpolation"] = true;
	res["sprites"] = textureInfo["sprites"];
	res["effects"].resize(0);
	for (int i = 0; i < effects.size(); i++) res["effects"].append(effects[i].toJsonObject());
	data = compress_gzip(json_encode(res));
	cout << "Success to pack ParticleData!" << endl;
}

#define IF(cond) If(cond, Execute(
#define ELSE ), Execute(
#define FI ))
#define FOR(i, st, en, step) [&](){\
    FuncNode i = ForPt.get(); \
    return Block(Execute({\
        ForPt.set(st - step), \
        While(ForPt.get() < en - step, Block(Execute({\
            ForPt.set(ForPt.get() + step), \
            Execute(
#define DONE )}))) \
    })); \
}()
#define CONTINUE Break(1, 0)
#define BREAK Break(2, 0)
