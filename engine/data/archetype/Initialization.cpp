class Initialization: public Archetype {
    public:

    string name = "Sirius Initialization";
    bool input = false;
    vector<pair<string, int> > data = {};

    var preprocess = {
        [](){
            // 界面开关参数
            var menuWidth = 0.15 * ui.menuConfiguration.scale;
            var menuHeight = 0.15 * ui.menuConfiguration.scale;
            var menuX = screen.r - interfaceGap;
            var menuY = screen.t - interfaceGap;
            // 首要指标参数
            var primaryMetricBarWidth = 0.75 * ui.primaryMetricConfiguration.scale;
            var primaryMetricBarHeight = 0.15 * ui.primaryMetricConfiguration.scale;
            var primaryMetricBarX = screen.l + interfaceGap;
            var primaryMetricBarY = screen.t - interfaceGap;
            var primaryMetricValueWidth = 0 * ui.primaryMetricConfiguration.scale;
            var primaryMetricValueHeight = 0.08 * ui.primaryMetricConfiguration.scale;
            var primaryMetricValueX = primaryMetricBarX + 0.715 * ui.primaryMetricConfiguration.scale;
            var primaryMetricValueY = primaryMetricBarY - 0.035 * ui.primaryMetricConfiguration.scale;
            // 次要指标参数
            var secondaryMetricBarWidth = 0.55 * ui.secondaryMetricConfiguration.scale;
            var secondaryMetricBarHeight = 0.15 * ui.secondaryMetricConfiguration.scale;
            var secondaryMetricBarX = screen.r - interfaceGap - menuWidth - interfaceGap;
            var secondaryMetricBarY = screen.t - interfaceGap;
            var secondaryMetricValueWidth = 0 * ui.secondaryMetricConfiguration.scale;
            var secondaryMetricValueHeight = 0.08 * ui.secondaryMetricConfiguration.scale;
            var secondaryMetricValueX = secondaryMetricBarX - 0.035 * ui.secondaryMetricConfiguration.scale;
            var secondaryMetricValueY = secondaryMetricBarY - 0.035 * ui.secondaryMetricConfiguration.scale;
            // 连击指标参数
            var comboValueWidth = 0 * ui.comboConfiguration.scale;
            var comboValueHeight = screen.h * 0.08 * ui.comboConfiguration.scale;
            var comboValueX = screen.w * 0.4;
            var comboValueY = Lerp(t, b, 0.425);
            var comboTextWidth = 0 * ui.comboConfiguration.scale;
            var comboTextHeight = screen.h * 0.033 * ui.comboConfiguration.scale;
            var comboTextX = screen.w * 0.4;
            var comboTextY = Lerp(t, b, 0.425);
            // 判定指标参数
            var judgmentX = 0, judgmentY = -0.115 * stage.h;
            var judgmentWidth = 0;
            var judgmentHeight = stage.h * 0.0475 * ui.judgmentConfiguration.scale;
            return Execute({
                ui.menu.set(menuX, menuY, 1, 1, menuWidth, menuHeight, 0, ui.menuConfiguration.alpha, HorizontalAlign.Center, true),
                ui.primaryMetricBar.set(primaryMetricBarX, primaryMetricBarY, 0, 1, primaryMetricBarWidth, primaryMetricBarHeight, 0, ui.primaryMetricConfiguration.alpha, HorizontalAlign.Left, true),
                ui.primaryMetricValue.set(primaryMetricValueX, primaryMetricValueY, 1, 1, primaryMetricValueWidth, primaryMetricValueHeight, 0, ui.primaryMetricConfiguration.alpha, HorizontalAlign.Right, false),
                ui.secondaryMetricBar.set(secondaryMetricBarX, secondaryMetricBarY, 1, 1, secondaryMetricBarWidth, secondaryMetricBarHeight, 0, ui.secondaryMetricConfiguration.alpha, HorizontalAlign.Left, true),
                ui.secondaryMetricValue.set(secondaryMetricValueX, secondaryMetricValueY, 1, 1, secondaryMetricValueWidth, secondaryMetricValueHeight, 0, ui.secondaryMetricConfiguration.alpha, HorizontalAlign.Right, false),
                ui.comboValue.set(comboValueX, comboValueY, 0.5, 0.5, comboValueWidth, comboValueHeight, 0, ui.comboConfiguration.alpha, HorizontalAlign.Center, false),
                ui.comboText.set(comboTextX, comboTextY, 0.5, 2.75, comboTextWidth, comboTextHeight, 0, ui.comboConfiguration.alpha, HorizontalAlign.Center, false),
                ui.judgment.set(judgmentX, judgmentY, 0.5, 0.5, judgmentWidth, judgmentHeight, 0, ui.judgmentConfiguration.alpha, HorizontalAlign.Center, false),
                LevelScore.set(0, score.perfect),
                LevelScore.set(1, score.great),
                LevelScore.set(2, score.good),
                lifes[3].set(0, 0, 0, -80),
                lifes[4].set(0, 0, 0, -80),
                lifes[5].set(0, 0, 0, -80),
                lifes[6].set(0, 0, 0, -80),
                lifes[7].set(0, 0, 0, -80),
                lifes[8].set(0, 0, 0, -80),
                lifes[9].set(0, 0, 0, -80),
                lifes[10].set(0, 0, 0, -40),
                lifes[11].set(0, 0, 0, -40),
                lifes[12].set(0, 0, 0, -80),
                lifes[13].set(0, 0, 0, -80),
            });
        }()
    };

    var spawnOrder = 0;

    var shouldSpawn = 1;

    var updateSequential = {
        EntityDespawn.set(0, 1)
    };
};