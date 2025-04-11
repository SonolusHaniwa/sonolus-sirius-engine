#ifndef PlayBlocks_H
#define PlayBlocks_H

const int RuntimeEnvironmentId = 1000;
const int RuntimeUpdateId = 1001;
const int RuntimeTouchArrayId = 1002;
const int RuntimeSkinTransformId = 1003;
const int RuntimeParticleTransformId = 1004;
const int RuntimeBackgroundId = 1005;
const int RuntimeUIId = 1006;
const int RuntimeUIConfigurationId = 1007;
const int LevelMemoryId = 2000;
const int LevelDataId = 2001;
const int LevelOptionId = 2002;
const int LevelBucketId = 2003;
const int LevelScoreId = 2004;
const int LevelLifeId = 2005;
const int EngineRomId = 3000;
const int EntityMemoryId = 4000;
const int EntityDataId = 4001;
const int EntitySharedMemoryId = 4002;
const int EntityInfoId = 4003;
const int EntityDespawnId = 4004;
const int EntityInputId = 4005;
const int EntityDataArrayId = 4101;
const int EntitySharedMemoryArrayId = 4102;
const int EntityInfoArrayId = 4103;
const int ArchetypeLifeId = 5000;
const int TemporaryMemoryId = 10000;

bool unused_readable_unused = [](){
	readable = {
		{ RuntimeEnvironmentId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ RuntimeUpdateId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ RuntimeTouchArrayId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ RuntimeSkinTransformId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ RuntimeParticleTransformId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ RuntimeBackgroundId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ RuntimeUIId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ RuntimeUIConfigurationId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ LevelMemoryId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ LevelDataId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ LevelOptionId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ LevelBucketId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ LevelScoreId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ LevelLifeId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EngineRomId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityMemoryId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityDataId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntitySharedMemoryId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityInfoId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityDespawnId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityInputId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityDataArrayId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntitySharedMemoryArrayId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityInfoArrayId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ ArchetypeLifeId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ TemporaryMemoryId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } }
	};
	return true;
}();

bool unused_writable_unused = [](){
	writable = {
		{ RuntimeEnvironmentId, { "preprocess" } },
		{ RuntimeUpdateId, {  } },
		{ RuntimeTouchArrayId, {  } },
		{ RuntimeSkinTransformId, { "preprocess", "updateSequential", "touch" } },
		{ RuntimeParticleTransformId, { "preprocess", "updateSequential", "touch" } },
		{ RuntimeBackgroundId, { "preprocess", "updateSequential", "touch" } },
		{ RuntimeUIId, { "preprocess" } },
		{ RuntimeUIConfigurationId, { "preprocess" } },
		{ LevelMemoryId, { "preprocess", "updateSequential", "touch" } },
		{ LevelDataId, { "preprocess" } },
		{ LevelOptionId, {  } },
		{ LevelBucketId, { "preprocess" } },
		{ LevelScoreId, { "preprocess" } },
		{ LevelLifeId, { "preprocess" } },
		{ EngineRomId, {  } },
		{ EntityMemoryId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityDataId, { "preprocess" } },
		{ EntitySharedMemoryId, { "preprocess", "updateSequential", "touch" } },
		{ EntityInfoId, {  } },
		{ EntityDespawnId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityInputId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } },
		{ EntityDataArrayId, { "preprocess" } },
		{ EntitySharedMemoryArrayId, { "preprocess", "updateSequential", "touch" } },
		{ EntityInfoArrayId, {  } },
		{ ArchetypeLifeId, { "preprocess" } },
		{ TemporaryMemoryId, { "preprocess", "spawnOrder", "shouldSpawn", "initialize", "updateSequential", "touch", "updateParallel", "terminate" } }
	};
	return true;
}();

