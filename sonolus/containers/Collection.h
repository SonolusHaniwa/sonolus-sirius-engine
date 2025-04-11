#ifndef Collection_H
#define Collection_H

template<typename T, int size>
class Collection {
    public:

    Variable count;
    Array<T, size> array = Array<T, size>();

    Constructor Collection(){}

    Blocked T get(FuncNode i) {
        return array[i];
    }
    Blocked SonolusApi add(const T &value) {
        array[count++] = value;
    }
    Blocked SonolusApi has(const T &value) {
        for (Variable i = 0; i < count; i++)
            if (value == array[i]) return true;
        return false;
    }
    Blocked SonolusApi indexOf(const T &value) {
        for (Variable i = 0; i < count; i++) 
            if (value == array[i]) return i;
        return -1;
    }
    Blocked SonolusApi clear() {
        count = 0;
    }

    T operator[] (FuncNode i) {
        return array[i];
    }
};

#endif