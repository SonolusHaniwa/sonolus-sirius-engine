#include<bits/stdc++.h>
#include<jsoncpp/json/json.h>
#include<libpng/png.h>
using namespace std;
int main() {
    ifstream fin("./sirius-assets/cache_spliteffectelements.json");
    Json::Reader reader;
    Json::Value source; 
    reader.parse(fin, source);
    ifstream fin2("./SkinData.json");
    Json::Reader reader2;
    Json::Value source2;
    reader2.parse(fin2, source2);
    int maxY = 0;
    for (int i = 0; i < source2["sprites"].size(); i++) {
        maxY = max(maxY, source2["sprites"][i]["y"].asInt() + source2["sprites"][i]["h"].asInt());
    }
    stringstream classCode, defineCode, utilsCode;
    map<int, vector<string> > colors;
    classCode << "class Sprites {" << endl;
    classCode << "    public:" << endl;
    classCode << "" << endl;
    defineCode << "auto skins = defineSkins<class Sprites>({" << endl;
    utilsCode << "var getSplitLine(var id) {" << endl;
    utilsCode << "    return Switch(id, {" << endl;
    // 编写 readme
    stringstream readmeCode;
    readmeCode << "|ID|Sprite|" << endl << "|:-:|:-:|" << endl;
    // 读取图片
    FILE *fp = fopen("./SkinTexture.png", "rb");
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    png_init_io(png_ptr, fp);
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);
    // 编辑图片
    png_bytep *row_pointers = png_get_rows(png_ptr, info_ptr);
    int x = 0;
    Json::Value::Members member = source.getMemberNames();
    for (auto it = member.begin(); it != member.end(); it++) {
        Json::Value::Members member2 = source[*it].getMemberNames();
        for (auto it2 = member2.begin(); it2 != member2.end(); it2++) {
            string id = (*it).substr(68);
            id = id.substr(0, id.size() - 7);
            int X = x, 
                r = 255 * source[*it][*it2]["r"].asDouble(),
                g = 255 * source[*it][*it2]["g"].asDouble(),
                b = 255 * source[*it][*it2]["b"].asDouble();
            for (int Y = maxY + 1; Y <= maxY + 256; Y++) {
                row_pointers[Y][X * 4] = r;
                row_pointers[Y][X * 4 + 1] = g;
                row_pointers[Y][X * 4 + 2] = b;
                row_pointers[Y][X * 4 + 3] = 255;
            }
            for (int Y = maxY + 257; Y <= maxY + 512; Y++) {
                row_pointers[Y][X * 4] = r;
                row_pointers[Y][X * 4 + 1] = g;
                row_pointers[Y][X * 4 + 2] = b;
                row_pointers[Y][X * 4 + 3] = maxY + 512 - Y;
            }
            for (int Y = maxY + 513; Y <= maxY + 768; Y++) {
                row_pointers[Y][X * 4] = r;
                row_pointers[Y][X * 4 + 1] = g;
                row_pointers[Y][X * 4 + 2] = b;
                row_pointers[Y][X * 4 + 3] = Y - maxY - 513;
            }
            Json::Value splitLineFull, splitLineTrans1, splitLineTrans2;
            splitLineFull["name"] = "Sirius Split Line #" + id;
            splitLineFull["x"] = x + 1;
            splitLineFull["y"] = maxY + 1;
            splitLineFull["w"] = 1;
            splitLineFull["h"] = 256;
            splitLineFull["transform"] = source2["sprites"][0]["transform"];
            splitLineTrans1["name"] = "Sirius Split Line Transform 1 #" + id;
            splitLineTrans1["x"] = x + 1;
            splitLineTrans1["y"] = maxY + 257;
            splitLineTrans1["w"] = 1;
            splitLineTrans1["h"] = 256;
            splitLineTrans1["transform"] = source2["sprites"][0]["transform"];
            splitLineTrans2["name"] = "Sirius Split Line Transform 2 #" + id;
            splitLineTrans2["x"] = x + 1;
            splitLineTrans2["y"] = maxY + 513;
            splitLineTrans2["w"] = 1;
            splitLineTrans2["h"] = 256;
            splitLineTrans2["transform"] = source2["sprites"][0]["transform"];
            source2["sprites"].append(splitLineFull);
            source2["sprites"].append(splitLineTrans1);
            source2["sprites"].append(splitLineTrans2);
            classCode << "    int SplitLine_" << id << " = " << (14 + x * 3) << ";" << endl;
            classCode << "    int SplitLineTrans1_" << id << " = " << (15 + x * 3) << ";" << endl;
            classCode << "    int SplitLineTrans2_" << id << " = " << (16 + x * 3) << ";" << endl;
            defineCode << "    {\"Sirius Split Line #" << id << "\", Sprites.SplitLine_" << id << "}," << endl;
            defineCode << "    {\"Sirius Split Line Transform 1 #" << id << "\", Sprites.SplitLineTrans1_" << id << "}," << endl;
            defineCode << "    {\"Sirius Split Line Transform 2 #" << id << "\", Sprites.SplitLineTrans2_" << id << "}," << endl;
            // utilsCode << "        {" << id << ", Sprites.SplitLine_" << id << "}," << endl;
            int idNumber = stoi(id);
            colors[idNumber].push_back(id);
            x++;
        }
    }
    // 输出图片
    FILE *fp2 = fopen("./SkinTexture2.png", "wb");
    png_structp png_ptr2 = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info_ptr2 = png_create_info_struct(png_ptr2);
    png_init_io(png_ptr2, fp2);
    png_set_IHDR(png_ptr2, info_ptr2, 4096, 4096, 8, PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    png_write_info(png_ptr2, info_ptr2);
    png_write_image(png_ptr2, row_pointers);
    png_write_end(png_ptr2, NULL);
    // 输出 json
    ofstream fout("./SkinData2.json");
    Json::FastWriter writer;
    fout << writer.write(source2);
    // 输出 code
    classCode << "};" << endl;
    defineCode << "});" << endl;
    for (auto v : colors) {
        int id = v.first; vector<string> ids = v.second;
        utilsCode << "        {" << id << ", setSplitLine({";
        for (int i = 0; i < ids.size(); i++) {
            utilsCode << "Sprites.SplitLine_" << ids[i];
            if (i != ids.size() - 1) {
                utilsCode << ", ";
            }
        } utilsCode << "})}," << endl;
    }
    utilsCode << "    });" << endl;
    utilsCode << "}" << endl;
    ofstream fout2("./skins.cpp");
    fout2 << classCode.str() << endl;
    fout2 << defineCode.str() << endl;
    fout2 << utilsCode.str() << endl;
    // 输出 readme
    for (int i = 0; i < source2["sprites"].size(); i++) {
        readmeCode << "|" << i << "|" << source2["sprites"][i]["name"].asString() << "|" << endl;
    } ofstream fout3("readme");
    fout3 << readmeCode.str() << endl;
    return 0;
}