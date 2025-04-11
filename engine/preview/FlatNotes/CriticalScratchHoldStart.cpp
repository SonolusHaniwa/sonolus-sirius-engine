class CriticalScratchHoldStart: public FlatNote {
	public:
	string name = "Sirius Critical Scratch Hold Start";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.CriticalNoteLeft; }
#undef DISABLE_INTERPRETER
};
