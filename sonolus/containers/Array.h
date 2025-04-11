#ifndef Array_H
#define Array_H

template<typename T, int size>
class Array {
    private:
    map<int, int> Tsize;
    map<int, FuncNode> index;
    int currentDefaultAllocatorId;

    public:
    Constructor Array() {
        currentDefaultAllocatorId = defaultAllocatorId;
        for (auto it = SonolusMemoryDelta.begin(); it != SonolusMemoryDelta.end(); it++)
            index[(*it).first] = SonolusMemoryIndex[(*it).first] + (*it).second;
        for (auto it = SonolusMemoryIndex.begin(); it != SonolusMemoryIndex.end(); it++)
            index[(*it).first] = SonolusMemoryDelta[(*it).first] + (*it).second;
        Tsize = SizeOf<T>();
        for (int i = 0; i < size; i++) T();
    }
    Constructor Array(const Array<T, size>& value) {
        currentDefaultAllocatorId = defaultAllocatorId;
        for (auto it = SonolusMemoryDelta.begin(); it != SonolusMemoryDelta.end(); it++)
            index[(*it).first] = SonolusMemoryIndex[(*it).first] + (*it).second;
        for (auto it = SonolusMemoryIndex.begin(); it != SonolusMemoryIndex.end(); it++)
            index[(*it).first] = SonolusMemoryDelta[(*it).first] + (*it).second;
        Tsize = SizeOf<T>();
        for (int i = 0; i < size; i++) T();
        for (int i = 0; i < size; i++) (*this)[i] = value[i];
    }

    T operator[] (FuncNode i) {
        int backupDefaultAllocatorId = defaultAllocatorId;
        defaultAllocatorId = currentDefaultAllocatorId;
        map<int, FuncNode> offsets;
        for (auto it = Tsize.begin(); it != Tsize.end(); it++) {
            int aId = (*it).first; FuncNode offset = index[aId] + i * (*it).second;
            offsets[aId] = offset;
        }
        auto backupSonolusMemoryIndex = SonolusMemoryIndex;
        auto backupSonolusMemoryDelta = SonolusMemoryDelta;
        SonolusMemoryIndex = offsets;
        SonolusMemoryDelta.clear();
        T res;
        SonolusMemoryIndex = backupSonolusMemoryIndex;
        SonolusMemoryDelta = backupSonolusMemoryDelta;
        defaultAllocatorId = backupDefaultAllocatorId;
        return res;
    }
    T operator[] (FuncNode i) const {
        return (*this)[i];
    }
    Array<T, size>& operator = (const Array<T, size>& value) {
        for (int i = 0; i < size; i++) (*this)[i] = value[i];
        return *this;
    }
};

template<typename T, int size> using Tuple = Array<T, size>;

#endif