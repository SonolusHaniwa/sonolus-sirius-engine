#ifndef Skins_H
#define Skins_H

#ifndef DISABLE_PACK_SKIN
#include"../utils/png.h"
#define DISABLE_INTERPRETER
#include"../utils/MaxRects.cpp"
#undef DISABLE_INTERPRETER

class SkinDataSprite {
	public:
	string name;
	int x, y, w, h;

	Json::Value toJsonObject() {
		Json::Value res;
		res["name"] = name;
		res["x"] = x; res["y"] = y; res["w"] = w; res["h"] = h;
		string x[8] = { "x1", "x2", "x3", "x4", "y1", "y2", "y3", "y4" };
        // string x[8];
        // x[0] = "x1"; x[1] = "x2"; x[2] = "x3"; x[3] = "x4";
        // x[4] = "x5"; x[5] = "x6"; x[6] = "x7"; x[7] = "x8";
		for (int i = 0; i < 8; i++) res["transform"][x[i]][x[i]] = 1;
		return res;
	}
};

class SkinData {
	public:
	int width, height;	
	bool interpolation = false;
	vector<SkinDataSprite> sprites;

	Json::Value toJsonObject() {
		Json::Value res;
		res["width"] = width;
		res["height"] = height;
		res["interpolation"] = interpolation;
		res["sprites"].resize(0);
		for (int i = 0; i < sprites.size(); i++) res["sprites"].append(sprites[i].toJsonObject());
		return res;
	}
};

bool fileExists(string path) {
	ifstream fin;
    fin.open(path.c_str());
	return fin.is_open();
}

void PackSkin() {
    string textureDir = dist + "/SkinTexture";
    string dataDir = dist + "/SkinData";
	cout << "Reading Skin Sprites..." << endl;
	vector<image> imgs; SkinData data;
	for (int i = 0; i < skin_sprites.size(); i++) {
		string imgPath = skin_sprites[i].second;
        SonolusAssert(
            fileExists(imgPath),
            "Unknown Skin Sprite \"%s\"",
            imgPath.c_str()
        );
		imgs.push_back(readImage(imgPath));
		data.sprites.push_back({ skin_sprites[i].first, 0, 0, 0, 0 });
	}

	cout << "Packing Skin Texture..." << endl;
	using namespace rbp;
	vector<RectSize> rects, rects_back; vector<rbp::Rect> result_rects; 
	vector<size_t> rects_id, rects_id_back, result_ids;
	for (int i = 0; i < imgs.size(); i++) rects.push_back({imgs[i].width + 2, imgs[i].height + 2});
	for (int i = 0; i < imgs.size(); i++) rects_id.push_back(i);
	rects_id_back = rects_id; rects_back = rects;
	int width = 512, height = 512;
	while (true) {
		rects = rects_back, rects_id = rects_id_back;
		result_rects.clear(); result_ids.clear();
		auto RectsFactory = MaxRects(width, height, false);
		int res = RectsFactory.insert(1, rects, rects_id, result_rects, result_ids);
		if (res == rects.size()) break;
		width *= 2, height *= 2;
	}

	cout << "Writing Skin Texture..." << endl;
	image outimg = image(width, height);
	outimg.width = width, outimg.height = height;
	data.width = width; data.height = height;
	for (int i = 0; i < result_rects.size(); i++) {
		int id = result_ids[i], x = result_rects[i].x + 1, y = result_rects[i].y + 1;
		data.sprites[id].x = x; data.sprites[id].y = y;
		data.sprites[id].w = result_rects[i].width - 2; data.sprites[id].h = result_rects[i].height - 2;
		for (int j = y; j < y + result_rects[i].height - 2; j++) {
			for (int k = x; k < x + result_rects[i].width - 2; k++) {
				outimg.data[j][k * 4] = imgs[id].data[j - y][(k - x) * imgs[id].channel];
				outimg.data[j][k * 4 + 1] = imgs[id].data[j - y][(k - x) * imgs[id].channel + 1];
				outimg.data[j][k * 4 + 2] = imgs[id].data[j - y][(k - x) * imgs[id].channel + 2];
				outimg.data[j][k * 4 + 3] = imgs[id].channel < 4 ? 255 : imgs[id].data[j - y][(k - x) * imgs[id].channel + 3];
			}
		}
	} writeImage(textureDir, outimg);

	cout << "Writing Skin Data..." << endl;
	string json = json_encode(data.toJsonObject());
	string dataBuffer = compress_gzip(json);
	ofstream fout; fout.open(dataDir);
    fout.write(dataBuffer.c_str(), dataBuffer.size());
}
#endif

