/**
 * @author 2024 (c) LittleYang0531
 * @date 2024/12/15
 */

#include<bits/stdc++.h>
using namespace std;
#include"../utils/json.h"

// struct group1 {
//     struct group2 {
//         Variable<LevelBucketId> min = Variable<LevelBucketId>(0, true);
//         Variable<LevelBucketId> max = Variable<LevelBucketId>(1, true);

//         Constructor group2(FuncNode offset) {
//             min.reallocate(offset + 0);
//             max.reallocate(offset + 1);
//         }
//     };
//     group2 perfect = group2(0);
//     group2 great = group2(2);
//     group2 good = group2(4);

//     Constrctor group1(FuncNode offset) {
//         perfect = group2(offset + 0);
//         perfect = group2(offset + 2);
//         perfect = group2(offset + 4);
//     }
// };

string generateName(int len) {
    string keys = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string res = "";
    for (int i = 0; i < len; i++) res += keys[rand() % keys.size()];
    return res;
}

pair<int, string> generateParameters(ofstream &fout, Json::Value values, string blockName, bool addVal, int tab) {
    string tabString = ""; 
    for (int i = 0; i < tab; i++) tabString += "\t";
    int siz = 0; vector<pair<int, string> > infos;
    if (values["type"].asString() == "group") {
        string name = tab == 0 ? blockName + "Group" : "Group_" + generateName(16);
        fout << tabString << "struct " << name << "{" << endl;
        for (int i = 0; i < values["items"].size(); i++)
            infos.push_back(generateParameters(fout, values["items"][i], blockName, true, tab + 1));
        fout << endl;
        if (!tab) fout << tabString << "\tConstructor " << name << "(FuncNode offset) {" << endl;
        else fout << tabString << "\tvoid reallocate(FuncNode offset) {" << endl;
        for (int i = 0; i < values["items"].size(); i++) {
            auto item = values["items"][i];
            if (item["type"].asString() == "item") {
                if (item.isMember("count")) {
                    fout << tabString << "\t\t" << item["name"].asString() 
                         << " = VariablesArray<" << blockName << "Id>(offset + " << siz << ", " << item["count"].asInt() << ");" << endl;
                    siz += item["count"].asInt();
                } else if (item.isMember("forEach")) {
                    for (int j = 0; j < item["forEach"].size(); j++)
                        fout << tabString << "\t\t" << item["forEach"][j].asString() << "_" << item["name"].asString() 
                             << ".reallocate(offset + " << siz << ");" << endl, siz++;
                } else if (item.isMember("minCount")) assert(false);
                else {
                    fout << tabString << "\t\t" << item["name"].asString() << ".reallocate(offset + " << siz << ");" << endl;
                    siz++;
                }
            } else {
                if (item.isMember("minCount")) assert(false);
                else if (item.isMember("count")) assert(false);
                else if (item.isMember("forEach")) {
                    for (int j = 0; j < item["forEach"].size(); j++) {
                        fout << tabString << "\t\t" << item["forEach"][j].asString() << ".reallocate(offset + " << siz << ");" << endl;
                        siz += infos[i].first;
                    }
                } else assert(false);
            }
        }
        fout << tabString << "\t}" << endl;
        fout << tabString << "};" << endl;
        if (addVal) {
            if (values.isMember("minCount")) assert(false);
            else if (values.isMember("count")) assert(false);
            else if (values.isMember("forEach")) {
                for (int i = 0; i < values["forEach"].size(); i++) 
                    fout << tabString << name << " " << values["forEach"][i].asString() << ";" << endl;
            } else assert(false);
        }
        return { siz, name };
    } else {
        siz = 1;
        if (values.isMember("count")) {
            fout << tabString << "VariablesArray<" << blockName << "Id> " << values["name"].asString() 
                 << " = VariablesArray<" << blockName << "Id>(0, " << values["count"].asInt() << ");" << endl;
        } else if (values.isMember("forEach")) {
            for (int i = 0; i < values["forEach"].size(); i++)
                fout << tabString << "Variable " << values["forEach"][i].asString() << "_" << values["name"].asString()
                     << " = Variable(" << blockName << "Id, 0);" << endl;
        } else if (values.isMember("minCount")) assert(false);
        else {
            fout << tabString << "Variable " << values["name"].asString() 
                 << " = Variable(" << blockName << "Id, 0);" << endl;
        }
        return { 1, "" };
    }
};

