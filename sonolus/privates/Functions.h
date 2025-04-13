#ifndef Functions_H
#define Functions_H

#define default default_value

FuncNode Abs(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Abs", args);
	return code;
}

FuncNode Add(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Add\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Add", args);
	return code;
}

FuncNode And(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"And\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("And", args);
	return code;
}

FuncNode Arccos(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Arccos", args);
	return code;
}

FuncNode Arcsin(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Arcsin", args);
	return code;
}

FuncNode Arctan(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Arctan", args);
	return code;
}

FuncNode Arctan2(FuncNode y, FuncNode x) {
	vector<FuncNode> args;
	args.push_back(y);
	args.push_back(x);
	FuncNode code = FuncNode("Arctan2", args);
	return code;
}

FuncNode BeatToBPM(FuncNode beat) {
	vector<FuncNode> args;
	args.push_back(beat);
	FuncNode code = FuncNode("BeatToBPM", args);
	return code;
}

FuncNode BeatToStartingBeat(FuncNode beat) {
	vector<FuncNode> args;
	args.push_back(beat);
	FuncNode code = FuncNode("BeatToStartingBeat", args);
	return code;
}

FuncNode BeatToStartingTime(FuncNode beat) {
	vector<FuncNode> args;
	args.push_back(beat);
	FuncNode code = FuncNode("BeatToStartingTime", args);
	return code;
}

FuncNode BeatToTime(FuncNode beat) {
	vector<FuncNode> args;
	args.push_back(beat);
	FuncNode code = FuncNode("BeatToTime", args);
	return code;
}

FuncNode Block(FuncNode body) {
	vector<FuncNode> args;
	args.push_back(body);
	FuncNode code = FuncNode("Block", args);
	return code;
}

FuncNode Break(FuncNode count, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(count);
	args.push_back(value);
	FuncNode code = FuncNode("Break", args);
	SonolusRun(code);
	return code;
}

FuncNode Ceil(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Ceil", args);
	return code;
}

FuncNode Clamp(FuncNode x, FuncNode a, FuncNode b) {
	vector<FuncNode> args;
	args.push_back(x);
	args.push_back(a);
	args.push_back(b);
	FuncNode code = FuncNode("Clamp", args);
	return code;
}

FuncNode Copy(FuncNode srcId, FuncNode srcIndex, FuncNode dstId, FuncNode dstIndex, FuncNode count) {
	vector<FuncNode> args;
	args.push_back(srcId);
	args.push_back(srcIndex);
	args.push_back(dstId);
	args.push_back(dstIndex);
	args.push_back(count);
	FuncNode code = FuncNode("Copy", args);
	SonolusRun(code);
	return code;
}

FuncNode Cos(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Cos", args);
	return code;
}

FuncNode Cosh(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Cosh", args);
	return code;
}

FuncNode DebugLog(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("DebugLog", args);
	SonolusRun(code);
	return code;
}

FuncNode DebugPause() {
	vector<FuncNode> args;
	FuncNode code = FuncNode("DebugPause", args);
	SonolusRun(code);
	return code;
}

FuncNode DecrementPost(FuncNode id, FuncNode index) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	FuncNode code = FuncNode("DecrementPost", args);
	SonolusRun(code);
	return code;
}

FuncNode DecrementPostPointed(FuncNode id, FuncNode index, FuncNode offset) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	FuncNode code = FuncNode("DecrementPostPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode DecrementPostShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	FuncNode code = FuncNode("DecrementPostShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode DecrementPre(FuncNode id, FuncNode index) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	FuncNode code = FuncNode("DecrementPre", args);
	SonolusRun(code);
	return code;
}

FuncNode DecrementPrePointed(FuncNode id, FuncNode index, FuncNode offset) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	FuncNode code = FuncNode("DecrementPrePointed", args);
	SonolusRun(code);
	return code;
}

FuncNode DecrementPreShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	FuncNode code = FuncNode("DecrementPreShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode Degree(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Degree", args);
	return code;
}

FuncNode DestroyParticleEffect(FuncNode particleId) {
	vector<FuncNode> args;
	args.push_back(particleId);
	FuncNode code = FuncNode("DestroyParticleEffect", args);
	SonolusRun(code);
	return code;
}

FuncNode Divide(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Divide\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Divide", args);
	return code;
}

