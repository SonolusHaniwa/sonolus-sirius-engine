class Clips {
    public:

    EffectClip Stage = defineEffectClip(EffectClipName.Stage);
    EffectClip Good = defineEffectClip(EffectClipName.Good);
    EffectClip Bad = defineEffectClip(EffectClipName.GoodAlternative);
    EffectClip Perfect = defineEffectClip(EffectClipName.Perfect);
    EffectClip Great = defineEffectClip(EffectClipName.PerfectAlternative);
    EffectClip Scratch = defineEffectClip("Sirius Scratch");
    EffectClip Hold = defineEffectClip(EffectClipName.Hold);
    EffectClip Sound = defineEffectClip("Sirius Sound");
    EffectClip Critical = defineEffectClip("Sirius Critical");
}Clips;