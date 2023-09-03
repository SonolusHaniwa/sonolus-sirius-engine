class Initialization: public Archetype {
    public:

    string name = "Sirius Initialization";

    var preprocess = {
        canvas.set(Scroll.LeftToRight, 10),
        [](){
            var menuWidth = 0.15 * ui.menuConfiguration.scale;
            var menuHeight = 0.15 * ui.menuConfiguration.scale;
            var menuX = screen.r - interfaceGap;
            var menuY = screen.t - interfaceGap;
            return ui.menu.set(menuX, menuY, 1, 1, menuWidth, menuHeight, 0, ui.menuConfiguration.alpha, true);
        }()
    };
};