#include<bits/stdc++.h>
#include"sonolus.h"
using namespace std;

const string dist = "./dist";
#include"engine/engine.cpp"

vector<string> explode(const char* seperator, const char* source) {
	string src = source; vector<string> res;
	while (src.find(seperator) != string::npos) {
		int wh = src.find(seperator);
		res.push_back(src.substr(0, src.find(seperator)));
		src = src.substr(wh + string(seperator).size());
	} res.push_back(src);
	return res;
}

string readFile(string path) {
    ifstream fin(path);
    fin.seekg(0, ios::end);
    int len = fin.tellg();
    if (len == -1) {
        cout << "No such file or directory: \"" << path << "\"" << endl;
        exit(1);
    } fin.seekg(0, ios::beg);
    char* buffer = new char[len];
    fin.read(buffer, len);
    fin.close(); return string(buffer, len);
}

#include"convert.h"

void helpText(int argc, char** argv) {
    cout << "Usage: " << endl;
    cout << endl;
    cout << "Create Engine Scripts: " << endl;
    #ifdef play
    cout << "    EngineConfig & EnginePlayData: " << argv[0] << endl;
    #elif tutorial
    cout << "    EngineConfig & EngineTutorialData: " << argv[0] << endl;
    #elif preview
    cout << "    EngineConfig & EnginePreviewData: " << argv[0] << endl;
    #elif watch
    cout << "    EngineConfig & EngineWatchData: " << argv[0] << endl;
    #endif
    cout << "Chart Convertor: " << endl;
    cout << "    Sirius TXT -> Sonolus LevelData: " << argv[0] << " txt2data <txt> <chart_info> <data>" << endl;
    cout << "    Ched SUS -> Sirius TXT: " << argv[0] << " sus2txt <sus> <txt>" << endl;
    cout << "    Ched SUS -> Sonolus LevelData: " << argv[0] << " sus2data <sus> <music_config> <data>" << endl;
    exit(1);
}

int main(int argc, char** argv) {
    // 谱面转换测试
    if (argc >= 2) {
        if (string(argv[1]) == "txt2data") {
            if (argc != 5) helpText(argc, argv);
            string info = readFile(argv[3]); string chart = readFile(argv[2]);
            double chartOffset = fromMusicInfo(info);
            string LevelData = fromSirius(chart, chartOffset);
            cout << "Compressing..." << endl;
            buffer data = compress_gzip(LevelData, 9);
            cout << "Compress Finished." << endl;
            ofstream fout(argv[4]);
            for (int i = 0; i < data.size(); i++) fout << data.v[i];
            fout.close();
            return 0;
        } else if (string(argv[1]) == "sus2txt") {
            if (argc != 4) helpText(argc, argv);
            string sus = readFile(argv[2]);
            string txt = fromSUS(sus);
            ofstream fout(argv[3]);
            fout << txt; fout.close();
            return 0;
        } else if (string(argv[1]) == "sus2data") {
            if (argc != 5) helpText(argc, argv);
            string info = readFile(argv[3]); string chart = readFile(argv[2]);
            double chartOffset = fromMusicInfo(info);
            string LevelData = fromSirius(fromSUS(chart), chartOffset);
            cout << "Compressing..." << endl;
            buffer data = compress_gzip(LevelData, 9);
            cout << "Compress Finished." << endl;
            ofstream fout(argv[4]);
            for (int i = 0; i < data.size(); i++) fout << data.v[i];
            fout.close();
            return 0;
        } else helpText(argc, argv);
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
#elif preview
    buffer data, configuration;
    build<
        // Replace with your archetypes here
        Initialization,
		Stage,
		SiriusNormalNote,
		SiriusCriticalNote,
		SiriusFlickNote,
		SiriusHoldStart,
		SiriusHoldEighth,
		SiriusCriticalHoldStart,
		SiriusScratchHoldStart,
		SiriusCriticalScratchHoldStart,
		SiriusHoldEnd,
		SiriusScratchHoldEnd,
		SiriusSound,
		SiriusSyncLine,
        SplitLine
    >(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EnginePreviewData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#elif watch
	buffer data, configuration;
	build<
		// Replace with your archetypes here
		Initialization,
		Stage,
		NormalNote,
		CriticalNote
	>(configuration, data);
    ofstream fout((dist + "/EngineConfiguration"));
    for (int i = 0; i < configuration.size(); i++) fout << configuration.v[i];
    fout.close(); fout.open((dist + "/EngineWatchData"));
    for (int i = 0; i < data.size(); i++) fout << data.v[i];
#endif
}
