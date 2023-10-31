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
}Texts;

auto texts = defineInstructionTexts<class Texts>({
	{InstructionText.Tap, Texts.NormalNote},
	{InstructionText.Tap, Texts.CriticalNote},
	{InstructionText.TapAndFlick, Texts.ScratchNote},
	{InstructionText.HoldAndFollow, Texts.HoldStartNote},
	{InstructionText.Release, Texts.HoldEndNote},
	{InstructionText.HoldAndFollow, Texts.CriticalHoldStartNote},
	{InstructionText.Release, Texts.CriticalHoldEndNote},
});