class SkinSprite {
    public:

    int id;
    string spriteName;

    operator int() {
        return id;
    }

    operator FuncNode() {
        return id;
    }

    operator Variable() {
        return id;
    }
};

SkinSprite defineSkinSprite(string name, string path = "") {
    if (path == "") path = "./skins/" + name + ".png";
    skin_sprites.push_back({ name, path });
    return { int(skin_sprites.size()) - 1, name };
}

class SkinSpriteName {
    public:

    string NoteHeadNeutral = "#NOTE_HEAD_NEUTRAL";
    string NoteHeadRed = "#NOTE_HEAD_RED";
    string NoteHeadGreen = "#NOTE_HEAD_GREEN";
    string NoteHeadBlue = "#NOTE_HEAD_BLUE";
    string NoteHeadYellow = "#NOTE_HEAD_YELLOW";
    string NoteHeadPurple = "#NOTE_HEAD_PURPLE";
    string NoteHeadCyan = "#NOTE_HEAD_CYAN";

    string NoteTickNeutral = "#NOTE_TICK_NEUTRAL";
    string NoteTickRed = "#NOTE_TICK_RED";
    string NoteTickGreen = "#NOTE_TICK_GREEN";
    string NoteTickBlue = "#NOTE_TICK_BLUE";
    string NoteTickYellow = "#NOTE_TICK_YELLOW";
    string NoteTickPurple = "#NOTE_TICK_PURPLE";
    string NoteTickCyan = "#NOTE_TICK_CYAN";

    string NoteTailNeutral = "#NOTE_TAIL_NEUTRAL";
    string NoteTailRed = "#NOTE_TAIL_RED";
    string NoteTailGreen = "#NOTE_TAIL_GREEN";
    string NoteTailBlue = "#NOTE_TAIL_BLUE";
    string NoteTailYellow = "#NOTE_TAIL_YELLOW";
    string NoteTailPurple = "#NOTE_TAIL_PURPLE";
    string NoteTailCyan = "#NOTE_TAIL_CYAN";

    string NoteConnectionNeutral = "#NOTE_CONNECTION_NEUTRAL";
    string NoteConnectionRed = "#NOTE_CONNECTION_RED";
    string NoteConnectionGreen = "#NOTE_CONNECTION_GREEN";
    string NoteConnectionBlue = "#NOTE_CONNECTION_BLUE";
    string NoteConnectionYellow = "#NOTE_CONNECTION_YELLOW";
    string NoteConnectionPurple = "#NOTE_CONNECTION_PURPLE";
    string NoteConnectionCyan = "#NOTE_CONNECTION_CYAN";

    string NoteConnectionNeutralSeamless = "#NOTE_CONNECTION_NEUTRAL_SEAMLESS";
    string NoteConnectionRedSeamless = "#NOTE_CONNECTION_RED_SEAMLESS";
    string NoteConnectionGreenSeamless = "#NOTE_CONNECTION_GREEN_SEAMLESS";
    string NoteConnectionBlueSeamless = "#NOTE_CONNECTION_BLUE_SEAMLESS";
    string NoteConnectionYellowSeamless = "#NOTE_CONNECTION_YELLOW_SEAMLESS";
    string NoteConnectionPurpleSeamless = "#NOTE_CONNECTION_PURPLE_SEAMLESS";
    string NoteConnectionCyanSeamless = "#NOTE_CONNECTION_CYAN_SEAMLESS";

    string SimultaneousConnectionNeutral = "#SIMULTANEOUS_CONNECTION_NEUTRAL";
    string SimultaneousConnectionRed = "#SIMULTANEOUS_CONNECTION_RED";
    string SimultaneousConnectionGreen = "#SIMULTANEOUS_CONNECTION_GREEN";
    string SimultaneousConnectionBlue = "#SIMULTANEOUS_CONNECTION_BLUE";
    string SimultaneousConnectionYellow = "#SIMULTANEOUS_CONNECTION_YELLOW";
    string SimultaneousConnectionPurple = "#SIMULTANEOUS_CONNECTION_PURPLE";
    string SimultaneousConnectionCyan = "#SIMULTANEOUS_CONNECTION_CYAN";

