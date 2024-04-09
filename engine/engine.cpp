using namespace std;

const string Scope = "sirius";

#include"configuration/options.cpp"
#include"configuration/ui.cpp"

#ifdef play
using namespace playData;
// #elif tutorial
// using namespace tutorialData;
#elif preview
using namespace previewData;
#elif watch
using namespace watchData;
#endif

#if play || preview || watch
#include"skins.cpp"
#include"effects.cpp"
#include"particles.cpp"
#include"buckets.cpp"
#include"constants.cpp"
#include"types.cpp"
#include"utils.cpp"
#include"getSplitLine.cpp"
#endif

#ifdef play
#include"play/Initialization.cpp"
#include"play/InputManager.cpp"
#include"play/Stage.cpp"
#include"play/flatNotes/FlatNote.cpp"
#include"play/flatNotes/NormalNote.cpp"
#include"play/flatNotes/CriticalNote.cpp"
#include"play/flatNotes/HoldStart.cpp"
#include"play/flatNotes/CriticalHoldStart.cpp"
#include"play/flatNotes/ScratchHoldStart.cpp"
#include"play/flatNotes/CriticalScratchHoldStart.cpp"
#include"play/FlickNote.cpp"
#include"play/holdNotes/Sound.cpp"
#include"play/holdNotes/HoldEighth.cpp"
#include"play/holdNotes/HoldEnd.cpp"
#include"play/holdNotes/ScratchHoldEnd.cpp"
#include"play/SyncLine.cpp"
#include"play/SplitLine.cpp"
#include"play/HiSpeed.cpp"
// #elif tutorial
// #include"skins.cpp"
// #include"effects.cpp"
// #include"particles.cpp"
// #include"tutorial/instructionTexts.cpp"
// #include"tutorial/instructionIcons.cpp"
// #include"tutorial/constants.cpp"
// #include"tutorial/utils.cpp"
// #include"getSplitLine.cpp"
// #include"tutorial/components/Note.cpp"
// #include"tutorial/components/Flick.cpp"
// #include"tutorial/components/Hold.cpp"
// #include"tutorial/components/Scratch.cpp"
// #include"tutorial/components/JumpScratch.cpp"
// #include"tutorial/preprocess.cpp"
// #include"tutorial/navigate.cpp"
// #include"tutorial/update.cpp"
#elif preview
#include"preview/Initialization.cpp"
#include"preview/Stage.cpp"
#include"preview/flatNotes/FlatNote.cpp"
#include"preview/flatNotes/NormalNote.cpp"
#include"preview/flatNotes/CriticalNote.cpp"
#include"preview/flatNotes/HoldStart.cpp"
#include"preview/flatNotes/CriticalHoldStart.cpp"
#include"preview/flatNotes/ScratchHoldStart.cpp"
#include"preview/flatNotes/CriticalScratchHoldStart.cpp"
#include"preview/FlickNote.cpp"
#include"preview/holdNotes/HoldEighth.cpp"
#include"preview/holdNotes/HoldEnd.cpp"
#include"preview/holdNotes/ScratchHoldEnd.cpp"
#include"preview/holdNotes/Sound.cpp"
#include"preview/SyncLine.cpp"
#include"preview/SplitLine.cpp"
#include"preview/HiSpeed.cpp"
#elif watch
#include"watch/updateSpawn.cpp"
#include"watch/Initialization.cpp"
#include"watch/Stage.cpp"
#include"watch/UpdateJudgment.cpp"
#include"watch/flatNotes/FlatNote.cpp"
#include"watch/flatNotes/NormalNote.cpp"
#include"watch/flatNotes/CriticalNote.cpp"
#include"watch/flatNotes/HoldStart.cpp"
#include"watch/flatNotes/CriticalHoldStart.cpp"
#include"watch/flatNotes/ScratchHoldStart.cpp"
#include"watch/flatNotes/CriticalScratchHoldStart.cpp"
#include"watch/FlickNote.cpp"
#include"watch/holdNotes/HoldEnd.cpp"
#include"watch/holdNotes/ScratchHoldEnd.cpp"
#include"watch/holdNotes/HoldEighth.cpp"
#include"watch/holdNotes/Sound.cpp"
#include"watch/SyncLine.cpp"
#include"watch/SplitLine.cpp"
#endif
