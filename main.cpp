#include<bits/stdc++.h>
#include"sonolus/sonolus.h"
#include"engine/engine.cpp"
#include"levelData.cpp"

string readFile(string path) {
    ifstream fin; fin.open(path);
    fin.seekg(0, ios::end);
    int len = fin.tellg();
    SonolusAssert(
        len >= 0,
        "No such file or directory: \"%s\"!",
        path.c_str()
    );
    fin.seekg(0, ios::beg);
    char* buffer = new char[len];
    fin.read(buffer, len);
    fin.close(); 
    return string(buffer, len);
}

void helpText(string path) {
    cout << "Usage: " << endl;
    cout << endl;
    cout << "Create Engine Scripts: " << endl;
    #ifdef play
    cout << "    EngineConfig & EnginePlayData: " << path << endl;
    #endif
    #ifdef tutorial
    cout << "    EngineConfig & EngineTutorialData: " << path << endl;
    #endif
    #ifdef preview
    cout << "    EngineConfig & EnginePreviewData: " << path << endl;
    #endif
    #ifdef watch
    cout << "    EngineConfig & EngineWatchData: " << path << endl;
    #endif
    cout << "Chart Convertor: " << endl;
    cout << "    Sirius TXT -> Sonolus LevelData: " << path << " txt2data <txt> [<chart_info>] <data>" << endl;
    cout << "    Ched SUS -> Sirius TXT: " << path << " sus2txt <sus> <txt>" << endl;
    cout << "    Ched SUS -> Sonolus LevelData: " << path << " sus2data <sus> [<music_config>] <data>" << endl;
    exit(1);
}

using namespace std;
int main(int argc, char** argv) {
    if (argc >= 2) {
        if (string(argv[1]) == "txt2data") {
            if (argc < 4) helpText(argv[0]);
            double chartOffset = argc >= 5 ? fromMusicInfo(readFile(argv[3])) : 0;
            string LevelData = txt2data(readFile(argv[2]), chartOffset);
            cout << "Compressing..." << endl;
            string data = compress_gzip(LevelData);
            cout << "Compress Finished." << endl;
            ofstream fout; fout.open(argc >= 5 ? argv[4] : argv[3]);
            fout.write(data.c_str(), data.size());
            return 0;
        } else if (string(argv[1]) == "sus2txt") {
            if (argc < 4) helpText(argv[0]);
            string txt = sus2txt(readFile(argv[2]));
            ofstream fout; fout.open(argv[3]);
            fout.write(txt.c_str(), txt.size());
            return 0;
        } else if (string(argv[1]) == "sus2data") {
            if (argc < 4) helpText(argv[0]);
            double chartOffset = argc >= 5 ? fromMusicInfo(readFile(argv[3])) : 0;
            string LevelData = txt2data(sus2txt(readFile(argv[2])), chartOffset);
            cout << "Compressing..." << endl;
            string data = compress_gzip(LevelData);
            cout << "Compress Finished." << endl;
            ofstream fout; fout.open(argc >= 5 ? argv[4] : argv[3]);
            fout.write(data.c_str(), data.size());
            return 0;
        } else helpText(argv[0]);
    }

    UI.SetScope(scope);
    UI.SetMenu(Visibility(1.0, 1.0));
    UI.SetJudgment(
        Visibility(1.0, 1.0), 
        Animation(
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.InSine),
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.InSine)
        ),
        EngineConfigurationJudgmentErrorStyle.None,
        EngineConfigurationJudgmentErrorPlacement.LeftRight,
        20.0
    );
    UI.SetCombo(
        Visibility(1.0, 1.0),
        Animation(
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.InSine),
            AnimationTween(0.6, 1.0, 0.1, EngineConfigurationAnimationTweenEase.Linear)
        )
    );
    UI.SetMetric(
        EngineConfigurationMetric.Arcade,
        Visibility(1.0, 1.0),
        EngineConfigurationMetric.Life,
        Visibility(1.0, 1.0)
    );
    UI.SetProgress(Visibility(1.0, 1.0));
    UI.SetTutorial(
        Visibility(1.0, 1.0),
        Visibility(1.0, 1.0)
    );

    BuildConfiguration();
    #ifdef play
    BuildData(
        Initialization, 
        InputManager,
        Stage,
        NormalNote,
        CriticalNote,
        HoldStart,
        CriticalHoldStart,
        ScratchHoldStart,
        CriticalScratchHoldStart,
        FlickNote,
        Sound,
        HoldEighth,
        HoldEnd,
        NontailHoldEnd,
        ScratchHoldEnd,
        NontailScratchHoldEnd,
        SyncLine,
        SplitLine,
        HiSpeed
    );
    #endif
    #ifdef tutorial
    BuildData();
    #endif
    #ifdef preview
    BuildData(
        Initialization,
        Stage,
        NormalNote,
        CriticalNote,
        HoldStart,
        CriticalHoldStart,
        ScratchHoldStart,
        CriticalScratchHoldStart,
        FlickNote,
        Sound,
        HoldEighth,
        HoldEnd,
        NontailHoldEnd,
        ScratchHoldEnd,
        NontailScratchHoldEnd,
        SyncLine,
        SplitLine,
        HiSpeed
    );
    #endif
    #ifdef watch
    BuildData(
        Initialization,
        Stage,
        UpdateJudgment,
        NormalNote,
        CriticalNote,
        HoldStart,
        CriticalHoldStart,
        ScratchHoldStart,
        CriticalScratchHoldStart,
        FlickNote,
        Sound,
        HoldEighth,
        HoldEnd,
        NontailHoldEnd,
        ScratchHoldEnd,
        NontailScratchHoldEnd,
        SyncLine,
        SplitLine
    );
    #endif
    
    PackSkin();
    PackEffect();
}