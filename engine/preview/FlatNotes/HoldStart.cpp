class HoldStart: public FlatNote {
	public:
	string name = "Sirius Hold Start";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.HoldNoteLeft; }
#undef DISABLE_INTERPRETER
};
