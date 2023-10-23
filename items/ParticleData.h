#ifndef PARTICLEDATA_H
#define PARTICLEDATA_H

class TransformExpression {
	public:
	vector<pair<string, double> > expression;

	Json::Value toJsonObject() {
		Json::Value json;
		for (int i = 0 ; i < expression.size(); i++)
			json[expression[i].first] = expression[i].second;
		return json;
	}
};

class TransformExpressionInput {
	public:
	string name = "";
	double multiplier = 1;

	TransformExpressionInput(string name): name(name){}
	TransformExpressionInput operator * (double multiplier) {
		this->multiplier *= multiplier;
		return (*this);
	}
	operator TransformExpression() {
		TransformExpression exp;
		exp.expression.push_back({name, multiplier});
		return exp;
	}
};

TransformExpression operator + (TransformExpression exp, TransformExpressionInput input) {
	exp.expression.push_back({input.name, input.multiplier});
	return exp;
}
TransformExpression operator - (TransformExpression exp, TransformExpressionInput input) {
	exp.expression.push_back({input.name, -1 * input.multiplier});
	return exp;
}
TransformExpression operator + (TransformExpressionInput input1, TransformExpressionInput input2) {
	TransformExpression exp;
	exp.expression.push_back({input1.name, input1.multiplier});
	exp.expression.push_back({input2.name, input2.multiplier});
	return exp;
}
TransformExpression operator - (TransformExpressionInput input1, TransformExpressionInput input2) {
	TransformExpression exp;
	exp.expression.push_back({input1.name, input1.multiplier});
	exp.expression.push_back({input2.name, -1 * input2.multiplier});
	return exp;
}

class ParticleSpriteProperty {
	public:
	TransformExpression from;
	TransformExpression to;
	string ease;

	Json::Value toJsonObject() {
		Json::Value res;
		res["from"] = from.toJsonObject();
		res["to"] = to.toJsonObject();
		res["ease"] = ease;
		return res;
	}
};
class ParticleDataEffectSprite {
	public:
	int sprite = 0;
	string color = "#fff";
	double start = 0;
	double duration = 1;
	ParticleSpriteProperty x;
	ParticleSpriteProperty y;
	ParticleSpriteProperty w;
	ParticleSpriteProperty h;
	ParticleSpriteProperty r;
	ParticleSpriteProperty a;
	
	Json::Value toJsonObject() {
		Json::Value res;
		res["sprite"] = sprite;
		res["color"] = color;
		res["start"] = start;
		res["duration"] = duration;
		res["x"] = x.toJsonObject();
		res["y"] = y.toJsonObject();
		res["w"] = w.toJsonObject();
		res["h"] = h.toJsonObject();
		res["r"] = r.toJsonObject();
		res["a"] = a.toJsonObject();
		return res;
	}
};
class ParticleDataEffect {
	public:
	string name;
	TransformExpression x1, y1, x2, y2, x3, y3, x4, y4;
	vector<pair<int, vector<ParticleDataEffectSprite> > > groups;

	Json::Value toJsonObject() {
		Json::Value res;
		res["name"] = name;
		res["transform"]["x1"] = x1.toJsonObject();
		res["transform"]["y1"] = y1.toJsonObject();
		res["transform"]["x2"] = x2.toJsonObject();
		res["transform"]["y2"] = y2.toJsonObject();
		res["transform"]["x3"] = x3.toJsonObject();
		res["transform"]["y3"] = y3.toJsonObject();
		res["transform"]["x4"] = x4.toJsonObject();
		res["transform"]["y4"] = y4.toJsonObject();
		res["groups"].resize(0);
		for (int i = 0; i < groups.size(); i++) {
			res["groups"][i]["count"] = groups[i].first;
			res["groups"][i]["particles"].resize(0);
			for (int j = 0; j < groups[i].second.size(); j++) 
				res["groups"][i]["particles"].append(groups[i].second[j].toJsonObject());
		} return res;
	}
};

vector<string> Sprites;
vector<ParticleDataEffect> effects;
#define defineSprite(name) int name = [](){Sprites.push_back(#name);return Sprites.size() - 1;}()
void defineEffect(ParticleDataEffect effect) { effects.push_back(effect); }

namespace particleData {
	TransformExpressionInput c("c");
	TransformExpressionInput x1("x1"), y1("y1"), x2("x2"), y2("y2"), x3("x3"), y3("y3"), x4("x4"), y4("y4");
	TransformExpressionInput r1("r1"), r2("r2"), r3("r3"), r4("r4");
	TransformExpressionInput sinr1("sinr1"), sinr2("sinr2"), sinr3("sinr3"), sinr4("sinr4");
	TransformExpressionInput cosr1("cosr1"), cosr2("cosr2"), cosr3("cosr3"), cosr4("cosr4");
};

#endif
