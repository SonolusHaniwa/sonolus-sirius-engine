#ifndef Rect_H
#define Rect_H

class Rectangle {
    public:

    Variable l;
    Variable b;
    Variable r;
    Variable t;

    Constructor Rectangle(){}
    Constructor Rectangle(FuncNode l, FuncNode b, FuncNode r, FuncNode t) {
        this->l = l;
        this->b = b;
        this->r = r;
        this->t = t;
    }

    Blocked FuncNode w() {
        return r - l;
    }
    Blocked FuncNode h() {
        return t - b;
    }
    Blocked FuncNode aspectRatio() {
        return w() / h();
    }
    Blocked Vector c() {
        return Vector((l + r) / 2, (b + t) / 2);
    }
    Blocked Vector cl() {
        return Vector(l, (b + t) / 2);
    }
    Blocked Vector cb() {
        return Vector((l + r) / 2, b);
    }
    Blocked Vector cr() {
        return Vector(r, (b + t) / 2);
    }
    Blocked Vector ct() {
        return Vector((l + r) / 2, t);
    }
    Blocked Vector lb() {
        return Vector(l, b);
    }
    Blocked Vector rb() {
        return Vector(r, b);
    }
    Blocked Vector lt() {
        return Vector(l, t);
    }
    Blocked Vector rt() {
        return Vector(r, t);
    }
    Blocked Rectangle add(const Vector &vec) {
        #ifdef COMPILE_RUNTIME
        return Rectangle(
            l + vec.x, b + vec.y,
            r + vec.x, t + vec.y
        );
        #endif
    }
    Blocked Rectangle sub(const Vector &vec) {
        #ifdef COMPILE_RUNTIME
        return Rectangle(
            l - vec.x, b - vec.y,
            r - vec.x, t - vec.y
        );
        #endif
    }
    Blocked Rectangle mul(FuncNode value) {
        return Rectangle(
            l * value, b * value,
            r * value, t * value
        );
    }
    Blocked Rectangle div(FuncNode value) {
        return Rectangle(
            l / value, b / value,
            r / value, t / value
        );
    }
    Blocked Rectangle translate(FuncNode x, FuncNode y) {
        Vec lbv = Vec(l, b).translate(x, y);
        Vec rtv = Vec(r, t).translate(x, y);
        return Rectangle(lbv.x, lbv.y, rtv.x, rtv.y);
    }
    Blocked Rectangle scale(FuncNode x, FuncNode y) {
        Vec lbv = Vec(l, b).scale(x, y);
        Vec rtv = Vec(r, t).scale(x, y);
        return Rectangle(lbv.x, lbv.y, rtv.x, rtv.y);
    }
    Blocked Rectangle rotate(FuncNode angle) {
        Vec lbv = Vec(l, b).rotate(angle);
        Vec rtv = Vec(r, t).rotate(angle);
        return Rectangle(lbv.x, lbv.y, rtv.x, rtv.y);
    }
    Blocked Rectangle transform(const Matrix &mat) {
        Vec lbv = Vec(l, b).transform(mat);
        Vec rtv = Vec(r, t).transform(mat);
        return Rectangle(lbv.x, lbv.y, rtv.x, rtv.y);
    }
    Blocked Rectangle expand(FuncNode x, FuncNode y) {
        return Rectangle(l - x, b - y, r + x, t + y);
    }
    Blocked Rectangle shrink(FuncNode x, FuncNode y) {
        return Rectangle(l + x, b + y, r - x, t - y);
    }
    Blocked FuncNode contains(const Vector &vec) {
        #ifdef COMPILE_RUNTIME
        return l < vec.x && vec.x < r && b < vec.y && vec.y < t;
        #endif
    }
    Blocked FuncNode overlaps(const Rectangle &rect) {
        #ifdef COMPILE_RUNTIME
        return rect.b < t && b < rect.t && rect.l < r && rect.r < l;
        #endif
    }

