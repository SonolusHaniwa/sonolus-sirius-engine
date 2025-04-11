/**
 * @author 2024 (c) LittleYang0531
 * @attention 目前该程序只支持最大一层 group，如果后面官方出了很多层的 group 再写
 * @attention 还要注意官方的变量定义中有没有出现 C++ 关键字，有的话请添加在 keywords 数组里
 * @date 2024/12/13
 */

#include<bits/stdc++.h>
using namespace std;
#include"../utils/json.h"
vector<string> keywords = {
    "default"
};
int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " Functions.json Functions.h" << endl;
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
    fout << "#ifndef Functions_H" << endl;
    fout << "#define Functions_H" << endl;
    fout << endl;
    for (int i = 0; i < keywords.size(); i++)
        fout << "#define " << keywords[i] << " " << keywords[i] << "_value" << endl;
    fout << endl;
    for (int i = 0; i < json.size(); i++) {
        auto func = json[i];
        for (int j = 0; j < func["parameters"].size(); j++) {
            auto p = func["parameters"][j];
            if (p["type"] == "group") {
                fout << "struct " << func["name"].asString() << "_Group_";
                for (int k = 0; k < p["items"].size(); k++) {
                    auto item = p["items"][k];
                    fout << item["name"].asString();
                    if (k != p["items"].size() - 1) fout << "_";
                }
                fout << "{" << endl;
                for (int k = 0; k < p["items"].size(); k++) {
                    auto item = p["items"][k];
                    fout << "\tFuncNode " << item["name"].asString() << ";" << endl;
                }
                fout << "};" << endl;
            }
        }
        fout << "FuncNode " << func["name"].asString() << "(";
        for (int j = 0; j < func["parameters"].size(); j++) {
            auto p = func["parameters"][j];
            if (p["type"] == "group") {
                string argName = "";
                for (int k = 0; k < p["items"].size(); k++) {
                    auto item = p["items"][k];
                    argName += item["name"].asString();
                    if (k != p["items"].size() - 1) argName += "_";
                }
                if (p.isMember("minCount")) {
                    fout << "vector<" << func["name"].asString() << "_Group_" << argName << "> " << argName;
                } else if (p.isMember("count")) {
                    for (int k = 0; k < p["count"].asInt(); k++)
                        fout << func["name"].asString() << "_Group_" << argName << " " << argName << k << (k != p["count"].asInt() - 1 ? ", " : "");
                } else if (p.isMember("forEach")) {
                    for (int k = 0; k < p["forEach"].size(); k++)
                        fout << func["name"].asString() << "_Group_" << argName << " " << p["forEach"][k].asString() << (k != p["forEach"].size() - 1 ? ", " : "");
                } else {
                    fout << func["name"].asString() << "_Group_" << argName << " " << argName;
                }
            } else {
                if (p.isMember("minCount")) {
                    fout << "vector<FuncNode> " << p["name"].asString();
                } else if (p.isMember("count")) {
                    for (int k = 0; k < p["count"].asInt(); k++)
                        fout << "FuncNode " << p["name"].asString() << k << (k != p["count"].asInt() - 1 ? ", " : "");
                } else if (p.isMember("forEach")) {
                    for (int k = 0; k < p["forEach"].size(); k++)
                        fout << "FuncNode " << p["forEach"][k].asString() << (k != p["forEach"].size() - 1 ? ", " : "");
                } else {
                    fout << "FuncNode " << p["name"].asString();
                }
            }
            if (j != func["parameters"].size() - 1) fout << ", ";
        }
        fout << ") {" << endl;;
        fout << "\tvector<FuncNode> args;" << endl;
        for (int j = 0; j < func["parameters"].size(); j++) {
            auto p = func["parameters"][j];
            if (p["type"] == "group") {
                string argName = "";
                for (int k = 0; k < p["items"].size(); k++) {
                    auto item = p["items"][k];
                    argName += item["name"].asString();
                    if (k != p["items"].size() - 1) argName += "_";
                }
                if (p.isMember("minCount")) {
                    fout << "\tif(" << argName << ".size() < " << p["minCount"].asInt() << ") {" << endl;
                    fout << "\t\t" << 
                        "cout << \"Error: The argument \\\"" << argName << "\\\" in function \\\"" << func["name"].asString() << 
                        "\\\" expect as least " << p["minCount"].asInt() << " values, but only \" << " << argName << ".size() << \" was provided.\" << endl;" << endl;
                    fout << "\t\t" << 
                        "cout << \"    Error occurred in \" << callFromFunc << \" in \" << callFromFile << \":\" << callFromLine << \":\" << callFromColumn << endl;" << endl;
                    fout << "\t}" << endl;
                    fout << "\tfor (int i = 0; i < " << argName << ".size(); i++) {" << endl;
                    for (int k = 0; k < p["items"].size(); k++) {
                        auto item = p["items"][k];
                        fout << "\t\targs.push_back(" << argName << "[i]." << item["name"].asString() << ");" << endl;
                    }
                    fout << "\t}" << endl;
                } else if (p.isMember("count")) {
                    for (int k = 0; k < p["count"].asInt(); k++) {
                        for (int l = 0; l < p["items"].size(); l++) {
                            auto item = p["items"][l];
                            fout << "\targs.push_back(" << argName << k << "." << item["name"].asString() << ");" << endl;
                        }
                    }
                } else if (p.isMember("forEach")) {
                    for (int k = 0; k < p["forEach"].size(); k++) {
                        for (int l = 0; l < p["items"].size(); l++) {
                            auto item = p["items"][l];
                            fout << "\targs.push_back(" << p["forEach"][k].asString() << "." << item["name"].asString() << ");" << endl;
                        }
                    }
                } else {
                    for (int k = 0; k < p["items"].size(); k++) {
                        auto item = p["items"][k];
                        fout << "\targs.push_back(" << argName << "." << item["name"].asString() << ");" << endl;
                    }
                }
            } else {
                if (p.isMember("minCount")) {
                    fout << "\tif(" << p["name"].asString() << ".size() < " << p["minCount"].asInt() << ") {" << endl;
                    fout << "\t\t" << 
                        "cout << \"Error: The argument \\\"" << p["name"].asString() << "\\\" in function \\\"" << func["name"].asString() << 
                        "\\\" expect as least " << p["minCount"].asInt() << " values, but only \" << " << p["name"].asString() << ".size() << \" was provided.\" << endl;" << endl;
                    fout << "\t\t" << 
                        "cout << \"    Error occurred in \" << callFromFunc << \" in \" << callFromFile << \":\" << callFromLine << \":\" << callFromColumn << endl;" << endl;
                    fout << "\t}" << endl;
                    fout << "\tfor (int i = 0; i < " << p["name"].asString() << ".size(); i++) {" << endl;
                    fout << "\t\targs.push_back(" << p["name"].asString() << "[i]);" << endl;
                    fout << "\t}" << endl;
                } else if (p.isMember("count")) {
                    for (int k = 0; k < p["count"].asInt(); k++)
                        fout << "\targs.push_back(" << p["name"].asString() << k << ");" << endl;
                } else if (p.isMember("forEach")) {
                    for (int k = 0; k < p["forEach"].size(); k++)
                        fout << "\targs.push_back(" << p["forEach"][k].asString() << ");" << endl;
                } else {
                    fout << "\targs.push_back(" << p["name"].asString() << ");" << endl;
                }
            }
        }
        fout << "\tFuncNode code = FuncNode(\"" + func["name"].asString() + "\", args);" << endl;
        if (func["sideEffects"].asBool()) fout << "\tSonolusRun(code);" << endl;
        fout << "\treturn code;" << endl;
        fout << "}" << endl;
        fout << endl;
    }
    for (int i = 0; i < keywords.size(); i++)
        fout << "#undef " << keywords[i] << endl;
    fout << endl;
    fout << "#endif" << endl;
    fout.close();
}