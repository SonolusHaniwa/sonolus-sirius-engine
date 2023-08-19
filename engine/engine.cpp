using namespace std;

const string Scope = "sirius";

#include"configuration/options.cpp"
#include"configuration/ui.cpp"
#ifdef play
using namespace playData;
#include"data/skins.cpp"
#include"data/effects.cpp"
#include"data/particles.cpp"
#include"data/buckets.cpp"
#include"data/constants.cpp"
#include"data/utils.cpp"
#include"data/archetype/Initialization.cpp"
#include"data/archetype/InputManager.cpp"
#include"data/archetype/Stage.cpp"
#elif tutorial
using namespace tutorialData;
#include"tutorialData/skins.cpp"
#include"tutorialData/effects.cpp"
#include"tutorialData/particles.cpp"
#include"tutorialData/instructionTexts.cpp"
#include"tutorialData/instructionIcons.cpp"
#include"tutorialData/preprocess.cpp"
#include"tutorialData/navigate.cpp"
#include"tutorialData/update.cpp"
#endif