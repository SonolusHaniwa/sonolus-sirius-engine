bool note_line_tap = [](){
	const int effectGroupCount = 7;
	string name[effectGroupCount] = {
		ParticleEffectName.NoteLinearTapNeutral,
		ParticleEffectName.NoteLinearTapRed,
		ParticleEffectName.NoteLinearTapGreen,
		ParticleEffectName.NoteLinearTapBlue,
		ParticleEffectName.NoteLinearTapYellow,
		ParticleEffectName.NoteLinearTapPurple,
		ParticleEffectName.NoteLinearTapCyan
	};
	string color[effectGroupCount] = { "#fff", "#fff", "#fff", "#fff", "#fff", "#fff", "#fff" };
	for (int i = 0; i < effectGroupCount; i++)
		defineEffect({
			name: name[i],
			x1: x1, y1: y1, x2: x2, y2: y2,
			x3: x3, y3: y3, x4: x4, y4: y4,
			groups: {{1, {
				{
					sprite: note_linear_background,
					color: color[i],
					start: 0.16,
					duration: 0.64,
					x: { from: c * 0, to: c * 0 },
					y: { from: c * 0, to: c * 0 },
					w: { from: c * 1, to: c * 1 },
					h: { from: c * 1, to: c * 1 },
					a: { from: c * 0.6, to: c * 0, ease: AnimationEase.InCubic }
				}, {
					sprite: note_linear_background,
					color: color[i],
					start: 0,
					duration: 0.16,
					x: { from: c * 0, to: c * 0 },
					y: { from: c * 0, to: c * 0 },
					w: { from: c * 1, to: c * 1 },
					h: { from: c * 0.2, to: c * 1, ease: AnimationEase.OutCubic },
					a: { from: c * 0, to: c * 0.6, ease: AnimationEase.InCubic }
				}
			}}, {15, {
				{
					sprite: note_linear_line,
					color: color[i],
					start: 0,
					duration: 0.16,
					x: { from: r1 * 2 - c * 1, to: r1 * 2 - c * 1 },
					y: { from: c * 0, to: r2 * 0.05, ease: AnimationEase.OutCubic },
					w: { from: c * 0.1, to: c * 0.1 },
					h: { from: c * 0.0, to: r3 * 0.25 + c * 0.6, ease: AnimationEase.OutCubic },
					a: { from: c * 0, to: c * 0.6, ease: AnimationEase.InCubic }
				}, {
					sprite: note_linear_line,
					color: color[i],
					start: 0.16,
					duration: 0.64,
					x: { from: r1 * 2 - c * 1, to: r1 * 2 - c * 1 },
					y: { from: r2 * 0.05, to: r2 * 0.05 },
					w: { from: c * 0.1, to: c * 0.1 },
					h: { from: r3 * 0.25 + c * 0.6, to: r3 * 0.25 + c * 0.6 },
					a: { from: c * 0.6, to: c * 0, ease: AnimationEase.InCubic }
				}
			}}}
		});
	return true;	
}();
