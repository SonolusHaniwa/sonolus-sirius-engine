#ifndef Tuple_H
#define Tuple_H

template<typename T>
class Tuple {
    public:

    T arg;
};

template<typename T, typename... Args>
class Tuple: private Tuple<Args> {
    public:

    T arg;
};

#endif