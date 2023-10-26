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
	string color[effectGroupCount] = { "#fff", "#fff", "#fff", "#fff", "#fff", "#fff", "#fff" };
	for (int i = 0; i < effectGroupCount; i++)
		defineEffect({
			name: name[i],
			x1: x1, y1: y1, x2: x2, y2: y2,
			x3: x3, y3: y3, x4: x4, y4: y4,
			groups: {{1, {
				{
					sprite: note_circular_tap,
					color: color[i],
					duration: 1,
					x: { from: c * 0, to: c * -0.005, ease: AnimationEase.OutCubic },
					y: { from: c * 0, to: c * -0.5, ease: AnimationEase.OutCubic },
					w: { from: c * 1, to: c * 1.01, ease: AnimationEase.OutCubic },
					h: { from: c * 1, to: c * 2.0, ease: AnimationEase.OutCubic },
					a: { from: c * 1, to: c * 0, ease: AnimationEase.InCubic }
				}
			}}}
		});
	return true;	
}();
