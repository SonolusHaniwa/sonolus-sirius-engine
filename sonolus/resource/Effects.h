#ifndef Effects_H
#define Effects_H

#ifndef DISABLE_PACK_EFFECT
#include"../utils/zip.h"

class EffectData {
	public:
    vector<pair<string, string> > clips;

	Json::Value toJsonObject() {
		Json::Value res;
		res["clips"].resize(0);
		for (int i = 0; i < clips.size(); i++) {
            Json::Value single;
            single["name"] = clips[i].first;
            single["filename"] = clips[i].second;
            res["clips"].append(single);
        } return res;
	}
};

void PackEffect() {
    string audioDir = dist + "/EffectAudio";
    string dataDir = dist + "/EffectData";
	cout << "Packing Effect Audios..." << endl;
    remove(audioDir.c_str());

    EffectData data;
    for (int i = 0; i < effect_clips.size(); i++) {
        string name = effect_clips[i].second;
        string filename = to_string(i);
        data.clips.push_back(make_pair(effect_clips[i].first, filename));
        ifstream fin; fin.open(name);
        fin.seekg(0, ios::end); int len = fin.tellg();
        SonolusAssert(
            len != -1,
            "Unknown Effect Clip \"%s\"",
            name.c_str()
        );
        char* ch = new char[len]; fin.seekg(0, ios::beg);
        fin.read(ch, len); fin.close(); string res = string(ch, len); delete[] ch;
        writeFileIntoZip(audioDir, filename, res);
    }

	cout << "Writing Effect Data..." << endl;
	string json = json_encode(data.toJsonObject());
	string dataBuffer = compress_gzip(json);
	ofstream fout; fout.open(dataDir);
    fout.write(dataBuffer.c_str(), dataBuffer.size());
}
#endif

class EffectClip {
    public:

    int id;
    string clipName;

    operator int() {
        return id;
    }

    operator FuncNode() {
        return id;
    }

    operator Variable() {
        return id;
    }
};

EffectClip defineEffectClip(string name, string path = "") {
    if (path == "") path = "./effects/" + name + ".mp3";
    effect_clips.push_back({ name, path });
    return { int(effect_clips.size()) - 1, name };
}

class EffectClipName {
    public:

    string Miss = "#MISS";
    string Perfect = "#PERFECT";
    string Great = "#GREAT";
    string Good = "#GOOD";

    string Hold = "#HOLD";

    string MissAlternative = "#MISS_ALTERNATIVE";
    string PerfectAlternative = "#PERFECT_ALTERNATIVE";
    string GreatAlternative = "#GREAT_ALTERNATIVE";
    string GoodAlternative = "#GOOD_ALTERNATIVE";

    string HoldAlternative = "#HOLD_ALTERNATIVE";

    string Stage = "#STAGE";
}EffectClipName;

#endif