    static Blocked Rectangle zero() {
        return Rectangle(0, 0, 0, 0);
    }
    static Blocked Rectangle one() {
        return Rectangle(-1, -1, 1, 1);
    }
    static Blocked Rectangle L() {
        return Rectangle(-1, -1, 0, 1);
    }
    static Blocked Rectangle B() {
        return Rectangle(-1, -1, 1, 0);
    }
    static Blocked Rectangle R() {
        return Rectangle(0, -1, 1, 1);
    }
    static Blocked Rectangle T() {
        return Rectangle(-1, 0, 1, 1);
    }
    static Blocked Rectangle LB() {
        return Rectangle(-1, -1, 0, 0);
    }
    static Blocked Rectangle RB() {
        return Rectangle(0, -1, 1, 0);
    }
    static Blocked Rectangle LT() {
        return Rectangle(-1, 0, 0, 1); 
    }
    static Blocked Rectangle RT() {
        return Rectangle(0, 0, 1, 1);
    }
    
    Rectangle operator + (const Vector &vec) {
        return add(vec);
    }
    Rectangle operator - (const Vector &vec) {
        return sub(vec);
    }
    Rectangle operator * (FuncNode value) {
        return mul(value);
    }
    Rectangle operator / (FuncNode value) {
        return div(value);
    }
    Rectangle& operator += (const Vector &vec) {
        l += vec.x, b += vec.y;
        r += vec.x, t += vec.y;
        return *this;
    }
    Rectangle& operator -= (const Vector &vec) {
        l -= vec.x, b -= vec.y;
        r -= vec.x, t -= vec.y;
        return *this;
    }
    Rectangle& operator *= (FuncNode value) {
        l *= value, b *= value;
        r *= value, t *= value;
        return *this;
    }
    Rectangle& operator /= (FuncNode value) {
        l /= value, b /= value;
        r /= value, t /= value;
        return *this;
    }
    FuncNode operator == (const Rectangle &a) {
        #ifdef COMPILE_RUNTIME
        return l == a.l && r == a.r && b == a.b && t == a.t;
        #endif
    }
};

Blocked Rectangle lerp(const Rectangle &x, const Rectangle &y, FuncNode s) {
    return Rectangle(
        FuncNode("Lerp", { x.l, y.l, s }),
        FuncNode("Lerp", { x.b, y.b, s }),
        FuncNode("Lerp", { x.r, y.r, s }),
        FuncNode("Lerp", { x.t, y.t, s })
    );
}
Blocked Rectangle lerpClamped(const Rectangle &x, const Rectangle &y, FuncNode s) {
    return Rectangle(
        FuncNode("LerpClamped", { x.l, y.l, s }),
        FuncNode("LerpClamped", { x.b, y.b, s }),
        FuncNode("LerpClamped", { x.r, y.r, s }),
        FuncNode("LerpClamped", { x.t, y.t, s })
    );
}
Blocked Rectangle remap(FuncNode a, FuncNode b, const Rectangle &c, const Rectangle &d, FuncNode s) {
    return Rectangle(
        FuncNode("Remap", { a, b, c.l, d.l, s }),
        FuncNode("Remap", { a, b, c.b, d.b, s }),
        FuncNode("Remap", { a, b, c.r, d.r, s }),
        FuncNode("Remap", { a, b, c.t, d.t, s })
    );
}
Blocked Rectangle remapClamped(FuncNode a, FuncNode b, const Rectangle &c, const Rectangle &d, FuncNode s) {
    return Rectangle(
        FuncNode("RemapClamped", { a, b, c.l, d.l, s }),
        FuncNode("RemapClamped", { a, b, c.b, d.b, s }),
        FuncNode("RemapClamped", { a, b, c.r, d.r, s }),
        FuncNode("RemapClamped", { a, b, c.t, d.t, s })
    );
}

using Rect = Rectangle;

#endif