#ifndef PreviewRuntime_H
#define PreviewRuntime_H

const int OptionId = PreviewOptionId;
auto unused_defaultAllocatorId_unused = [](){
    defaultAllocatorId = PreviewDataId;
    createNodeContainer();
    return true;
}(); 

Variable &debugMode = RuntimeEnvironment.debugMode;
Variable &aspectRatio = RuntimeEnvironment.screenAspectRatio;
Variable &scroll = RuntimeCanvas.scroll;
Variable &canvasSize = RuntimeCanvas.size;
struct transforms {
    VariablesArray<RuntimeSkinTransformId> &skin = RuntimeSkinTransform;
}transforms;
RuntimeUIGroup &ui = RuntimeUI;
RuntimeUIConfigurationGroup &configuration = RuntimeUIConfiguration;

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