const int magicNumber = 0x114514;

enum NoteType {
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
    CriticalHold = 101,
    ScratchHold = 110,
    ScratchCriticalHold = 111,
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

string fromSirius(string text, double chartOffset, double bgmOffset = 0) {
    // 谱面读取
    auto lines = explode("\n", text.c_str());
    vector<Note> notes;
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
                single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
                single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
                single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
                total++;
            } else {
                single["archetype"] = "Sirius Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
                single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
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
            case Hold: case CriticalHold: case ScratchHold: case ScratchCriticalHold: {
                lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case Sound: case ScratchSound: {
                single["archetype"] = "Sirius Sound";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
				single["data"][3]["name"] = "holdType"; single["data"][3]["value"] = lastType[x.leftLane][x.leftLane + x.laneLength - 1];
                total++;
            } break;
            case SoundPurple: {
                single["archetype"] = "Sirius Scratch Hold End";
                single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.startTime;
            	single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
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
                single["data"][1]["name"] = "lane"; single["data"][1]["value"] = x.leftLane;
                single["data"][2]["name"] = "laneLength"; single["data"][2]["value"] = x.laneLength;
				single["data"][3]["name"] = "holdType"; single["data"][3]["value"] = lastType[x.leftLane][x.leftLane + x.laneLength - 1];
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
            single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            total++;
        } else {
            single["archetype"] = "Sirius Scratch Hold End";
            single["data"][0]["name"] = "beat"; single["data"][0]["value"] = x.endTime;
            single["data"][1]["name"] = "stBeat"; single["data"][1]["value"] = lastTime[x.leftLane][x.leftLane + x.laneLength - 1];
            single["data"][2]["name"] = "lane"; single["data"][2]["value"] = x.leftLane;
            single["data"][3]["name"] = "laneLength"; single["data"][3]["value"] = x.laneLength;
            single["data"][4]["name"] = "scratchLength"; single["data"][4]["value"] = x.scratchLength;
            total++;
        } lastTime[x.leftLane][x.leftLane + x.laneLength - 1] = 0; res.append(single);
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
	data["formatVersion"] = 3;
	data["bgmOffset"] = bgmOffset;
	data["entities"] = res;
	return json_encode(data);
}

void addTime( double &current, double bpm, 
    tuple<string, int, int, string> a, 
    tuple<string, int, int, string> b) {
    int a1 = atoi(get<0>(a).substr(0, 3).c_str());
    int b1 = atoi(get<0>(b).substr(0, 3).c_str());
    int a2 = get<1>(a), b2 = get<1>(b);
    int a3 = get<2>(a), b3 = get<2>(b);
    double timesPerBeat = 60.0 * 4 / bpm;
    // cout << current << " " << (1.0 * b2 / b3 - 1.0 * a2 / a3) * timesPerBeat << endl; exit(1);
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

string fromSUS(string text) {
    auto lines = explode("\n", text.c_str());
    double ticks_per_beat = 480;
    vector<tuple<string, int, int, string> > mainData;
    map<string, int> bpmList;
    int currentBpm = 120; double currentTime = 0;
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
                while (tmp3[1].size() < 5) tmp3[1] += '0'; // upd: 解决部分 Ched 保存 HiSpeed 不会保留五位小数的问题 2024/01/13
                exp[i] = tmp2[0] + "'" + tmp2[1] + ":" + tmp3[0] + "." + tmp3[1];
            }
            sort(exp.begin(), exp.end(), [](string a, string b){
            	return a.size() == b.size() ? a < b : a.size() < b.size();
            }); // upd: 字符串类型的数字不能直接排序，警钟敲烂😓 2023/01/14
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
                    if (currentSplitLine * 10 != lines || currentSplitLineType != types)
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
        }
        for (int j = 0; j < body.size(); j += 2) 
            mainData.push_back({head, j / 2, max(1, int(body.size()) / 2), body.substr(j, 2)});
    }

