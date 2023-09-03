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
		if (a.endTime == endTime) return leftLane * 100 + laneLength < a.leftLane * 100 + a.laneLength;
        return endTime < a.endTime;
    }
};

vector<string> explode(const char* seperator, const char* source) {
	string src = source; vector<string> res;
	while (src.find(seperator) != string::npos) {
		int wh = src.find(seperator);
		res.push_back(src.substr(0, src.find(seperator)));
		src = src.substr(wh + string(seperator).size());
	} res.push_back(src);
	return res;
}

Json::Value fromSirius(string path, double chartOffset, double bgmOffset = 0) {
    // 谱面读取
    ifstream fin(path); vector<Note> notes;
    while (!fin.eof()) {
        char unused = 0;
        Note x; string xx; getline(fin, xx);
        auto components = explode(",", xx.c_str());
        if (components.size() < 7) break;
        x.startTime = atof(components[0].c_str()) + chartOffset;
        x.endTime = atof(components[1].c_str());
        if (x.endTime != -1) x.endTime += chartOffset;
        x.type = atoi(components[2].c_str());
        x.leftLane = atoi(components[3].c_str());
        x.laneLength = atoi(components[4].c_str());
        string s = components[5];
        x.scratchLength = atoi(components[6].c_str());
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
    } sort(notes.begin(), notes.end(), [&](Note a, Note b){
        if (a.startTime == b.startTime) return a.type < b.type;
        return a.startTime < b.startTime;
    });
    cout << "[INFO] Total Note Number: " << notes.size() << endl;

    // 开始转换
	Json::Value res, single; set<Note> holdEnd;
    map<double, int> SyncLineLeft, SyncLineRight;
    auto addSyncLine = [&](double beat, int leftLane, int laneLength) {
        if (SyncLineLeft.find(beat) == SyncLineLeft.end()) SyncLineLeft[beat] = leftLane;
        else SyncLineLeft[beat] = min(SyncLineLeft[beat], leftLane);
        if (SyncLineRight.find(beat) == SyncLineRight.end()) SyncLineRight[beat] = leftLane + laneLength - 1;
        else SyncLineRight[beat] = max(SyncLineRight[beat], leftLane + laneLength - 1);
    };
	single["archetype"] = "Sirius Initialization";
	res.append(single);
	single["archetype"] = "Sirius Input Manager";
	res.append(single);
	single["archetype"] = "Sirius Stage";
	res.append(single);
    double lastTime[13][13]; int lastType[13][13], total = 0;
    for (int i = 0; i < 13; i++) for (int j = 0; j < 13; j++) lastTime[i][j] = 0, lastType[i][j] = 0;
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
                total++;
            } else {
                single["archetype"] = "Sirius Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
                total++;
            } lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = 0; res.append(single);
			lastType[x.leftLane][x.leftLane + x.laneLength - 1] = 0; addSyncLine(x.endTime, x.leftLane, x.laneLength);
        }
        // 处理当前 Note
        Note x = notes[i]; Json::Value single;
        single["archetype"] = "";
        switch(x.type) {
            case Normal: {
                single["archetype"] = "Sirius Normal Note";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case Critical: {
                single["archetype"] = "Sirius Critical Note";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case Flick: {
                single["archetype"] = "Sirius Flick Note";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case HoldStart: {
                single["archetype"] = "Sirius Hold Start";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break; 
            case CriticalHoldStart: {
                single["archetype"] = "Sirius Critical Hold Start";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case ScratchHoldStart: {
                single["archetype"] = "Sirius Scratch Hold Start";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case ScratchCriticalHoldStart: {
                single["archetype"] = "Sirius Critical Scratch Hold Start";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case Hold: case CriticalHold: case ScratchHold: {
                lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case Sound: {
                single["archetype"] = "Sirius Sound";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
				single["data"][4]["name"] = "holdType"; single["data"][4]["value"] = lastType[x.leftLane][x.leftLane + x.laneLength - 1];
                lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                total++;
            } break;
            case SoundPurple: {
                single["archetype"] = "Sirius Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = 0;
                lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case HoldEighth: {
                if (lastTime[x.leftLane][x.leftLane + x.laneLength - 1] == x.startTime) break;
                single["archetype"] = "Sirius Hold Eighth";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
				single["data"][4]["name"] = "holdType"; single["data"][4]["value"] = lastType[x.leftLane][x.leftLane + x.laneLength - 1];
                lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                total++;
            } break;
            case None: {
                single["archetype"] = "Sirius Split Line";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "endBeat"; single["data"][1]["value"] = x.endTime;
                single["data"][2]["name"] = "split"; single["data"][2]["value"] = x.gimmickType - 10;
                single["data"][3]["name"] = "color"; single["data"][3]["value"] = x.scratchLength;
            } break;
        } if (single["archetype"] != "") res.append(single);
        if (single["archetype"] == Json::Value::null) cout << single << endl;
        if ((10 * (i + 1) / notes.size()) != (10 * i / notes.size())) cout << "[INFO] " << 100 * (i + 1) / notes.size() << "% Notes Solved." << endl;
    }

	// 处理完 HoldEnd
	while (holdEnd.size()) {
        Note x = *holdEnd.begin(); holdEnd.erase(holdEnd.begin()); Json::Value single;
        if (x.type == Hold || x.type == CriticalHold) {
            single["archetype"] = "Sirius Hold End";
            single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
            single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            total++;
        } else {
            single["archetype"] = "Sirius Scratch Hold End";
            single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
            single["data"][1]["name"] = "lastBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
            total++;
        } lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = 0; res.append(single);
        lastType[x.leftLane][x.leftLane + x.laneLength - 1] = 0; addSyncLine(x.endTime, x.leftLane, x.laneLength);
    }

    cout << "[INFO] Total Note Number: " << total << endl;
    cout << "[INFO] Solving Sync Line..." << endl;

    // 处理同步线
    for (auto v : SyncLineLeft) {
        double beat = v.first; int left = v.second;
        Json::Value single; single["archetype"] = "Sirius Sync Line";
        single["data"][0]["name"] = "beat"; single["data"][0]["value"] = beat;
        single["data"][1]["name"] = "left"; single["data"][1]["value"] = left;
        single["data"][2]["name"] = "right"; single["data"][2]["value"] = SyncLineRight[beat];
        res.append(single);
    }

    cout << "[INFO] Sync Line Solved." << endl;

	Json::Value data;
	data["bgmOffset"] = bgmOffset;
	data["entities"] = res;
	return data;
}

int main(int argc, char** argv) {
    // 谱面转换测试
	if (argc >= 4) {
		ifstream fin(argv[2]);
		string s; fin >> s; fin >> s;
		s = s.substr(s.find(",", s.find(",") + 1) + 1, 5);
		stringstream ss; ss << s; double offset; ss >> offset;
		Json::Value LevelData = fromSirius(argv[1], offset);
		string dataJson = json_encode(LevelData);
        cout << "Compressing..." << endl;
		buffer data = compress_gzip(dataJson, 9);
        cout << "Compress Finished." << endl;
		ofstream preFout(argv[3]);
        for (int i = 0; i < data.size(); i++) preFout << data.v[i];
		preFout.close();
        return 0;
	}

    engineConfiguration.ui = configurationUI;
#ifdef play
    buffer data, configuration;
    build<
        // Replace with your archetypes here
        Initialization,
        InputManager,
        Stage,
        NormalNote,
        CriticalNote,
        FlickNote,
		SiriusHoldStart,
		SiriusCriticalHoldStart,
		SiriusScratchHoldStart,
		SiriusCriticalScratchHoldStart,
		SiriusHoldEighth,
        SiriusSound,
		SiriusHoldEnd,
		SiriusScratchHoldEnd,
        SyncLine,
        SplitLine
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