FuncNode DoWhile(FuncNode body, FuncNode test) {
	vector<FuncNode> args;
	args.push_back(body);
	args.push_back(test);
	FuncNode code = FuncNode("DoWhile", args);
	return code;
}

struct Draw_Group_x_y{
	FuncNode x;
	FuncNode y;
};
FuncNode Draw(FuncNode id, Draw_Group_x_y x_y0, Draw_Group_x_y x_y1, Draw_Group_x_y x_y2, Draw_Group_x_y x_y3, FuncNode z, FuncNode a) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(z);
	args.push_back(a);
	FuncNode code = FuncNode("Draw", args);
	SonolusRun(code);
	return code;
}

struct DrawCurvedB_Group_x_y{
	FuncNode x;
	FuncNode y;
};
FuncNode DrawCurvedB(FuncNode id, DrawCurvedB_Group_x_y x_y0, DrawCurvedB_Group_x_y x_y1, DrawCurvedB_Group_x_y x_y2, DrawCurvedB_Group_x_y x_y3, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(z);
	args.push_back(a);
	args.push_back(n);
	args.push_back(p);
	args.push_back(q);
	FuncNode code = FuncNode("DrawCurvedB", args);
	SonolusRun(code);
	return code;
}

struct DrawCurvedBT_Group_x_y{
	FuncNode x;
	FuncNode y;
};
struct DrawCurvedBT_Group_p_q{
	FuncNode p;
	FuncNode q;
};
FuncNode DrawCurvedBT(FuncNode id, DrawCurvedBT_Group_x_y x_y0, DrawCurvedBT_Group_x_y x_y1, DrawCurvedBT_Group_x_y x_y2, DrawCurvedBT_Group_x_y x_y3, FuncNode z, FuncNode a, FuncNode n, DrawCurvedBT_Group_p_q p_q0, DrawCurvedBT_Group_p_q p_q1) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(z);
	args.push_back(a);
	args.push_back(n);
	args.push_back(p_q0.p);
	args.push_back(p_q0.q);
	args.push_back(p_q1.p);
	args.push_back(p_q1.q);
	FuncNode code = FuncNode("DrawCurvedBT", args);
	SonolusRun(code);
	return code;
}

struct DrawCurvedL_Group_x_y{
	FuncNode x;
	FuncNode y;
};
FuncNode DrawCurvedL(FuncNode id, DrawCurvedL_Group_x_y x_y0, DrawCurvedL_Group_x_y x_y1, DrawCurvedL_Group_x_y x_y2, DrawCurvedL_Group_x_y x_y3, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(z);
	args.push_back(a);
	args.push_back(n);
	args.push_back(p);
	args.push_back(q);
	FuncNode code = FuncNode("DrawCurvedL", args);
	SonolusRun(code);
	return code;
}

struct DrawCurvedLR_Group_x_y{
	FuncNode x;
	FuncNode y;
};
struct DrawCurvedLR_Group_p_q{
	FuncNode p;
	FuncNode q;
};
FuncNode DrawCurvedLR(FuncNode id, DrawCurvedLR_Group_x_y x_y0, DrawCurvedLR_Group_x_y x_y1, DrawCurvedLR_Group_x_y x_y2, DrawCurvedLR_Group_x_y x_y3, FuncNode z, FuncNode a, FuncNode n, DrawCurvedLR_Group_p_q p_q0, DrawCurvedLR_Group_p_q p_q1) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(z);
	args.push_back(a);
	args.push_back(n);
	args.push_back(p_q0.p);
	args.push_back(p_q0.q);
	args.push_back(p_q1.p);
	args.push_back(p_q1.q);
	FuncNode code = FuncNode("DrawCurvedLR", args);
	SonolusRun(code);
	return code;
}

struct DrawCurvedR_Group_x_y{
	FuncNode x;
	FuncNode y;
};
FuncNode DrawCurvedR(FuncNode id, DrawCurvedR_Group_x_y x_y0, DrawCurvedR_Group_x_y x_y1, DrawCurvedR_Group_x_y x_y2, DrawCurvedR_Group_x_y x_y3, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(z);
	args.push_back(a);
	args.push_back(n);
	args.push_back(p);
	args.push_back(q);
	FuncNode code = FuncNode("DrawCurvedR", args);
	SonolusRun(code);
	return code;
}

