using namespace std;

class Clips {
    public:

    int Stage = 0;
    int Good = 1;
    int Bad = 2;
    int Perfect = 3;
    int Great = 4;
    int Scratch = 5;
    int Hold = 6;
    int Sound = 7;
    int Critical = 8;
}Clips;

auto effects = defineEffects<class Clips>({
    {EffectClipName.Stage, Clips.Stage},
    {EffectClipName.Good, Clips.Good},
    {EffectClipName.GoodAlternative, Clips.Bad},
    {EffectClipName.Perfect, Clips.Perfect},
    {EffectClipName.PerfectAlternative, Clips.Great},
    {"Sirius Scratch", Clips.Scratch},
    {"Sirius Critical", Clips.Critical},
    {"Sirius Sound", Clips.Sound},
    {EffectClipName.Hold, Clips.Hold},
});