#ifndef TutorialBuild_H
#define TutorialBuild_H

class EngineTutorialData {
    public:

    string skinRenderMode = "default";
    vector<pair<string, int> > skinSprites = {};
    vector<pair<string, int> > effectClips = {};
    vector<pair<string, int> > particleEffects = {};
    vector<pair<string, int> > instructionTexts = {};
    vector<pair<string, int> > instructionIcons = {};
    int preprocess = 0;
    int navigate = 0;
    int update = 0;
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
        res["instruction"]["texts"].resize(0);
        for (int i = 0; i < instructionTexts.size(); i++) {
            Json::Value single;
            single["name"] = instructionTexts[i].first;
            single["id"] = instructionTexts[i].second;
            res["instruction"]["texts"].append(single);
        }
        res["instruction"]["icons"].resize(0);
        for (int i = 0; i < instructionIcons.size(); i++) {
            Json::Value single;
            single["name"] = instructionIcons[i].first;
            single["id"] = instructionIcons[i].second;
            res["instruction"]["icons"].append(single);
        }
        res["preprocess"] = preprocess;
        res["navigate"] = navigate;
        res["update"] = update;
        res["nodes"].resize(0);
        for (int i = 0; i < nodes.size(); i++)
            res["nodes"].append(nodes[i].toJsonObject());
        return res;
    }
}engineTutorialData;

vector<function<SonolusApi()> > Preprocesses = {};
vector<pair<function<SonolusApi(var, var)>, double> > TemporarySegments = {};
vector<vector<pair<function<SonolusApi(var, var)>, double> > > Segments = {};
vector<function<SonolusApi(var, var)> > Statics = {};

vector<SwitchWithDefault_Group_test_consequent> Duration, BaseTime, NextSegment;
int segmentNumber = 0, groupNumber = 0; double sumTime = 0; 
void TutorialBuildPreprocess() {
    int id = 0;
    for (int i = 0; i < Segments.size(); i++) {
        auto segmentGroup = Segments[i];
        int tmpid = id; groupNumber++;
        for (int j = 0; j < segmentGroup.size(); j++) {
            auto segment = segmentGroup[j];
            segmentNumber++;
            Duration.push_back({ id, segment.second }), 
            BaseTime.push_back({ id, sumTime }), 
            sumTime += segment.second; id++;
        }
        for (int j = tmpid; j < id; j++) NextSegment.push_back({ j, id });
    }
};

var tutorialNavigation, tutorialStartTime;
SonolusApi TutorialPreprocess() {    
    tutorialStartTime = 0;
    tutorialNavigation = 0;
    for (CppLoop int i = 0; i < Preprocesses.size(); i++) Preprocesses[i]();
}

SonolusApi TutorialNavigate() {
    for (var i = 0; i < If(navigation > 0, 1, groupNumber - 1); i++) {
        tutorialNavigation = SwitchWithDefault(tutorialNavigation, NextSegment, 0);
        tutorialNavigation = tutorialNavigation % segmentNumber;
    }
    tutorialStartTime = times.now;
    instruction = -1;
}

FuncNode TutorialUpdateContainer(function<SonolusApi(var, var)> func, var arg1, var arg2) {
    int tmp = SonolusMemoryDelta[TemporaryMemoryId];
    createNodeContainer();
    func(arg1, arg2);
    FuncNode node = mergeNodeContainer();
    SonolusMemoryDelta[TemporaryMemoryId] = tmp;
    return node;
}
SonolusApi TutorialUpdate() {
    if (times.now - tutorialStartTime > SwitchWithDefault(tutorialNavigation, Duration, 1)) {
        tutorialNavigation = tutorialNavigation + 1;
        tutorialNavigation = tutorialNavigation % segmentNumber;
        tutorialStartTime = times.now;
    }

    for (CppLoop int i = 0; i < Statics.size(); i++) {
        auto Static = Statics[i];
        Static(SwitchWithDefault(tutorialNavigation, BaseTime, 1) + times.now - tutorialStartTime, sumTime);
    }
    
    vector<SwitchWithDefault_Group_test_consequent> funcs; int id = 0;
    for (CppLoop int i = 0; i < Segments.size(); i++) {
        auto group = Segments[i];
        for (CppLoop int j = 0; j < group.size(); j++) {
            auto segment = group[j];
            funcs.push_back({
                id++,
                TutorialUpdateContainer(segment.first, times.now - tutorialStartTime, segment.second)
            });
        }
    }
        
    SonolusRun(SwitchWithDefault(tutorialNavigation, funcs, 0));
}

void BuildData() {
    TutorialBuildPreprocess();

    archetypeName = "Tutorial Archetype";
    defaultAllocatorId = TemporaryMemoryId;

    createNodeContainer();
    callbackName = "preprocess";
    TutorialPreprocess();
    engineTutorialData.preprocess = mergeNodeContainer().getNodeId();

    createNodeContainer();
    callbackName = "navigate";
    TutorialNavigate();
    engineTutorialData.navigate = mergeNodeContainer().getNodeId();

    createNodeContainer();
    callbackName = "update";
    TutorialUpdate();
    engineTutorialData.update = mergeNodeContainer().getNodeId();

    engineTutorialData.nodes = dataContainer;
    engineTutorialData.skinSprites.clear();
    for (int i = 0; i < skin_sprites.size(); i++) 
        engineTutorialData.skinSprites.push_back({ skin_sprites[i].first, i });
    engineTutorialData.effectClips.clear();
    for (int i = 0; i < effect_clips.size(); i++) 
        engineTutorialData.effectClips.push_back({ effect_clips[i].first, i });
    engineTutorialData.particleEffects.clear();
    for (int i = 0; i < particle_effects.size(); i++) 
        engineTutorialData.particleEffects.push_back({ particle_effects[i].first, i });
    engineTutorialData.instructionTexts.clear();
    for (int i = 0; i < instruction_texts.size(); i++)
        engineTutorialData.instructionTexts.push_back({ instruction_texts[i], i });
    engineTutorialData.instructionIcons.clear();
    for (int i = 0; i < instruction_icons.size(); i++)
        engineTutorialData.instructionIcons.push_back({ instruction_icons[i], i });
    
    string EngineTutorialData = compress_gzip(json_encode(engineTutorialData.toJsonObject()));
    ofstream fout = ofstream(dist + "/EngineTutorialData");
    fout.write(EngineTutorialData.c_str(), EngineTutorialData.size());
}

#define defineTutorialPreprocess(func) bool unused_##func##_unused = [](){ Preprocesses.push_back(func); return true; }()
#define defineTutorialSegment(func, duration) bool unused_##func##_unused = [](){ TemporarySegments.push_back({ func, duration }); return true; }()
#define defineTutorialSegmentsGroup(name) bool unused_##name##_unused = [](){ Segments.push_back(TemporarySegments); TemporarySegments.clear(); return true; }()
#define defineTutorialStatic(func) bool unused_##func##_unused = [](){ Statics.push_back(func); return true; }()

#endif