struct DrawCurvedT_Group_x_y{
	FuncNode x;
	FuncNode y;
};
FuncNode DrawCurvedT(FuncNode id, DrawCurvedT_Group_x_y x_y0, DrawCurvedT_Group_x_y x_y1, DrawCurvedT_Group_x_y x_y2, DrawCurvedT_Group_x_y x_y3, FuncNode z, FuncNode a, FuncNode n, FuncNode p, FuncNode q) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(z);
	args.push_back(a);
	args.push_back(n);
	args.push_back(p);
	args.push_back(q);
	FuncNode code = FuncNode("DrawCurvedT", args);
	SonolusRun(code);
	return code;
}

FuncNode EaseInBack(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInBack", args);
	return code;
}

FuncNode EaseInCirc(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInCirc", args);
	return code;
}

FuncNode EaseInCubic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInCubic", args);
	return code;
}

FuncNode EaseInElastic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInElastic", args);
	return code;
}

FuncNode EaseInExpo(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInExpo", args);
	return code;
}

FuncNode EaseInOutBack(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutBack", args);
	return code;
}

FuncNode EaseInOutCirc(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutCirc", args);
	return code;
}

FuncNode EaseInOutCubic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutCubic", args);
	return code;
}

FuncNode EaseInOutElastic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutElastic", args);
	return code;
}

FuncNode EaseInOutExpo(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutExpo", args);
	return code;
}

FuncNode EaseInOutQuad(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutQuad", args);
	return code;
}

FuncNode EaseInOutQuart(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutQuart", args);
	return code;
}

FuncNode EaseInOutQuint(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutQuint", args);
	return code;
}

FuncNode EaseInOutSine(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInOutSine", args);
	return code;
}

FuncNode EaseInQuad(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInQuad", args);
	return code;
}

FuncNode EaseInQuart(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInQuart", args);
	return code;
}

FuncNode EaseInQuint(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInQuint", args);
	return code;
}

FuncNode EaseInSine(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseInSine", args);
	return code;
}

FuncNode EaseOutBack(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutBack", args);
	return code;
}

FuncNode EaseOutCirc(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutCirc", args);
	return code;
}

FuncNode EaseOutCubic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutCubic", args);
	return code;
}

FuncNode EaseOutElastic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutElastic", args);
	return code;
}

FuncNode EaseOutExpo(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutExpo", args);
	return code;
}

FuncNode EaseOutInBack(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInBack", args);
	return code;
}

FuncNode EaseOutInCirc(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInCirc", args);
	return code;
}

FuncNode EaseOutInCubic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInCubic", args);
	return code;
}

FuncNode EaseOutInElastic(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInElastic", args);
	return code;
}

FuncNode EaseOutInExpo(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInExpo", args);
	return code;
}

FuncNode EaseOutInQuad(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInQuad", args);
	return code;
}

FuncNode EaseOutInQuart(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInQuart", args);
	return code;
}

FuncNode EaseOutInQuint(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInQuint", args);
	return code;
}

FuncNode EaseOutInSine(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutInSine", args);
	return code;
}

FuncNode EaseOutQuad(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutQuad", args);
	return code;
}

FuncNode EaseOutQuart(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutQuart", args);
	return code;
}

FuncNode EaseOutQuint(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutQuint", args);
	return code;
}

FuncNode EaseOutSine(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("EaseOutSine", args);
	return code;
}

FuncNode Equal(FuncNode lhs, FuncNode rhs) {
	vector<FuncNode> args;
	args.push_back(lhs);
	args.push_back(rhs);
	FuncNode code = FuncNode("Equal", args);
	return code;
}

FuncNode Execute(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Execute\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Execute", args);
	return code;
}

FuncNode Execute0(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Execute0\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Execute0", args);
	return code;
}

FuncNode ExportValue(FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("ExportValue", args);
	SonolusRun(code);
	return code;
}

FuncNode Floor(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Floor", args);
	return code;
}

FuncNode Frac(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Frac", args);
	return code;
}

FuncNode Get(FuncNode id, FuncNode index) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	FuncNode code = FuncNode("Get", args);
	return code;
}

FuncNode GetPointed(FuncNode id, FuncNode index, FuncNode offset) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	FuncNode code = FuncNode("GetPointed", args);
	return code;
}

