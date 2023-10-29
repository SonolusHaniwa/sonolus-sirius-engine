using namespace std;

auto preprocess = definePreprocess({
     [](){
        var menuWidth = 0.15 * ui.menuConfiguration.scale;
        var menuHeight = 0.15 * ui.menuConfiguration.scale;
        var menuX = screen.r - interfaceGap;
        var menuY = screen.t - interfaceGap;
        var previousWidth = 0.15 * ui.navigationConfiguration.scale;
        var previousHeight = 0.15 * ui.navigationConfiguration.scale;
        var previousX = screen.l + interfaceGap;
        var previousY = 0;
        var nextX = screen.r - interfaceGap;
        var nextY = 0;
        var instructionWidth = 1.2 * ui.instructionConfiguration.scale;
        var instructionHeight = 0.15 * ui.instructionConfiguration.scale;
        return Execute({
            ui.menu.set(menuX, menuY, 1, 1, menuWidth, menuHeight, 0, ui.menuConfiguration.alpha, true),
            ui.navigationPrevious.set(previousX, previousY, 0, 0.5, previousWidth, previousHeight, 0, ui.navigationConfiguration.alpha, true),
            ui.navigationNext.set(nextX, nextY, 1, 0.5, previousWidth, previousHeight, 0, ui.navigationConfiguration.alpha, true),
            ui.instruction.set(0, 0, 0.5, 0.5, instructionWidth, instructionHeight, 0, ui.instructionConfiguration.alpha, true)
        });
    }(),
    tutorialStartTime.set(times.now),
    tutorialNavigation.set(0)
});