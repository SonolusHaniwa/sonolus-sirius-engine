#ifndef Dictionary_H
#define Dictionary_H

template<typename T1, typename T2, int size>
class Dictionary {
    public:

    Variable count;
    Array<T1, size> keys = Array<T1, size>();
    Array<T2, size> values = Array<T2, size>();

    Constructor Dictionary(){}

    Blocked T1 getKey(FuncNode i) {
        return keys[i];
    }
    Blocked T2 getValue(FuncNode i) {
        return values[i];
    }
    Blocked SonolusApi has(const T1 &key) {
        for (Variable i = 0; i < count; i++) 
            if (keys[i] == key) return true;
        return false;
    }
    Blocked SonolusApi indexOf(const T1 &key) {
        for (Variable i = 0; i < count; i++) 
            if (keys[i] == key) return i;
        return -1;
    }
    Blocked SonolusApi set(const T1 &key, const T2 &value) {
        Variable index = indexOf(key);
        if (index == -1) {
            keys[count] = key;
            values[count] = value;
            count++;
        } else values[index] = value;
    }
    Blocked SonolusApi clear() {
        count = 0;
    }

    T2 operator [] (const T1 &key) {
        Variable id = indexOf(key);
        return getValue(id);
    }
};

template<typename T1, typename T2, int size> using Map = Dictionary<T1, T2, size>;

#endif