FuncNode GetShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	FuncNode code = FuncNode("GetShifted", args);
	return code;
}

FuncNode Greater(FuncNode lhs, FuncNode rhs) {
	vector<FuncNode> args;
	args.push_back(lhs);
	args.push_back(rhs);
	FuncNode code = FuncNode("Greater", args);
	return code;
}

FuncNode GreaterOr(FuncNode lhs, FuncNode rhs) {
	vector<FuncNode> args;
	args.push_back(lhs);
	args.push_back(rhs);
	FuncNode code = FuncNode("GreaterOr", args);
	return code;
}

FuncNode HasEffectClip(FuncNode id) {
	vector<FuncNode> args;
	args.push_back(id);
	FuncNode code = FuncNode("HasEffectClip", args);
	return code;
}

FuncNode HasParticleEffect(FuncNode id) {
	vector<FuncNode> args;
	args.push_back(id);
	FuncNode code = FuncNode("HasParticleEffect", args);
	return code;
}

FuncNode HasSkinSprite(FuncNode id) {
	vector<FuncNode> args;
	args.push_back(id);
	FuncNode code = FuncNode("HasSkinSprite", args);
	return code;
}

FuncNode If(FuncNode test, FuncNode consequent, FuncNode alternate) {
	vector<FuncNode> args;
	args.push_back(test);
	args.push_back(consequent);
	args.push_back(alternate);
	FuncNode code = FuncNode("If", args);
	return code;
}

FuncNode IncrementPost(FuncNode id, FuncNode index) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	FuncNode code = FuncNode("IncrementPost", args);
	SonolusRun(code);
	return code;
}

FuncNode IncrementPostPointed(FuncNode id, FuncNode index, FuncNode offset) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	FuncNode code = FuncNode("IncrementPostPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode IncrementPostShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	FuncNode code = FuncNode("IncrementPostShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode IncrementPre(FuncNode id, FuncNode index) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	FuncNode code = FuncNode("IncrementPre", args);
	SonolusRun(code);
	return code;
}

FuncNode IncrementPrePointed(FuncNode id, FuncNode index, FuncNode offset) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	FuncNode code = FuncNode("IncrementPrePointed", args);
	SonolusRun(code);
	return code;
}

FuncNode IncrementPreShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	FuncNode code = FuncNode("IncrementPreShifted", args);
	SonolusRun(code);
	return code;
}

struct Judge_Group_min_max{
	FuncNode min;
	FuncNode max;
};
FuncNode Judge(FuncNode source, FuncNode target, Judge_Group_min_max perfect, Judge_Group_min_max great, Judge_Group_min_max good) {
	vector<FuncNode> args;
	args.push_back(source);
	args.push_back(target);
	args.push_back(perfect.min);
	args.push_back(perfect.max);
	args.push_back(great.min);
	args.push_back(great.max);
	args.push_back(good.min);
	args.push_back(good.max);
	FuncNode code = FuncNode("Judge", args);
	return code;
}

FuncNode JudgeSimple(FuncNode source, FuncNode target, FuncNode perfect, FuncNode great, FuncNode good) {
	vector<FuncNode> args;
	args.push_back(source);
	args.push_back(target);
	args.push_back(perfect);
	args.push_back(great);
	args.push_back(good);
	FuncNode code = FuncNode("JudgeSimple", args);
	return code;
}

FuncNode JumpLoop(vector<FuncNode> branch) {
	vector<FuncNode> args;
	if(branch.size() < 1) {
		cout << "Error: The argument \"branch\" in function \"JumpLoop\" expect as least 1 values, but only " << branch.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < branch.size(); i++) {
		args.push_back(branch[i]);
	}
	FuncNode code = FuncNode("JumpLoop", args);
	return code;
}

FuncNode Lerp(FuncNode x, FuncNode y, FuncNode s) {
	vector<FuncNode> args;
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	FuncNode code = FuncNode("Lerp", args);
	return code;
}

FuncNode LerpClamped(FuncNode x, FuncNode y, FuncNode s) {
	vector<FuncNode> args;
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	FuncNode code = FuncNode("LerpClamped", args);
	return code;
}