int main(int argc, char** argv) {
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " Blocks.json Blocks.h mode" << endl;
        return 1;
    }
    ifstream fin; fin.open(argv[1]);
    fin.seekg(0, ios::end);
    int len = fin.tellg();
    char *ch = new char[len];
    fin.seekg(0, ios::beg);
    fin.read(ch, len);
    string s = string(ch, len);
    Json::Value json = json_decode(s);
    fin.close();
    ofstream fout; fout.open(argv[2]);
    string id = argv[3];
    int h = 0; for (int i = 0; i < id.size(); i++) h += id[i];
    srand(h);
    fout << "#ifndef " << argv[3] << "Blocks_H" << endl;
    fout << "#define " << argv[3] << "Blocks_H" << endl;
    fout << endl;
    for (int i = 0; i < json.size(); i++)
        fout << "const int " << json[i]["name"].asString() << "Id = " << json[i]["id"].asInt() << ";" << endl;
    fout << endl;
    fout << "bool unused_readable_unused = [](){" << endl;
    fout << "\treadable = {" << endl;
    for (int i = 0; i < json.size(); i++) {
        fout << "\t\t{ " << json[i]["name"].asString() << "Id, { ";
        for (int j = 0; j < json[i]["readable"].size(); j++) 
            fout << "\"" << json[i]["readable"][j].asString() << "\"" << (j != json[i]["readable"].size() - 1 ? ", " : "");
        fout << " } }" << (i != json.size() - 1 ? "," : "") << endl;
    }
    fout << "\t};" << endl;
    fout << "\treturn true;" << endl;
    fout << "}();" << endl;
    fout << endl;
    fout << "bool unused_writable_unused = [](){" << endl;
    fout << "\twritable = {" << endl;
    for (int i = 0; i < json.size(); i++) {
        fout << "\t\t{ " << json[i]["name"].asString() << "Id, { ";
        for (int j = 0; j < json[i]["writable"].size(); j++) 
            fout << "\"" << json[i]["writable"][j].asString() << "\"" << (j != json[i]["writable"].size() - 1 ? ", " : "");
        fout << " } }" << (i != json.size() - 1 ? "," : "") << endl;
    }
    fout << "\t};" << endl;
    fout << "\treturn true;" << endl;
    fout << "}();" << endl;
    fout << endl;
    fout << "bool unused_blockName_unused = [](){" << endl;
    fout << "\tblockName = {" << endl;
    for (int i = 0; i < json.size(); i++)
        fout << "\t\t{ " << json[i]["name"].asString() << "Id, \"" << json[i]["name"].asString() << "\" }" << (i != json.size() - 1 ? "," : "") << endl;
    fout << "\t};" << endl;
    fout << "\treturn true;" << endl;
    fout << "}();" << endl;
    fout << endl;
    fout << "bool unused_writeBlockInfo_unused = [](){" << endl; 
    for (int i = 0; i < json.size(); i++) {
        if (
            json[i]["values"][0]["type"].asString() == "item" &&
            json[i]["values"][0]["name"].asString() == "generic"
        ) {
            fout << "\tSonolusMemorySize[" << json[i]["name"].asString() << "Id] = " << json[i]["values"][0]["count"].asInt() << ";" << endl;
            fout << "\tSonolusMemoryDelta[" << json[i]["name"].asString() << "Id] = 1;" << endl;
            fout << "\tallowAllocate.insert(" << json[i]["name"].asString() << "Id);" << endl;
        }
    }
    fout << "\treturn true;" << endl;
    fout << "}();" << endl;
    fout << endl;
    for (int i = 0; i < json.size(); i++) {
        if (
            json[i]["values"].size() == 1 && json[i]["values"][0]["type"].asString() == "group" && 
            (json[i]["values"][0].isMember("minCount") || json[i]["values"][0].isMember("count"))
        ) {
            auto info = generateParameters(fout, json[i]["values"][0], json[i]["name"].asString(), false, 0);
            fout << "BlocksArray<" << info.second << "> " << json[i]["name"].asString() 
                 << " = BlocksArray<" << info.second << ">(" << info.first << ");" << endl;
            fout << endl;
        } else if (
            json[i]["values"].size() == 1 && json[i]["values"][0]["type"].asString() == "item" && 
            (json[i]["values"][0].isMember("minCount") || json[i]["values"][0].isMember("count"))
        ) {
            fout << "VariablesArray<" << json[i]["name"].asString() << "Id> " << json[i]["name"].asString() 
                 << " = VariablesArray<" << json[i]["name"].asString() << "Id>(0, 1 << 16);" << endl;
            fout << endl;
        } else {
            Json::Value tmp;
            tmp["type"] = "group";
            tmp["items"] = json[i]["values"];
            string name = generateParameters(fout, tmp, json[i]["name"].asString(), false, 0).second;
            fout << name << " " << json[i]["name"].asString() 
                 << " = " << name << "(0);" << endl;
            fout << endl;
        }
    }
    fout << endl;
    fout << "#endif" << endl;
    fout.close();
}