    string SimultaneousConnectionNeutralSeamless = "#SIMULTANEOUS_CONNECTION_NEUTRAL_SEAMLESS";
    string SimultaneousConnectionRedSeamless = "#SIMULTANEOUS_CONNECTION_RED_SEAMLESS";
    string SimultaneousConnectionGreenSeamless = "#SIMULTANEOUS_CONNECTION_GREEN_SEAMLESS";
    string SimultaneousConnectionBlueSeamless = "#SIMULTANEOUS_CONNECTION_BLUE_SEAMLESS";
    string SimultaneousConnectionYellowSeamless = "#SIMULTANEOUS_CONNECTION_YELLOW_SEAMLESS";
    string SimultaneousConnectionPurpleSeamless = "#SIMULTANEOUS_CONNECTION_PURPLE_SEAMLESS";
    string SimultaneousConnectionCyanSeamless = "#SIMULTANEOUS_CONNECTION_CYAN_SEAMLESS";

    string DirectionalMarkerNeutral = "#DIRECTIONAL_MARKER_NEUTRAL";
    string DirectionalMarkerRed = "#DIRECTIONAL_MARKER_RED";
    string DirectionalMarkerGreen = "#DIRECTIONAL_MARKER_GREEN";
    string DirectionalMarkerBlue = "#DIRECTIONAL_MARKER_BLUE";
    string DirectionalMarkerYellow = "#DIRECTIONAL_MARKER_YELLOW";
    string DirectionalMarkerPurple = "#DIRECTIONAL_MARKER_PURPLE";
    string DirectionalMarkerCyan = "#DIRECTIONAL_MARKER_CYAN";

    string SimultaneousMarkerNeutral = "#SIMULTANEOUS_MARKER_NEUTRAL";
    string SimultaneousMarkerRed = "#SIMULTANEOUS_MARKER_RED";
    string SimultaneousMarkerGreen = "#SIMULTANEOUS_MARKER_GREEN";
    string SimultaneousMarkerBlue = "#SIMULTANEOUS_MARKER_BLUE";
    string SimultaneousMarkerYellow = "#SIMULTANEOUS_MARKER_YELLOW";
    string SimultaneousMarkerPurple = "#SIMULTANEOUS_MARKER_PURPLE";
    string SimultaneousMarkerCyan = "#SIMULTANEOUS_MARKER_CYAN";

    string StageMiddle = "#STAGE_MIDDLE";

    string StageLeftBorder = "#STAGE_LEFT_BORDER";
    string StageRightBorder = "#STAGE_RIGHT_BORDER";
    string StageTopBorder = "#STAGE_TOP_BORDER";
    string StageBottomBorder = "#STAGE_BOTTOM_BORDER";
    string StageLeftBorderSeamless = "#STAGE_LEFT_BORDER_SEAMLESS";
    string StageRightBorderSeamless = "#STAGE_RIGHT_BORDER_SEAMLESS";
    string StageTopBorderSeamless = "#STAGE_TOP_BORDER_SEAMLESS";
    string StageBottomBorderSeamless = "#STAGE_BOTTOM_BORDER_SEAMLESS";

    string StageTopLeftCorner = "#STAGE_TOP_LEFT_CORNER";
    string StageTopRightCorner = "#STAGE_TOP_RIGHT_CORNER";
    string StageBottomLeftCorner = "#STAGE_BOTTOM_LEFT_CORNER";
    string StageBottomRightCorner = "#STAGE_BOTTOM_RIGHT_CORNER";

    string Lane = "#LANE";
    string LaneSeamless = "#LANE_SEAMLESS";

    string LaneAlternative = "#LANE_ALTERNATIVE";
    string LaneAlternativeSeamless = "#LANE_ALTERNATIVE_SEAMLESS";

    string JudgmentLine = "#JUDGMENT_LINE";
    string NoteSlot = "#NOTE_SLOT";

    string StageCover = "#STAGE_COVER";

    string GridNeutral = "#GRID_NEUTRAL";
    string GridRed = "#GRID_RED";
    string GridGreen = "#GRID_GREEN";
    string GridBlue = "#GRID_BLUE";
    string GridYellow = "#GRID_YELLOW";
    string GridPurple = "#GRID_PURPLE";
    string GridCyan = "#GRID_CYAN";
}SkinSpriteName;

#endif