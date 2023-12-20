template<int containerId, typename T1, typename T2> 
class Map {
	public:

	int capacity = 0, offset = 0, classSize_key = 0, classSize_val = 0;
	vector<T1> key; vector<T2> val;
	FuncNode size = 0;

	// Map(){}
	Map(int siz) {
		capacity = siz; classSize_key = T1().classSize, classSize_val = T2().classSize;
		size = Get(containerId, allocatorSize[containerId]);
		offset = allocatorSize[containerId] + 1;
		for (int i = 0; i < siz; i++) key.push_back(T1()), val.push_back(T2());
		allocatorSize[containerId] += (classSize_key + classSize_val) * capacity + 1;
	}
	FuncNode add(T1 key, T2 value) {
		return {
			setFixedMemory(containerId, offset + size * (classSize_key + classSize_val), classSize_key, key.serialize()),
			setFixedMemory(containerId, offset + size * (classSize_key + classSize_val) + classSize_key, classSize_val, value.serialize()),
			Set(containerId, offset - 1, size + 1),
		};
	}
	T1 getKeyById(FuncNode index) {
		return T1(getFixedMemory(containerId, offset + index * (classSize_key + classSize_val), classSize_key));
	}
	T2 getValById(FuncNode index) {
		return T2(getFixedMemory(containerId, offset + index * (classSize_key + classSize_val) + classSize_key, classSize_val));
	}
	FuncNode indexOf(T1 key) { // 时间复杂度 O(size * classSize_key)
		return Block(Execute({
			FOR (i, 0, size, 1) {
				IF (key == getKeyById(i)) { Break(3, i) } FI
			} DONE,
			Break(1, -1)
		}));
	}
	T2 get(T1 key) { // 不安全的函数，使用前请用 indexOf() != -1 判断 key 的存在性
		return getValById(indexOf(key));
	}
	T2 operator [] (T1 key) { // 问题同上
		return get(key);
	}
	FuncNode set(T1 key, T2 value) {
		return {
			IF (indexOf(key) == -1) { add(key, value) }
			ELSE { setFixedMemory(containerId, offset + indexOf(key) * (classSize_key + classSize_val) + classSize_key, classSize_val, value.serialize()) } FI
		};
	}
	FuncNode clear() {
		return { Set(containerId, offset - 1, 0) };
	}
};
