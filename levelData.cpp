namespace wds {
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

    class InitializationEntity: public LevelEntity { defineArchetypeName("Sirius Initialization"); };
    class InputManagerEntity: public LevelEntity { defineArchetypeName("Sirius Input Manager"); };
    class StageEntity: public LevelEntity { defineArchetypeName("Sirius Stage") };
    class FlatNoteEntity: public LevelEntity {
        public:
        defineLevelDataValue(beat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
    };
    class NormalNoteEntity: public FlatNoteEntity { defineArchetypeName("Sirius Normal Note"); };
    class CriticalNoteEntity: public FlatNoteEntity { defineArchetypeName("Sirius Critical Note"); };
    class HoldStartEntity: public FlatNoteEntity { defineArchetypeName("Sirius Hold Start"); };
    class CriticalHoldStartEntity: public FlatNoteEntity { defineArchetypeName("Sirius Critical Hold Start"); };
    class ScratchHoldStartEntity: public FlatNoteEntity { defineArchetypeName("Sirius Scratch Hold Start"); };
    class CriticalScratchHoldStartEntity: public FlatNoteEntity { defineArchetypeName("Sirius Critical Scratch Hold Start"); };
    class FlickNoteEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Flick Note");
        defineLevelDataValue(beat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
        defineLevelDataValue(scratchLength);
    };
    class SoundEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Sound");
        defineLevelDataValue(beat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
        defineLevelDataValue(holdType);
    };
    class HoldEighthEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Hold Eighth");
        defineLevelDataValue(beat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
        defineLevelDataValue(holdType);
    };
    class HoldEndEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Hold End");
        defineLevelDataValue(beat);
        defineLevelDataValue(stBeat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
    };
    class NontailHoldEndEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Nontail Hold End");
        defineLevelDataValue(beat);
        defineLevelDataValue(stBeat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
    };
    class ScratchHoldEndEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Scratch Hold End");
        defineLevelDataValue(beat);
        defineLevelDataValue(stBeat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
        defineLevelDataValue(scratchLength);
    };
    class NontailScratchHoldEndEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Nontail Scratch Hold End");
        defineLevelDataValue(beat);
        defineLevelDataValue(stBeat);
        defineLevelDataValue(lane);
        defineLevelDataValue(laneLength);
        defineLevelDataValue(scratchLength);
    };
    class SyncLineEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Sync Line");
        defineLevelDataValue(beat);
        defineLevelDataValue(left);
        defineLevelDataValue(right);
    };
    class SplitLineEntity: public LevelEntity {
        public:
        defineArchetypeName("Sirius Split Line");
        defineLevelDataValue(beat);
        defineLevelDataValue(endBeat);
        defineLevelDataValue(split);
        defineLevelDataValue(color);
    };
    class HiSpeedEntity: public LevelEntity {
        public:
        defineArchetypeName(EngineArchetypeName.TimeScaleChange);
        defineLevelDataValueDetailed(beat, EngineArchetypeDataName.Beat);
        defineLevelDataValueDetailed(value, EngineArchetypeDataName.TimeScale);
    };
}

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

vector<string> explode(string seperator, string source) {
	string src = source; vector<string> res;
	while (src.find(seperator) != string::npos) {
		int wh = src.find(seperator);
		res.push_back(src.substr(0, src.find(seperator)));
		src = src.substr(wh + string(seperator).size());
	} res.push_back(src);
	return res;
}

double fromMusicInfo(string text) {
    auto res = explode("\n", text.c_str());
    SonolusAssert(res.size() >= 2, "Invalid Music Info.");
    res = explode(",", res[1].c_str());
    SonolusAssert(res.size() >= 3, "Invalid Music Info.");
    return atof(res[2].c_str());
}

