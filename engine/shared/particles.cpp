class Effects {
    public:

    ParticleEffect NormalLinear = defineParticleEffect(ParticleEffectName.NoteLinearTapPurple);
	ParticleEffect NormalCircular = defineParticleEffect(ParticleEffectName.NoteCircularTapPurple);
	ParticleEffect Lane = defineParticleEffect(ParticleEffectName.LaneLinear);
	ParticleEffect CriticalLinear = defineParticleEffect(ParticleEffectName.NoteLinearTapRed);
	ParticleEffect CriticalCircular = defineParticleEffect(ParticleEffectName.NoteCircularTapRed);
	ParticleEffect HoldLinear = defineParticleEffect(ParticleEffectName.NoteLinearTapGreen);
	ParticleEffect HoldCircular = defineParticleEffect(ParticleEffectName.NoteCircularTapGreen);
	ParticleEffect ScratchLinear = defineParticleEffect(ParticleEffectName.NoteLinearTapCyan);
	ParticleEffect ScratchCircular = defineParticleEffect(ParticleEffectName.NoteCircularTapCyan);
	ParticleEffect Hold = defineParticleEffect(ParticleEffectName.NoteCircularHoldGreen);
	ParticleEffect Scratch = defineParticleEffect(ParticleEffectName.NoteCircularHoldCyan);
}Effects;