#ifndef Quad_H
#define Quad_H

class Quadratic {
    public:

    Array<Variable, 4> x;
    Array<Variable, 4> y;

    Constructor Quadratic(){}
    Constructor Quadratic(const Rectangle &rect) {
        x[0] = rect.l; y[0] = rect.b;
        x[1] = rect.l; y[1] = rect.t;
        x[2] = rect.r; y[2] = rect.t;
        x[3] = rect.r; y[3] = rect.b;
    }
    Constructor Quadratic(const Vector &p1, const Vector &p2, const Vector &p3, const Vector &p4) {
        x[0] = p1.x, y[0] = p1.y;
        x[1] = p2.x, y[1] = p2.y;
        x[2] = p3.x, y[2] = p3.y;
        x[3] = p4.x, y[3] = p4.y;
    }
    Constructor Quadratic(FuncNode x1, FuncNode y1, FuncNode x2, FuncNode y2, FuncNode x3, FuncNode y3, FuncNode x4, FuncNode y4) {
        x[0] = x1, y[0] = y1;
        x[1] = x2, y[1] = y2;
        x[2] = x3, y[2] = y3;
        x[3] = x4, y[3] = y4;
    }

    Blocked Vector p1() {
        return Vector(x[0], y[0]);
    }
    Blocked Vector p2() {
        return Vector(x[1], y[1]);
    }
    Blocked Vector p3() {
        return Vector(x[2], y[2]);
    }
    Blocked Vector p4() {
        return Vector(x[3], y[3]);
    }
    Blocked Vector c() {
        return (p1() + p2() + p3() + p4()) / 4;
    }
    Blocked Vector c12() {
        return (p1() + p2()) / 2;
    }
    Blocked Vector c13() {
        return (p1() + p3()) / 2;
    }
    Blocked Vector c14() {
        return (p1() + p4()) / 2;
    }
    Blocked Vector c23() {
        return (p2() + p3()) / 2;
    }
    Blocked Vector c24() {
        return (p2() + p4()) / 2;
    }
    Blocked Vector c34() {
        return (p3() + p4()) / 2;
    }
    Blocked Rectangle aabb() {
        return Rectangle(
            FuncNode("Min", { x[0], FuncNode("Min", { x[1], FuncNode("Min", { x[2], x[3] }) }) }),
            FuncNode("Min", { y[0], FuncNode("Min", { y[1], FuncNode("Min", { y[2], y[3] }) }) }),
            FuncNode("Max", { x[0], FuncNode("Max", { x[1], FuncNode("Max", { x[2], x[3] }) }) }),
            FuncNode("Max", { y[0], FuncNode("Max", { y[1], FuncNode("Max", { y[2], y[3] }) }) })
        );
    }
    Blocked Quadratic add(const Vector &vec) {
        #ifdef COMPILE_RUNTIME
        return Quadratic(
            x[0] + vec.x, y[0] + vec.y,
            x[1] + vec.x, y[1] + vec.y,
            x[2] + vec.x, y[2] + vec.y,
            x[3] + vec.x, y[3] + vec.y
        );
        #endif
    }
    Blocked Quadratic sub(const Vector &vec) {
        #ifdef COMPILE_RUNTIME
        return Quadratic(
            x[0] - vec.x, y[0] - vec.y,
            x[1] - vec.x, y[1] - vec.y,
            x[2] - vec.x, y[2] - vec.y,
            x[3] - vec.x, y[3] - vec.y
        );
        #endif
    }
    Blocked Quadratic mul(FuncNode value) {
        return Quadratic(
            x[0] * value, y[0] * value,
            x[1] * value, y[1] * value,
            x[2] * value, y[2] * value,
            x[3] * value, y[3] * value
        );
    }
    Blocked Quadratic div(FuncNode value) {
        return Quadratic(
            x[0] / value, y[0] / value,
            x[1] / value, y[1] / value,
            x[2] / value, y[2] / value,
            x[3] / value, y[3] / value
        );
    }
    Blocked Quadratic translate(FuncNode x, FuncNode y) {
        Vec p0 = Vec(this->x[0], this->y[0]).translate(x, y);
        Vec p1 = Vec(this->x[1], this->y[1]).translate(x, y);
        Vec p2 = Vec(this->x[2], this->y[2]).translate(x, y);
        Vec p3 = Vec(this->x[3], this->y[3]).translate(x, y);
        return Quadratic(p0, p1, p2, p3);
    }
    Blocked Quadratic scale(FuncNode x, FuncNode y) {
        Vec p0 = Vec(this->x[0], this->y[0]).scale(x, y);
        Vec p1 = Vec(this->x[1], this->y[1]).scale(x, y);
        Vec p2 = Vec(this->x[2], this->y[2]).scale(x, y);
        Vec p3 = Vec(this->x[3], this->y[3]).scale(x, y);
        return Quadratic(p0, p1, p2, p3);
    }
    Blocked Quadratic rotate(FuncNode angle) {
        Vec p0 = Vec(x[0], y[0]).rotate(angle);
        Vec p1 = Vec(x[1], y[1]).rotate(angle);
        Vec p2 = Vec(x[2], y[2]).rotate(angle);
        Vec p3 = Vec(x[3], y[3]).rotate(angle);
        return Quadratic(p0, p1, p2, p3);
    }
    Blocked Quadratic transform(const Matrix &mat) {
        Vec p0 = Vec(x[0], y[0]).transform(mat);
        Vec p1 = Vec(x[1], y[1]).transform(mat);
        Vec p2 = Vec(x[2], y[2]).transform(mat);
        Vec p3 = Vec(x[3], y[3]).transform(mat);
        return Quadratic(p0, p1, p2, p3);
    }
    Blocked Quadratic swapRotate90() {
        return Quadratic(x[1], y[1], x[2], y[2], x[3], y[3], x[0], y[0]);
    }
    Blocked Quadratic swapRotate180() {
        return Quadratic(x[2], y[2], x[3], y[3], x[0], y[0], x[1], y[1]);
    }
    Blocked Quadratic swapRotate270() {
        return Quadratic(x[3], y[3], x[0], y[0], x[1], y[1], x[2], y[2]);
    }
    Blocked Quadratic swapMirrorY() {
        return Quadratic(x[3], y[3], x[2], y[2], x[1], y[1], x[0], y[0]);
    }
    Blocked Quadratic swapMirrorX() {
        return Quadratic(x[1], y[1], x[0], y[0], x[3], y[3], x[2], y[2]);
    }

