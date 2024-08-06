const int magicNumber = 0x114514;

enum NoteType {
    HiSpeed = -1,
    None = 0,
    Normal = 10,
    Critical = 20,
    Sound = 30,
    ScratchSound = 31,
    SoundPurple = 40,
    Flick = 50,
    HoldStart = 80,
    CriticalHoldStart = 81,
    ScratchHoldStart = 82,
    ScratchCriticalHoldStart = 83,
    Hold = 100,
    NontailHold = 1100,
    CriticalHold = 101,
    NontailCriticalHold = 1101,
    ScratchHold = 110,
    NontailScratchHold = 1110,
    ScratchCriticalHold = 111,
    NontailScratchCriticalHold = 1111,
    BlueTap = 200,
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
    Split6 = 16,
    // 接下来的东西我也不知道是干啥用的
    FullSplit1 = 31,
    FullSplit2 = 32,
    FullSplit3 = 33,
    FullSplit4 = 34,
    FullSplit5 = 35,
    FullSplit6 = 36,
    LightSplit1 = 51,
    LightSplit2 = 52,
    LightSplit3 = 53,
    LightSplit4 = 54,
    LightSplit5 = 55,
    LightSplit6 = 56,
    IgnoreSplit1 = 71,
    IgnoreSplit2 = 72,
    IgnoreSplit3 = 73,
    IgnoreSplit4 = 74,
    IgnoreSplit5 = 75,
    IgnoreSplit6 = 76
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

double fromMusicInfo(string text) {
    auto res = explode("\n", text.c_str());
    if (res.size() < 2) {
        cout << "Invalid Music Info." << endl;
        exit(1);
    } res = explode(",", res[1].c_str());
    if (res.size() < 3) {
        cout << "Invalid Music Info." << endl;
        exit(1);
    } return atof(res[2].c_str());
}

string getRef(int len = 32) {
	string res = "", key = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int i = 0; i < len; i++) res += key[rand() % key.size()];
	return res;
}

