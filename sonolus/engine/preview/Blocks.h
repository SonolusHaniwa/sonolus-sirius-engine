#ifndef PreviewBlocks_H
#define PreviewBlocks_H

const int RuntimeEnvironmentId = 1000;
const int RuntimeCanvasId = 1001;
const int RuntimeSkinTransformId = 1002;
const int RuntimeUIId = 1003;
const int RuntimeUIConfigurationId = 1004;
const int PreviewDataId = 2000;
const int PreviewOptionId = 2001;
const int EngineRomId = 3000;
const int EntityDataId = 4000;
const int EntitySharedMemoryId = 4001;
const int EntityInfoId = 4002;
const int EntityDataArrayId = 4100;
const int EntitySharedMemoryArrayId = 4101;
const int EntityInfoArrayId = 4102;
const int TemporaryMemoryId = 10000;

bool unused_readable_unused = [](){
	readable = {
		{ RuntimeEnvironmentId, { "preprocess", "render" } },
		{ RuntimeCanvasId, { "preprocess", "render" } },
		{ RuntimeSkinTransformId, { "preprocess", "render" } },
		{ RuntimeUIId, { "preprocess", "render" } },
		{ RuntimeUIConfigurationId, { "preprocess", "render" } },
		{ PreviewDataId, { "preprocess", "render" } },
		{ PreviewOptionId, { "preprocess", "render" } },
		{ EngineRomId, { "preprocess", "render" } },
		{ EntityDataId, { "preprocess", "render" } },
		{ EntitySharedMemoryId, { "preprocess", "render" } },
		{ EntityInfoId, { "preprocess", "render" } },
		{ EntityDataArrayId, { "preprocess", "render" } },
		{ EntitySharedMemoryArrayId, { "preprocess", "render" } },
		{ EntityInfoArrayId, { "preprocess", "render" } },
		{ TemporaryMemoryId, { "preprocess", "render" } }
	};
	return true;
}();

bool unused_writable_unused = [](){
	writable = {
		{ RuntimeEnvironmentId, { "preprocess" } },
		{ RuntimeCanvasId, { "preprocess" } },
		{ RuntimeSkinTransformId, { "preprocess" } },
		{ RuntimeUIId, { "preprocess" } },
		{ RuntimeUIConfigurationId, { "preprocess" } },
		{ PreviewDataId, { "preprocess" } },
		{ PreviewOptionId, {  } },
		{ EngineRomId, {  } },
		{ EntityDataId, { "preprocess" } },
		{ EntitySharedMemoryId, { "preprocess" } },
		{ EntityInfoId, {  } },
		{ EntityDataArrayId, { "preprocess" } },
		{ EntitySharedMemoryArrayId, { "preprocess" } },
		{ EntityInfoArrayId, {  } },
		{ TemporaryMemoryId, { "preprocess", "render" } }
	};
	return true;
}();

bool unused_blockName_unused = [](){
	blockName = {
		{ RuntimeEnvironmentId, "RuntimeEnvironment" },
		{ RuntimeCanvasId, "RuntimeCanvas" },
		{ RuntimeSkinTransformId, "RuntimeSkinTransform" },
		{ RuntimeUIId, "RuntimeUI" },
		{ RuntimeUIConfigurationId, "RuntimeUIConfiguration" },
		{ PreviewDataId, "PreviewData" },
		{ PreviewOptionId, "PreviewOption" },
		{ EngineRomId, "EngineRom" },
		{ EntityDataId, "EntityData" },
		{ EntitySharedMemoryId, "EntitySharedMemory" },
		{ EntityInfoId, "EntityInfo" },
		{ EntityDataArrayId, "EntityDataArray" },
		{ EntitySharedMemoryArrayId, "EntitySharedMemoryArray" },
		{ EntityInfoArrayId, "EntityInfoArray" },
		{ TemporaryMemoryId, "TemporaryMemory" }
	};
	return true;
}();

