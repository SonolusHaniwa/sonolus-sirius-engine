#ifndef WatchRuntime_H
#define WatchRuntime_H

const int OptionId = LevelOptionId;
auto unused_defaultAllocatorId_unused = [](){
    defaultAllocatorId = LevelMemoryId;
    createNodeContainer();
    return true;
}(); 

Variable &debugMode = RuntimeEnvironment.debugMode;
Variable &aspectRatio = RuntimeEnvironment.screenAspectRatio;
struct offset {
    Variable &audio = RuntimeEnvironment.audioOffset;
    Variable &input = RuntimeEnvironment.inputOffset;
}offsets;
Variable &replay = RuntimeEnvironment.replay;
struct times {
    Variable &now = RuntimeUpdate.time;
    Variable &delta = RuntimeUpdate.deltaTime;
    Variable &scaled = RuntimeUpdate.scaledTime;
}times;
Variable &skip = RuntimeUpdate.skip;
struct transforms {
    VariablesArray<RuntimeSkinTransformId> &skin = RuntimeSkinTransform;
    VariablesArray<RuntimeParticleTransformId> &particle = RuntimeParticleTransform;
}transforms;
RuntimeUIGroup &ui = RuntimeUI;
RuntimeUIConfigurationGroup &configuration = RuntimeUIConfiguration;
BlocksArray<LevelBucketGroup> &buckets = LevelBucket;
LevelScoreGroup &scores = LevelScore;
LevelLifeGroup &lifes = LevelLife;

template<typename T>
SonolusApi setUI(T &ui, var anchorX, var anchorY, var pivotX, var pivotY, var width, var height, var rotation, var alpha, var horizontalAlign, var background) {
    ui.anchorX = anchorX; ui.anchorY = anchorY;
    ui.pivotX = pivotX; ui.pivotY = pivotY;
    ui.width = width; ui.height = height;
    ui.rotation = rotation;
    ui.alpha = alpha;
    ui.horizontalAlign = horizontalAlign;
    ui.background = background;
}

SonolusApi setBucket(var bucketId, var perfectMin, var perfectMax, var greatMin, var greatMax, var goodMin, var goodMax) {
    buckets[bucketId].perfect.min = perfectMin;
    buckets[bucketId].perfect.max = perfectMax;
    buckets[bucketId].great.min = greatMin;
    buckets[bucketId].great.max = greatMax;
    buckets[bucketId].good.min = goodMin;
    buckets[bucketId].good.max = goodMax;
}

SonolusApi setScore(var perfect, var great, var good) {
    scores.perfect_multiplier = perfect;
    scores.great_multiplier = great;
    scores.good_multiplier = good;
}

#endif