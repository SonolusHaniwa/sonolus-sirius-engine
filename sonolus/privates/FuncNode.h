#ifndef FuncNode_H
#define FuncNode_H

class DataNode {
    public:

    bool isValue = true;
    double value = 0;
    string name = "";
    vector<int> param = {};

	bool operator < (const DataNode& a) const {
        if (a.isValue != isValue) return isValue < a.isValue;
        if (a.isValue) return value < a.value;
        else if (param == a.param) return name < a.name;
        else return param < a.param;
    }

	bool operator == (const DataNode& a) const {
		if (a.isValue != isValue) return false;
		if (isValue) return value == a.value;
		else return name == a.name && param == a.param;
	}

	Json::Value toJsonObject() {
		Json::Value res;
		if (isValue) res["value"] = value;
		else {
			res["func"] = name;
			res["args"].resize(0);
			for (int i = 0; i < param.size(); i++) res["args"].append(param[i]);
		}
		return res;
	}
};

map<DataNode, int> hashMap;
vector<DataNode> dataContainer;

class FuncNode {
	private:
	int nodeId = 0;

	int allocate(DataNode tmp) {
		if (hashMap.find(tmp) != hashMap.end()) return hashMap[tmp];
		hashMap[tmp] = dataContainer.size(); dataContainer.push_back(tmp);
		return hashMap[tmp];
	}

	public:
	Constructor FuncNode() {
		DataNode tmp = {
			isValue: true,
			value: 0
		};
		nodeId = allocate(tmp);
	}
	Constructor FuncNode(double value) {
		DataNode tmp = {
			isValue: true,
			value: value
		};
		nodeId = allocate(tmp);
	}
	Constructor FuncNode(string func, vector<FuncNode> args) {
		vector<int> nodes;
		for (int i = 0; i < args.size(); i++) nodes.push_back(args[i].nodeId);
		DataNode tmp = {
			isValue: false,
			name: func,
			param: nodes
		};
		nodeId = allocate(tmp);
	}

	string toString(int tabLength = 0) {
		stringstream ss; string pre = "";
		for (int i = 0; i < tabLength; i++) pre += "  ";
		DataNode node = dataContainer[nodeId];
		if (node.isValue) return ss << pre << node.value, ss.str();
		bool allValue = true;
		for (int i = 0; i < node.param.size(); i++) allValue &= dataContainer[node.param[i]].isValue;
		if (allValue) {
			ss << pre << node.name << "(";
			for (int i = 0; i < node.param.size(); i++) 
				ss << dataContainer[node.param[i]].value << (i != node.param.size() - 1 ? ", " : "");
			ss << ")";
		} else {
			ss << pre << node.name << "(" << endl;
			for (int i = 0; i < node.param.size(); i++) {
				FuncNode newNode = 0;
				newNode.nodeId = node.param[i];
				ss << newNode.toString(tabLength + 1) << (i != node.param.size() - 1 ? ", " : "") << endl;
			} ss << pre << ")";
		}
		return ss.str();
	}

	DataNode getNode() {
		return dataContainer[nodeId];
	}
	int getNodeId() {
		return nodeId;
	}

	#ifndef COMPILE_RUNTIME
	operator bool() {
		return false;
	}
	#endif
};

ostream& operator << (ostream& fout, FuncNode node) {
	return fout << node.toString();
}

stack<vector<FuncNode> > nodesContainer;
stack<int> blockCounter;
stack<bool> addBlockCounter;
void createNodeContainer(bool add = true) {
	nodesContainer.push({});
	if (add) blockCounter.push(1);
	else blockCounter.top() += 1;
	addBlockCounter.push(add);
}
void SonolusRun(FuncNode code) {
	SonolusAssert(nodesContainer.size(), "You shouldn't do anything outside Archetypes!");
	nodesContainer.top().push_back(code);
}
FuncNode mergeNodeContainer() {
	assert(nodesContainer.size());
	auto c = nodesContainer.top(); nodesContainer.pop();
	if (addBlockCounter.top()) blockCounter.pop();
	else blockCounter.top() -= 1;
	addBlockCounter.pop();
	// SonolusAssert(c.size(), "Your Sonolus will boom if I accept your empty function.");
	if (c.size() == 0) c.push_back(0);
	FuncNode res = FuncNode("Block", { FuncNode("Execute", c) });
	return res;
}

#endif