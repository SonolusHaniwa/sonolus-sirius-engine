#ifndef EngineInstruction_H
#define Engineinstruction_H

class InstructionText {
    public:

    int id;
    string name;

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

vector<string> instruction_texts;
InstructionText defineInstructionText(string name) {
    instruction_texts.push_back(name);
    return { int(instruction_texts.size()) - 1 };
}

class InstructionIcon {
    public:

    int id;
    string name;

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

vector<string> instruction_icons;
InstructionIcon defineInstructionIcon(string name) {
    instruction_icons.push_back(name);
    return { int(instruction_icons.size()) - 1 };
}

#endif