#ifndef TutorialRuntime_H
#define TutorialRuntime_H

const int OptionId = 0;
auto unused_defaultAllocatorId_unused = [](){
    defaultAllocatorId = TutorialMemoryId;
    createNodeContainer();
    return true;
}(); 

Variable &debugMode = RuntimeEnvironment.debugMode;
Variable &aspectRatio = RuntimeEnvironment.screenAspectRatio;
struct offset {
    Variable &audio = RuntimeEnvironment.audioOffset;
}offsets;
struct times {
    Variable &now = RuntimeUpdate.time;
    Variable &delta = RuntimeUpdate.deltaTime;
    Variable &scaled = RuntimeUpdate.time;
}times;
Variable &navigation = RuntimeUpdate.navigationDirection;
struct transforms {
    VariablesArray<RuntimeSkinTransformId> &skin = RuntimeSkinTransform;
    VariablesArray<RuntimeParticleTransformId> &particle = RuntimeParticleTransform;
}transforms;
RuntimeUIGroup &ui = RuntimeUI;
RuntimeUIConfigurationGroup &configuration = RuntimeUIConfiguration;
Variable &instruction = TutorialInstruction.text;

template<typename T>
SonolusApi setUI(T &ui, var anchorX, var anchorY, var pivotX, var pivotY, var width, var height, var rotation, var alpha, var background) {
    ui.anchorX = anchorX; ui.anchorY = anchorY;
    ui.pivotX = pivotX; ui.pivotY = pivotY;
    ui.width = width; ui.height = height;
    ui.rotation = rotation;
    ui.alpha = alpha;
    ui.background = background;
}

#endif