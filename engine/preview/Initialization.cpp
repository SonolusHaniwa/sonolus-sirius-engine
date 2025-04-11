class Initialization: public Archetype {
    public:

    string name = "Sirius Initialization";

    SonolusApi preprocess() {
		duration = 0; noteCount = 0;
		
        var menuWidth = 0.15 * configuration.menu.scale;
        var menuHeight = 0.15 * configuration.menu.scale;
        var menuX = screen.r - interfaceGap;
        var menuY = screen.t - interfaceGap;
        setUI(ui.menu, menuX, menuY, 1, 1, menuWidth, menuHeight, 0, configuration.menu.alpha, true);
     	
        var progressWidth = screen.w - interfaceGap * 2;
        var progressHeight = 0.15 * configuration.progress.scale;
        var progressX = screen.l + interfaceGap;
        var progressY = screen.b + interfaceGap;
        setUI(ui.progress, progressX, progressY, 0, 0, progressWidth, progressHeight, 0, configuration.progress.alpha, true);
    }
};
