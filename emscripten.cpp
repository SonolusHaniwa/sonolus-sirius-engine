// 将 convert.h 中的代码转为 js 用于 Stellarity
#include"/usr/include/jsoncpp/json/json.h"
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<sstream>
#include<algorithm>
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

#include"modules/json.h"
#include"modules/buffer.h"
#include"modules/gzip.h"
#include"convert.h"

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
	cout << data.size() << endl;
	// for (int i = 0; i < strlen(input); i++) data.push_back(input[i]);
	string res = fromSUS(data);
	char* result = const_cast<char*>(res.c_str());
	// for (int i = 0; i < res.size(); i++) result[i] = res[i];
	return result;
}

extern "C" EMSCRIPTEN_KEEPALIVE char* txt2data(char* input) {
	string data; data = string(input, strlen(input));
	// for (int i = 0; i < strlen(input); i++) data.push_back(input[i]);
	string res = fromSirius(data, 0, 0);
	char* result = const_cast<char*>(res.c_str());
	// for (int i = 0; i < res.size(); i++) result[i] = res[i];
	return result;
}
