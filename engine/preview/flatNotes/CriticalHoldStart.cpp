class SiriusCriticalHoldStart: public FlatNote {
	public:
	static constexpr const char* name = "Sirius Critical Hold Start";

	let getSprite() { return Sprites.CriticalNoteLeft; }
};
