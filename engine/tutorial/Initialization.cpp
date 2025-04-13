Blocked SonolusApi Initialization() {
    var menuWidth = 0.15 * configuration.menu.scale;
    var menuHeight = 0.15 * configuration.menu.scale;
    var menuX = screen.r - interfaceGap;
    var menuY = screen.t - interfaceGap;
    setUI(ui.menu, menuX, menuY, 1, 1, menuWidth, menuHeight, 0, configuration.menu.alpha, true);

    var previousWidth = 0.15 * configuration.navigation.scale;
    var previousHeight = 0.15 * configuration.navigation.scale;
    var previousX = stage.l + interfaceGap;
    var previousY = 0;
    setUI(ui.navigationPrevious, previousX, previousY, 0, 0.5, previousWidth, previousHeight, 0, configuration.navigation.alpha, true);
    
    var nextX = stage.r - interfaceGap;
	var nextY = 0;
    setUI(ui.navigationNext, nextX, nextY, 1, 0.5, previousWidth, previousHeight, 0, configuration.navigation.alpha, true);

    var instructionWidth = 1.2 * configuration.instruction.scale;
    var instructionHeight = 0.15 * configuration.instruction.scale;
    setUI(ui.instruction, 0, 0, 0.5, 0.5, instructionWidth, instructionHeight, 0, configuration.instruction.alpha, false);
}

defineTutorialPreprocess(Initialization);

double tutorialFrozeTime = 2.0;
double tutorialClickTime = 4.0;
double tutorialDisappearTime = effectDurationTime.getNode().value + 0.5;