class Vec {
    CLASSBEGIN
    
    defineVar(let, x, 0);
    defineVar(let, y, 0);
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

	defineVar(let, l, 0);
	defineVar(let, r, 0);
	defineVar(let, b, 0);
	defineVar(let, t, 0);

	let contain(let x, let y) {
		return l <= x && x <= r && b <= y && y <= t;
	}
};
