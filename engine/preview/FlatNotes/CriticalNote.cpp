class CriticalNote: public FlatNote {
	public:
	string name = "Sirius Critical Note";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.CriticalNoteLeft; }
#undef DISABLE_INTERPRETER
};
