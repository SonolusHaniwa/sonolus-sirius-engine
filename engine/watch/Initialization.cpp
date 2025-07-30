class Initialization: public Archetype {
	public:

	string name = "Sirius Initialization";

	SonolusApi spawnTime() { return 0; }
	SonolusApi despawnTime() { return 0; }

	int preprocessOrder = -10000;
	SonolusApi preprocess() {
      	// 界面开关参数
        var menuWidth = 0.15 * configuration.menu.scale;
        var menuHeight = 0.15 * configuration.menu.scale;
        var menuX = screen.r - interfaceGap;
        var menuY = screen.t - interfaceGap;
        setUI(ui.menu, menuX, menuY, 1, 1, menuWidth, menuHeight, 0, configuration.menu.alpha, HorizontalAlign.Center, true);
        
        // 首要指标参数
        var primaryMetricBarWidth = 0.75 * configuration.primaryMetric.scale;
        var primaryMetricBarHeight = 0.15 * configuration.primaryMetric.scale;
        var primaryMetricBarX = screen.l + interfaceGap;
        var primaryMetricBarY = screen.t - interfaceGap;
        var primaryMetricValueWidth = 0 * configuration.primaryMetric.scale;
        var primaryMetricValueHeight = 0.08 * configuration.primaryMetric.scale;
        var primaryMetricValueX = primaryMetricBarX + 0.715 * configuration.primaryMetric.scale;
        var primaryMetricValueY = primaryMetricBarY - 0.035 * configuration.primaryMetric.scale;
        setUI(ui.primaryMetricBar, primaryMetricBarX, primaryMetricBarY, 0, 1, primaryMetricBarWidth, primaryMetricBarHeight, 0, configuration.primaryMetric.alpha, HorizontalAlign.Left, true);
        setUI(ui.primaryMetricValue, primaryMetricValueX, primaryMetricValueY, 1, 1, primaryMetricValueWidth, primaryMetricValueHeight, 0, configuration.primaryMetric.alpha, HorizontalAlign.Right, false);
        
        // 次要指标参数
        var secondaryMetricBarWidth = 0.55 * configuration.secondaryMetric.scale;
        var secondaryMetricBarHeight = 0.15 * configuration.secondaryMetric.scale;
        var secondaryMetricBarX = screen.r - interfaceGap - menuWidth - interfaceGap;
        var secondaryMetricBarY = screen.t - interfaceGap;
        var secondaryMetricValueWidth = 0 * configuration.secondaryMetric.scale;
        var secondaryMetricValueHeight = 0.08 * configuration.secondaryMetric.scale;
        var secondaryMetricValueX = secondaryMetricBarX - 0.035 * configuration.secondaryMetric.scale;
        var secondaryMetricValueY = secondaryMetricBarY - 0.035 * configuration.secondaryMetric.scale;
        setUI(ui.secondaryMetricBar, secondaryMetricBarX, secondaryMetricBarY, 1, 1, secondaryMetricBarWidth, secondaryMetricBarHeight, 0, configuration.secondaryMetric.alpha, HorizontalAlign.Left, true);
        setUI(ui.secondaryMetricValue, secondaryMetricValueX, secondaryMetricValueY, 1, 1, secondaryMetricValueWidth, secondaryMetricValueHeight, 0, configuration.secondaryMetric.alpha, HorizontalAlign.Right, false);
        
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
            setUI(ui.comboValue, comboValueX, comboValueY, 0.5, 0.5, comboValueWidth, comboValueHeight, 0, configuration.combo.alpha, HorizontalAlign.Center, false);
            setUI(ui.comboText, comboTextX, comboTextY, 0.5, 2.75, comboTextWidth, comboTextHeight, 0, configuration.combo.alpha, HorizontalAlign.Center, false);
	    }
        
        // 判定指标参数
        var judgmentX = 0, judgmentY = -0.115 * stage.h;
        var judgmentWidth = 0;
        var judgmentHeight = stage.h * 0.0475 * configuration.judgment.scale;
        if (!hasJudgment) {
            setUI(ui.judgment, judgmentX, judgmentY, 0.5, 0.5, judgmentWidth, judgmentHeight, 0, configuration.judgment.alpha, HorizontalAlign.Center, false);
        }
        
        // 进度条参数
        var progressWidth = screen.w - interfaceGap * 2;
        var progressHeight = 0.15 * configuration.progress.scale;
        var progressX = screen.l + interfaceGap;
        var progressY = screen.b + interfaceGap;
        setUI(ui.progress, progressX, progressY, 0, 0, progressWidth, progressHeight, 0, configuration.progress.alpha, HorizontalAlign.Center, true);
        
        setScore(score.perfect, score.great, score.good);

        // for (int i = 3; i <= 9; i++) lifes[i].set(0, 0, 0, -80);
        // for (int i = 10; i <= 11; i++) lifes[i].set(0, 0, 0, -40);
        // for (int i = 12; i <= 13; i++) lifes[i].set(0, 0, 0, -80);
        
        // buckets[0].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[1].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[2].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.good * 1000, judgment.good * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[3].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[4].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[5].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[6].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[7].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[8].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[9].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[10].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[11].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);
        // buckets[12].set(-1 * judgment.perfect * 1000, judgment.perfect * 1000, -1 * judgment.great * 1000, judgment.great * 1000, -1 * judgment.good * 1000, judgment.good * 1000);

        comboNumber = 0; comboStatus = 0;
    }
};
