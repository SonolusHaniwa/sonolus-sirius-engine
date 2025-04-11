#ifndef Range_H
#define Range_H

class Range {
    public:

    Variable min;
    Variable max;

    Constructor Range(){}
    Constructor Range(FuncNode x, FuncNode y) {
        min = x;
        max = y;
    }

    Blocked FuncNode length() {
        return max - min;
    }
    Blocked Range mirror() {
        return Range(-max, -min);
    }
    Blocked Range add(FuncNode val) {
        return Range(min + val, max + val);
    }
    Blocked Range sub(FuncNode val) {
        return Range(min - val, max - val);
    }
    Blocked Range mul(FuncNode val) {
        return Range(min * val, max * val);
    }
    Blocked Range div(FuncNode val) {
        return Range(min / val, max / val);
    }
    Blocked Range translate(FuncNode val) {
        return Range(min + val, max + val);
    }
    Blocked Range scale(FuncNode val) {
        return Range(min * val, max * val);
    }
    Blocked Range expand(FuncNode val) {
        return Range(min - val, max + val);
    }
    Blocked Range shrink(FuncNode val) {
        return Range(min + val, max - val);
    }
    Blocked FuncNode contains(FuncNode val) {
        return min <= val && val <= max;
    }

    static Blocked Range zero() {
        return Range(0, 0);
    }
    static Blocked Range one() {
        return Range(-1, 1);
    }
    static Blocked Range L() {
        return Range(-1, 0);
    }
    static Blocked Range R() {
        return Range(0, 1);
    }

    Range operator + (FuncNode a) {
        return add(a);
    }
    Range operator - (FuncNode a) {
        return sub(a);
    }
    Range operator - () {
        min = -max;
        max = -min;
        return *this;
    }
    Range operator * (FuncNode a) {
        return mul(a);
    }
    Range operator / (FuncNode a) {
        return div(a);
    }
    Range& operator += (const Range &a) {
        min += a.min; max += a.max;
        return *this;
    }
    // Range& operator -= (const Range &a) {
    //     min -= a.min; max -= a.max;
    //     return *this;
    // }
    Range& operator *= (const Range &a) {
        min *= a.min; max *= a.max;
        return *this;
    }
    // Range& operator /= (const Range &a) {
    //     min /= a.min; max /= a.max;
    //     return *this;
    // }
    Range& operator ++ () {
        min++; max++;
        return *this;
    }
    Range& operator ++ (int) {
        auto res = (*this);
        ++(*this);
        return res;
    }
    Range& operator -- () {
        min--; max--;
        return *this;
    }
    Range& operator -- (int) {
        auto res = (*this);
        --(*this);
        return res;
    }
    FuncNode operator == (const Range &a) {
        #ifdef COMPILE_RUNTIME
        return min == a.min && max == a.max;
        #endif
    }
};

Blocked Range lerp(const Range &x, const Range &y, FuncNode s) {
    return Range(
        FuncNode("Lerp", { x.min, y.min, s }),
        FuncNode("Lerp", { x.max, y.max, s })
    );
}
Blocked Range lerpClamped(const Range &x, const Range &y, FuncNode s) {
    return Range(
        FuncNode("LerpClamped", { x.min, y.min, s }),
        FuncNode("LerpClamped", { x.max, y.max, s })
    );
}
Blocked Range remap(FuncNode a, FuncNode b, const Range &c, const Range &d, FuncNode s) {
    return Range(
        FuncNode("Remap", { a, b, c.min, d.min, s }),
        FuncNode("Remap", { a, b, c.max, d.max, s })
    );
}
Blocked Range remapClamped(FuncNode a, FuncNode b, const Range &c, const Range &d, FuncNode s) {
    return Range(
        FuncNode("RemapClamped", { a, b, c.min, d.min, s }),
        FuncNode("RemapClamped", { a, b, c.max, d.max, s })
    );
}

using Rg = Range;

#endif