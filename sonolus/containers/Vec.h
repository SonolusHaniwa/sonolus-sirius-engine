#ifndef Vec_H
#define Vec_H

class Vector {
    public:

    Variable x;
    Variable y;

    Constructor Vector(){}
    Constructor Vector(FuncNode x, FuncNode y) {
        this->x = x;
        this->y = y;
    }

    Blocked FuncNode length() {
        return FuncNode("Power", { x * x + y * y });
    }
    Blocked Vector add(const Vector &vec) const {
        #ifdef COMPILE_RUNTIME
        return Vector(x + vec.x, y + vec.y);
        #endif
    }
    Blocked Vector sub(const Vector &vec) const {
        #ifdef COMPILE_RUNTIME
        return Vector(x - vec.x, y - vec.y);
        #endif
    }
    Blocked Vector mul(FuncNode val) {
        return Vector(x * val, y * val);
    }
    Blocked Vector div(FuncNode val) {
        return Vector(x / val, y / val);
    }
    Blocked Vector translate(FuncNode x, FuncNode y) {
        return Vector(this->x + x, this->y + y);
    }
    Blocked Vector scale(FuncNode x, FuncNode y) {
        return Vector(this->x * x, this->y * y);
    }
    Blocked Vector rotate(FuncNode angle) {
        FuncNode c = FuncNode("Cos", { angle });
        FuncNode s = FuncNode("Sin", { angle });
        return Vector(c * x - s * y, s * x + c * y);
    }
    Blocked Vector transform(const Matrix &mat) {
        FuncNode m[4][4];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) m[i][j] = mat.m[i][j];
        return Vector(x * m[0][0] + y * m[0][1] + m[0][3], x * m[1][0] + y * m[1][1] + m[1][3]);
    }

    static Blocked Vector zero() {
        return Vector(0, 0);
    }
    static Blocked Vector one() {
        return Vector(1, 1);
    }
    static Blocked Vector L() {
        return Vector(-1, 0);
    }
    static Blocked Vector R() {
        return Vector(1, 0);
    }
    static Blocked Vector B() {
        return Vector(0, -1);
    }
    static Blocked Vector T() {
        return Vector(0, 1);
    }
    static Blocked Vector LB() {
        return Vector(-1, -1);
    }
    static Blocked Vector RB() {
        return Vector(1, -1);
    }
    static Blocked Vector LT() {
        return Vector(-1, 1);
    }
    static Blocked Vector RT() {
        return Vector(1, 1);
    }

    Vector operator + (const Vector &a) const {
        return add(a);
    }
    Vector operator - (const Vector &a) const {
        return sub(a);
    }
    Vector operator - () {
        return Vector::zero().sub(*this);
    }
    Vector operator * (FuncNode a) {
        return mul(a);
    }
    Vector operator / (FuncNode a) {
        return div(a);
    }
    Vector& operator += (const Vector &a) {
        x += a.x; y += a.y;
        return *this;
    }
    Vector& operator -= (const Vector &a) {
        x -= a.x; y -= a.y;
        return *this;
    }
    Vector& operator *= (const Vector &a) {
        x *= a.x; y *= a.y;
        return *this;
    }
    Vector& operator /= (const Vector &a) {
        x /= a.x; y /= a.y;
        return *this;
    }
    Vector& operator ++ () {
        x++; y++;
        return *this;
    }
    Vector& operator ++ (int) {
        auto res = (*this);
        ++(*this);
        return res;
    }
    Vector& operator -- () {
        x--; y--;
        return *this;
    }
    Vector& operator -- (int) {
        auto res = (*this);
        --(*this);
        return res;
    }
    FuncNode operator == (const Vector &a) {
        #ifdef COMPILE_RUNTIME
        return x == a.x && y == a.y;
        #endif
    }

    operator Draw_Group_x_y() { return { x, y }; }
    operator DrawCurvedBT_Group_x_y() { return { x, y }; }
    operator DrawCurvedL_Group_x_y() { return { x, y }; }
    operator DrawCurvedLR_Group_x_y() { return { x, y }; }
    operator DrawCurvedR_Group_x_y() { return { x, y }; }
    operator DrawCurvedT_Group_x_y() { return { x, y }; }
    operator MoveParticleEffect_Group_x_y() { return { x, y }; }
    operator SpawnParticleEffect_Group_x_y() { return { x, y }; }
};

Blocked Vector lerp(const Vector &x, const Vector &y, FuncNode s) {
    return Vector(
        FuncNode("Lerp", { x.x, y.x, s }),
        FuncNode("Lerp", { x.y, y.y, s })
    );
}
Blocked Vector lerpClamped(const Vector &x, const Vector &y, FuncNode s) {
    return Vector(
        FuncNode("LerpClamped", { x.x, y.x, s }),
        FuncNode("LerpClamped", { x.y, y.y, s })
    );
}
Blocked Vector remap(FuncNode a, FuncNode b, const Vector &c, const Vector &d, FuncNode s) {
    return Vector(
        FuncNode("Remap", { a, b, c.x, d.x, s }),
        FuncNode("Remap", { a, b, c.y, d.y, s })
    );
}
Blocked Vector remapClamped(FuncNode a, FuncNode b, const Vector &c, const Vector &d, FuncNode s) {
    return Vector(
        FuncNode("RemapClamped", { a, b, c.x, d.x, s }),
        FuncNode("RemapClamped", { a, b, c.y, d.y, s })
    );
}

using Vec = Vector;

#endif