    static Blocked Quadratic zero() {
        return Quadratic(0, 0, 0, 0, 0, 0, 0, 0);
    }
    static Blocked Quadratic one() {
        return Quadratic(-1, -1, -1, 1, 1, 1, 1, -1);
    }
    static Blocked Quadratic L() {
        return Quadratic(-1, -1, -1, 1, 0, 1, 0, -1);
    }
    static Blocked Quadratic B() {
        return Quadratic(-1, -1, -1, 0, 1, 0, 1, -1);
    }
    static Blocked Quadratic R() {
        return Quadratic(0, -1, 0, 1, 1, 1, 1, -1);
    }
    static Blocked Quadratic T() {
        return Quadratic(-1, 0, -1, 1, 1, 1, 1, 0);
    }
    static Blocked Quadratic LB() {
        return Quadratic(-1, -1, -1, 0, 0, 0, 0, -1);
    }
    static Blocked Quadratic RB() {
        return Quadratic(0, -1, 0, 0, 1, 0, 1, -1);
    }
    static Blocked Quadratic LT() {
        return Quadratic(-1, 0, -1, 1, 0, 1, 0, 0);
    }
    static Blocked Quadratic RT() {
        return Quadratic(0, 0, 0, 1, 1, 1, 1, 0);
    }

    Quadratic operator + (const Vector& vec) {
        return add(vec);
    }
    Quadratic operator - (const Vector& vec) {
        return sub(vec);
    }
    Quadratic operator * (FuncNode value) {
        return mul(value);
    }
    Quadratic operator / (FuncNode value) {
        return div(value);
    }
    Quadratic& operator += (const Vector &vec) {
        #ifdef COMPILE_RUNTIME
        x[0] = x[0] + vec.x, y[0] = y[0] + vec.y;
        x[1] = x[1] + vec.x, y[1] = y[1] + vec.y;
        x[2] = x[2] + vec.x, y[2] = y[2] + vec.y;
        x[3] = x[3] + vec.x, y[3] = y[3] + vec.y;
        #endif
        return *this;
    }
    Quadratic& operator -= (const Vector &vec) {
        #ifdef COMPILE_RUNTIME
        x[0] = x[0] - vec.x, y[0] = y[0] - vec.y;
        x[1] = x[1] - vec.x, y[1] = y[1] - vec.y;
        x[2] = x[2] - vec.x, y[2] = y[2] - vec.y;
        x[3] = x[3] - vec.x, y[3] = y[3] - vec.y;
        #endif
        return *this;
    }
    Quadratic& operator *= (FuncNode value) {
        x[0] = x[0] * value, y[0] = y[0] * value;
        x[1] = x[1] * value, y[1] = y[1] * value;
        x[2] = x[2] * value, y[2] = y[2] * value;
        x[3] = x[3] * value, y[3] = y[3] * value;
        return *this;
    }
    Quadratic& operator /= (FuncNode value) {
        x[0] = x[0] / value, y[0] = y[0] / value;
        x[1] = x[1] / value, y[1] = y[1] / value;
        x[2] = x[2] / value, y[2] = y[2] / value;
        x[3] = x[3] / value, y[3] = y[3] / value;
        return *this;
    }
    FuncNode operator == (const Quadratic &a) {
        return x[0] == a.x[0] && y[0] == a.y[0] && x[1] == a.x[1] && y[1] == a.y[1] &&
            x[2] == a.x[2] && y[2] == a.y[2] && x[3] == a.x[3] && y[3] == a.y[3];
    }
};

