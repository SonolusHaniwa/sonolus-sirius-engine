// 哈希表 O(n)

const int64_t k1 = 23;
const int64_t k2 = 55331;
const int64_t p1 = 1e9 + 7;
const int64_t p2 = 998244353;
template<typename T>
struct hashMap {
    int *map1, *map2;
    hashMap() {
        map1 = new int[1 << 20];
        map2 = new int[1 << 20];
        memset(map1, -1, sizeof(map1));
        memset(map2, -1, sizeof(map2));
    }
    int64_t getHash(T v, bool hashType) {
        string tmp = v.toString();
        int64_t hash = 0;
        for (int i = 0; i < tmp.size(); i++) 
            hash *= hashType ? k1 : k2, hash %= hashType ? p1 : p2,
            hash += tmp[i], hash %= hashType ? p1 : p2;
        return hash;
    }
    void insert(T key, int value) {
        int64_t hash1 = getHash(key, 0);
        int64_t hash2 = getHash(key, 1);
        hash1 %= (1 << 20); hash2 %= (1 << 20);
        map1[hash1] = value; map2[hash2] = value;
    }
    int get(T key) {
        int64_t hash1 = getHash(key, 0);
        int64_t hash2 = getHash(key, 1);
        hash1 %= (1 << 20); hash2 %= (1 << 20);
        if (map1[hash1] != map2[hash2]) throw runtime_error("Hash Collision!");
        return map1[hash1];
    }
    bool exist(T key) {
        int64_t hash1 = getHash(key, 0);
        int64_t hash2 = getHash(key, 1);
        hash1 %= (1 << 20); hash2 %= (1 << 20);
        if (map1[hash1] != map2[hash2]) throw runtime_error("Hash Collision!");
        return map1[hash1] != -1;
    }
};
