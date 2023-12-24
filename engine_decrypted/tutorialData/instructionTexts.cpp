using namespace std;

class Texts {
    public:

    int NormalNote = 0;
    int CriticalNote = 1;
    int ScratchNote = 2;
	int HoldStartNote = 3;
	int HoldEndNote = 4;
	int CriticalHoldStartNote = 5;
	int CriticalHoldEndNote = 6;
	int ScratchStartNote = 7;
	int ScratchEndNote = 8;
	int CriticalScratchStartNote = 9;
	int CriticalScratchEndNote = 10;
	int JumpScratchStartNote = 11;
	int JumpScratchMiddleNote = 12;
	int JumpScratchEndNote = 13;
}Texts;

auto texts = defineInstructionTexts<class Texts>({
	{InstructionText.Tap, Texts.NormalNote},
	{InstructionText.Tap, Texts.CriticalNote},
	{InstructionText.TapAndFlick, Texts.ScratchNote},
	{InstructionText.HoldAndFollow, Texts.HoldStartNote},
	{InstructionText.Release, Texts.HoldEndNote},
	{InstructionText.HoldAndFollow, Texts.CriticalHoldStartNote},
	{InstructionText.Release, Texts.CriticalHoldEndNote},
	{InstructionText.HoldAndFollow, Texts.ScratchStartNote},
	{InstructionText.Flick, Texts.ScratchEndNote},
	{InstructionText.HoldAndFollow, Texts.CriticalScratchStartNote},
	{InstructionText.Flick, Texts.CriticalScratchEndNote},
	{InstructionText.HoldAndFollow, Texts.JumpScratchStartNote},
	{InstructionText.Flick, Texts.JumpScratchMiddleNote},
	{InstructionText.Flick, Texts.JumpScratchEndNote},
});
