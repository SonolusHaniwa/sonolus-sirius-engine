#include<bits/stdc++.h>
#include<jsoncpp/json/json.h>
using namespace std;
int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " [json] [cpp]";
		return 1;
	}
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	fin.seekg(0, ios::end);
	int len = fin.tellg();
	fin.seekg(0, ios::beg);
	char* ch = new char[len];
	fin.read(ch, len); fin.close();
	string json = string(ch, len);
	Json::Value obj; Json::Reader reader;
	reader.parse(json, obj);
	
	stringstream idCode, pointerCode, tableCode; int blockNum = 0;
	for (int i = 0; i < obj.size(); i++) {
		if (obj[i]["name"].asString() == "TemporaryMemory") {
			for (int j = 0; j < obj[i]["readable"].size(); j++) {
				idCode << "int " << obj[i]["readable"][j].asString() << "Id = " << j << ";" << endl;
			} blockNum = obj[i]["readable"].size();
		}
	}
	tableCode << "bool readMap[10001][" << blockNum << "]; " << endl;
	tableCode << "bool writeMap[10001][" << blockNum << "];" << endl;
	tableCode << "bool initializeReadWriteTable = [](){" << endl;
	tableCode << "\tmemset(readMap, 0, sizeof readMap); memset(writeMap, 0 sizeof writeMap);" << endl;
	for (int i = 0; i < obj.size(); i++) {
		string name = obj[i]["name"].asString();
		int id = obj[i]["id"].asInt();
		idCode << "int " << name << "Id = " << id << ";" << endl;
		pointerCode << "Pointer<" << name << "Id> " << name << ";" << endl;
		Json::Value newObj = obj[i]["readable"];
		if (newObj.size()) tableCode << "\t";
		for (int j = 0; j < newObj.size(); j++) {
			tableCode << "writeMap[" << name << "Id][" << newObj[j].asString() << "Id] = 1; ";
		} if (newObj.size()) tableCode << endl;
		newObj = obj[i]["writable"];
		if (newObj.size()) tableCode << "\t";
		for (int j = 0; j < newObj.size(); j++) {
			tableCode << "readMap[" << name << "Id][" << newObj[j].asString() << "Id] = 1; ";
		} if (newObj.size()) tableCode << endl;
	}
	tableCode << "\treturn true;" << endl;
	tableCode << "}();" << endl;
	
	fout << idCode.str() << endl;
	fout << pointerCode.str() << endl;
	fout << tableCode.str();
}