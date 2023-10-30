using namespace std;

class Texts {
    public:

    int NormalNote = 0;
    int CriticalNote = 1;
    
}Texts;

auto texts = defineInstructionTexts<class Texts>({
	{InstructionText.Tap, Texts.NormalNote},
	{InstructionText.Tap, Texts.CriticalNote}
});