string txt2data(string text, double chartOffset, double bgmOffset = 0) {
    using namespace wds;
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
        callStacks.push_back({});
        if (a.startTime == b.startTime) return a.type < b.type;
        return a.startTime < b.startTime;
    });
    cout << "[INFO] Total Note Number: " << notes.size() << endl;

    // 开始转换
    LevelRawData levelData;
	set<Note> holdEnd;
    map<double, int> SyncLineLeft, SyncLineRight;
    auto addSyncLine = [&](double beat, int leftLane, int laneLength) {
        if (SyncLineLeft.find(beat) == SyncLineLeft.end()) SyncLineLeft[beat] = leftLane;
        else SyncLineLeft[beat] = min(SyncLineLeft[beat], leftLane);
        if (SyncLineRight.find(beat) == SyncLineRight.end()) SyncLineRight[beat] = leftLane + laneLength - 1;
        else SyncLineRight[beat] = max(SyncLineRight[beat], leftLane + laneLength - 1);
    };
    levelData.append(InitializationEntity());
    levelData.append(InputManagerEntity());
    levelData.append(StageEntity());
    HiSpeedEntity hiSpeed;
    hiSpeed.beat = 0;
    hiSpeed.value = 60;
    levelData.append(hiSpeed);
    double lastEighthTime[13][13]; int lastType[13][13], total = 0;
    for (int i = 0; i < 13; i++) for (int j = 0; j < 13; j++) lastEighthTime[i][j] = 0, lastType[i][j] = 0;
    for (int i = 0; i < notes.size(); i++) {
        // 提前处理 Sirius HoldEnd;
        while (holdEnd.size() && (*holdEnd.begin()).endTime <= notes[i].startTime) {
            Note x = *holdEnd.begin(); holdEnd.erase(holdEnd.begin());
            if (x.type == Hold || x.type == CriticalHold) {
                HoldEndEntity entity;
                entity.beat = x.endTime;
                entity.stBeat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                total++;
            } else if (x.type == NontailHold || x.type == NontailCriticalHold) {
                NontailHoldEndEntity entity;
                entity.beat = x.endTime;
                entity.stBeat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                total++;
            } else if (x.type == ScratchHold || x.type == ScratchCriticalHold) {
                ScratchHoldEndEntity entity;
                entity.beat = x.endTime;
                entity.stBeat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                entity.scratchLength = x.scratchLength;
                levelData.append(entity);
                total++;
            } else {
                NontailScratchHoldEndEntity entity;
                entity.beat = x.endTime;
                entity.stBeat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                entity.scratchLength = x.scratchLength;
                levelData.append(entity);
                total++;
            }
            if (x.type >= NontailHold) continue;
			addSyncLine(x.endTime, x.leftLane, x.laneLength);
        }
        // 处理当前 Note
        Note x = notes[i];
        switch(x.type) {
            case Normal: {
                NormalNoteEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case Critical: {
                CriticalNoteEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case Flick: {
                FlickNoteEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                entity.scratchLength = x.scratchLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case wds::HoldStart: {
                HoldStartEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break; 
            case BlueTap: { // 和上面的相同
                HoldStartEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break; 
            case wds::CriticalHoldStart: {
                CriticalHoldStartEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case wds::ScratchHoldStart: {
                ScratchHoldStartEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case ScratchCriticalHoldStart: {
                CriticalScratchHoldStartEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case Hold:  {
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case CriticalHold: { // 和上面的相同
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case ScratchHold: { // 和上面的相同
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case ScratchCriticalHold: { // 和上面的相同
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case NontailHold: { // 和上面的相同
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case NontailCriticalHold: { // 和上面的相同
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case NontailScratchHold: { // 和上面的相同
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case NontailScratchCriticalHold: { // 和上面的相同
				lastType[x.leftLane][x.leftLane + x.laneLength - 1] = x.type;
                holdEnd.insert(x);
            } break;
            case wds::Sound:  {
                lastEighthTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                SoundEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
				entity.holdType = lastType[x.leftLane][x.leftLane + x.laneLength - 1];
                levelData.append(entity);
                total++;
            } break;
            case ScratchSound: { // 和上面的相同
                lastEighthTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                SoundEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
				entity.holdType = lastType[x.leftLane][x.leftLane + x.laneLength - 1];
                levelData.append(entity);
                total++;
            } break;
            case SoundPurple: {
                lastEighthTime[x.leftLane][x.leftLane + x.laneLength - 1] = x.startTime;
                ScratchHoldEndEntity entity;
                entity.beat = x.startTime;
            	entity.stBeat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                entity.scratchLength = x.scratchLength;
                levelData.append(entity);
                addSyncLine(x.startTime, x.leftLane, x.laneLength);
                total++;
            } break;
            case wds::HoldEighth: {
                if (lastEighthTime[x.leftLane][x.leftLane + x.laneLength - 1] == x.startTime) break;
                HoldEighthEntity entity;
                entity.beat = x.startTime;
                entity.lane = x.leftLane;
                entity.laneLength = x.laneLength;
                // 历史遗留代码了，这个属性现在应该不需要了 2024.5.27
				entity.holdType = 0;
                levelData.append(entity);
                total++;
            } break;
            case None: {
                SplitLineEntity entity;
                entity.beat = x.startTime;
                entity.endBeat = x.endTime;
                entity.split = x.gimmickType - 10;
                entity.color = x.scratchLength;
                levelData.append(entity);
            } break;
            case wds::HiSpeed: {
                HiSpeedEntity entity;
                entity.beat = x.startTime;
                entity.value = x.endTime - chartOffset;
                levelData.append(entity);
            }
        }
        if ((10 * (i + 1) / notes.size()) != (10 * i / notes.size())) 
            cout << "[INFO] " << 100 * (i + 1) / notes.size() << "% Notes Solved." << endl;
    }

	// 处理完 HoldEnd
	while (holdEnd.size()) {
        Note x = *holdEnd.begin(); holdEnd.erase(holdEnd.begin()); Json::Value single;
        if (x.type == Hold || x.type == CriticalHold) {
            HoldEndEntity entity;
            entity.beat = x.endTime;
            entity.stBeat = x.startTime;
            entity.lane = x.leftLane;
            entity.laneLength = x.laneLength;
            levelData.append(entity);
            total++;
        } else if (x.type == NontailHold || x.type == NontailCriticalHold) {
            NontailHoldEndEntity entity;
            entity.beat = x.endTime;
            entity.stBeat = x.startTime;
            entity.lane = x.leftLane;
            entity.laneLength = x.laneLength;
            levelData.append(entity);
            total++;
        } else if (x.type == ScratchHold || x.type == ScratchCriticalHold) {
            ScratchHoldEndEntity entity;
            entity.beat = x.endTime;
            entity.stBeat = x.startTime;
            entity.lane = x.leftLane;
            entity.laneLength = x.laneLength;
            entity.scratchLength = x.scratchLength;
            levelData.append(entity);
            total++;
        } else {
            NontailScratchHoldEndEntity entity;
            entity.beat = x.endTime;
            entity.stBeat = x.startTime;
            entity.lane = x.leftLane;
            entity.laneLength = x.laneLength;
            entity.scratchLength = x.scratchLength;
            levelData.append(entity);
            total++;
        }
        if (x.type >= NontailHold) continue;
        addSyncLine(x.endTime, x.leftLane, x.laneLength);
    }
    cout << "[INFO] Total Note Number: " << total << endl;
    cout << "[INFO] Solving Sync Line..." << endl;

    // 处理同步线
    for (auto v = SyncLineLeft.begin(); v != SyncLineLeft.end(); v++) {
        double beat = (*v).first; int left = (*v).second;
        SyncLineEntity entity;
        entity.beat = beat;
        entity.left = left;
        entity.right = SyncLineRight[beat];
        levelData.append(entity);
    }
    cout << "[INFO] Sync Line Solved." << endl;

    levelData.bgmOffset = bgmOffset;
	return json_encode(levelData.toJsonObject());
}

const int magicNumber = 0x114514;

void addTime( 
    double &current, double bpm, double beat,
    tuple<string, int, int, string> a, 
    tuple<string, int, int, string> b
) {
    int a1 = atoi(get<0>(a).substr(0, 3).c_str());
    int b1 = atoi(get<0>(b).substr(0, 3).c_str());
    int a2 = get<1>(a), b2 = get<1>(b);
    int a3 = get<2>(a), b3 = get<2>(b);
    double timesPerBeat = 60.0 * beat / bpm;
    if (a1 == b1) current += (1.0 * b2 / b3 - 1.0 * a2 / a3) * timesPerBeat;
    else current += ((b1 - a1 - 1) + 1.0 - 1.0 * a2 / a3 + 1.0 * b2 / b3) * timesPerBeat; 
}

int extract2(char x) {
    return isdigit(x) ? x - '0' : x - 'a' + 10;
}

int getLine(char x, char offset = '0', int offset2 = 0) {
    int id = extract2(x) - 1;
    int off = extract2(offset);
    id += off + offset2;
    SonolusAssert(
        id > 0 && id <= 12,
        "Invalid Line %d",
        id
    );
    return id;
}

string sus2txt(string text) {
    using namespace wds;
    auto lines = explode("\n", text.c_str());
    double ticks_per_beat = 480;
    vector<tuple<string, int, double, string> > mainData;
    map<string, double> bpmList;
    double currentBpm = 120.0; double currentBeat = 2, currentTime = 0;
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
            double bpm = atof(body.c_str());
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
                    SonolusAssert(
                        tmp1.size() == 2,
                        "Invalid Split Line Parameter: \"%s\"",
                        exp[i].c_str()
                    );
	                string beat = tmp1[0], type = tmp1[1];
	                auto tmp2 = explode("'", beat.c_str());
                    SonolusAssert(
                        tmp2.size() == 2,
                        "Invalid Split Line Parameter: \"%s\"",
                        exp[i].c_str()
                    );
	                auto tmp3 = explode(".", type.c_str());
                    SonolusAssert(
                        tmp3.size() == 2,
                        "Invalid Split Line Parameter: \"%s\"",
                        exp[i].c_str()
                    );
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
                    callStacks.push_back({});
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
                        SonolusAssert(
                            currentSplitLine * -1 == lines && currentSplitLineType == types,
                            "Overlapped Split Line: \"%s\"",
                            exp[i].c_str()
                        );
	                    currentSplitLine = 0; currentSplitLineType = 0;
	                } else {
                        SonolusAssert(
                            1 <= lines && lines <= 6,
                            "Invalid Split Line Parameter: \"%s\"",
                            exp[i].c_str()
                        );
	                    currentSplitLine = lines; currentSplitLineType = types;
	                }
	                switch(tmp2[0].size()) {
	                    case 0: tmp2[0] = "000"; break;
	                    case 1: tmp2[0] = "00" + tmp2[0]; break;
	                    case 2: tmp2[0] = "0" + tmp2[0]; break;
	                }
	                mainData.push_back({ tmp2[0] + "SL", atoi(tmp2[1].c_str()), 1920.0, type });
	            }
	            continue;
	        } else if (head.substr(3, 2) == "00") {
	            body = body.substr(1, body.size() - 2);
	            if (body == "") continue;
	            auto exp = explode(", ", body.c_str());
	            for (auto i = 0; i < exp.size(); i++) {
	                string tmp = exp[i];
	                auto tmp1 = explode(":", tmp.c_str());
                    SonolusAssert(
                        tmp1.size() == 2,
                        "Invalid HiSpeed Parameter: \"%s\"",
                        exp[i].c_str()
                    );
	                string beat = tmp1[0], type = tmp1[1];
	                auto tmp2 = explode("'", beat.c_str());
                    SonolusAssert(
                        tmp2.size() == 2,
                        "Invalid HiSpeed Parameter: \"%s\"",
                        exp[i].c_str()
                    );
	                switch(tmp2[0].size()) {
	                    case 0: tmp2[0] = "000"; break;
	                    case 1: tmp2[0] = "00" + tmp2[0]; break;
	                    case 2: tmp2[0] = "0" + tmp2[0]; break;
	                }
	                mainData.push_back({ tmp2[0] + "HS", atoi(tmp2[1].c_str()), 1920.0, type });
	            }
	            continue;
	        }
        }
        if (head.substr(3, 2) == "02") { // 处理变拍事件
            mainData.push_back({ head, 0, 1.0, body });
            continue;
        }
        for (int j = 0; j < body.size(); j += 2) if (body.substr(j, 2) != "00")
            mainData.push_back({ head, j / 2, max(1, int(body.size()) / 2) * 1.0, body.substr(j, 2) });
    }

    // 音符排序
    // cout << mainData.size() << endl;
    sort(mainData.begin(), mainData.end(), [](
        tuple<string, int, double, string> a, 
        tuple<string, int, double, string> b
    ){
        callStacks.push_back({});
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
    stringstream txt; map<double, vector<tuple<string, int, double, string> > > noteList[13][13];
    for (int i = 0; i < mainData.size(); i++) {
        if (i == 0) addTime(currentTime, currentBpm, currentBeat, { "00000", 0, 1.0, "00" }, mainData[i]);
        else addTime(currentTime, currentBpm, currentBeat, mainData[i - 1], mainData[i]);
        string head = get<0>(mainData[i]), body = get<3>(mainData[i]);
        int beat = atoi(head.substr(0, 3).c_str());
        string prop = head.substr(3);
        if (prop == "08") { // BPM Change
            if (get<3>(mainData[i]) == "00") continue;
            double bpm = bpmList[get<3>(mainData[i])];
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
        	txt << currentTime << "," << atof(body.c_str()) << "," << NoteType::HiSpeed << "," << -1 << "," << 0 << "," << 0 << "," << 0 << endl;
        } else if (prop[0] == '1') { // Tap
            if (body == "00") continue;
            if (body[0] != '1' && body[0] != '2' && body[0] != '3' && body[0] != '4') 
            SonolusAssert(
                string("1234").find(body[0]) != string::npos,
                "Invalid Tap Type \"%s: %s\"",
                head.c_str(),
                body.c_str()
            );
            int l = getLine(prop[1]), r = getLine(prop[1], body[1], -1);
            if (body[0] == '1' || body[0] == '2' || body[0] == '4') noteList[l][r][currentTime].push_back(mainData[i]); // upd: 新增 Damage 功能
            else ; // Note Type = 3, 不知道干嘛的
        } else if (prop[0] == '5') { // Flick
            if (body == "00") continue;
            SonolusAssert(
                string("134").find(body[0]) != string::npos,
                "Invalid Flick Type \"%s: %s\"",
                head.c_str(),
                body.c_str()
            );
            int l = getLine(prop[1]), r = getLine(prop[1], body[1], -1);
            noteList[l][r][currentTime].push_back(mainData[i]);
        } else if (prop[0] == '3') { // Slide(Hold)
            if (body == "00") continue;
            SonolusAssert(
                string("123").find(body[0]) != string::npos,
                "Invalid Slide Type \"%s: %s\"",
                head.c_str(),
                body.c_str()
            );
            int l = getLine(prop[1]), r = getLine(prop[1], body[1], -1);
            noteList[l][r][currentTime].push_back({ get<0>(mainData[i]), get<1>(mainData[i]), currentBpm, get<3>(mainData[i]) });
        }
    }

    // 开始解析
    // 优先解析 Slide
#define DISABLE_INTERPRETER
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
#undef DISABLE_INTERPRETER
                    SonolusAssert(
                        slideNumber,
                        "Unknown Slide Sound in [%d, %d]",
                        l, r
                    );
#define DISABLE_INTERPRETER
                    txt << t << "," << -1 << "," << NoteType::Sound << "," 
                        << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
                }
                for (int k = 0; k < SlideEndName.size(); k++) {
#undef DISABLE_INTERPRETER
                    SonolusAssert(
                        slides[SlideEndName[k]].inSlide && slideNumber,
                        "Unknown Slide End in [%d, %d]",
                        l, r
                    );
#define DISABLE_INTERPRETER
                    int ScratchType = 0; bool shouldUnscratch = true;
                    if (isDamage) { // 如果没有尾
                        for (auto &x : noteList[l][r][t]) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '1' && body[0] == '4') {
                                x = { get<0>(x), magicNumber, get<2>(x), get<3>(x) };
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
                                x = { get<0>(x), magicNumber, get<2>(x), get<3>(x) };
                                shouldUnscratch = false;
                            }
                        }
                    }
                    if (shouldUnscratch && slides[SlideEndName[k]].ScratchSlide) {
                        slides[SlideEndName[k]].ScratchSlide = false;
                        if (!slides[SlideEndName[k]].isCausedByDamage) slides[SlideEndName[k]].addStart = true;
                    }
                    int noteType = (slides[SlideEndName[k]].CriticalSlide ? 
                        (slides[SlideEndName[k]].ScratchSlide ? ScratchCriticalHoldStart : NoteType::CriticalHoldStart) :
                        (slides[SlideEndName[k]].ScratchSlide ? NoteType::ScratchHoldStart : NoteType::HoldStart));
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
                        txt << i << "," << -1 << "," << NoteType::HoldEighth << "," << l << "," << (r - l + 1) << "," << 0 << "," << 0 << endl;
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
                            x = { get<0>(x), magicNumber, get<2>(x), get<3>(x) };
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
#undef DISABLE_INTERPRETER
                    SonolusAssert(
                        !slides[SlideStartName[k]].inSlide,
                        "Overlapped Slide in [%d, %d]",
                        l, r
                    );
#define DISABLE_INTERPRETER
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
                                x = { get<0>(x), magicNumber, get<2>(x), get<3>(x) };
                                break;
                            }
                        }
                    }
                    if (isDamage) { // 如果没有头
                        for (auto &x : noteList[l][r][t]) {
                            string head = get<0>(x), body = get<3>(x);
                            string prop = head.substr(3);
                            if (prop[0] == '1' && body[0] == '4') {
                                x = { get<0>(x), magicNumber, get<2>(x), get<3>(x) };
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
#undef DISABLE_INTERPRETER

    // 结果排序
    string output = txt.str();
    auto tmp = explode("\n", output.c_str());
    sort(tmp.begin(), tmp.end(), [](string a, string b){
        callStacks.push_back({});
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
