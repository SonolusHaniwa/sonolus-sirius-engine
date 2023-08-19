using namespace std;

namespace playData {
    const int LevelMemoryId = 2000;
    const int LevelDataId = 2001;
    const int LevelOptionId = 2002;
    const int LevelBucketId = 2003;
    const int LevelScoreId = 2004;
    const int LevelLifeId = 2005;
    const int EntityInfoArrayId = 4103;
    const int EntityDataArrayId = 4101;
    const int EntitySharedMemoryArrayId = 4102;
    const int EntityInfoId = 4003;
    const int EntityMemoryId = 4000;
    const int EntityDataId = 4001;
    const int EntityInputId = 4005;
    const int EntitySharedMemoryId = 4002;
    const int ArchetypeLifeId = 5000;
    const int EngineRomId = 3000;
    const int TemporaryMemoryId = 10000;
    const int EntityDespawnId = 4004;
    const int RuntimeEnvironmentId = 1000;
    const int RuntimeUpdateId = 1001;
    const int RuntimeTouchArrayId = 1002;
    const int RuntimeSkinTransformId = 1003;
    const int RuntimeParticleTransformId = 1004;
    const int RuntimeBackgroundId = 1005;
    const int RuntimeUIId = 1006;
    const int RuntimeUIConfigurationId = 1007;

    Pointer<RuntimeEnvironmentId> RuntimeEnvironment;
    Pointer<RuntimeUpdateId> RuntimeUpdate;
    Pointer<RuntimeTouchArrayId> RuntimeTouch;
    Pointer<RuntimeSkinTransformId> RuntimeSkinTransform;
    Pointer<RuntimeParticleTransformId> RuntimeParticleTransform;
    Pointer<RuntimeBackgroundId> RuntimeBackground;
    Pointer<RuntimeUIId> RuntimeUI;
    Pointer<RuntimeUIConfigurationId> RuntimeUIConfiguration;
    Pointer<LevelMemoryId> LevelMemory;
    Pointer<LevelDataId> LevelData;
    Pointer<LevelOptionId> LevelOption;
    Pointer<LevelBucketId> LevelBucket;
    Pointer<LevelScoreId> LevelScore;
    Pointer<LevelLifeId> LevelLife;
    Pointer<EngineRomId> EngineRom;
    Pointer<EntityMemoryId> EntityMemory;
    Pointer<EntityDataArrayId> EntityDataArray;
    Pointer<EntityDataId> EntityData;
    Pointer<EntitySharedMemoryArrayId> EntitySharedMemoryArray;
    Pointer<EntitySharedMemoryId> EntitySharedMemory;
    Pointer<EntityInfoArrayId> EntityInfoArray;
    Pointer<EntityInfoId> EntityInfo;
    Pointer<EntityDespawnId> EntityDespawn;
    Pointer<EntityInputId> EntityInput;
    Pointer<ArchetypeLifeId> ArchetypeLife;
    Pointer<TemporaryMemoryId> TemporaryMemory;

    class screen {
        public:

        FuncNode aspectRatio = RuntimeEnvironment.get(1);
        FuncNode l = Multiply({-1, aspectRatio});
        FuncNode b = -1;
        FuncNode r = aspectRatio;
        FuncNode t = 1;
        FuncNode w = Multiply({aspectRatio, 2});
        FuncNode h = 2;
    }screen;

    class ui {
        public:

        class layout {
            public: 

            FuncNode offset = 0;
            layout(){};
            layout(FuncNode offset):offset(offset){};

            FuncNode anchorX = RuntimeUI.get(Add({Multiply({offset, 10}), 0}));
            FuncNode anchorY = RuntimeUI.get(Add({Multiply({offset, 10}), 1}));
            FuncNode pivotX = RuntimeUI.get(Add({Multiply({offset, 10}), 2}));
            FuncNode pivotY = RuntimeUI.get(Add({Multiply({offset, 10}), 3}));
            FuncNode width = RuntimeUI.get(Add({Multiply({offset, 10}), 4}));
            FuncNode height = RuntimeUI.get(Add({Multiply({offset, 10}), 5}));
            FuncNode rotation = RuntimeUI.get(Add({Multiply({offset, 10}), 6}));
            FuncNode alpha = RuntimeUI.get(Add({Multiply({offset, 10}), 7}));
            FuncNode horizontalAlign = RuntimeUI.get(Add({Multiply({offset, 10}), 8}));
            FuncNode background = RuntimeUI.get(Add({Multiply({offset, 10}), 9}));


