#ifndef EngineDataBucket_H
#define EngineDataBucket_H

class EngineDataBucketSprite {
    public:

    int id = 0;
    int fallbackId = 0;
    double x = 0;
    double y = 0;
    double w = 0;
    double h = 0;
    double rotation = 0;

    Constructor EngineDataBucketSprite(){}
    Constructor EngineDataBucketSprite(
        int id,
        int fallbackId,
        double x, double y,
        double w, double h,
        double rotation
    ): id(id), fallbackId(fallbackId), x(x), y(y), w(w), h(h), rotation(rotation){}

    Json::Value toJsonObject() {
        Json::Value res;
        res["id"] = id;
        if (fallbackId != 0) res["fallbackId"] = fallbackId;
        res["x"] = x;
        res["y"] = y;
        res["w"] = w;
        res["h"] = h;
        res["rotation"] = rotation;
        return res;
    }
};

class EngineDataBucket {
    public:

    vector<EngineDataBucketSprite> sprites;
    string unit = "";

    Json::Value toJsonObject() {
        Json::Value res;
        res["sprites"].resize(0);
        for (int i = 0; i < sprites.size(); i++) res["sprites"].append(sprites[i].toJsonObject());
        if (unit != "") res["unit"] = unit;
        return res;
    }
};

class Bucket {
    public:

    int id;

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

vector<EngineDataBucket> data_buckets;
Bucket defineBucket(vector<EngineDataBucketSprite> sprites, string unit) {
    EngineDataBucket bucket;
    bucket.unit = unit;
    bucket.sprites = sprites;
    data_buckets.push_back(bucket);
    return { int(data_buckets.size()) - 1 };
}

#endif