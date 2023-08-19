#include<bits/stdc++.h>
#include"sonolus.h"
using namespace std;

const string dist = "./dist";
#include"engine/engine.cpp"

enum NoteType {
    None = 0,
    Normal = 10,
    Critical = 20,
    Sound = 30,
    SoundPurple = 40,
    Flick = 50,
    HoldStart = 80,
    CriticalHoldStart = 81,
    ScratchHoldStart = 82,
    ScratchCriticalHoldStart = 83,
    Hold = 100,
    CriticalHold = 101,
    ScratchHold = 110,
    HoldEighth = 900
};
enum GimmickType {
    JumpScratch = 1,
    OneDirection = 2,
    Split1 = 11,
    Split2 = 12,
    Split3 = 13,
    Split4 = 14,
    Split5 = 15,
    Split6 = 16
};
struct Note {
    double startTime;
    double endTime;
    int type;
    int leftLane;
    int laneLength;
    int gimmickType;
    int scratchLength;

    bool operator < (const Note& a) const {
        return endTime < a.endTime;
    }
};

Json::Value fromSirius(string path, int bgmOffset) {
    // 谱面读取
    ifstream fin(path); vector<Note> notes;
    while (!fin.eof()) {
        char unused = 0;
        Note x; fin >> x.startTime >> unused >> x.endTime >> unused >> x.type >> unused >> x.leftLane >> unused >> x.laneLength >> unused;
        string s; fin >> s; x.scratchLength = atoi(s.substr(s.find(",") + 1).c_str());
        s = s.substr(0, s.find(","));
        if (s == "JumpScratch") x.gimmickType = JumpScratch;
        else if (s == "OneDirection") x.gimmickType = OneDirection;
        else if (s == "11") x.gimmickType = Split1;
        else if (s == "12") x.gimmickType = Split2;
        else if (s == "13") x.gimmickType = Split3;
        else if (s == "14") x.gimmickType = Split4;
        else if (s == "15") x.gimmickType = Split5;
        else if (s == "16") x.gimmickType = Split6;
        else x.gimmickType = 0;
        notes.push_back(x);
    } sort(notes.begin(), notes.end(), [](Note a, Note b){
        if (a.startTime == b.startTime) return a.type < b.type;
        return a.startTime < b.startTime;
    });

    // 开始转换
	Json::Value res, single; set<Note> holdEnd;
    map<double, int> SyncLineLeft, SyncLineRight;
	single["archetype"] = "Sirius Initialization";
	res.append(single);
	single["archetype"] = "Sirius Input Manager";
	res.append(single);
	single["archetype"] = "Sirius Stage";
	res.append(single);
    double lastTime[13][13];
    for (int i = 0; i < 13; i++) for (int j = 0; j < 13; j++) lastTime[i][j] = 0;
    for (int i = 0; i < notes.size(); i++) {
        // 提前处理 Sirius HoldEnd;
        while (holdEnd.size() && (*holdEnd.begin()).endTime <= notes[i].startTime) {
            Note x = *holdEnd.begin(); holdEnd.erase(holdEnd.begin()); Json::Value single;
            if (x.type == Hold || x.type == CriticalHold) {
                single["archetype"] = "Sirius Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                SyncLineLeft[x.endTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
                SyncLineRight[x.endTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
            } else {
                single["archetype"] = "Sirius Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
                SyncLineLeft[x.endTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
                SyncLineRight[x.endTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
            } lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = 0; res.append(single);
        }
        // 处理当前 Note
        Note x = notes[i]; Json::Value single;
        switch(x.type) {
            case Normal: case Sound: {
                single["archetype"] = "Sirius Normal Note";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                SyncLineLeft[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
                SyncLineRight[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
            } break;
            case Critical: case SoundPurple: case CriticalHoldStart: case ScratchCriticalHoldStart:  {
                single["archetype"] = "Sirius Critical Note";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                SyncLineLeft[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
                SyncLineRight[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
            } break;
            case Flick: {
                single["archetype"] = "Sirius Flick Note";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                SyncLineLeft[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
                SyncLineRight[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
            } break;
            case HoldStart: {
                single["archetype"] = "Sirius Hold Start";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                SyncLineLeft[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
                SyncLineRight[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
            } break;
            case ScratchHoldStart: {
                single["archetype"] = "Sirius Scratch Hold Start";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                SyncLineLeft[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
                SyncLineRight[x.startTime] = 1.0 * (x.leftLane * 2 + x.laneLength - 1) / 2;
            } break;
            case Hold: case CriticalHold: case ScratchHold: {
                lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                holdEnd.insert(x);
            } break;
            case HoldEighth: {
                single["archetype"] = "Sirius Hold Eighth";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
            } break;
            case None: {
                single["archetype"] = "Sirius Split Line";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "endBeat"; single["data"][1]["value"] = x.endTime;
                single["data"][2]["name"] = "split"; single["data"][2]["value"] = x.gimmickType - 10;
            } break;
        } if (single["archetype"] != "") res.append(single);
    }

    // 处理同步线
    for (auto v : SyncLineLeft) {
        double beat = v.first; int left = v.second;
        if (SyncLineRight[beat] == left) continue;
        Json::Value single; single["archetype"] = "Sirius Sync Line";
        single["data"][0]["name"] = "beat"; single["data"][0]["value"] = beat;
        single["data"][1]["name"] = "left"; single["data"][1]["value"] = left;
        single["data"][2]["name"] = "right"; single["data"][2]["value"] = SyncLineRight[beat];
        res.append(single);
    }

	Json::Value data;
	data["bgmOffset"] = bgmOffset;
	data["entities"] = res;
	return data;
}

int main(int argc, char** argv) {
    // 谱面转换测试
	if (argc >= 3) {
		Json::Value LevelData = fromSirius(argv[1], 0);
		string dataJson = json_encode(LevelData);
		buffer data = compress_gzip(dataJson, 9);
		ofstream preFout(argv[2]);
		for (int i = 0; i < data.size(); i++) preFout << data.v[i];
		preFout.close();
	}

    engineConfiguration.ui = configurationUI;
#ifdef play
    buffer data, configuration;
    build<
        // Replace with your archetypes here
        Initialization,
        InputManager,
        Stage
    >(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EngineData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#elif tutorial
    buffer data, configuration;
    build(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EngineTutorialData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#endif
}