bool unused_writeBlockInfo_unused = [](){
	SonolusMemorySize[PreviewDataId] = 4096;
	SonolusMemoryDelta[PreviewDataId] = 1;
	allowAllocate.insert(PreviewDataId);
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

	Constructor RuntimeEnvironmentGroup(FuncNode offset) {
		debugMode.reallocate(offset + 0);
		screenAspectRatio.reallocate(offset + 1);
	}
};
RuntimeEnvironmentGroup RuntimeEnvironment = RuntimeEnvironmentGroup(0);

struct RuntimeCanvasGroup{
	Variable scroll = Variable(RuntimeCanvasId, 0);
	Variable size = Variable(RuntimeCanvasId, 0);

	Constructor RuntimeCanvasGroup(FuncNode offset) {
		scroll.reallocate(offset + 0);
		size.reallocate(offset + 1);
	}
};
RuntimeCanvasGroup RuntimeCanvas = RuntimeCanvasGroup(0);

VariablesArray<RuntimeSkinTransformId> RuntimeSkinTransform = VariablesArray<RuntimeSkinTransformId>(0, 1 << 16);

struct RuntimeUIGroup{
	struct Group_r7lLuofqbV4aIOsl{
		Variable anchorX = Variable(RuntimeUIId, 0);
		Variable anchorY = Variable(RuntimeUIId, 0);
		Variable pivotX = Variable(RuntimeUIId, 0);
		Variable pivotY = Variable(RuntimeUIId, 0);
		Variable width = Variable(RuntimeUIId, 0);
		Variable height = Variable(RuntimeUIId, 0);
		Variable rotation = Variable(RuntimeUIId, 0);
		Variable alpha = Variable(RuntimeUIId, 0);
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
			background.reallocate(offset + 8);
		}
	};
	Group_r7lLuofqbV4aIOsl menu;
	Group_r7lLuofqbV4aIOsl progress;

	Constructor RuntimeUIGroup(FuncNode offset) {
		menu.reallocate(offset + 0);
		progress.reallocate(offset + 9);
	}
};
RuntimeUIGroup RuntimeUI = RuntimeUIGroup(0);

struct RuntimeUIConfigurationGroup{
	struct Group_2r2W6GSKyZAfOsND{
		Variable scale = Variable(RuntimeUIConfigurationId, 0);
		Variable alpha = Variable(RuntimeUIConfigurationId, 0);

		void reallocate(FuncNode offset) {
			scale.reallocate(offset + 0);
			alpha.reallocate(offset + 1);
		}
	};
	Group_2r2W6GSKyZAfOsND menu;
	Group_2r2W6GSKyZAfOsND progress;

	Constructor RuntimeUIConfigurationGroup(FuncNode offset) {
		menu.reallocate(offset + 0);
		progress.reallocate(offset + 2);
	}
};
RuntimeUIConfigurationGroup RuntimeUIConfiguration = RuntimeUIConfigurationGroup(0);

VariablesArray<PreviewDataId> PreviewData = VariablesArray<PreviewDataId>(0, 1 << 16);

VariablesArray<PreviewOptionId> PreviewOption = VariablesArray<PreviewOptionId>(0, 1 << 16);

VariablesArray<EngineRomId> EngineRom = VariablesArray<EngineRomId>(0, 1 << 16);

VariablesArray<EntityDataId> EntityData = VariablesArray<EntityDataId>(0, 1 << 16);

VariablesArray<EntitySharedMemoryId> EntitySharedMemory = VariablesArray<EntitySharedMemoryId>(0, 1 << 16);

struct EntityInfoGroup{
	Variable index = Variable(EntityInfoId, 0);
	Variable archetype = Variable(EntityInfoId, 0);

	Constructor EntityInfoGroup(FuncNode offset) {
		index.reallocate(offset + 0);
		archetype.reallocate(offset + 1);
	}
};
EntityInfoGroup EntityInfo = EntityInfoGroup(0);

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

	Constructor EntityInfoArrayGroup(FuncNode offset) {
		index.reallocate(offset + 0);
		archetype.reallocate(offset + 1);
	}
};
BlocksArray<EntityInfoArrayGroup> EntityInfoArray = BlocksArray<EntityInfoArrayGroup>(2);

VariablesArray<TemporaryMemoryId> TemporaryMemory = VariablesArray<TemporaryMemoryId>(0, 1 << 16);


#endif