bool unused_blockName_unused = [](){
	blockName = {
		{ RuntimeEnvironmentId, "RuntimeEnvironment" },
		{ RuntimeUpdateId, "RuntimeUpdate" },
		{ RuntimeTouchArrayId, "RuntimeTouchArray" },
		{ RuntimeSkinTransformId, "RuntimeSkinTransform" },
		{ RuntimeParticleTransformId, "RuntimeParticleTransform" },
		{ RuntimeBackgroundId, "RuntimeBackground" },
		{ RuntimeUIId, "RuntimeUI" },
		{ RuntimeUIConfigurationId, "RuntimeUIConfiguration" },
		{ LevelMemoryId, "LevelMemory" },
		{ LevelDataId, "LevelData" },
		{ LevelOptionId, "LevelOption" },
		{ LevelBucketId, "LevelBucket" },
		{ LevelScoreId, "LevelScore" },
		{ LevelLifeId, "LevelLife" },
		{ EngineRomId, "EngineRom" },
		{ EntityMemoryId, "EntityMemory" },
		{ EntityDataId, "EntityData" },
		{ EntitySharedMemoryId, "EntitySharedMemory" },
		{ EntityInfoId, "EntityInfo" },
		{ EntityDespawnId, "EntityDespawn" },
		{ EntityInputId, "EntityInput" },
		{ EntityDataArrayId, "EntityDataArray" },
		{ EntitySharedMemoryArrayId, "EntitySharedMemoryArray" },
		{ EntityInfoArrayId, "EntityInfoArray" },
		{ ArchetypeLifeId, "ArchetypeLife" },
		{ TemporaryMemoryId, "TemporaryMemory" }
	};
	return true;
}();

bool unused_writeBlockInfo_unused = [](){
	SonolusMemorySize[LevelMemoryId] = 4096;
	SonolusMemoryDelta[LevelMemoryId] = 1;
	allowAllocate.insert(LevelMemoryId);
	SonolusMemorySize[LevelDataId] = 4096;
	SonolusMemoryDelta[LevelDataId] = 1;
	allowAllocate.insert(LevelDataId);
	SonolusMemorySize[EntityMemoryId] = 64;
	SonolusMemoryDelta[EntityMemoryId] = 1;
	allowAllocate.insert(EntityMemoryId);
	SonolusMemorySize[EntityDataId] = 32;
	SonolusMemoryDelta[EntityDataId] = 1;
	allowAllocate.insert(EntityDataId);
	SonolusMemorySize[EntitySharedMemoryId] = 32;
	SonolusMemoryDelta[EntitySharedMemoryId] = 1;
	allowAllocate.insert(EntitySharedMemoryId);
	SonolusMemorySize[TemporaryMemoryId] = 4096;
	SonolusMemoryDelta[TemporaryMemoryId] = 1;
	allowAllocate.insert(TemporaryMemoryId);
	return true;
}();

struct RuntimeEnvironmentGroup{
	Variable debugMode = Variable(RuntimeEnvironmentId, 0);
	Variable screenAspectRatio = Variable(RuntimeEnvironmentId, 0);
	Variable audioOffset = Variable(RuntimeEnvironmentId, 0);
	Variable inputOffset = Variable(RuntimeEnvironmentId, 0);
	Variable multiplayer = Variable(RuntimeEnvironmentId, 0);

	Constructor RuntimeEnvironmentGroup(FuncNode offset) {
		debugMode.reallocate(offset + 0);
		screenAspectRatio.reallocate(offset + 1);
		audioOffset.reallocate(offset + 2);
		inputOffset.reallocate(offset + 3);
		multiplayer.reallocate(offset + 4);
	}
};
RuntimeEnvironmentGroup RuntimeEnvironment = RuntimeEnvironmentGroup(0);

struct RuntimeUpdateGroup{
	Variable time = Variable(RuntimeUpdateId, 0);
	Variable deltaTime = Variable(RuntimeUpdateId, 0);
	Variable scaledTime = Variable(RuntimeUpdateId, 0);
	Variable touchCount = Variable(RuntimeUpdateId, 0);

	Constructor RuntimeUpdateGroup(FuncNode offset) {
		time.reallocate(offset + 0);
		deltaTime.reallocate(offset + 1);
		scaledTime.reallocate(offset + 2);
		touchCount.reallocate(offset + 3);
	}
};
RuntimeUpdateGroup RuntimeUpdate = RuntimeUpdateGroup(0);

struct RuntimeTouchArrayGroup{
	Variable id = Variable(RuntimeTouchArrayId, 0);
	Variable started = Variable(RuntimeTouchArrayId, 0);
	Variable ended = Variable(RuntimeTouchArrayId, 0);
	Variable t = Variable(RuntimeTouchArrayId, 0);
	Variable st = Variable(RuntimeTouchArrayId, 0);
	Variable x = Variable(RuntimeTouchArrayId, 0);
	Variable y = Variable(RuntimeTouchArrayId, 0);
	Variable sx = Variable(RuntimeTouchArrayId, 0);
	Variable sy = Variable(RuntimeTouchArrayId, 0);
	Variable dx = Variable(RuntimeTouchArrayId, 0);
	Variable dy = Variable(RuntimeTouchArrayId, 0);
	Variable vx = Variable(RuntimeTouchArrayId, 0);
	Variable vy = Variable(RuntimeTouchArrayId, 0);
	Variable vr = Variable(RuntimeTouchArrayId, 0);
	Variable vw = Variable(RuntimeTouchArrayId, 0);

