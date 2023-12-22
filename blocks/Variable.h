stack<vector<FuncNode> > nodesContainer;
stack<int> blockCounter;
void createNodeContainer();
void R(FuncNode);

template<int identifierId>
class Variable {
    public:

    int offset;
    Variable(){
        offset = allocatorSize[identifierId]++;
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, 0}));
    }
    Variable(int val) {
    	offset = allocatorSize[identifierId]++;
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val}));
    }
    Variable(double val) {
    	offset = allocatorSize[identifierId]++;
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val}));
    }
    template<int T>
    Variable(Variable<T> val) {
    	offset = allocatorSize[identifierId]++;
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val.get()}));
    }
    Variable(FuncNode val) {
    	offset = allocatorSize[identifierId]++;
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val}));
    }

	FuncNode get() {
		return FuncNode(RuntimeFunction.Get, {identifierId, offset});
	}
    void set(int val) {
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val}));
    }
    void set(double val) {
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val}));
    }
    void set(FuncNode val) {
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val}));
    }
    template<int T>
    void set(Variable<T> val) {
		R(FuncNode(RuntimeFunction.Set, {identifierId, offset, val.get()}));
    }

    operator FuncNode() {
    	return get();
    }
};

void createNodeContainer() {
	nodesContainer.push(vector<FuncNode>());
	blockCounter.push(1);
}
void R(FuncNode body) {
	nodesContainer.top().push_back(body);
}
FuncNode mergeNodeContainer() {
	assert(nodesContainer.size());
	auto c = nodesContainer.top(); nodesContainer.pop();
	FuncNode res = FuncNode(RuntimeFunction.Block, {
		FuncNode(RuntimeFunction.Execute, c)
	}); return res;
}
