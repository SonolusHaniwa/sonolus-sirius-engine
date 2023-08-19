using namespace std;

class Sprites {
    public:

    int Stage = 0;
    int Judgeline = 1;
    int NormalNote = 2;
    int CriticalNote = 3;
    int HoldNote = 4;
    int ScratchNote = 5;
    int ScratchArrow = 6;
    int Hold = 7;
    int Scratch = 8;
    int StageBackground = 9;
}Sprites;

auto skins = defineSkins<class Sprites>({
    {"Sirius Stage", Sprites.Stage},
    {"Sirius Judgeline", Sprites.Judgeline},
    {"Sirius Normal Note", Sprites.NormalNote},
    {"Sirius Critical Note", Sprites.CriticalNote},
    {"Sirius Hold Note", Sprites.HoldNote},
    {"Sirius Scratch Note", Sprites.ScratchNote},
    {"Sirius Scratch Arrow", Sprites.ScratchArrow},
    {"Sirius Hold", Sprites.Hold},
    {"Sirius Scratch", Sprites.Scratch},
    {"Sirius Stage Background", Sprites.StageBackground}
});