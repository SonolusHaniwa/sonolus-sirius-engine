using namespace std;

const string Scope = "sirius";

#include"configuration/options.cpp"
#include"configuration/ui.cpp"

#ifdef play
using namespace playData;
#elif tutorial
using namespace tutorialData;
#elif preview
using namespace previewData;
#elif watch
using namespace watchData;
#endif

#include"skins.cpp"
#include"effects.cpp"
#include"particles.cpp"
// #include"data/buckets.cpp"
#include"constants.cpp"
#include"types.cpp"
#include"utils.cpp"
#include"getSplitLine.cpp"

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
#elif tutorial
#include"skins.cpp"
#include"effects.cpp"
#include"particles.cpp"
#include"tutorial/instructionTexts.cpp"
#include"tutorial/instructionIcons.cpp"
#include"tutorial/constants.cpp"
#include"tutorial/utils.cpp"
#include"getSplitLine.cpp"
#include"tutorial/components/Note.cpp"
#include"tutorial/components/Flick.cpp"
#include"tutorial/components/Hold.cpp"
#include"tutorial/components/Scratch.cpp"
#include"tutorial/components/JumpScratch.cpp"
#include"tutorial/preprocess.cpp"
#include"tutorial/navigate.cpp"
#include"tutorial/update.cpp"
#elif preview
#include"skins.cpp"
#include"preview/constants.cpp"
#include"preview/utils.cpp"
#include"getSplitLine.cpp"
#include"preview/archetype/Initialization.cpp"
#include"preview/archetype/Stage.cpp"
#include"preview/archetype/NormalNote.cpp"
#include"preview/archetype/CriticalNote.cpp"
#include"preview/archetype/FlickNote.cpp"
#include"preview/archetype/HoldStart.cpp"
#include"preview/archetype/HoldEighth.cpp"
#include"preview/archetype/CriticalHoldStart.cpp"
#include"preview/archetype/ScratchHoldStart.cpp"
#include"preview/archetype/CriticalScratchHoldStart.cpp"
#include"preview/archetype/HoldEnd.cpp"
#include"preview/archetype/ScratchHoldEnd.cpp"
#include"preview/archetype/Sound.cpp"
#include"preview/archetype/SyncLine.cpp"
#include"preview/archetype/SplitLine.cpp"
#elif watch
#include"watch/updateSpawn.cpp"
#include"watch/Initialization.cpp"
#include"watch/Stage.cpp"
// #include"watch/archetype/notes/flatNotes/FlatNote.cpp"
// #include"watch/archetype/notes/flatNotes/NormalNote.cpp"
// #include"watch/archetype/notes/flatNotes/CriticalNote.cpp"
// #include"watch/archetype/notes/flatNotes/FlickNote.cpp"
// #include"watch/archetype/notes/flatNotes/HoldStart.cpp"
// #include"watch/archetype/notes/flatNotes/CriticalHoldStart.cpp"
// #include"watch/archetype/notes/flatNotes/ScratchHoldStart.cpp"
// #include"watch/archetype/notes/flatNotes/CriticalScratchHoldStart.cpp"
// #include"watch/archetype/notes/holdTickNotes/HoldTickNote.cpp"
// #include"watch/archetype/notes/holdTickNotes/HoldEnd.cpp"
// #include"watch/archetype/notes/holdTickNotes/ScratchHoldEnd.cpp"
// #include"watch/archetype/notes/holdTickNotes/HoldEighth.cpp"
// #include"watch/archetype/notes/holdTickNotes/Sound.cpp"
// #include"watch/archetype/SyncLine.cpp"
// #include"watch/archetype/SplitLine.cpp"
#endif
