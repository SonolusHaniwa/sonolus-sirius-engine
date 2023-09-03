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
#include"data/archetype/NormalNote.cpp"
#include"data/archetype/CriticalNote.cpp"
#include"data/archetype/FlickNote.cpp"
#include"data/archetype/HoldStart.cpp"
#include"data/archetype/CriticalHoldStart.cpp"
#include"data/archetype/ScratchHoldStart.cpp"
#include"data/archetype/CriticalScratchHoldStart.cpp"
#include"data/archetype/Sound.cpp"
#include"data/archetype/HoldEighth.cpp"
#include"data/archetype/HoldEnd.cpp"
#include"data/archetype/ScratchHoldEnd.cpp"
#include"data/archetype/SyncLine.cpp"
#include"data/archetype/SplitLine.cpp"
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
#elif preview
using namespace previewData;
#include"previewData/skins.cpp"
#include"previewData/constants.cpp"
#include"previewData/archetype/Initialization.cpp"
#endif
