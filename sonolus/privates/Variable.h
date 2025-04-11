#ifndef Variable_H
#define Variable_H

#define ALLOCATOR_SIZE 10001

map<int, int> SonolusMemorySize;
map<int, FuncNode> SonolusMemoryIndex;
map<int, int> SonolusMemoryDelta;
set<int> allowAllocate;

template<typename T>
map<int, int> SizeOf() {
    createNodeContainer(false);
    auto backupSonolusMemoryDelta = SonolusMemoryDelta;
    SonolusMemoryDelta.clear();
    T x;
    map<int, int> result = SonolusMemoryDelta;
    SonolusMemoryDelta = backupSonolusMemoryDelta;
    mergeNodeContainer();
    return result;
}

// Tips: 当 index.getNodeId().isValue 为 0 时，说明是初始化，否则是引用
int defaultAllocatorId = 0;
class Variable {
    public:
    int allocatorId = defaultAllocatorId;
    FuncNode index = 0;

    FuncNode allocate() {
        // cout << allocatorId << " " << SonolusMemoryIndex[allocatorId] + SonolusMemoryDelta[allocatorId] << endl;
        if (allowAllocate.count(allocatorId) == 0) {
            // cerr << "You are not allowed to allocate pointer dynamically!" << endl;
            return -1;
        }
        FuncNode index = SonolusMemoryIndex[allocatorId] + SonolusMemoryDelta[allocatorId];
        int val1 = index.getNode().value, val2 = SonolusMemorySize[allocatorId];
        SonolusAssert(
            index.getNode().isValue == 0 || index.getNode().value < SonolusMemorySize[allocatorId],
            "Memory is full!(id: %d, allocated %d / %d)",
            allocatorId,
            val1,
            val2
        );
        SonolusMemoryDelta[allocatorId]++;
        return index;
    }

    public:

    // 基础构造函数
    Constructor Variable() {
        index = allocate();
    }
    Constructor Variable(FuncNode value) {
        index = allocate();
        if (index.getNode().isValue) Set(allocatorId, index, value);
    }
    Constructor Variable(double value) {
        index = allocate();
        if (index.getNode().isValue) Set(allocatorId, index, value);
    }
    Constructor Variable(int allocatorId, int index) { // 构造指针类型
        this->allocatorId = allocatorId;
        this->index = index;
    }
    Constructor Variable(int allocatorId, FuncNode index) { // 构造指针类型
        this->allocatorId = allocatorId;
        this->index = index;
    }
    // 拷贝函数
    Constructor Variable(const Variable &value) {
        index = allocate();
        if (index.getNode().isValue) Set(allocatorId, index, FuncNode("Get", { value.allocatorId, value.index }));
    }
    Constructor Variable(const Variable &value, int offset) {
        #ifndef COMPILE_RUNTIME
        this->index = FuncNode(value.index) + offset;
        #else
        this->index = value.index + offset;
        #endif
    }
    // 类型转换函数
    operator FuncNode() {
        return FuncNode("Get", { allocatorId, index });
    }
    operator FuncNode() const {
        return FuncNode("Get", { allocatorId, index });
    }
    #ifndef COMPILE_RUNTIME
    operator int() {
        return false;
    }
    #endif

    // 拷贝赋值
    Variable& operator = (FuncNode a) {
        Set(allocatorId, index, a);
        return *this;
    }
    Variable& operator = (double a) {
        Set(allocatorId, index, a);
        return *this;
    }
    Variable& operator = (const Variable &a) {
        Set(allocatorId, index, FuncNode("Get", { a.allocatorId, a.index }));
        return *this;
    }

    void reallocate(FuncNode index) {
        this->index = index;
    }
};

Variable& operator ++ (Variable &a) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) + 1);
    return a;
}

Variable& operator ++ (Variable &a, int) {
    auto res = a;
    ++a;
    return res;
}

Variable& operator -- (Variable &a) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) - 1);
    return a;
}

Variable& operator -- (Variable &a, int) {
    auto res = a;
    --a;
    return res;
}

Variable& operator += (Variable &a, FuncNode b) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) + b);
    return a;
}

Variable& operator -= (Variable &a, FuncNode b) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) - b);
    return a;
}

Variable& operator *= (Variable &a, FuncNode b) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) * b);
    return a;
}

Variable& operator /= (Variable &a, FuncNode b) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) / b);
    return a;
}

Variable& operator %= (Variable &a, FuncNode b) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) % b);
    return a;
}

Variable& operator &= (Variable &a, FuncNode b) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) & b);
    return a;
}

Variable& operator |= (Variable &a, FuncNode b) {
    Set(a.allocatorId, a.index, FuncNode("Get", { a.allocatorId, a.index }) | b);
    return a;
}

FuncNode GetValue(const Variable &v) {
    return FuncNode(v);
}

Variable GetPointer(int allocatorId, FuncNode index) {
    return Variable(allocatorId, index);
}


#endif