	Constructor RuntimeTouchArrayGroup(FuncNode offset) {
		id.reallocate(offset + 0);
		started.reallocate(offset + 1);
		ended.reallocate(offset + 2);
		t.reallocate(offset + 3);
		st.reallocate(offset + 4);
		x.reallocate(offset + 5);
		y.reallocate(offset + 6);
		sx.reallocate(offset + 7);
		sy.reallocate(offset + 8);
		dx.reallocate(offset + 9);
		dy.reallocate(offset + 10);
		vx.reallocate(offset + 11);
		vy.reallocate(offset + 12);
		vr.reallocate(offset + 13);
		vw.reallocate(offset + 14);
	}
};
BlocksArray<RuntimeTouchArrayGroup> RuntimeTouchArray = BlocksArray<RuntimeTouchArrayGroup>(15);

VariablesArray<RuntimeSkinTransformId> RuntimeSkinTransform = VariablesArray<RuntimeSkinTransformId>(0, 1 << 16);

VariablesArray<RuntimeParticleTransformId> RuntimeParticleTransform = VariablesArray<RuntimeParticleTransformId>(0, 1 << 16);

struct RuntimeBackgroundGroup{
	Variable x = Variable(RuntimeBackgroundId, 0);
	Variable y = Variable(RuntimeBackgroundId, 0);

	Constructor RuntimeBackgroundGroup(FuncNode offset) {
		x.reallocate(offset + 0);
		y.reallocate(offset + 1);
	}
};
BlocksArray<RuntimeBackgroundGroup> RuntimeBackground = BlocksArray<RuntimeBackgroundGroup>(2);

struct RuntimeUIGroup{
	struct Group_MYQveg5DpKye902Z{
		Variable anchorX = Variable(RuntimeUIId, 0);
		Variable anchorY = Variable(RuntimeUIId, 0);
		Variable pivotX = Variable(RuntimeUIId, 0);
		Variable pivotY = Variable(RuntimeUIId, 0);
		Variable width = Variable(RuntimeUIId, 0);
		Variable height = Variable(RuntimeUIId, 0);
		Variable rotation = Variable(RuntimeUIId, 0);
		Variable alpha = Variable(RuntimeUIId, 0);
		Variable horizontalAlign = Variable(RuntimeUIId, 0);
		Variable background = Variable(RuntimeUIId, 0);

		void reallocate(FuncNode offset) {
			anchorX.reallocate(offset + 0);
			anchorY.reallocate(offset + 1);
			pivotX.reallocate(offset + 2);
			pivotY.reallocate(offset + 3);
			width.reallocate(offset + 4);
			height.reallocate(offset + 5);
			rotation.reallocate(offset + 6);
			alpha.reallocate(offset + 7);
			horizontalAlign.reallocate(offset + 8);
			background.reallocate(offset + 9);
		}
	};
	Group_MYQveg5DpKye902Z menu;
	Group_MYQveg5DpKye902Z judgment;
	Group_MYQveg5DpKye902Z comboValue;
	Group_MYQveg5DpKye902Z comboText;
	Group_MYQveg5DpKye902Z primaryMetricBar;
	Group_MYQveg5DpKye902Z primaryMetricValue;
	Group_MYQveg5DpKye902Z secondaryMetricBar;
	Group_MYQveg5DpKye902Z secondaryMetricValue;

	Constructor RuntimeUIGroup(FuncNode offset) {
		menu.reallocate(offset + 0);
		judgment.reallocate(offset + 10);
		comboValue.reallocate(offset + 20);
		comboText.reallocate(offset + 30);
		primaryMetricBar.reallocate(offset + 40);
		primaryMetricValue.reallocate(offset + 50);
		secondaryMetricBar.reallocate(offset + 60);
		secondaryMetricValue.reallocate(offset + 70);
	}
};
RuntimeUIGroup RuntimeUI = RuntimeUIGroup(0);