FuncNode Less(FuncNode lhs, FuncNode rhs) {
	vector<FuncNode> args;
	args.push_back(lhs);
	args.push_back(rhs);
	FuncNode code = FuncNode("Less", args);
	return code;
}

FuncNode LessOr(FuncNode lhs, FuncNode rhs) {
	vector<FuncNode> args;
	args.push_back(lhs);
	args.push_back(rhs);
	FuncNode code = FuncNode("LessOr", args);
	return code;
}

FuncNode Log(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Log", args);
	return code;
}

FuncNode Max(FuncNode x, FuncNode y) {
	vector<FuncNode> args;
	args.push_back(x);
	args.push_back(y);
	FuncNode code = FuncNode("Max", args);
	return code;
}

FuncNode Min(FuncNode x, FuncNode y) {
	vector<FuncNode> args;
	args.push_back(x);
	args.push_back(y);
	FuncNode code = FuncNode("Min", args);
	return code;
}

FuncNode Mod(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Mod\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Mod", args);
	return code;
}

struct MoveParticleEffect_Group_x_y{
	FuncNode x;
	FuncNode y;
};
FuncNode MoveParticleEffect(FuncNode particleId, MoveParticleEffect_Group_x_y x_y0, MoveParticleEffect_Group_x_y x_y1, MoveParticleEffect_Group_x_y x_y2, MoveParticleEffect_Group_x_y x_y3) {
	vector<FuncNode> args;
	args.push_back(particleId);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	FuncNode code = FuncNode("MoveParticleEffect", args);
	SonolusRun(code);
	return code;
}

FuncNode Multiply(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Multiply\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Multiply", args);
	return code;
}

FuncNode Negate(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Negate", args);
	return code;
}

FuncNode Not(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Not", args);
	return code;
}

FuncNode NotEqual(FuncNode lhs, FuncNode rhs) {
	vector<FuncNode> args;
	args.push_back(lhs);
	args.push_back(rhs);
	FuncNode code = FuncNode("NotEqual", args);
	return code;
}

FuncNode Or(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Or\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Or", args);
	return code;
}

FuncNode Paint(FuncNode id, FuncNode x, FuncNode y, FuncNode size, FuncNode rotation, FuncNode z, FuncNode a) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(size);
	args.push_back(rotation);
	args.push_back(z);
	args.push_back(a);
	FuncNode code = FuncNode("Paint", args);
	SonolusRun(code);
	return code;
}

FuncNode Play(FuncNode id, FuncNode distance) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(distance);
	FuncNode code = FuncNode("Play", args);
	SonolusRun(code);
	return code;
}

FuncNode PlayLooped(FuncNode id) {
	vector<FuncNode> args;
	args.push_back(id);
	FuncNode code = FuncNode("PlayLooped", args);
	// SonolusRun(code);
	return code;
}

FuncNode PlayLoopedScheduled(FuncNode id, FuncNode startTime) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(startTime);
	FuncNode code = FuncNode("PlayLoopedScheduled", args);
	// SonolusRun(code);
	return code;
}

FuncNode PlayScheduled(FuncNode id, FuncNode time, FuncNode distance) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(time);
	args.push_back(distance);
	FuncNode code = FuncNode("PlayScheduled", args);
	SonolusRun(code);
	return code;
}

FuncNode Power(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Power\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Power", args);
	return code;
}

FuncNode Print(FuncNode value, FuncNode format, FuncNode decimalPlaces, FuncNode anchorX, FuncNode anchorY, FuncNode pivotX, FuncNode pivotY, FuncNode width, FuncNode height, FuncNode rotation, FuncNode color, FuncNode alpha, FuncNode horizontalAlign, FuncNode background) {
	vector<FuncNode> args;
	args.push_back(value);
	args.push_back(format);
	args.push_back(decimalPlaces);
	args.push_back(anchorX);
	args.push_back(anchorY);
	args.push_back(pivotX);
	args.push_back(pivotY);
	args.push_back(width);
	args.push_back(height);
	args.push_back(rotation);
	args.push_back(color);
	args.push_back(alpha);
	args.push_back(horizontalAlign);
	args.push_back(background);
	FuncNode code = FuncNode("Print", args);
	SonolusRun(code);
	return code;
}

FuncNode Radian(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Radian", args);
	return code;
}

