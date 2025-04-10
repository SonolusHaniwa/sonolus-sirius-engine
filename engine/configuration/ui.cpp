using namespace std;

EngineConfigurationUI configurationUI = {
    .primaryMetric = Metric.arcade, 
    .secondaryMetric = Metric.life,
    .menuVisibility = {
        .scale = 1.0,
        .alpha = 1.0
    }, 
    .judgmentVisibility = {
        .scale = 1.0,
        .alpha = 1.0
    },
    .comboVisibility = {
        .scale = 1.0,
        .alpha = 1.0
    },
    .primaryMetricVisibility = {
        .scale = 1.0,
        .alpha = 1.0
    },
    .secondaryMetricVisbility = {
        .scale = 1.0,
        .alpha = 1.0
    },
    .progressVisibility = {
    	.scale = 1.0,
    	.alpha = 1.0	
    },
    .tutorialNavigationVisibility = {
        .scale = 1.0,
        .alpha = 1.0
    },
    .tutorialInstructionVisibility = {
        .scale = 1.0,
        .alpha = 1.0
    },
    .judgmentAnimation = {
        .scale = {
            .from = 0.6,
            .to = 1.0,
            .duration = 0.1,
            .ease = AnimationEase.InSine
        },
        .alpha = {
            .from = 0.6,
            .to = 1.0,
            .duration = 0.1,
            .ease = AnimationEase.InSine
        }
    },
    .comboAnimation = {
        .scale = {
            .from = 0.6,
            .to = 1.0,
            .duration = 0.1,
            .ease = AnimationEase.InSine
        },
        .alpha = {
            .from = 0.6,
            .to = 1.0,
            .duration = 0.1,
            .ease = AnimationEase.Linear
        }
    },
    .judgmentErrorStyle = ErrorStyle.none,
    .judgmentErrorPlacement = ErrorPlacement.leftRight,
    .judgmentErrorMin = 20,
    .scope = Scope
};
