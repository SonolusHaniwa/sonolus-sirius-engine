class Initialization: public Archetype {
    public:

    static constexpr const char* name = "Sirius Initialization";

    SonolusApi preprocess() {
    	FUNCBEGIN
		duration = 0; noteCount = 0;
		
        let menuWidth = 0.15 * ui.menuConfiguration.scale;
        let menuHeight = 0.15 * ui.menuConfiguration.scale;
        let menuX = screen.r - interfaceGap;
        let menuY = screen.t - interfaceGap;
     	ui.menu.set(menuX, menuY, 1, 1, menuWidth, menuHeight, 0, ui.menuConfiguration.alpha, true);
     	
        let progressWidth = screen.w - interfaceGap * 2;
        let progressHeight = 0.15 * ui.progressConfiguration.scale;
        let progressX = screen.l + interfaceGap;
        let progressY = screen.b + interfaceGap;
        ui.progress.set(progressX, progressY, 0, 0, progressWidth, progressHeight, 0, ui.progressConfiguration.alpha, true);
        return VOID;
    }
};