FuncNode Random(FuncNode min, FuncNode max) {
	vector<FuncNode> args;
	args.push_back(min);
	args.push_back(max);
	FuncNode code = FuncNode("Random", args);
	return code;
}

FuncNode RandomInteger(FuncNode min, FuncNode max) {
	vector<FuncNode> args;
	args.push_back(min);
	args.push_back(max);
	FuncNode code = FuncNode("RandomInteger", args);
	return code;
}

FuncNode Rem(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Rem\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Rem", args);
	return code;
}

FuncNode Remap(FuncNode a, FuncNode b, FuncNode c, FuncNode d, FuncNode x) {
	vector<FuncNode> args;
	args.push_back(a);
	args.push_back(b);
	args.push_back(c);
	args.push_back(d);
	args.push_back(x);
	FuncNode code = FuncNode("Remap", args);
	return code;
}

FuncNode RemapClamped(FuncNode a, FuncNode b, FuncNode c, FuncNode d, FuncNode x) {
	vector<FuncNode> args;
	args.push_back(a);
	args.push_back(b);
	args.push_back(c);
	args.push_back(d);
	args.push_back(x);
	FuncNode code = FuncNode("RemapClamped", args);
	return code;
}

FuncNode Round(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Round", args);
	return code;
}

FuncNode Set(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("Set", args);
	SonolusRun(code);
	return code;
}

FuncNode SetAdd(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("SetAdd", args);
	SonolusRun(code);
	return code;
}

FuncNode SetAddPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetAddPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetAddShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetAddShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode SetDivide(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("SetDivide", args);
	SonolusRun(code);
	return code;
}

FuncNode SetDividePointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetDividePointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetDivideShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetDivideShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode SetMod(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("SetMod", args);
	SonolusRun(code);
	return code;
}

FuncNode SetModPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetModPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetModShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetModShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode SetMultiply(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("SetMultiply", args);
	SonolusRun(code);
	return code;
}

FuncNode SetMultiplyPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetMultiplyPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetMultiplyShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetMultiplyShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode SetPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetPower(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("SetPower", args);
	SonolusRun(code);
	return code;
}

FuncNode SetPowerPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetPowerPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetPowerShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetPowerShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode SetRem(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("SetRem", args);
	SonolusRun(code);
	return code;
}

FuncNode SetRemPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetRemPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetRemShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetRemShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode SetShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode SetSubtract(FuncNode id, FuncNode index, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(value);
	FuncNode code = FuncNode("SetSubtract", args);
	SonolusRun(code);
	return code;
}

FuncNode SetSubtractPointed(FuncNode id, FuncNode index, FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(index);
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("SetSubtractPointed", args);
	SonolusRun(code);
	return code;
}

FuncNode SetSubtractShifted(FuncNode id, FuncNode x, FuncNode y, FuncNode s, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x);
	args.push_back(y);
	args.push_back(s);
	args.push_back(value);
	FuncNode code = FuncNode("SetSubtractShifted", args);
	SonolusRun(code);
	return code;
}

FuncNode Sign(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Sign", args);
	return code;
}

FuncNode Sin(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Sin", args);
	return code;
}

FuncNode Sinh(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Sinh", args);
	return code;
}

FuncNode Spawn(FuncNode id, vector<FuncNode> memory) {
	vector<FuncNode> args;
	args.push_back(id);
	if(memory.size() < 0) {
		cout << "Error: The argument \"memory\" in function \"Spawn\" expect as least 0 values, but only " << memory.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < memory.size(); i++) {
		args.push_back(memory[i]);
	}
	FuncNode code = FuncNode("Spawn", args);
	SonolusRun(code);
	return code;
}

struct SpawnParticleEffect_Group_x_y{
	FuncNode x;
	FuncNode y;
};
FuncNode SpawnParticleEffect(FuncNode id, SpawnParticleEffect_Group_x_y x_y0, SpawnParticleEffect_Group_x_y x_y1, SpawnParticleEffect_Group_x_y x_y2, SpawnParticleEffect_Group_x_y x_y3, FuncNode duration, FuncNode isLooped) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(duration);
	args.push_back(isLooped);
	FuncNode code = FuncNode("SpawnParticleEffect", args);
	SonolusRun(code);
	return code;
}

