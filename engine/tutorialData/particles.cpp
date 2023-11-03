using namespace std;

class Effects {
    public:
	
	int NormalLinear = 0;
	int NormalCircular = 1;
	int Lane = 2;
	int CriticalLinear = 3;
	int CriticalCircular = 4;
	int HoldLinear = 5;
	int HoldCircular = 6;
	int ScratchLinear = 7;
	int ScratchCircular = 8;
	int Hold = 9;
	int Scratch = 10;
}Effects;

auto particles = defineParticles<class Effects>({
	{ParticleEffectName.NoteLinearTapPurple, Effects.NormalLinear},
	{ParticleEffectName.NoteCircularTapPurple, Effects.NormalCircular},
	{ParticleEffectName.LaneLinear, Effects.Lane},
	{ParticleEffectName.NoteLinearTapRed, Effects.CriticalLinear},
	{ParticleEffectName.NoteCircularTapRed, Effects.CriticalCircular},
	{ParticleEffectName.NoteLinearTapGreen, Effects.HoldLinear},
	{ParticleEffectName.NoteCircularTapGreen, Effects.HoldCircular},
	{ParticleEffectName.NoteLinearTapCyan, Effects.ScratchLinear},
	{ParticleEffectName.NoteCircularTapCyan, Effects.ScratchCircular},
	{ParticleEffectName.NoteCircularHoldGreen, Effects.Hold},
	{ParticleEffectName.NoteCircularHoldCyan, Effects.Scratch}
});
