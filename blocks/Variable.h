template<int identifierId>
class Variable {
    public:

    int offset;
    Variable(){
        offset = allocatorSize[identifierId]++;
    }

    FuncNode get() {
        return Get(identifierId, offset);
    }
    FuncNode add(FuncNode value) {
        return Set(identifierId, offset, Add({Get(identifierId, offset), value}));
    }
    FuncNode subtract(FuncNode value) {
        return Set(identifierId, offset, Subtract({Get(identifierId, offset), value}));
    }
    FuncNode multiply(FuncNode value) {
        return Set(identifierId, offset, Multiply({Get(identifierId, offset), value}));
    }
    FuncNode divide(FuncNode value) {
        return Set(identifierId, offset, Divide({Get(identifierId, offset), value}));
    }
    FuncNode mod(FuncNode value) {
        return Set(identifierId, offset, Mod({Get(identifierId, offset), value}));
    }
    FuncNode set(FuncNode value) {
        return Set(identifierId, offset, value);
    }
};
