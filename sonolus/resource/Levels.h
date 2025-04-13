#ifndef Levels_H
#define Levels_H

string getRef(int len = 32) {
	string res = "", key = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int i = 0; i < len; i++) res += key[rand() % key.size()];
	return res;
}

class LevelEntity {
	public:

	string archetype = "";
	string name = getRef();

	struct LevelEntityData {
		string name = "";
		bool isValue = true;
		double value = 0;
		string refName = "";
		
		Constructor LevelEntityData(string name, bool isValue): name(name), isValue(isValue) {};

		LevelEntityData operator = (double val) {
			value = val;
			return *this;
		}
		LevelEntityData operator = (LevelEntity val) {
			refName = val.name;
			return *this;
		}
	};

	vector<LevelEntityData*> data;

	#define defineArchetypeName(name) \
		private: bool archetype_unused = [&](){ \
			archetype = name; return true; \
		}();
		
	#define defineLevelDataValue(name) \
		public: LevelEntityData name = LevelEntityData(#name, true); \
		private: bool unused_##name##_unused = [&](){ \
			data.push_back(&name); \
			return true; \
		}();

	#define defineLevelDataValueDetailed(varName, dataName) \
		public: LevelEntityData varName = LevelEntityData(dataName, true); \
		private: bool unused_##varName##_unused = [&](){ \
			data.push_back(&varName); \
			return true; \
		}();
		
	#define defineLevelDataRef(name) \
		public: LevelEntityData name = LevelEntityData(#name, false); \
		private: bool unused_##name##_unused = [&](){ \
			data.push_back(&name); \
			return true; \
		}();

	#define defineLevelDataRefDetailed(varName, dataName) \
		public: LevelEntityData varName = LevelEntityData(dataName, false); \
		private: bool unused_##varName##_unused = [&](){ \
			data.push_back(&varName); \
			return true; \
		}();

	Json::Value toJsonObject() { // Serialize
		Json::Value res;
		res["archetype"] = archetype;
		res["name"] = name;
		res["data"].resize(0);
		for (int i = 0; i < data.size(); i++) {
			auto item = *data[i]; Json::Value single;
			single["name"] = item.name;
			if (item.isValue) single["value"] = item.value;
			else single["ref"] = item.refName;
			res["data"].append(single);
		}
		return res;
	}

	void fromJsonObject(Json::Value res) { // Deserialize
		name = res["name"].asString();
		for (int i = 0; i < data.size(); i++) {
			string varName = (*data[i]).name;
            bool exist = false;
			for (int j = 0; j < res["data"].size(); j++) {
				if (res["data"][j]["name"] != varName) continue;
				if ((*data[i]).isValue) (*data[i]).value = res["data"][j]["value"].asDouble();
				else (*data[i]).refName = res["data"][j]["ref"].asString();
                exist = true;
			}
            SonolusAssert(
                exist, 
                "Unsafe conversion from archetype \"%s\" to archetype \"%s\"!",
                res["archetype"].asCString(),
                archetype.c_str()
            );
		}
    }
};

class LevelRawData {
	public:

	double bgmOffset = 0;
	vector<Json::Value> entities;

#define DISABLE_INTERPRETER
	template<typename T>
	void append(T val) {
#undef DISABLE_INTERPRETER
		entities.push_back(val.toJsonObject());
#define DISABLE_INTERPRETER
	}

	template<typename T>
	T get(int id) {
		T res = *(new T);
#undef DISABLE_INTERPRETER
		res.fromJsonObject(entities[id]);
#define DISABLE_INTERPRETER
		return res;
	}

	template<typename T>
	T front() {
		return get<T>(0);
	}

	template<typename T>
	T back() {
		return get<T>(entities.size() - 1);
	}

	int size() { return entities.size(); }
#undef DISABLE_INTERPRETER

	Json::Value toJsonObject() {
		Json::Value res;
		res["bgmOffset"] = bgmOffset;
		res["entities"].resize(0);
		for (int i = 0; i < entities.size(); i++) res["entities"].append(entities[i]);
		return res;
	}
};

template<typename T1, typename T2>
T1 Transform(T2 v) {
    T1 res;
    res.fromJsonObject(v.toJsonObject());
    return res;
}

#endif