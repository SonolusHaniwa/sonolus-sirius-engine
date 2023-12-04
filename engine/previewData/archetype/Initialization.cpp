class Initialization: public Archetype {
    public:

    string name = "Sirius Initialization";

    var preprocess() {
		return {
			duration.set(0), noteCount.set(0),
		    [](){
	            var menuWidth = 0.15 * ui.menuConfiguration.scale;
	            var menuHeight = 0.15 * ui.menuConfiguration.scale;
	            var menuX = screen.r - interfaceGap;
	            var menuY = screen.t - interfaceGap;
		        return ui.menu.set(menuX, menuY, 1, 1, menuWidth, menuHeight, 0, ui.menuConfiguration.alpha, true);
		    }(),
		    [](){
		        var progressWidth = screen.w - interfaceGap * 2;
		        var progressHeight = 0.15 * ui.progressConfiguration.scale;
		        var progressX = screen.l + interfaceGap;
		        var progressY = screen.b + interfaceGap;
		        return ui.progress.set(progressX, progressY, 0, 0, progressWidth, progressHeight, 0, ui.progressConfiguration.alpha, true);
			}()
	    };	
	}
};
