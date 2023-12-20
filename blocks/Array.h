template<int containerId, typename T>
class Array {
	public:

	int capacity = 0, offset = 0, classSize = 0;
	vector<T> val;

	// Array(){}
	Array(int siz) {
		capacity = siz; classSize = T().classSize;
		offset = allocatorSize[containerId];
		for (int i = 0; i < siz; i++) val.push_back(T());
		allocatorSize[containerId] += classSize * capacity;
	}
	FuncNode set(FuncNode index, T obj) {
		return setFixedMemory(containerId, offset + index * classSize, classSize, obj.serialize());
	}
	T get(FuncNode index) {
		return T(getFixedMemory(containerId, offset + index * classSize, classSize));
	}
	T operator [] (FuncNode id) {
		return get(id);
	}
	FuncNode indexOf(T obj) { // 时间复杂度 O(capacity * classSize)
		return Block(Execute({
			FOR (i, 0, capacity, 1) {
				IF (obj == get(i)) { Break(3, i) } FI
			} DONE,
			Break(1, -1)
		}));
	}
};
