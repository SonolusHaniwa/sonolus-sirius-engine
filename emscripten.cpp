// 将 levelData.cpp 中的代码转为 js 用于 Stellarity
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<sstream>
#include<algorithm>
#include<assert.h>
#include<iomanip>
using namespace std;

vector<string> explode(const char* seperator, const char* source) {
	string src = source; vector<string> res;
	while (src.find(seperator) != string::npos) {
		int wh = src.find(seperator);
		res.push_back(src.substr(0, src.find(seperator)));
		src = src.substr(wh + string(seperator).size());
	} res.push_back(src);
	return res;
}

#define DISABLE_PACK_SKIN
#define DISABLE_PACK_EFFECT
#define GZIP_H
#define ConfigurationBuild_H
#include"sonolus/sonolus.h"
#define sus2txt __builtin_sus2txt
#define txt2data __builtin_txt2data
#include"levelData.cpp"
#undef sus2txt
#undef txt2data

#ifndef EM_PORT_API
#	if defined(__EMSCRIPTEN__)
#		include <emscripten.h>
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#		else
#			define EM_PORT_API(rettype) rettype EMSCRIPTEN_KEEPALIVE
#		endif
#	else
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype
#		else
#			define EM_PORT_API(rettype) rettype
#		endif
#	endif
#endif

extern "C" EMSCRIPTEN_KEEPALIVE char* sus2txt(char* input) {
	string data; data = string(input, strlen(input));
	// cout << data.size() << endl;
	// for (int i = 0; i < strlen(input); i++) data.push_back(input[i]);
	string res = __builtin_sus2txt(data);
	char* result = const_cast<char*>(res.c_str());
	// for (int i = 0; i < res.size(); i++) result[i] = res[i];
	return result;
}

extern "C" EMSCRIPTEN_KEEPALIVE char* txt2data(char* input) {
	string data; data = string(input, strlen(input));
	// for (int i = 0; i < strlen(input); i++) data.push_back(input[i]);
	string res = __builtin_txt2data(data, 0, 0);
	char* result = const_cast<char*>(res.c_str());
	// for (int i = 0; i < res.size(); i++) result[i] = res[i];
	return result;
}