#ifndef Operators_H
#define Operators_H

#ifdef COMPILE_RUNTIME
FuncNode operator + (FuncNode a, FuncNode b) { 
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value + b.getNode().value;
	return FuncNode("Add", { a, b }); 
}

FuncNode operator - (FuncNode a, FuncNode b) { 
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value - b.getNode().value;
	return FuncNode("Subtract", { a, b }); 
}

FuncNode operator - (FuncNode a) {
    if (a.getNode().isValue) return -a.getNode().value;
	return FuncNode("Multiply", { -1, a }); 
}

FuncNode operator * (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value * b.getNode().value;
	return FuncNode("Multiply", { a, b }); 
}

FuncNode operator / (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value / b.getNode().value;
	return FuncNode("Divide", { a, b }); 
}

FuncNode operator % (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value - b.getNode().value * int(a.getNode().value / b.getNode().value);
	return FuncNode("Mod", { a, b }); 
}

FuncNode operator == (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value == b.getNode().value;
	return FuncNode("Equal", { a, b }); 
}

FuncNode operator != (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value != b.getNode().value;
	return FuncNode("NotEqual", { a, b }); 
}

FuncNode operator < (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value < b.getNode().value;
	return FuncNode("Less", { a, b }); 
}

FuncNode operator <= (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value <= b.getNode().value;
	return FuncNode("LessOr", { a, b }); 
}

FuncNode operator > (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value > b.getNode().value;
	return FuncNode("Greater", { a, b }); 
}

FuncNode operator >= (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value >= b.getNode().value;
	return FuncNode("GreaterOr", { a, b }); 
}

FuncNode operator || (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value || b.getNode().value;
	return FuncNode("Or", { a, b }); 
}

FuncNode operator && (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return a.getNode().value && b.getNode().value;
	return FuncNode("And", { a, b }); 
}

FuncNode operator ! (FuncNode a) {
    if (a.getNode().isValue) return !a.getNode().value;
    return FuncNode("Not", { a });
}

FuncNode operator | (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return int(a.getNode().value) | int(b.getNode().value);
	return FuncNode("Or", { a, b }); 
}

FuncNode operator & (FuncNode a, FuncNode b) {
    if (a.getNode().isValue && b.getNode().isValue) return int(a.getNode().value) & int(b.getNode().value);
	return FuncNode("And", { a, b });
}

FuncNode operator ~ (FuncNode a) {
    if (a.getNode().isValue) return ~int(a.getNode().value);
    return FuncNode("Not", { a });
}
#endif

#endif