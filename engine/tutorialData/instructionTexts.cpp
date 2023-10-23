using namespace std;

class Texts {
    public:

    int Note = 0;
    int CriticalNote = 1;
    int Flick = 2;
	int HoldStart = 3;
	int HoldEnd = 4;
	int ScratchStart = 5;
	int ScratchEnd = 6;
}Texts;

auto texts = defineInstructionTexts<class Texts>({
	{"", Texts.Note},
	{"Tap the note", Texts.CriticalNote},
	{"Tap and flick the note", Texts.Flick},
	{"Tap and Hold", Texts.HoldStart},
	{"Hold", Texts.HoldEnd}

});