struct RuntimeUIConfigurationGroup{
	struct Group_s7jSpZv7FXeEyerI{
		Variable scale = Variable(RuntimeUIConfigurationId, 0);
		Variable alpha = Variable(RuntimeUIConfigurationId, 0);

		void reallocate(FuncNode offset) {
			scale.reallocate(offset + 0);
			alpha.reallocate(offset + 1);
		}
	};
	Group_s7jSpZv7FXeEyerI menu;
	Group_s7jSpZv7FXeEyerI judgment;
	Group_s7jSpZv7FXeEyerI combo;
	Group_s7jSpZv7FXeEyerI primaryMetric;
	Group_s7jSpZv7FXeEyerI secondaryMetric;

	Constructor RuntimeUIConfigurationGroup(FuncNode offset) {
		menu.reallocate(offset + 0);
		judgment.reallocate(offset + 2);
		combo.reallocate(offset + 4);
		primaryMetric.reallocate(offset + 6);
		secondaryMetric.reallocate(offset + 8);
	}
};
RuntimeUIConfigurationGroup RuntimeUIConfiguration = RuntimeUIConfigurationGroup(0);

VariablesArray<LevelMemoryId> LevelMemory = VariablesArray<LevelMemoryId>(0, 1 << 16);

VariablesArray<LevelDataId> LevelData = VariablesArray<LevelDataId>(0, 1 << 16);

VariablesArray<LevelOptionId> LevelOption = VariablesArray<LevelOptionId>(0, 1 << 16);

struct LevelBucketGroup{
	struct Group_AIEowH1mZxOgyQFq{
		Variable min = Variable(LevelBucketId, 0);
		Variable max = Variable(LevelBucketId, 0);

		void reallocate(FuncNode offset) {
			min.reallocate(offset + 0);
			max.reallocate(offset + 1);
		}
	};
	Group_AIEowH1mZxOgyQFq perfect;
	Group_AIEowH1mZxOgyQFq great;
	Group_AIEowH1mZxOgyQFq good;

	Constructor LevelBucketGroup(FuncNode offset) {
		perfect.reallocate(offset + 0);
		great.reallocate(offset + 2);
		good.reallocate(offset + 4);
	}
};
BlocksArray<LevelBucketGroup> LevelBucket = BlocksArray<LevelBucketGroup>(6);

struct LevelScoreGroup{
	Variable perfect_multiplier = Variable(LevelScoreId, 0);
	Variable great_multiplier = Variable(LevelScoreId, 0);
	Variable good_multiplier = Variable(LevelScoreId, 0);
	struct Group_VxHKUCPih3wdhlwr{
		Variable consecutiveMultiplier = Variable(LevelScoreId, 0);
		Variable consecutiveStep = Variable(LevelScoreId, 0);
		Variable consecutiveCap = Variable(LevelScoreId, 0);

		void reallocate(FuncNode offset) {
			consecutiveMultiplier.reallocate(offset + 0);
			consecutiveStep.reallocate(offset + 1);
			consecutiveCap.reallocate(offset + 2);
		}
	};
	Group_VxHKUCPih3wdhlwr perfect;
	Group_VxHKUCPih3wdhlwr great;
	Group_VxHKUCPih3wdhlwr good;

	Constructor LevelScoreGroup(FuncNode offset) {
		perfect_multiplier.reallocate(offset + 0);
		great_multiplier.reallocate(offset + 1);
		good_multiplier.reallocate(offset + 2);
		perfect.reallocate(offset + 3);
		great.reallocate(offset + 6);
		good.reallocate(offset + 9);
	}
};
LevelScoreGroup LevelScore = LevelScoreGroup(0);

struct LevelLifeGroup{
	struct Group_18dyPckwa6dWWqKz{
		Variable consecutiveIncrement = Variable(LevelLifeId, 0);
		Variable consecutiveStep = Variable(LevelLifeId, 0);

		void reallocate(FuncNode offset) {
			consecutiveIncrement.reallocate(offset + 0);
			consecutiveStep.reallocate(offset + 1);
		}
	};
	Group_18dyPckwa6dWWqKz perfect;
	Group_18dyPckwa6dWWqKz great;
	Group_18dyPckwa6dWWqKz good;

	Constructor LevelLifeGroup(FuncNode offset) {
		perfect.reallocate(offset + 0);
		great.reallocate(offset + 2);
		good.reallocate(offset + 4);
	}
};
LevelLifeGroup LevelLife = LevelLifeGroup(0);