            FuncNode set(FuncNode anchorX, FuncNode anchorY, FuncNode pivotX, FuncNode pivotY, FuncNode width, FuncNode height, FuncNode rotation, FuncNode alpha, FuncNode horizontalAlign, FuncNode background) {
                return Execute({
                    RuntimeUI.set(Add({Multiply({offset, 10}), 0}), anchorX),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 1}), anchorY),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 2}), pivotX),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 3}), pivotY),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 4}), width),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 5}), height),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 6}), rotation),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 7}), alpha),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 8}), horizontalAlign),
                    RuntimeUI.set(Add({Multiply({offset, 10}), 9}), background),
                });
            }
        };

        class configuration {
            public:

            FuncNode offset = 0;
            configuration(){};
            configuration(FuncNode offset):offset(offset){};

            FuncNode scale = RuntimeUIConfiguration.get(Add({Multiply({offset, 2}), 0}));
            FuncNode alpha = RuntimeUIConfiguration.get(Add({Multiply({offset, 2}), 1}));
        };

        layout menu = layout(0);
        layout judgment = layout(1);
        layout comboValue = layout(2);
        layout comboText = layout(3);
        layout primaryMetricBar = layout(4);
        layout primaryMetricValue = layout(5);
        layout secondaryMetricBar = layout(6);
        layout secondaryMetricValue = layout(7);

        configuration menuConfiguration = configuration(0);
        configuration judgmentConfiguration = configuration(1);
        configuration comboConfiguration = configuration(2);
        configuration primaryMetricConfiguration = configuration(3);
        configuration secondaryMetricConfiguration = configuration(4);
    }ui;

    class life {
        public:

        FuncNode offset = 0;
        FuncNode perfect = ArchetypeLife.get(0);
        FuncNode great = ArchetypeLife.get(1);
        FuncNode good = ArchetypeLife.get(2);
        FuncNode miss = ArchetypeLife.get(3);

        life(){};
        life(FuncNode offset):offset(offset){
            perfect = ArchetypeLife.get(Add({Multiply({offset, 4}), 0}));
            great = ArchetypeLife.get(Add({Multiply({offset, 4}), 1}));
            good = ArchetypeLife.get(Add({Multiply({offset, 4}), 2}));
            miss = ArchetypeLife.get(Add({Multiply({offset, 4}), 3}));
        };
        life operator [] (FuncNode offset) {
            return life(offset);
        }
        FuncNode set(FuncNode perfect, FuncNode great, FuncNode good, FuncNode bad) {
            return Execute({
                ArchetypeLife.set(Add({Multiply({offset, 4}), 0}), perfect),
                ArchetypeLife.set(Add({Multiply({offset, 4}), 1}), great),
                ArchetypeLife.set(Add({Multiply({offset, 4}), 2}), good),
                ArchetypeLife.set(Add({Multiply({offset, 4}), 3}), bad),
            });
        }
    }lifes;

    class bucket {
        public:

        FuncNode offset = 0;
        FuncNode minPerfect = LevelBucket.get(0), maxPerfect = LevelBucket.get(1);
        FuncNode minGreat = LevelBucket.get(2), maxGreat = LevelBucket.get(3);
        FuncNode minGood = LevelBucket.get(4), maxGood = LevelBucket.get(5);

        bucket(){}
        bucket(FuncNode offset):offset(offset){
            minPerfect = LevelBucket.get(Add({Multiply({offset, 6}), 0}));
            maxPerfect = LevelBucket.get(Add({Multiply({offset, 6}), 1}));
            minGreat = LevelBucket.get(Add({Multiply({offset, 6}), 2}));
            maxGreat = LevelBucket.get(Add({Multiply({offset, 6}), 3}));
            minGood = LevelBucket.get(Add({Multiply({offset, 6}), 4}));
            maxGood = LevelBucket.get(Add({Multiply({offset, 6}), 5}));
        }
        bucket operator [] (FuncNode offset) {
            return bucket(offset);
        }

        FuncNode set(FuncNode minPerfect, FuncNode maxPerfect, FuncNode minGreat, FuncNode maxGreat, FuncNode minGood, FuncNode maxGood) {
            return Execute({
                LevelBucket.set(Add({Multiply({offset, 6}), 0}), minPerfect),
                LevelBucket.set(Add({Multiply({offset, 6}), 1}), maxPerfect),
                LevelBucket.set(Add({Multiply({offset, 6}), 2}), minGreat),
                LevelBucket.set(Add({Multiply({offset, 6}), 3}), maxGreat),
                LevelBucket.set(Add({Multiply({offset, 6}), 4}), minGood),
                LevelBucket.set(Add({Multiply({offset, 6}), 5}), maxGood)
            });
        }
    }buckets;

    class entityInfo {
        public:

        FuncNode id = EntityInfo.get(0);
        FuncNode archetype = EntityInfo.get(1);
        FuncNode state = EntityInfo.get(2);
    }entityInfo;

    class Touch {
        public:

        FuncNode offset = 0;
        Touch(){};
        Touch(FuncNode offset):offset(offset){};
        Touch operator [] (FuncNode offset) {
            return Touch(offset);
        }
        FuncNode size = RuntimeUpdate.get(3);

        FuncNode id = RuntimeTouch.get(Add({Multiply({offset, 15}), 0}));
        FuncNode started = RuntimeTouch.get(Add({Multiply({offset, 15}), 1}));
        FuncNode ended = RuntimeTouch.get(Add({Multiply({offset, 15}), 2}));
        FuncNode t = RuntimeTouch.get(Add({Multiply({offset, 15}), 3}));
        FuncNode st = RuntimeTouch.get(Add({Multiply({offset, 15}), 4}));
        FuncNode x = RuntimeTouch.get(Add({Multiply({offset, 15}), 5}));
        FuncNode y = RuntimeTouch.get(Add({Multiply({offset, 15}), 6}));
        FuncNode sx = RuntimeTouch.get(Add({Multiply({offset, 15}), 7}));
        FuncNode sy = RuntimeTouch.get(Add({Multiply({offset, 15}), 8}));
        FuncNode dx = RuntimeTouch.get(Add({Multiply({offset, 15}), 9}));
        FuncNode dy = RuntimeTouch.get(Add({Multiply({offset, 15}), 10}));
        FuncNode vx = RuntimeTouch.get(Add({Multiply({offset, 15}), 11}));
        FuncNode vy = RuntimeTouch.get(Add({Multiply({offset, 15}), 12}));
        FuncNode vr = RuntimeTouch.get(Add({Multiply({offset, 15}), 13}));
        FuncNode vw = RuntimeTouch.get(Add({Multiply({offset, 15}), 14}));
    }touches;

    int allocatorSize[10000] = {0};

    template<int identifierId>
    class Array {
        public:

        int offset;
        int capacity;
        FuncNode size = Get(identifierId, 0);
        int sizeOffset = 0;

        Array(){}
        Array(int capacity):capacity(capacity){
            sizeOffset = allocatorSize[identifierId];
            size = Get(identifierId, sizeOffset);
            offset = allocatorSize[identifierId] + 1;
            allocatorSize[identifierId] += capacity + 1;
        };
        FuncNode operator [] (FuncNode id) {
            return Get(identifierId, Add({id, offset}));
        }
        FuncNode add(FuncNode value) {
            return Execute({
                Set(identifierId, Add({size, offset}), value),
                Set(identifierId, sizeOffset, Add({size, 1})),
            });
        }
        FuncNode has(FuncNode value) {
            FuncNode res = false;
            for (int i = capacity - 1; i >= 0; i--) {
                res = If(
                    Equal(Get(identifierId, Add({i, offset})), value),
                    true,
                    res
                );
            } return res;
        }
        FuncNode indexOf(FuncNode value) {
            FuncNode res = -1;
            for (int i = capacity - 1; i >= 0; i--) {
                res = If(
                    Equal(Get(identifierId, Add({i, offset})), value),
                    i,
                    res
                );
            } return res;
        }
        FuncNode clear() {
            FuncNode res = Execute({Set(identifierId, sizeOffset, 0)});
            for (int i = 0; i < capacity; i++) res.args.push_back(Set(identifierId, Add({i, offset}), 0));
            return res;
        }
    };

    template<int identifierId>
    class Variable {
        public:

        int offset;
        Variable(){
            offset = allocatorSize[identifierId]++;
        }

        FuncNode get() {
            return Get(identifierId, offset);
        }
        FuncNode add(FuncNode value) {
            return Set(identifierId, offset, Add({Get(identifierId, offset), value}));
        }
        FuncNode subtract(FuncNode value) {
            return Set(identifierId, offset, Subtract({Get(identifierId, offset), value}));
        }
        FuncNode multiply(FuncNode value) {
            return Set(identifierId, offset, Multiply({Get(identifierId, offset), value}));
        }
        FuncNode divide(FuncNode value) {
            return Set(identifierId, offset, Divide({Get(identifierId, offset), value}));
        }
        FuncNode mod(FuncNode value) {
            return Set(identifierId, offset, Mod({Get(identifierId, offset), value}));
        }
        FuncNode set(FuncNode value) {
            return Set(identifierId, offset, value);
        }
    };

    Variable<EntityMemoryId> ForPt;
    Variable<EntityMemoryId> isHighlighted;
    Variable<EntityMemoryId> playLoopedId;
    Variable<EntityMemoryId> trackTouchId;

    class HorizontalAlign {
        public:

        int Left = -1;
        int Center = 0;
        int Right = 1;
    }HorizontalAlign;

    class EntityState {
        public:

        int Waiting = 0;
        int Active = 1;
        int Despawned = 2;    
    }EntityState;

    class times {
        public:

        FuncNode now = RuntimeUpdate.get(0);
        FuncNode delta = RuntimeUpdate.get(1);
        FuncNode scaled = RuntimeUpdate.get(2);
    }times;
};