FuncNode SpawnParticleEffect2(FuncNode id, SpawnParticleEffect_Group_x_y x_y0, SpawnParticleEffect_Group_x_y x_y1, SpawnParticleEffect_Group_x_y x_y2, SpawnParticleEffect_Group_x_y x_y3, FuncNode duration, FuncNode isLooped) {
	vector<FuncNode> args;
	args.push_back(id);
	args.push_back(x_y0.x);
	args.push_back(x_y0.y);
	args.push_back(x_y1.x);
	args.push_back(x_y1.y);
	args.push_back(x_y2.x);
	args.push_back(x_y2.y);
	args.push_back(x_y3.x);
	args.push_back(x_y3.y);
	args.push_back(duration);
	args.push_back(isLooped);
	FuncNode code = FuncNode("SpawnParticleEffect", args);
	return code;
}

FuncNode StackEnter(FuncNode size) {
	vector<FuncNode> args;
	args.push_back(size);
	FuncNode code = FuncNode("StackEnter", args);
	SonolusRun(code);
	return code;
}

FuncNode StackGet(FuncNode offset) {
	vector<FuncNode> args;
	args.push_back(offset);
	FuncNode code = FuncNode("StackGet", args);
	return code;
}

FuncNode StackGetFrame(FuncNode offset) {
	vector<FuncNode> args;
	args.push_back(offset);
	FuncNode code = FuncNode("StackGetFrame", args);
	return code;
}

FuncNode StackGetFramePointer() {
	vector<FuncNode> args;
	FuncNode code = FuncNode("StackGetFramePointer", args);
	return code;
}

FuncNode StackGetPointer() {
	vector<FuncNode> args;
	FuncNode code = FuncNode("StackGetPointer", args);
	return code;
}

FuncNode StackGrow(FuncNode size) {
	vector<FuncNode> args;
	args.push_back(size);
	FuncNode code = FuncNode("StackGrow", args);
	SonolusRun(code);
	return code;
}

FuncNode StackInit() {
	vector<FuncNode> args;
	FuncNode code = FuncNode("StackInit", args);
	SonolusRun(code);
	return code;
}

FuncNode StackLeave() {
	vector<FuncNode> args;
	FuncNode code = FuncNode("StackLeave", args);
	SonolusRun(code);
	return code;
}

FuncNode StackPop() {
	vector<FuncNode> args;
	FuncNode code = FuncNode("StackPop", args);
	SonolusRun(code);
	return code;
}

FuncNode StackPush(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("StackPush", args);
	SonolusRun(code);
	return code;
}

FuncNode StackSet(FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("StackSet", args);
	SonolusRun(code);
	return code;
}

FuncNode StackSetFrame(FuncNode offset, FuncNode value) {
	vector<FuncNode> args;
	args.push_back(offset);
	args.push_back(value);
	FuncNode code = FuncNode("StackSetFrame", args);
	SonolusRun(code);
	return code;
}

FuncNode StackSetFramePointer(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("StackSetFramePointer", args);
	SonolusRun(code);
	return code;
}

FuncNode StackSetPointer(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("StackSetPointer", args);
	SonolusRun(code);
	return code;
}

FuncNode StopLooped(FuncNode loopId) {
	vector<FuncNode> args;
	args.push_back(loopId);
	FuncNode code = FuncNode("StopLooped", args);
	SonolusRun(code);
	return code;
}

FuncNode StopLoopedScheduled(FuncNode loopId, FuncNode endTime) {
	vector<FuncNode> args;
	args.push_back(loopId);
	args.push_back(endTime);
	FuncNode code = FuncNode("StopLoopedScheduled", args);
	SonolusRun(code);
	return code;
}

FuncNode Subtract(vector<FuncNode> value) {
	vector<FuncNode> args;
	if(value.size() < 1) {
		cout << "Error: The argument \"value\" in function \"Subtract\" expect as least 1 values, but only " << value.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < value.size(); i++) {
		args.push_back(value[i]);
	}
	FuncNode code = FuncNode("Subtract", args);
	return code;
}

