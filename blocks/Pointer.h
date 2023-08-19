template<int identifierId>
class Pointer {
    public:
    
    FuncNode offset = 0;
    int size = -1;

    FuncNode get(FuncNode i) {
        if (size != -1 && i.isValue == true &&
            (i.value >= size || i.value < 0)) throwWarning("");
        return Get(identifierId, Add({i, offset}));
    }

    FuncNode set(FuncNode i, FuncNode value) {
        if (size != -1 && i.isValue == true &&
            (i.value >= size || i.value < 0)) throwWarning("");
        return Execute({
			Set(identifierId, Add({i, offset}), value)
		});
    }

    FuncNode set2(FuncNode i, FuncNode value) {
        return set(i, value);
    }
};

template<typename T, int blockSize>
class PointerArray {
    public:

    T operator [] (int offset) {return T(Multiply({offset, blockSize}));}
    T operator [] (FuncNode offset) {return T(Multiply({offset, blockSize}));};
};