class NormalNote: public FlatNote {
	public:
	string name = "Sirius Normal Note";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.NormalNoteLeft; }
#undef DISABLE_INTERPRETER
};
