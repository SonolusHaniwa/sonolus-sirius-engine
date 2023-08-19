using namespace std;

class Clips {
    public:

    int Miss = 0;
    int Great = 1;
    int FlickGreat = 2;
    int Perfect = 3;
    int FlickPerfect = 4;
    int HoldStart = 5;
    int Scratch = 6;
    int Hold = 7;
}Clips;

auto effects = defineEffects<class Clips>({
    {"Sirius Miss", Clips.Miss},
    {"Sirius Great", Clips.Great},
    {"Sirius Flick Great", Clips.FlickGreat},
    {"Sirius Perfect", Clips.Perfect},
    {"Sirius Flick Perfect", Clips.FlickPerfect},
    {"Sirius Hold Start", Clips.HoldStart},
    {"Sirius Scratch", Clips.Scratch},
    {"Sirius Hold", Clips.Hold}
});