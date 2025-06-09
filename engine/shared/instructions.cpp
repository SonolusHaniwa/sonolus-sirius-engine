class iTexts {
    public:

    InstructionText NormalNote = defineInstructionText(Text.Tap);
    InstructionText CriticalNote = defineInstructionText(Text.Tap);
    InstructionText ScratchNote = defineInstructionText(Text.TapFlick);
	InstructionText HoldStartNote = defineInstructionText(Text.HoldFollow);
	InstructionText HoldEndNote = defineInstructionText(Text.Release);
	InstructionText CriticalHoldStartNote = defineInstructionText(Text.HoldFollow);
	InstructionText CriticalHoldEndNote = defineInstructionText(Text.Release);
	InstructionText ScratchStartNote = defineInstructionText(Text.HoldFollow);
	InstructionText ScratchEndNote = defineInstructionText(Text.Flick);
	InstructionText CriticalScratchStartNote = defineInstructionText(Text.HoldFollow);
	InstructionText CriticalScratchEndNote = defineInstructionText(Text.Flick);
	InstructionText JumpScratchStartNote = defineInstructionText(Text.HoldFollow);
	InstructionText JumpScratchMiddleNote = defineInstructionText(Text.Flick);
	InstructionText JumpScratchEndNote = defineInstructionText(Text.Flick);
}iTexts;

class iIcons {
    public:

    InstructionIcon Hand = defineInstructionIcon(InstructionIconName.Hand);
}iIcons;