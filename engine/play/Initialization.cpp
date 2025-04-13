class Initialization: public Archetype {
    public:

    string name = "Sirius Initialization";
    bool input = false;

    SonolusApi preprocess() {
        // 界面开关参数
        var menuWidth = 0.15 * configuration.menu.scale;
        var menuHeight = 0.15 * configuration.menu.scale;
        var menuX = screen.r - interfaceGap;
        var menuY = screen.t - interfaceGap;
        setUI(
            ui.menu, 
            menuX, menuY, 
            1, 1, 
            menuWidth, menuHeight, 
            0, 
            configuration.menu.alpha, 
            HorizontalAlign.Center, 
            true
        );
        
        // 首要指标参数
        var primaryMetricBarWidth = 0.75 * configuration.primaryMetric.scale;
        var primaryMetricBarHeight = 0.15 * configuration.primaryMetric.scale;
        var primaryMetricBarX = screen.l + interfaceGap;
        var primaryMetricBarY = screen.t - interfaceGap;
        var primaryMetricValueWidth = 0 * configuration.primaryMetric.scale;
        var primaryMetricValueHeight = 0.08 * configuration.primaryMetric.scale;
        var primaryMetricValueX = primaryMetricBarX + 0.715 * configuration.primaryMetric.scale;
        var primaryMetricValueY = primaryMetricBarY - 0.035 * configuration.primaryMetric.scale;
        setUI(
            ui.primaryMetricBar, 
            primaryMetricBarX, primaryMetricBarY, 
            0, 1, 
            primaryMetricBarWidth, primaryMetricBarHeight, 
            0, 
            configuration.primaryMetric.alpha, 
            HorizontalAlign.Left, 
            true
        );
        setUI(
            ui.primaryMetricValue, 
            primaryMetricValueX, primaryMetricValueY, 
            1, 1, 
            primaryMetricValueWidth, primaryMetricValueHeight, 
            0, 
            configuration.primaryMetric.alpha, 
            HorizontalAlign.Right, 
            false
        );
        
        // 次要指标参数
        var secondaryMetricBarWidth = 0.55 * configuration.secondaryMetric.scale;
        var secondaryMetricBarHeight = 0.15 * configuration.secondaryMetric.scale;
        var secondaryMetricBarX = screen.r - interfaceGap - menuWidth - interfaceGap;
        var secondaryMetricBarY = screen.t - interfaceGap;
        var secondaryMetricValueWidth = 0 * configuration.secondaryMetric.scale;
        var secondaryMetricValueHeight = 0.08 * configuration.secondaryMetric.scale;
        var secondaryMetricValueX = secondaryMetricBarX - 0.035 * configuration.secondaryMetric.scale;
        var secondaryMetricValueY = secondaryMetricBarY - 0.035 * configuration.secondaryMetric.scale;
        setUI(
            ui.secondaryMetricBar, 
            secondaryMetricBarX, secondaryMetricBarY, 
            1, 1, 
            secondaryMetricBarWidth, secondaryMetricBarHeight, 
            0, 
            configuration.secondaryMetric.alpha, 
            HorizontalAlign.Left, 
            true
        );
        setUI(
            ui.secondaryMetricValue, 
            secondaryMetricValueX, secondaryMetricValueY, 
            1, 1, 
            secondaryMetricValueWidth, secondaryMetricValueHeight, 
            0, 
            configuration.secondaryMetric.alpha, 
            HorizontalAlign.Right, 
            false
        );
        
        // 连击指标参数
        var comboValueWidth = 0 * configuration.combo.scale;
        var comboValueHeight = screen.h * 0.08 * configuration.combo.scale;
        var comboValueX = screen.w * 0.4;
        var comboValueY = Lerp(t, b, 0.425);
        var comboTextWidth = 0 * configuration.combo.scale;
        var comboTextHeight = screen.h * 0.033 * configuration.combo.scale;
        var comboTextX = screen.w * 0.4;
        var comboTextY = Lerp(t, b, 0.425);
        if (!hasCombo) {
	        setUI(
                ui.comboValue, 
                comboValueX, comboValueY, 
                0.5, 0.5, 
                comboValueWidth, comboValueHeight, 
                0, 
                configuration.combo.alpha, 
                HorizontalAlign.Center, 
                false
            );
	        setUI(
                ui.comboText, 
                comboTextX, comboTextY, 
                0.5, 2.75, 
                comboTextWidth, comboTextHeight, 
                0, 
                configuration.combo.alpha, 
                HorizontalAlign.Center, 
                false
            );
	    }
        
        // 判定指标参数
        var judgmentX = 0, judgmentY = -0.115 * stage.h;
        var judgmentWidth = 0;
    	var judgmentHeight = stage.h * 0.0475 * configuration.judgment.scale;
        if (!hasJudgment) {
        	setUI(
                ui.judgment, 
                judgmentX, judgmentY, 
                0.5, 0.5, 
                judgmentWidth, judgmentHeight, 
                0, 
                configuration.judgment.alpha, 
                HorizontalAlign.Center, 
                false
            );
        }
        
        setScore(score.perfect, score.great, score.good);

        // setBucket(0, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(1, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(2, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.good * 1000, judgment.good * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(3, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(4, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(5, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(6, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(7, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(8, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(9, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(10, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(11, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // setBucket(12, -1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);

        comboNumber = 0; comboStatus = 0;
        totalAccuracy = 0; currentAccuracy = 0;

        despawn.despawn = 1;
    }

    SonolusApi spawnOrder() { return 0; }
    SonolusApi shouldSpawn() { return 1; }
};
