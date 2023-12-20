#pragma once

class CustomClass {
	public:
	
	int classSize = 0;
	vector<function<void(FuncNode)> > deserializiers;
	vector<function<FuncNode()> > serializiers;

	CustomClass(){}
	CustomClass(vector<FuncNode> args) {
		assert(args.size() == classSize);
		for (int i = 0; i < classSize; i++) deserializiers[i](args[i]); 
	}

	FuncNode operator == (CustomClass a) {
		vector<FuncNode> args;
		for (int i = 0; i < classSize; i++) args.push_back(serializiers[i]() == a.serializiers[i]());
		return And(args);
	}

	vector<FuncNode> serialize() {
		vector<FuncNode> res;
		for (int i = 0; i < classSize; i++) res.push_back(serializiers[i]());
		return res;
	}

	#define defineVar(T, valName, value) T valName = value; \
	    bool unused_##valName##_unused = [&](){ \
    		for (int i = 0; i < valName.classSize; i++) \
    			deserializiers.push_back(valName.deserializiers[i]), \
    			serializiers.push_back(valName.serializiers[i]); \
    		classSize += valName.classSize; \
	    	return true; \
	    }();
};

#define customClass(name) class name: public CustomClass

int allocatorSize[10001] = {0};

vector<FuncNode> getFixedMemory(FuncNode containerId, FuncNode offset, int len) {
	vector<FuncNode> args;
	for (int i = 0; i < len; i++) args.push_back(Get(containerId, offset + i));
	return args;
}

FuncNode setFixedMemory(FuncNode containerId, FuncNode offset, int len, vector<FuncNode> list) {
	assert(len == list.size()); vector<FuncNode> args;
	for (int i = 0; i < len; i++) args.push_back(Set(containerId, offset + i, list[i]));
	return Execute(args);
}