struct Switch_Group_test_consequent{
	FuncNode test;
	FuncNode consequent;
};
FuncNode Switch(FuncNode discriminant, vector<Switch_Group_test_consequent> test_consequent) {
	vector<FuncNode> args;
	args.push_back(discriminant);
	if(test_consequent.size() < 0) {
		cout << "Error: The argument \"test_consequent\" in function \"Switch\" expect as least 0 values, but only " << test_consequent.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < test_consequent.size(); i++) {
		args.push_back(test_consequent[i].test);
		args.push_back(test_consequent[i].consequent);
	}
	FuncNode code = FuncNode("Switch", args);
	return code;
}

FuncNode SwitchInteger(FuncNode discriminant, vector<FuncNode> consequent) {
	vector<FuncNode> args;
	args.push_back(discriminant);
	if(consequent.size() < 0) {
		cout << "Error: The argument \"consequent\" in function \"SwitchInteger\" expect as least 0 values, but only " << consequent.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < consequent.size(); i++) {
		args.push_back(consequent[i]);
	}
	FuncNode code = FuncNode("SwitchInteger", args);
	return code;
}

FuncNode SwitchIntegerWithDefault(FuncNode discriminant, vector<FuncNode> consequent, FuncNode default) {
	vector<FuncNode> args;
	args.push_back(discriminant);
	if(consequent.size() < 0) {
		cout << "Error: The argument \"consequent\" in function \"SwitchIntegerWithDefault\" expect as least 0 values, but only " << consequent.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < consequent.size(); i++) {
		args.push_back(consequent[i]);
	}
	args.push_back(default);
	FuncNode code = FuncNode("SwitchIntegerWithDefault", args);
	return code;
}

struct SwitchWithDefault_Group_test_consequent{
	FuncNode test;
	FuncNode consequent;
};
FuncNode SwitchWithDefault(FuncNode discriminant, vector<SwitchWithDefault_Group_test_consequent> test_consequent, FuncNode default) {
	vector<FuncNode> args;
	args.push_back(discriminant);
	if(test_consequent.size() < 0) {
		cout << "Error: The argument \"test_consequent\" in function \"SwitchWithDefault\" expect as least 0 values, but only " << test_consequent.size() << " was provided." << endl;
		cout << "    Error occurred in " << callFromFunc << " in " << callFromFile << ":" << callFromLine << ":" << callFromColumn << endl;
	}
	for (int i = 0; i < test_consequent.size(); i++) {
		args.push_back(test_consequent[i].test);
		args.push_back(test_consequent[i].consequent);
	}
	args.push_back(default);
	FuncNode code = FuncNode("SwitchWithDefault", args);
	return code;
}

FuncNode Tan(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Tan", args);
	return code;
}

FuncNode Tanh(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Tanh", args);
	return code;
}

FuncNode TimeToScaledTime(FuncNode time) {
	vector<FuncNode> args;
	args.push_back(time);
	FuncNode code = FuncNode("TimeToScaledTime", args);
	return code;
}

FuncNode TimeToStartingScaledTime(FuncNode time) {
	vector<FuncNode> args;
	args.push_back(time);
	FuncNode code = FuncNode("TimeToStartingScaledTime", args);
	return code;
}

FuncNode TimeToStartingTime(FuncNode time) {
	vector<FuncNode> args;
	args.push_back(time);
	FuncNode code = FuncNode("TimeToStartingTime", args);
	return code;
}

FuncNode TimeToTimeScale(FuncNode time) {
	vector<FuncNode> args;
	args.push_back(time);
	FuncNode code = FuncNode("TimeToTimeScale", args);
	return code;
}

FuncNode Trunc(FuncNode value) {
	vector<FuncNode> args;
	args.push_back(value);
	FuncNode code = FuncNode("Trunc", args);
	return code;
}

FuncNode Unlerp(FuncNode a, FuncNode b, FuncNode x) {
	vector<FuncNode> args;
	args.push_back(a);
	args.push_back(b);
	args.push_back(x);
	FuncNode code = FuncNode("Unlerp", args);
	return code;
}

FuncNode UnlerpClamped(FuncNode a, FuncNode b, FuncNode x) {
	vector<FuncNode> args;
	args.push_back(a);
	args.push_back(b);
	args.push_back(x);
	FuncNode code = FuncNode("UnlerpClamped", args);
	return code;
}

FuncNode While(FuncNode test, FuncNode body) {
	vector<FuncNode> args;
	args.push_back(test);
	args.push_back(body);
	FuncNode code = FuncNode("While", args);
	return code;
}

#undef default

#endif
