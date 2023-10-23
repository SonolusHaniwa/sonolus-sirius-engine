bool note_circular_tap = [](){
	const int effectGroupCount = 7;
	string name[effectGroupCount] = {
		ParticleEffectName.NoteCircularTapNeutral,
		ParticleEffectName.NoteCircularTapRed,
		ParticleEffectName.NoteCircularTapGreen,
		ParticleEffectName.NoteCircularTapBlue,
		ParticleEffectName.NoteCircularTapYellow,
		ParticleEffectName.NoteCircularTapPurple,
		ParticleEffectName.NoteCircularTapCyan
	};
	for (int i = 0; i < effectGroupCount; i++)
		defineEffect({
			name: name[i],
			x1: x1,
			y1: y1,
			x2: x2,
			y2: y2,
			x3: x3,
			y3: y3,
			x4: x4,
			y4: y4,
		});
	return true;	
}();
