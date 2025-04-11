class ScratchHoldStart: public FlatNote {
	public:
	string name = "Sirius Scratch Hold Start";

#define DISABLE_INTERPRETER
	var getSprite() { return Sprites.NormalNoteLeft; }
#undef DISABLE_INTERPRETER
};