VariablesArray<EngineRomId> EngineRom = VariablesArray<EngineRomId>(0, 1 << 16);

VariablesArray<EntityMemoryId> EntityMemory = VariablesArray<EntityMemoryId>(0, 1 << 16);

VariablesArray<EntityDataId> EntityData = VariablesArray<EntityDataId>(0, 1 << 16);

VariablesArray<EntitySharedMemoryId> EntitySharedMemory = VariablesArray<EntitySharedMemoryId>(0, 1 << 16);

struct EntityInfoGroup{
	Variable index = Variable(EntityInfoId, 0);
	Variable archetype = Variable(EntityInfoId, 0);
	Variable state = Variable(EntityInfoId, 0);

	Constructor EntityInfoGroup(FuncNode offset) {
		index.reallocate(offset + 0);
		archetype.reallocate(offset + 1);
		state.reallocate(offset + 2);
	}
};
EntityInfoGroup EntityInfo = EntityInfoGroup(0);

struct EntityDespawnGroup{
	Variable despawn = Variable(EntityDespawnId, 0);

	Constructor EntityDespawnGroup(FuncNode offset) {
		despawn.reallocate(offset + 0);
	}
};
EntityDespawnGroup EntityDespawn = EntityDespawnGroup(0);

struct EntityInputGroup{
	Variable judgment = Variable(EntityInputId, 0);
	Variable accuracy = Variable(EntityInputId, 0);
	Variable bucketIndex = Variable(EntityInputId, 0);
	Variable bucketValue = Variable(EntityInputId, 0);

	Constructor EntityInputGroup(FuncNode offset) {
		judgment.reallocate(offset + 0);
		accuracy.reallocate(offset + 1);
		bucketIndex.reallocate(offset + 2);
		bucketValue.reallocate(offset + 3);
	}
};
EntityInputGroup EntityInput = EntityInputGroup(0);

struct EntityDataArrayGroup{
	VariablesArray<EntityDataArrayId> generic = VariablesArray<EntityDataArrayId>(0, 32);

	Constructor EntityDataArrayGroup(FuncNode offset) {
		generic = VariablesArray<EntityDataArrayId>(offset + 0, 32);
	}
};
BlocksArray<EntityDataArrayGroup> EntityDataArray = BlocksArray<EntityDataArrayGroup>(32);

struct EntitySharedMemoryArrayGroup{
	VariablesArray<EntitySharedMemoryArrayId> generic = VariablesArray<EntitySharedMemoryArrayId>(0, 32);

	Constructor EntitySharedMemoryArrayGroup(FuncNode offset) {
		generic = VariablesArray<EntitySharedMemoryArrayId>(offset + 0, 32);
	}
};
BlocksArray<EntitySharedMemoryArrayGroup> EntitySharedMemoryArray = BlocksArray<EntitySharedMemoryArrayGroup>(32);

struct EntityInfoArrayGroup{
	Variable index = Variable(EntityInfoArrayId, 0);
	Variable archetype = Variable(EntityInfoArrayId, 0);
	Variable state = Variable(EntityInfoArrayId, 0);

	Constructor EntityInfoArrayGroup(FuncNode offset) {
		index.reallocate(offset + 0);
		archetype.reallocate(offset + 1);
		state.reallocate(offset + 2);
	}
};
BlocksArray<EntityInfoArrayGroup> EntityInfoArray = BlocksArray<EntityInfoArrayGroup>(3);

struct ArchetypeLifeGroup{
	Variable perfect_increment = Variable(ArchetypeLifeId, 0);
	Variable great_increment = Variable(ArchetypeLifeId, 0);
	Variable good_increment = Variable(ArchetypeLifeId, 0);
	Variable miss_increment = Variable(ArchetypeLifeId, 0);

	Constructor ArchetypeLifeGroup(FuncNode offset) {
		perfect_increment.reallocate(offset + 0);
		great_increment.reallocate(offset + 1);
		good_increment.reallocate(offset + 2);
		miss_increment.reallocate(offset + 3);
	}
};
BlocksArray<ArchetypeLifeGroup> ArchetypeLife = BlocksArray<ArchetypeLifeGroup>(4);

VariablesArray<TemporaryMemoryId> TemporaryMemory = VariablesArray<TemporaryMemoryId>(0, 1 << 16);


#endif
