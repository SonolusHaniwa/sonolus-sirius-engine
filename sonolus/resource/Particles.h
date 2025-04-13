#ifndef Particles_H
#define Particles_H

class ParticleEffect {
    public:

    int id;
    string effectName;

    operator int() {
        return id;
    }

    operator FuncNode() {
        return id;
    }

    operator Variable() {
        return id;
    }
};

ParticleEffect defineParticleEffect(string name) {
    // if (path == "") path = "./skin/" + name + ".png";
    particle_effects.push_back({ name, name });
    return { int(particle_effects.size()) - 1, name };
}

class ParticleEffectName {
    public:

    string NoteCircularTapNeutral = "#NOTE_CIRCULAR_TAP_NEUTRAL";
    string NoteCircularTapRed = "#NOTE_CIRCULAR_TAP_RED";
    string NoteCircularTapGreen = "#NOTE_CIRCULAR_TAP_GREEN";
    string NoteCircularTapBlue = "#NOTE_CIRCULAR_TAP_BLUE";
    string NoteCircularTapYellow = "#NOTE_CIRCULAR_TAP_YELLOW";
    string NoteCircularTapPurple = "#NOTE_CIRCULAR_TAP_PURPLE";
    string NoteCircularTapCyan = "#NOTE_CIRCULAR_TAP_CYAN";

    string NoteCircularAlternativeNeutral = "#NOTE_CIRCULAR_ALTERNATIVE_NEUTRAL";
    string NoteCircularAlternativeRed = "#NOTE_CIRCULAR_ALTERNATIVE_RED";
    string NoteCircularAlternativeGreen = "#NOTE_CIRCULAR_ALTERNATIVE_GREEN";
    string NoteCircularAlternativeBlue = "#NOTE_CIRCULAR_ALTERNATIVE_BLUE";
    string NoteCircularAlternativeYellow = "#NOTE_CIRCULAR_ALTERNATIVE_YELLOW";
    string NoteCircularAlternativePurple = "#NOTE_CIRCULAR_ALTERNATIVE_PURPLE";
    string NoteCircularAlternativeCyan = "#NOTE_CIRCULAR_ALTERNATIVE_CYAN";

    string NoteCircularHoldNeutral = "#NOTE_CIRCULAR_HOLD_NEUTRAL";
    string NoteCircularHoldRed = "#NOTE_CIRCULAR_HOLD_RED";
    string NoteCircularHoldGreen = "#NOTE_CIRCULAR_HOLD_GREEN";
    string NoteCircularHoldBlue = "#NOTE_CIRCULAR_HOLD_BLUE";
    string NoteCircularHoldYellow = "#NOTE_CIRCULAR_HOLD_YELLOW";
    string NoteCircularHoldPurple = "#NOTE_CIRCULAR_HOLD_PURPLE";
    string NoteCircularHoldCyan = "#NOTE_CIRCULAR_HOLD_CYAN";

    string NoteLinearTapNeutral = "#NOTE_LINEAR_TAP_NEUTRAL";
    string NoteLinearTapRed = "#NOTE_LINEAR_TAP_RED";
    string NoteLinearTapGreen = "#NOTE_LINEAR_TAP_GREEN";
    string NoteLinearTapBlue = "#NOTE_LINEAR_TAP_BLUE";
    string NoteLinearTapYellow = "#NOTE_LINEAR_TAP_YELLOW";
    string NoteLinearTapPurple = "#NOTE_LINEAR_TAP_PURPLE";
    string NoteLinearTapCyan = "#NOTE_LINEAR_TAP_CYAN";

    string NoteLinearAlternativeNeutral = "#NOTE_LINEAR_ALTERNATIVE_NEUTRAL";
    string NoteLinearAlternativeRed = "#NOTE_LINEAR_ALTERNATIVE_RED";
    string NoteLinearAlternativeGreen = "#NOTE_LINEAR_ALTERNATIVE_GREEN";
    string NoteLinearAlternativeBlue = "#NOTE_LINEAR_ALTERNATIVE_BLUE";
    string NoteLinearAlternativeYellow = "#NOTE_LINEAR_ALTERNATIVE_YELLOW";
    string NoteLinearAlternativePurple = "#NOTE_LINEAR_ALTERNATIVE_PURPLE";
    string NoteLinearAlternativeCyan = "#NOTE_LINEAR_ALTERNATIVE_CYAN";

    string NoteLinearHoldNeutral = "#NOTE_LINEAR_HOLD_NEUTRAL";
    string NoteLinearHoldRed = "#NOTE_LINEAR_HOLD_RED";
    string NoteLinearHoldGreen = "#NOTE_LINEAR_HOLD_GREEN";
    string NoteLinearHoldBlue = "#NOTE_LINEAR_HOLD_BLUE";
    string NoteLinearHoldYellow = "#NOTE_LINEAR_HOLD_YELLOW";
    string NoteLinearHoldPurple = "#NOTE_LINEAR_HOLD_PURPLE";
    string NoteLinearHoldCyan = "#NOTE_LINEAR_HOLD_CYAN";

    string LaneCircular = "#LANE_CIRCULAR";
    string LaneLinear = "#LANE_LINEAR";

    string SlotCircular = "#SLOT_CIRCULAR";
    string SlotLinear = "#SLOT_LINEAR";

    string JudgeLineCircular = "#JUDGE_LINE_CIRCULAR";
    string JudgeLineLinear = "#JUDGE_LINE_LINEAR";
}ParticleEffectName;

#endif