string fromSirius(string text, double chartOffset, double bgmOffset = 0) {
    // 谱面读取
    auto lines = explode("\n", text.c_str());
    vector<Note> notes; double speed = 1;
    for (int i = 0; i < lines.size(); i++) {
        char unused = 0;
        Note x; string xx = lines[i];
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
        else if (s == "11" || s == "31" || s == "51" || s == "71") x.gimmickType = Split1;
        else if (s == "12" || s == "32" || s == "52" || s == "72") x.gimmickType = Split2;
        else if (s == "13" || s == "33" || s == "53" || s == "73") x.gimmickType = Split3;
        else if (s == "14" || s == "34" || s == "54" || s == "74") x.gimmickType = Split4;
        else if (s == "15" || s == "35" || s == "55" || s == "75") x.gimmickType = Split5;
        else if (s == "16" || s == "36" || s == "56" || s == "76") x.gimmickType = Split6;
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
	single["archetype"] = "Sirius Initialization"; single["data"].resize(0);
	res.append(single);
	single["archetype"] = "Sirius Input Manager"; single["data"].resize(0);
	res.append(single);
	single["archetype"] = "Sirius Stage"; single["data"].resize(0);
	res.append(single); 
	single["archetype"] = "#BPM_CHANGE";
	single["data"][0]["name"] = "#BEAT"; single["data"][0]["value"] = 0;
	single["data"][1]["name"] = "#BPM"; single["data"][1]["value"] = 60;
	res.append(single); 
    double lastEighthTime[13][13]; int lastType[13][13], total = 0;
    for (int i = 0; i < 13; i++) for (int j = 0; j < 13; j++) lastEighthTime[i][j] = 0, lastType[i][j] = 0;
    for (int i = 0; i < notes.size(); i++) {
        // 提前处理 Sirius HoldEnd;
        while (holdEnd.size() && (*holdEnd.begin()).endTime <= notes[i].startTime) {
            Note x = *holdEnd.begin(); holdEnd.erase(holdEnd.begin()); Json::Value single;
            if (x.type == Hold || x.type == CriticalHold) {
                single["archetype"] = "Sirius Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                total++;
            } else if (x.type == NontailHold || x.type == NontailCriticalHold) {
                single["archetype"] = "Sirius Nontail Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                total++;
            } else if (x.type == ScratchHold || x.type == ScratchCriticalHold) {
                single["archetype"] = "Sirius Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
                total++;
            } else {
                single["archetype"] = "Sirius Nontail Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
                total++;
            } res.append(single);
            if (x.type >= NontailHold) continue;
			addSyncLine(x.endTime, x.leftLane, x.laneLength);
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
                single["data"][3]["name"] = "scratchLength"; single["data"][3]["value"] = x.scratchLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case HoldStart: case BlueTap: {
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
            case Hold: case CriticalHold: case ScratchHold: case ScratchCriticalHold: 
            case NontailHold: case NontailCriticalHold: case NontailScratchHold: case NontailScratchCriticalHold: {
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case Sound: case ScratchSound: {
                lastEighthTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                single["archetype"] = "Sirius Sound";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
				single["data"][3]["name"] = "holdType"; single["data"][3]["value"] = lastType[x.leftLane][x.leftLane + x.laneLength - 1];
                total++;
            } break;
            case SoundPurple: {
                lastEighthTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                single["archetype"] = "Sirius Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
            	single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case HoldEighth: {
                if (lastEighthTime[x.leftLane][x.leftLane + x.laneLength - 1] == x.startTime) break;
                single["archetype"] = "Sirius Hold Eighth";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
                // 历史遗留代码了，这个属性现在应该不需要了 2024.5.27
				single["data"][3]["name"] = "holdType"; single["data"][3]["value"] = 0;
                total++;
            } break;
            case None: {
                single["archetype"] = "Sirius Split Line";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "endBeat"; single["data"][1]["value"] = x.endTime;
                single["data"][2]["name"] = "split"; single["data"][2]["value"] = x.gimmickType - 10;
                single["data"][3]["name"] = "color"; single["data"][3]["value"] = x.scratchLength;
            } break;
            case HiSpeed: {
                single["archetype"] = "#TIMESCALE_CHANGE";
                single["data"][0]["name"] = "#BEAT"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "#TIMESCALE"; single["data"][1]["value"] = x.endTime - chartOffset;
            }
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
            single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            total++;
        } else if (x.type == NontailHold || x.type == NontailCriticalHold) {
            single["archetype"] = "Sirius Nontail Hold End";
            single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
            single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            total++;
        } else if (x.type == ScratchHold || x.type == ScratchCriticalHold) {
            single["archetype"] = "Sirius Scratch Hold End";
            single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
            single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
            total++;
        } else {
            single["archetype"] = "Sirius Nontail Scratch Hold End";
            single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
            single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = x.startTime;
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
            total++;
        } res.append(single);
        if (x.type >= NontailHold) continue;
        addSyncLine(x.endTime, x.leftLane, x.laneLength);
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
	data["formatVersion"] = 5;
	data["bgmOffset"] = bgmOffset;
	data["entities"] = res;
	return json_encode(data);
}

void addTime( double &current, double bpm, double beat,
    tuple<string, int, int, string> a, 
    tuple<string, int, int, string> b) {
    int a1 = atoi(get<0>(a).substr(0, 3).c_str());
    int b1 = atoi(get<0>(b).substr(0, 3).c_str());
    int a2 = get<1>(a), b2 = get<1>(b);
    int a3 = get<2>(a), b3 = get<2>(b);
    double timesPerBeat = 60.0 * beat / bpm;
    if (a1 == b1) current += (1.0 * b2 / b3 - 1.0 * a2 / a3) * timesPerBeat;
    else current += ((b1 - a1 - 1) + 1.0 - 1.0 * a2 / a3 + 1.0 * b2 / b3) * timesPerBeat; 
}

int extract(char x) {
    return isdigit(x) ? x - '0' : x - 'a' + 10;
}

int getLine(char x, char offset = '0', int offset2 = 0) {
    int id = extract(x) - 1;
    int off = extract(offset);
    id += off + offset2;
    if (id <= 0 || id > 12) 
        throw runtime_error("Invalid Line " + to_string(id));
    return id;
}

// set<string> splitLineList = {
//     "1",
//     "2",
//     "3",
//     "4",
//     "5",
//     "6",
//     "7",
//     "8",
//     "9",
//     "1010",
//     "1020",
//     "1030",
//     "1040",
//     "1050",
//     "1060",
//     "1070",
//     "2010",
//     "2020",
//     "2030",
//     "2040",
//     "2050",
//     "3010",
//     "3020",
//     "3030",
//     "3040",
//     "3050",
//     "4010",
//     "4020",
//     "4030",
//     "4040",
//     "4050",
//     "10010",
//     "10020",
//     "10030",
//     "10040",
//     "10050",
//     "10060",
//     "10070",
//     "10100",
//     "10110",
//     "10120",
//     "10130",
//     "10140",
//     "10150",
//     "10160",
//     "10161",
//     "10162",
//     "10170",
//     "10180",
//     "10190",
//     "10191",
//     "10200",
//     "10220",
//     "10230",
//     "10240",
//     "10250",
//     "10260",
//     "10270",
//     "10280",
//     "10290",
//     "10300",
//     "10310",
//     "10320",
//     "10321",
//     "10322",
//     "10323",
//     "10324",
//     "10325",
//     "10326",
//     "10327",
//     "10328",
//     "10330",
//     "10340",
//     "10350",
//     "10360",
//     "10361",
//     "10370",
//     "10380",
//     "10390",
//     "10391",
//     "10392",
//     "10393",
//     "10400",
//     "10410",
//     "10420",
//     "10430",
//     "10440",
//     "10450",
//     "10460",
//     "10461",
//     "10470",
//     "10480",
//     "10481",
//     "10482",
//     "10490",
//     "10500",
//     "10510",
//     "10511",
//     "10512",
//     "10513",
//     "10514",
//     "10515",
//     "10516",
//     "10517",
//     "10518",
//     "10519",
//     "10530",
//     "10540",
//     "10550",
//     "10560",
//     "10570",
//     "10580",
//     "10590",
//     "10600",
//     "10610",
//     "10620",
//     "10630",
//     "10631",
//     "10640",
//     "10650",
//     "10660",
//     "10670",
//     "10680",
//     "10690",
//     "10710",
//     "10720",
//     "10770",
//     "10771",
//     "10780",
//     "10790",
//     "10791",
//     "10792",
//     "10800",
//     "10810",
//     "10820",
//     "10830",
//     "10840",
//     "10841",
//     "10850",
//     "10860",
//     "10920",
//     "10930",
//     "10940",
// };

string fromSUS(string text) {
    auto lines = explode("\n", text.c_str());
    double ticks_per_beat = 480;
    vector<tuple<string, int, int, string> > mainData;
    map<string, int> bpmList;
    int currentBpm = 120; double currentBeat = 2, currentTime = 0;
    int currentSplitLine = 0, currentSplitLineType = 0; double currentSplitLineTime = 0;
    double waveOffset = 0;
    for (int i = 0; i < lines.size(); i++) {
        while (lines[i].back() == '\n' || lines[i].back() == '\r') lines[i].pop_back();
        if (lines[i].size() && lines[i][0] == '\r') lines[i] = lines[i].substr(1);
        if (lines[i].size() == 0 || lines[i][0] != '#') continue;
        lines[i] = lines[i].substr(1);

        // 处理元数据
        if (lines[i].substr(0, 7) == "REQUEST") {
            string request = lines[i].substr(9, lines[i].size() - 10);
            auto res = explode(" ", request.c_str());
            if (res[0] == "ticks_per_beat") ticks_per_beat = atof(res[1].c_str());
            if (res[0] == "lane_slided") ; // 不知道干啥的
            continue;
        }
        if (lines[i].substr(0, 10) == "WAVEOFFSET") {
        	string t = lines[i].substr(11);
			currentTime = atof(t.c_str());
			continue;
        }

        // 处理谱面数据
        vector<string> res;
        if (lines[i].find(": ") != string::npos) res = explode(": ", lines[i].c_str());
        else if (lines[i].find(":") != string::npos) res = explode(":", lines[i].c_str());
        else continue;
        string head = res[0], body = res[1];
        if (head.substr(0, 3) == "BPM") {
            string id = head.substr(3);
            int bpm = atoi(body.c_str());
            bpmList[id] = bpm;
            continue;
        }
        if (head.substr(0, 3) == "TIL") {
        	if (head.substr(3, 2) == "01") {
	            body = body.substr(1, body.size() - 2);
	            if (body == "") continue;
	            auto exp = explode(", ", body.c_str());
	            for (auto i = 0; i < exp.size(); i++) {
	                string tmp = exp[i];
	                auto tmp1 = explode(":", tmp.c_str());
	                if (tmp1.size() != 2)
	                    throw runtime_error("Invalid Split Line Parameter: " + exp[i]);
	                string beat = tmp1[0], type = tmp1[1];
	                auto tmp2 = explode("'", beat.c_str());
	                if (tmp2.size() != 2)
	                    throw runtime_error("Invalid Split Line Parameter: " + exp[i]);
	                auto tmp3 = explode(".", type.c_str());
	                if (tmp3.size() != 2)
	                    throw runtime_error("Invalid Split Line Parameter: " + exp[i]);
	                // switch(tmp2[1].size()) {
	                //     case 0: tmp2[1] = "0000"; break;
	                //     case 1: tmp2[1] = "000" + tmp2[1]; break;
	                //     case 2: tmp2[1] = "00" + tmp2[1]; break;
	                //     case 3: tmp2[1] = "0" + tmp2[1]; break;
	                // } 
	                while (tmp2[1].size() < 4) tmp2[1] = '0' + tmp2[1];
	                while (tmp3[0].size() < 2) tmp3[0] = '0' + tmp3[0];
	                while (tmp3[1].size() < 5) tmp3[1] = '0' + tmp3[1]; // upd: 解决部分 Ched 保存 HiSpeed 不会保留五位小数的问题 2024/01/13
                    // auto tmp4 = tmp3[1]; // md ChedPlus 的版本不同，舍去前置零和舍去后置零 tm 还不一样
                    // while (tmp4.front() == '0') tmp4 = tmp4.substr(1);
                    // if (splitLineList.find(tmp4) == splitLineList.end()) 
                    //     throw runtime_error("Invalid Split Line Type: " + tmp4);
	                exp[i] = tmp2[0] + "'" + tmp2[1] + ":" + tmp3[0] + "." + tmp3[1];
	            }
	            sort(exp.begin(), exp.end(), [](string a, string b){
	            	return a.size() == b.size() ? a < b : a.size() < b.size();
	            }); // upd: 字符串类型的数字不能直接排序，警钟敲烂😓 2024/01/14
	            for (auto i = 0; i < exp.size(); i++) {
	                string tmp = exp[i];
	                // cout << tmp << endl;
	                auto tmp1 = explode(":", tmp.c_str());
	                string beat = tmp1[0], type = tmp1[1];
	                auto tmp2 = explode("'", beat.c_str());
	                auto tmp3 = explode(".", type.c_str());
	                int lines = atoi(tmp3[0].c_str()), types = atoi(tmp3[1].c_str());
	                if (currentSplitLine != 0) { // 分割线终点
	                	// cout << currentSplitLine << " " << currentSplitLineType << endl;
	                    if (currentSplitLine * -1 != lines || currentSplitLineType != types)
	                        throw runtime_error("Overlapped Split Line: " + exp[i]);
	                    currentSplitLine = 0; currentSplitLineType = 0;
	                } else {
	                    if (lines > 6 || lines < 1) 
	                        throw runtime_error("Invalid Split Line Parameter: " + exp[i]);
	                    currentSplitLine = lines; currentSplitLineType = types;
	                }
	                switch(tmp2[0].size()) {
	                    case 0: tmp2[0] = "000"; break;
	                    case 1: tmp2[0] = "00" + tmp2[0]; break;
	                    case 2: tmp2[0] = "0" + tmp2[0]; break;
	                }
	                mainData.push_back({tmp2[0] + "SL", atoi(tmp2[1].c_str()), 1920, type});
	            }
	            continue;
	        } else if (head.substr(3, 2) == "00") {
	            body = body.substr(1, body.size() - 2);
	            if (body == "") continue;
	            auto exp = explode(", ", body.c_str());
	            for (auto i = 0; i < exp.size(); i++) {
	                string tmp = exp[i];
	                auto tmp1 = explode(":", tmp.c_str());
	                if (tmp1.size() != 2)
	                    throw runtime_error("Invalid HiSpeed Parameter: " + exp[i]);
	                string beat = tmp1[0], type = tmp1[1];
	                auto tmp2 = explode("'", beat.c_str());
	                if (tmp2.size() != 2)
	                    throw runtime_error("Invalid HiSpeed Parameter: " + exp[i]);
	                switch(tmp2[0].size()) {
	                    case 0: tmp2[0] = "000"; break;
	                    case 1: tmp2[0] = "00" + tmp2[0]; break;
	                    case 2: tmp2[0] = "0" + tmp2[0]; break;
	                }
	                mainData.push_back({tmp2[0] + "HS", atoi(tmp2[1].c_str()), 1920, type});
	            }
	            continue;
	        }
        }
        if (head.substr(3, 2) == "02") { // 处理变拍事件
            mainData.push_back({head, 0, 1, body});
            continue;
        }
        for (int j = 0; j < body.size(); j += 2) if (body.substr(j, 2) != "00")
            mainData.push_back({head, j / 2, max(1, int(body.size()) / 2), body.substr(j, 2)});
    }

    // 音符排序
    // cout << mainData.size() << endl;
    sort(mainData.begin(), mainData.end(), [](
        tuple<string, int, int, string> a, 
        tuple<string, int, int, string> b){
        int a1 = atoi(get<0>(a).substr(0, 3).c_str());
        int b1 = atoi(get<0>(b).substr(0, 3).c_str());
        int a2 = get<1>(a), b2 = get<1>(b);
        int a3 = get<2>(a), b3 = get<2>(b);
        string a4 = get<0>(a).substr(3), b4 = get<0>(b).substr(3);
        if (a1 != b1) return a1 < b1;
        if (a2 * b3 != a3 * b2) return a2 * b3 < a3 * b2; 
        return a4 < b4;
    });

    // 处理主数据
    stringstream txt; map<double, vector<tuple<string, int, int, string> > > noteList[13][13];
    for (int i = 0; i < mainData.size(); i++) {
        if (i == 0) addTime(currentTime, currentBpm, currentBeat, {"00000", 0, 1, "00"}, mainData[i]);
        else addTime(currentTime, currentBpm, currentBeat, mainData[i - 1], mainData[i]);
        string head = get<0>(mainData[i]), body = get<3>(mainData[i]);
        int beat = atoi(head.substr(0, 3).c_str());
        string prop = head.substr(3);
        if (prop == "08") { // BPM Change
            if (get<3>(mainData[i]) == "00") continue;
            int bpm = bpmList[get<3>(mainData[i])];
            currentBpm = bpm;
        } else if (prop == "02") { // Beat Change 
            double beat = atof(get<3>(mainData[i]).c_str());
            currentBeat = beat;
        } else if (prop == "SL") { // Split Line
            auto tmp = explode(".", body.c_str());
            int line = atoi(tmp[0].c_str()), type = atoi(tmp[1].c_str());
            if (currentSplitLine == 0)
                currentSplitLine = line, currentSplitLineType = type, currentSplitLineTime = currentTime;
            else {
                txt << currentSplitLineTime << "," << currentTime << "," << None << "," << -1 << "," << 0 << ","
                    << 10 + currentSplitLine << "," << currentSplitLineType << endl; // 调整 Split Line 的时间
                currentSplitLine = 0; currentSplitLineType = 0; currentSplitLineTime = 0;
            }
        } else if (prop == "HS") { // HiSpeed
        	txt << currentTime << "," << atof(body.c_str()) << "," << HiSpeed << "," << -1 << "," << 0 << "," << 0 << "," << 0 << endl;
        } else if (prop[0] == '1') { // Tap
            if (body == "00") continue;
            if (body[0] != '1' && body[0] != '2' && body[0] != '3' && body[0] != '4') 
                throw runtime_error("Invalid Tap Type " + head + ": " + body);
            int l = getLine(prop[1]), r = getLine(prop[1], body[1], -1);
            if (body[0] == '1' || body[0] == '2' || body[0] == '4') noteList[l][r][currentTime].push_back(mainData[i]); // upd: 新增 Damage 功能
            else ; // Note Type = 3, 不知道干嘛的
        } else if (prop[0] == '5') { // Flick
            if (body == "00") continue;
            if (body[0] != '1' && body[0] != '3' && body[0] != '4') 
                throw runtime_error("Invalid Flick Type " + head + ": " +  body);
            int l = getLine(prop[1]), r = getLine(prop[1], body[1], -1);
            noteList[l][r][currentTime].push_back(mainData[i]);
        } else if (prop[0] == '3') { // Slide(Hold)
            if (body == "00") continue;
            if (body[0] != '1' && body[0] != '2' && body[0] != '3') 
                throw runtime_error("Invalid Slide Type " + head + ": " + body);
            int l = getLine(prop[1]), r = getLine(prop[1], body[1], -1);
            noteList[l][r][currentTime].push_back({get<0>(mainData[i]), get<1>(mainData[i]), currentBpm, get<3>(mainData[i])});
        }
    }

    // 开始解析
    // 优先解析 Slide
    struct SlideStructure {
    	bool inSlide = false;
    	bool CriticalSlide = false;
    	bool ScratchSlide = false;
    	bool addStart = true;
        bool isCausedByDamage = false;
    	double startTime = 0;
    };
    double tickTime = ticks_per_beat / 1920.0 * 60 * 4 / currentBpm;
    for (int l = 1; l <= 12; l++) {
        for (int r = l; r <= 12; r++) { // 枚举按键位置
            int slideNumber = 0;
            SlideStructure slides[128];
            for (auto v : noteList[l][r]) {
                double t = v.first; auto info = v.second;
                bool isCritical = false, isFlick = false, isDamage = false,
                     isSlideSound = false;
                vector<char> SlideStartName, SlideEndName;
                int bpm = 120;
                for (auto x : info) {
                    string head = get<0>(x), body = get<3>(x);
                    string prop = head.substr(3);
                    if (prop[0] == '1') isCritical |= (body[0] == '2');
                    if (prop[0] == '1') isDamage |= (body[0] == '4');
                    if (prop[0] == '5') isFlick |= 1;
                    if (prop[0] == '3') {
                        isSlideSound |= (body[0] == '3');
                       	if (body[0] == '1') SlideStartName.push_back(prop[2]);
                       	if (body[0] == '2') SlideEndName.push_back(prop[2]);
                        bpm = get<2>(x);
                        // cout << head << " " << body << endl;
                    }
                }
                // cout << endl;

                // Note 讨论
                if (SlideStartName.size() == 0 && SlideEndName.size() == 0 && !isSlideSound && !isFlick) continue;
                if (isSlideSound) {
                    if (slideNumber == 0) throw runtime_error("Unknown Slide Sound in [" + to_string(l) + ", " + to_string(r) + "]");
                    txt << t << "," << -1 << "," << Sound << "," 
                        << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                }
                for (int k = 0; k < SlideEndName.size(); k++) {
                    if (slideNumber == 0 || slides[SlideEndName[k]].inSlide == false) 
                    	throw runtime_error("Unknown Slide End in [" + to_string(l) + ", " + to_string(r) + "]");
                    int ScratchType = 0; bool shouldUnscratch = true;
                    if (isDamage) { // 如果没有尾
                        for (auto &x : noteList[l][r][t]) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '1' && body[0] == '4') {
                                x = {get<0>(x), magicNumber, get<2>(x), get<3>(x)};
                                break;
                            }
                        }
                    }
                    for (int i = 1; i <= 12; i++) {
                        if (i > l && i <= r) continue;
                        for (auto &x : (i <= l ? noteList[i][r][t] : noteList[l][i][t])) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '5') {
                                slides[SlideEndName[k]].ScratchSlide = true, ScratchType = (i == l ? (
                                    (body[0] == '3' ? -(r - l + 1) : (body[0] == '4' ? (r - l + 1) : 0))
                                ) : (i < l ? i - r - 1 : i - l + 1));
                                x = {get<0>(x), magicNumber, get<2>(x), get<3>(x)};
                                shouldUnscratch = false;
                            }
                        }
                    }
                    if (shouldUnscratch && slides[SlideEndName[k]].ScratchSlide) {
                        slides[SlideEndName[k]].ScratchSlide = false;
                        if (!slides[SlideEndName[k]].isCausedByDamage) slides[SlideEndName[k]].addStart = true;
                    }
                    int noteType = (slides[SlideEndName[k]].CriticalSlide ? 
                        (slides[SlideEndName[k]].ScratchSlide ? ScratchCriticalHoldStart : CriticalHoldStart) :
                        (slides[SlideEndName[k]].ScratchSlide ? ScratchHoldStart : HoldStart));
                    int holdType = (slides[SlideEndName[k]].CriticalSlide ? 
                        (slides[SlideEndName[k]].ScratchSlide ? ScratchCriticalHold : CriticalHold) :
                        (slides[SlideEndName[k]].ScratchSlide ? ScratchHold : Hold));
                    if (isDamage) holdType += 1000;
                    if (slides[SlideEndName[k]].addStart) txt << slides[SlideEndName[k]].startTime << "," << -1 << "," << noteType << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                    txt << slides[SlideEndName[k]].startTime << "," << t << "," << holdType << "," << l << "," << (r - l + 1) << "," 
                        << (ScratchType == 0 ? "0" : "JumpScratch") << "," << ScratchType << endl;
                    tickTime = ticks_per_beat / 3840.0 * 60 * 4 / bpm; // 最好不要在 Slide 中间切换 BPM
                    // cout << t - tickTime << endl;
                    for (double i = slides[SlideEndName[k]].startTime + tickTime; i <= t - 0.0001; i += tickTime) {
                        txt << i << "," << -1 << "," << HoldEighth << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                    }
                	// cout << "&" << slides[SlideEndName].inSlide << " " << SlideEndName << endl;
                    slides[SlideEndName[k]].inSlide = false; slideNumber--;
                	// cout << "&" << slides[SlideEndName].inSlide << " " << SlideEndName << endl;
                }
                if (isFlick && slideNumber) {
                    int dir = 0;
                    for (auto &x : noteList[l][r][t]) {
                        string head = get<0>(x), body = get<3>(x);
                        string prop = head.substr(3);
                        if (prop[0] == '5') {
                            x = {get<0>(x), magicNumber, get<2>(x), get<3>(x)};
                            if (body[0] == '3') dir = -(r - l + 1);
                            else if (body[0] == '4') dir = (r - l + 1);
                            else dir = 0;
                        }
                    }
                    txt << t << "," << -1 << "," << SoundPurple << "," 
                        << l << "," << (r - l + 1) << "," << 0 << "," << dir << endl;
                }
                for (int k = 0; k < SlideStartName.size(); k++) {
                	// cout << slides[SlideStartName].inSlide << " " << SlideStartName << endl;
                    if (slides[SlideStartName[k]].inSlide == true) throw runtime_error("Overlapped Slide in [" + to_string(l) + ", " + to_string(r) + "]");
                    slides[SlideStartName[k]] = SlideStructure();
                    slides[SlideStartName[k]].inSlide = true; 
                    slides[SlideStartName[k]].CriticalSlide = isCritical;
                    slides[SlideStartName[k]].addStart = !isDamage;
                    slides[SlideStartName[k]].isCausedByDamage = isDamage;
                    if (isCritical) { // 如果是 CriticalHold 或 CriticalScratchHold
                        for (auto &x : noteList[l][r][t]) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '1' && body[0] == '2') {
                                x = {get<0>(x), magicNumber, get<2>(x), get<3>(x)};
                                break;
                            }
                        }
                    }
                    if (isDamage) { // 如果没有头
                        for (auto &x : noteList[l][r][t]) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '1' && body[0] == '4') {
                                x = {get<0>(x), magicNumber, get<2>(x), get<3>(x)};
                                break;
                            }
                        }
                    }
                    for (int i = 1; i <= 12; i++) {
                        if (i > l && i < r) continue;
                        for (auto &x : (i <= l ? noteList[i][r][t] : noteList[l][i][t])) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '5') {
                                slides[SlideStartName[k]].ScratchSlide = true, 
                                slides[SlideStartName[k]].addStart = false;
                                break; 
                            }
                        }
                    } slides[SlideStartName[k]].startTime = t;
                    slideNumber++;
                }
            }
        }
    }

    // 处理余下 Note
    for (int l = 1; l <= 12; l++) {
        for (int r = l; r <= 12; r++) {
            for (auto x : noteList[l][r]) {
                double t = x.first; auto info = x.second;
                for (auto xx : info) {
                    if (get<1>(xx) == magicNumber) continue;
                    string head = get<0>(xx), body = get<3>(xx);
                    string prop = head.substr(3);
                    if (prop[0] == '1') {
                        if (body[0] == '1') txt << t << "," << -1 << "," << Normal << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                        if (body[0] == '2') txt << t << "," << -1 << "," << Critical << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                    }
                    if (prop[0] == '5') {
                        if (body[0] == '3') txt << t << "," << -1 << "," << Flick << "," << l << "," << (r - l + 1) << "," << 0 << "," << -(r - l + 1) << endl;
                        else if (body[0] == '4') txt << t << "," << -1 << "," << Flick << "," << l << "," << (r - l + 1) << "," << 0 << "," << (r - l + 1) << endl;
                        else txt << t << "," << -1 << "," << Flick << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                    }
                }
            }
        }
    }

    // 结果排序
    string output = txt.str();
    auto tmp = explode("\n", output.c_str());
    sort(tmp.begin(), tmp.end(), [](string a, string b){
        auto tmpa = explode(",", a.c_str());
        auto tmpb = explode(",", b.c_str());
        return atof(tmpa[0].c_str()) < atof(tmpb[0].c_str());
    });
    txt.str("");
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i].size() == 0) continue;
        txt << tmp[i] << endl;
    }

    return txt.str();
}
