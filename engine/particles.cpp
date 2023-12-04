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
	int text0 = 1000;
	int text1 = 1001;
	int text2 = 1002;
	int text3 = 1003;
	int text4 = 1004;
	int text5 = 1005;
	int text6 = 1006;
	int text7 = 1007;
	int text8 = 1008;
	int text9 = 1009;
	
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
	{ParticleEffectName.NoteCircularHoldCyan, Effects.Scratch},
	{"text0", Effects.text0},
	{"text1", Effects.text1},
	{"text2", Effects.text2},
	{"text3", Effects.text3},
	{"text4", Effects.text4},
	{"text5", Effects.text5},
	{"text6", Effects.text6},
	{"text7", Effects.text7},
	{"text8", Effects.text8},
	{"text9", Effects.text9},
});
