using namespace std;

class Clips {
    public:

    int Stage = 0;
    int Good = 1;
    int CriticalGood = 2;
    int Perfect = 3;
    int CriticalPerfect = 4;
    int Scratch = 5;
    int Hold = 6;
    int Sound = 7;
}Clips;

auto effects = defineEffects<class Clips>({
    {EffectClipName.Stage, Clips.Stage},
    {EffectClipName.Good, Clips.Good},
    {EffectClipName.GoodAlternative, Clips.CriticalGood},
    {EffectClipName.Perfect, Clips.Perfect},
    {EffectClipName.PerfectAlternative, Clips.CriticalPerfect},
    {"Sirius Scratch", Clips.Scratch},
    {EffectClipName.Hold, Clips.Hold},
    {EffectClipName.HoldAlternative, Clips.Sound},
});