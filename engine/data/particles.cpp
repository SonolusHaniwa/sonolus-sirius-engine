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
}Effects;

auto particles = defineParticles<class Effects>({
	{"#NOTE_LINEAR_TAP_PURPLE", Effects.NormalLinear},
	{"#NOTE_CIRCULAR_TAP_PURPLE", Effects.NormalCircular},
	{"#LANE_LINEAR", Effects.Lane},
	{"#NOTE_LINEAR_TAP_RED", Effects.CriticalLinear},
	{"#NOTE_CIRCULAR_TAP_RED", Effects.CriticalCircular},
	{"#NOTE_LINEAR_TAP_GREEN", Effects.HoldLinear},
	{"#NOTE_CIRCULAR_TAP_GREEN", Effects.HoldCircular},
	{"#NOTE_LINEAR_TAP_CYAN", Effects.ScratchLinear},
	{"#NOTE_CIRCULAR_TAP_CYAN", Effects.ScratchCircular}
});
