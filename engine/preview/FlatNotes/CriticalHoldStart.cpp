class CriticalHoldStart: public FlatNote {
	public:
	string name = "Sirius Critical Hold Start";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.CriticalNoteLeft; }
#undef DISABLE_INTERPRETER
};
