#ifndef TutorialBlocks_H
#define TutorialBlocks_H

const int RuntimeEnvironmentId = 1000;
const int RuntimeUpdateId = 1001;
const int RuntimeSkinTransformId = 1002;
const int RuntimeParticleTransformId = 1003;
const int RuntimeBackgroundId = 1004;
const int RuntimeUIId = 1005;
const int RuntimeUIConfigurationId = 1006;
const int TutorialMemoryId = 2000;
const int TutorialDataId = 2001;
const int TutorialInstructionId = 2002;
const int EngineRomId = 3000;
const int TemporaryMemoryId = 10000;

bool unused_readable_unused = [](){
	readable = {
		{ RuntimeEnvironmentId, { "preprocess", "navigate", "update" } },
		{ RuntimeUpdateId, { "preprocess", "navigate", "update" } },
		{ RuntimeSkinTransformId, { "preprocess", "navigate", "update" } },
		{ RuntimeParticleTransformId, { "preprocess", "navigate", "update" } },
		{ RuntimeBackgroundId, { "preprocess", "navigate", "update" } },
		{ RuntimeUIId, { "preprocess", "navigate", "update" } },
		{ RuntimeUIConfigurationId, { "preprocess", "navigate", "update" } },
		{ TutorialMemoryId, { "preprocess", "navigate", "update" } },
		{ TutorialDataId, { "preprocess", "navigate", "update" } },
		{ TutorialInstructionId, { "preprocess", "navigate", "update" } },
		{ EngineRomId, { "preprocess", "navigate", "update" } },
		{ TemporaryMemoryId, { "preprocess", "navigate", "update" } }
	};
	return true;
}();

bool unused_writable_unused = [](){
	writable = {
		{ RuntimeEnvironmentId, { "preprocess" } },
		{ RuntimeUpdateId, {  } },
		{ RuntimeSkinTransformId, { "preprocess", "navigate", "update" } },
		{ RuntimeParticleTransformId, { "preprocess", "navigate", "update" } },
		{ RuntimeBackgroundId, { "preprocess", "navigate", "update" } },
		{ RuntimeUIId, { "preprocess" } },
		{ RuntimeUIConfigurationId, { "preprocess" } },
		{ TutorialMemoryId, { "preprocess", "navigate", "update" } },
		{ TutorialDataId, { "preprocess" } },
		{ TutorialInstructionId, { "preprocess", "navigate", "update" } },
		{ EngineRomId, {  } },
		{ TemporaryMemoryId, { "preprocess", "navigate", "update" } }
	};
	return true;
}();

bool unused_blockName_unused = [](){
	blockName = {
		{ RuntimeEnvironmentId, "RuntimeEnvironment" },
		{ RuntimeUpdateId, "RuntimeUpdate" },
		{ RuntimeSkinTransformId, "RuntimeSkinTransform" },
		{ RuntimeParticleTransformId, "RuntimeParticleTransform" },
		{ RuntimeBackgroundId, "RuntimeBackground" },
		{ RuntimeUIId, "RuntimeUI" },
		{ RuntimeUIConfigurationId, "RuntimeUIConfiguration" },
		{ TutorialMemoryId, "TutorialMemory" },
		{ TutorialDataId, "TutorialData" },
		{ TutorialInstructionId, "TutorialInstruction" },
		{ EngineRomId, "EngineRom" },
		{ TemporaryMemoryId, "TemporaryMemory" }
	};
	return true;
}();

bool unused_writeBlockInfo_unused = [](){
	SonolusMemorySize[TutorialMemoryId] = 4096;
	SonolusMemoryDelta[TutorialMemoryId] = 1;
	allowAllocate.insert(TutorialMemoryId);
	SonolusMemorySize[TutorialDataId] = 4096;
	SonolusMemoryDelta[TutorialDataId] = 1;
	allowAllocate.insert(TutorialDataId);
	SonolusMemorySize[TemporaryMemoryId] = 4096;
	SonolusMemoryDelta[TemporaryMemoryId] = 1;
	allowAllocate.insert(TemporaryMemoryId);
	return true;
}();

struct RuntimeEnvironmentGroup{
	Variable debugMode = Variable(RuntimeEnvironmentId, 0);
	Variable screenAspectRatio = Variable(RuntimeEnvironmentId, 0);
	Variable audioOffset = Variable(RuntimeEnvironmentId, 0);

	Constructor RuntimeEnvironmentGroup(FuncNode offset) {
		debugMode.reallocate(offset + 0);
		screenAspectRatio.reallocate(offset + 1);
		audioOffset.reallocate(offset + 2);
	}
};
RuntimeEnvironmentGroup RuntimeEnvironment = RuntimeEnvironmentGroup(0);

struct RuntimeUpdateGroup{
	Variable time = Variable(RuntimeUpdateId, 0);
	Variable deltaTime = Variable(RuntimeUpdateId, 0);
	Variable navigationDirection = Variable(RuntimeUpdateId, 0);

	Constructor RuntimeUpdateGroup(FuncNode offset) {
		time.reallocate(offset + 0);
		deltaTime.reallocate(offset + 1);
		navigationDirection.reallocate(offset + 2);
	}
};
RuntimeUpdateGroup RuntimeUpdate = RuntimeUpdateGroup(0);

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
	struct Group_PZSBzYvZkjxrz1hh{
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
	Group_PZSBzYvZkjxrz1hh menu;
	Group_PZSBzYvZkjxrz1hh navigationPrevious;
	Group_PZSBzYvZkjxrz1hh navigationNext;
	Group_PZSBzYvZkjxrz1hh instruction;

	Constructor RuntimeUIGroup(FuncNode offset) {
		menu.reallocate(offset + 0);
		navigationPrevious.reallocate(offset + 9);
		navigationNext.reallocate(offset + 18);
		instruction.reallocate(offset + 27);
	}
};
RuntimeUIGroup RuntimeUI = RuntimeUIGroup(0);

struct RuntimeUIConfigurationGroup{
	struct Group_5LHKJ8civYrNsseF{
		Variable scale = Variable(RuntimeUIConfigurationId, 0);
		Variable alpha = Variable(RuntimeUIConfigurationId, 0);

		void reallocate(FuncNode offset) {
			scale.reallocate(offset + 0);
			alpha.reallocate(offset + 1);
		}
	};
	Group_5LHKJ8civYrNsseF menu;
	Group_5LHKJ8civYrNsseF navigation;
	Group_5LHKJ8civYrNsseF instruction;

	Constructor RuntimeUIConfigurationGroup(FuncNode offset) {
		menu.reallocate(offset + 0);
		navigation.reallocate(offset + 2);
		instruction.reallocate(offset + 4);
	}
};
RuntimeUIConfigurationGroup RuntimeUIConfiguration = RuntimeUIConfigurationGroup(0);

VariablesArray<TutorialMemoryId> TutorialMemory = VariablesArray<TutorialMemoryId>(0, 1 << 16);

VariablesArray<TutorialDataId> TutorialData = VariablesArray<TutorialDataId>(0, 1 << 16);

struct TutorialInstructionGroup{
	Variable text = Variable(TutorialInstructionId, 0);

	Constructor TutorialInstructionGroup(FuncNode offset) {
		text.reallocate(offset + 0);
	}
};
TutorialInstructionGroup TutorialInstruction = TutorialInstructionGroup(0);

VariablesArray<EngineRomId> EngineRom = VariablesArray<EngineRomId>(0, 1 << 16);

VariablesArray<TemporaryMemoryId> TemporaryMemory = VariablesArray<TemporaryMemoryId>(0, 1 << 16);


#endif