Blocked Quadratic lerp(const Quadratic &x, const Quadratic &y, FuncNode s) {
    return Quadratic(
        FuncNode("Lerp", { x.x[0], y.x[0], s }),
        FuncNode("Lerp", { x.y[0], y.y[0], s }),
        FuncNode("Lerp", { x.x[1], y.x[1], s }),
        FuncNode("Lerp", { x.y[1], y.y[1], s }),
        FuncNode("Lerp", { x.x[2], y.x[2], s }),
        FuncNode("Lerp", { x.y[2], y.y[2], s }),
        FuncNode("Lerp", { x.x[3], y.x[3], s }),
        FuncNode("Lerp", { x.y[3], y.y[3], s })
    );
}
Blocked Quadratic lerpClamped(const Quadratic &x, const Quadratic &y, FuncNode s) {
    return Quadratic(
        FuncNode("LerpClamped", { x.x[0], y.x[0], s }),
        FuncNode("LerpClamped", { x.y[0], y.y[0], s }),
        FuncNode("LerpClamped", { x.x[1], y.x[1], s }),
        FuncNode("LerpClamped", { x.y[1], y.y[1], s }),
        FuncNode("LerpClamped", { x.x[2], y.x[2], s }),
        FuncNode("LerpClamped", { x.y[2], y.y[2], s }),
        FuncNode("LerpClamped", { x.x[3], y.x[3], s }),
        FuncNode("LerpClamped", { x.y[3], y.y[3], s })
    );
}
Blocked Quadratic remap(FuncNode a, FuncNode b, const Quadratic &c, const Quadratic &d, FuncNode s) {
    return Quadratic(
        FuncNode("Remap", { a, b, c.x[0], d.x[0], s }),
        FuncNode("Remap", { a, b, c.y[0], d.y[0], s }),
        FuncNode("Remap", { a, b, c.x[1], d.x[1], s }),
        FuncNode("Remap", { a, b, c.y[1], d.y[1], s }),
        FuncNode("Remap", { a, b, c.x[2], d.x[2], s }),
        FuncNode("Remap", { a, b, c.y[2], d.y[2], s }),
        FuncNode("Remap", { a, b, c.x[3], d.x[3], s }),
        FuncNode("Remap", { a, b, c.y[3], d.y[3], s })
    );
}
Blocked Quadratic remapClamped(FuncNode a, FuncNode b, const Quadratic &c, const Quadratic &d, FuncNode s) {
    return Quadratic(
        FuncNode("RemapClamped", { a, b, c.x[0], d.x[0], s }),
        FuncNode("RemapClamped", { a, b, c.y[0], d.y[0], s }),
        FuncNode("RemapClamped", { a, b, c.x[1], d.x[1], s }),
        FuncNode("RemapClamped", { a, b, c.y[1], d.y[1], s }),
        FuncNode("RemapClamped", { a, b, c.x[2], d.x[2], s }),
        FuncNode("RemapClamped", { a, b, c.y[2], d.y[2], s }),
        FuncNode("RemapClamped", { a, b, c.x[3], d.x[3], s }),
        FuncNode("RemapClamped", { a, b, c.y[3], d.y[3], s })
    );
}

using Quad = Quadratic;

#endif