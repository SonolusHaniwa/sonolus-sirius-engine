class Vec {
    CLASSBEGIN
    
    defineVar(var, x, var());
    defineVar(var, y, var());
    Vec(){}
    Vec(var x, var y): x(x), y(y){}

    Vec operator + (Vec v) {
        return Vec(x + v.x, y + v.y);
    };
    Vec operator - (Vec v) {
        return Vec(x - v.x, y - v.y);
    };
    var operator * (Vec v) {
        return x * v.x + y * v.y;
    };
    var operator ^ (Vec v) {
        return x * v.y - y * v.x;
    }
};

class Rect {
	CLASSBEGIN

	defineVar(var, l, var());
	defineVar(var, r, var());
	defineVar(var, b, var());
	defineVar(var, t, var());

	var contain(var x, var y) {
		return l <= x && x <= r && b <= y && y <= t;
	}
};
