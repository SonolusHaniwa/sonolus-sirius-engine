#include"shared/options.cpp"
#include"shared/skins.cpp"
#include"shared/effects.cpp"
#include"shared/particles.cpp"
#include"shared/instructions.cpp"
#include"shared/constants.cpp"
#include"shared/utils.cpp"
#include"shared/getSplitLine.cpp"

#ifndef preview
#include"play/utils.cpp"
#else
#include"preview/utils.cpp"
#endif

#ifdef play
#include"play/Initialization.cpp"
#include"play/InputManager.cpp"
#include"play/Stage.cpp"
#include"play/FlatNotes/FlatNote.cpp"
#include"play/FlatNotes/NormalNote.cpp"
#include"play/FlatNotes/CriticalNote.cpp"
#include"play/FlatNotes/HoldStart.cpp"
#include"play/FlatNotes/CriticalHoldStart.cpp"
#include"play/FlatNotes/ScratchHoldStart.cpp"
#include"play/FlatNotes/CriticalScratchHoldStart.cpp"
#include"play/FlickNote.cpp"
#include"play/HoldNotes/Sound.cpp"
#include"play/HoldNotes/HoldEighth.cpp"
#include"play/HoldNotes/HoldEnd.cpp"
#include"play/HoldNotes/NontailHoldEnd.cpp"
#include"play/HoldNotes/ScratchHoldEnd.cpp"
#include"play/HoldNotes/NontailScratchHoldEnd.cpp"
#include"play/SyncLine.cpp"
#include"play/SplitLine.cpp"
#include"play/HiSpeed.cpp"
#endif
#ifdef tutorial
#include"tutorial/Initialization.cpp"
#include"tutorial/Hand.cpp"
#include"tutorial/Stage.cpp"
#include"tutorial/Notes/Note.cpp"
#include"tutorial/Notes/Flick.cpp"
#include"tutorial/Notes/Hold.cpp"
#include"tutorial/Notes/Scratch.cpp"
#include"tutorial/Notes/JumpScratch.cpp"
#endif
#ifdef preview
#include"preview/Initialization.cpp"
#include"preview/Stage.cpp"
#include"preview/FlatNotes/FlatNote.cpp"
#include"preview/FlatNotes/NormalNote.cpp"
#include"preview/FlatNotes/CriticalNote.cpp"
#include"preview/FlatNotes/HoldStart.cpp"
#include"preview/FlatNotes/CriticalHoldStart.cpp"
#include"preview/FlatNotes/ScratchHoldStart.cpp"
#include"preview/FlatNotes/CriticalScratchHoldStart.cpp"
#include"preview/FlickNote.cpp"
#include"preview/HoldNotes/Sound.cpp"
#include"preview/HoldNotes/HoldEighth.cpp"
#include"preview/HoldNotes/HoldEnd.cpp"
#include"preview/HoldNotes/NontailHoldEnd.cpp"
#include"preview/HoldNotes/ScratchHoldEnd.cpp"
#include"preview/HoldNotes/NontailScratchHoldEnd.cpp"
#include"preview/SyncLine.cpp"
#include"preview/SplitLine.cpp"
#include"preview/HiSpeed.cpp"
#endif
#ifdef watch
#include"watch/UpdateSpawn.cpp"
#include"watch/Initialization.cpp"
#include"watch/Stage.cpp"
#include"watch/UpdateJudgment.cpp"
#include"watch/FlatNotes/FlatNote.cpp"
#include"watch/FlatNotes/NormalNote.cpp"
#include"watch/FlatNotes/CriticalNote.cpp"
#include"watch/FlatNotes/HoldStart.cpp"
#include"watch/FlatNotes/CriticalHoldStart.cpp"
#include"watch/FlatNotes/ScratchHoldStart.cpp"
#include"watch/FlatNotes/CriticalScratchHoldStart.cpp"
#include"watch/FlickNote.cpp"
#include"watch/HoldNotes/Sound.cpp"
#include"watch/HoldNotes/HoldEighth.cpp"
#include"watch/HoldNotes/HoldEnd.cpp"
#include"watch/HoldNotes/NontailHoldEnd.cpp"
#include"watch/HoldNotes/ScratchHoldEnd.cpp"
#include"watch/HoldNotes/NontailScratchHoldEnd.cpp"
#include"watch/SyncLine.cpp"
#include"watch/SplitLine.cpp"
#endif