    // 音符排序
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
        if (i == 0) addTime(currentTime, currentBpm, {"00000", 0, 1, "00"}, mainData[i]);
        else addTime(currentTime, currentBpm, mainData[i - 1], mainData[i]);
        string head = get<0>(mainData[i]), body = get<3>(mainData[i]);
        int beat = atoi(head.substr(0, 3).c_str());
        string prop = head.substr(3);
        if (prop == "08") { // BPM Change
            if (get<3>(mainData[i]) == "00") continue;
            int bpm = bpmList[get<3>(mainData[i])];
            currentBpm = bpm;
        } else if (prop == "SL") { // Split Line
            auto tmp = explode(".", body.c_str());
            int line = atoi(tmp[0].c_str()), type = atoi(tmp[1].c_str());
            if (currentSplitLine == 0)
                currentSplitLine = line, currentSplitLineType = type, currentSplitLineTime = currentTime;
            else {
                txt << currentSplitLineTime << "," << currentTime << "," << 0 << "," << -1 << "," << 0 << ","
                    << 10 + currentSplitLine << "," << currentSplitLineType << endl; // 调整 Split Line 的时间
                currentSplitLine = 0; currentSplitLineType = 0; currentSplitLineTime = 0;
            }
        } else if (prop[0] == '1') { // Tap
            if (body == "00") continue;
            if (body[0] != '1' && body[0] != '2' && body[0] != '3') 
                throw runtime_error("Invalid Tap Type " + head + ": " + body);
            int l = getLine(prop[1]), r = getLine(prop[1], body[1], -1);
            if (body[0] == '1' || body[0] == '2') noteList[l][r][currentTime].push_back(mainData[i]);
            else ; // Note Type = 3, 不知道干嘛的
        } else if (prop[0] == '5') { // Flick
            if (body == "00") continue;
            if (body[0] != '1' && body[0] != '3' && body[0] != '4') 
                throw runtime_error("Invalid Flick Type " + head + ": " + body);
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
    double tickTime = ticks_per_beat / 1920.0 * 60 * 4 / currentBpm;
    for (int l = 1; l <= 12; l++) {
        for (int r = l; r <= 12; r++) { // 枚举按键位置
            bool inSlide = false, CriticalSlide = false, ScratchSlide = false, addStart = true;
            double startTime = 0;
            for (auto v : noteList[l][r]) {
                double t = v.first; auto info = v.second;
                bool isCritical = false, isFlick = false, 
                     isSlideStart = false, isSlideEnd = false, isSlideSound = false;
                int bpm = 120;
                for (auto x : info) {
                    string head = get<0>(x), body = get<3>(x);
                    string prop = head.substr(3);
                    if (prop[0] == '1') isCritical |= (body[0] == '2');
                    if (prop[0] == '5') isFlick |= 1;
                    if (prop[0] == '3') {
                        isSlideStart |= (body[0] == '1');
                        isSlideEnd |= (body[0] == '2');
                        isSlideSound |= (body[0] == '3');
                        bpm = get<2>(x);
                    }
                }
                // if (l == 1 && r == 3 && t > 15.3 && t < 15.4) cout << t << " " << isCritical << endl;

                // Note 讨论
                if (!isSlideStart && !isSlideEnd && !isSlideSound && !isFlick) continue;
                if (isSlideSound) {
                    if (!inSlide) throw runtime_error("Unknown Slide Sound in [" + to_string(l) + ", " + to_string(r) + "]");
                    txt << t << "," << -1 << "," << Sound << "," 
                        << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                }
                if (isSlideEnd) {
                    if (!inSlide) throw runtime_error("Unknown Slide End in [" + to_string(l) + ", " + to_string(r) + "]");
                    int ScratchType = 0;
                    for (int i = 1; i <= 12; i++) {
                        if (i > l && i <= r) continue;
                        for (auto &x : (i <= l ? noteList[i][r][t] : noteList[l][i][t])) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '5') {
                                ScratchSlide = true, ScratchType = (i == l ? 0 : (i < l ? i - r - 1 : i - l + 1));
                                x = {get<0>(x), magicNumber, get<2>(x), get<3>(x)};
                            }
                        }
                    }
                	// if (l == 1 && r == 3 && t > 18 && t < 19) cout << t << " " << CriticalSlide << endl;
                    int noteType = (CriticalSlide ? 
                        (ScratchSlide ? ScratchCriticalHoldStart : CriticalHoldStart) :
                        (ScratchSlide ? ScratchHoldStart : HoldStart));
                    int holdType = (CriticalSlide ? 
                        (ScratchSlide ? ScratchCriticalHold : CriticalHold) :
                        (ScratchSlide ? ScratchHold : Hold));
                    if (addStart) txt << startTime << "," << -1 << "," << noteType << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                    txt << startTime << "," << t << "," << holdType << "," << l << "," << (r - l + 1) << "," 
                        << (ScratchType == 0 ? "0" : "JumpScratch") << "," << ScratchType << endl;
                    tickTime = ticks_per_beat / 3840.0 * 60 * 4 / bpm; // 最好不要在 Slide 中间切换 BPM
                    // cout << t - tickTime << endl;
                    for (double i = startTime + tickTime; i <= t - 0.0001; i += tickTime) {
                        txt << i << "," << -1 << "," << HoldEighth << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                    } 
                    inSlide = false, CriticalSlide = false, ScratchSlide = false, addStart = true;
                }
                if (isFlick && inSlide) {
                    txt << t << "," << -1 << "," << SoundPurple << "," 
                        << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                    for (auto &x : noteList[l][r][t]) {
                        string head = get<0>(x), body = get<3>(x);
                        string prop = head.substr(3);
                        if (prop[0] == '5') {
                            x = {get<0>(x), magicNumber, get<2>(x), get<3>(x)};
                        }
                    }
                }
                if (isSlideStart) {
                    if (inSlide) throw runtime_error("Overlapped Slide in [" + to_string(l) + ", " + to_string(r) + "]");
                    inSlide = true; CriticalSlide = isCritical;
                    if (isCritical) {
                        for (auto &x : noteList[l][r][t]) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '1' && body[0] == '2') {
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
                                ScratchSlide = true, addStart = false;
                                break; 
                            }
                        }
                    } startTime = t;
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
                        txt << t << "," << -1 << "," << Flick << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
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
