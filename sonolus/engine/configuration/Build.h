#ifndef ConfigurationBuild_H
#define ConfigurationBuild_H

vector<Json::Value> engineConfigurationOptions;

/**
 * @brief Engine configuration option is used by Sonolus app to populate options section in level and engine configuration interface.
 *
 * This function can help you to create a `slider option` in Sonolus app, and it will return a proper `Variable` pointer which point to one memory in `LevelOption` or `PreviewOption` block.
 *
 * @param name The name of this option. Standardized option names starts with `#` and will be translated into client language when displayed. Special options names will have its effect applied automatically.
 * @param description Description will be displayed below this option. If you do not specify any description, it will not be displayed.
 * @param standard Whether this option is considered as a standard option. See wiki website for detailed information.
 * @param advanced If `advanced` is `true`, a sentence `This option is for advanced players.` will be displayed below this option.
 * @param scope Option values are automatically saved and shared between all levels. When a saved value matching the scope and name exists, it will be recalled.
 * @param def Default value of this slider option. `def` value must be between `min` value and `max` value.
 * @param min Minimal value range of this slider option. `min` value must be equal to or smaller than `max` value.
 * @param max Maximal value range of this slider option. `max` value must be equal to or greater than `min` value.
 * @param step Step value of this slider option. `step` value must be greater than `0`.
 * @param unit Unit of this slider option. `""` or `Text.PercentageUnit` is recommended.
 * @return `Variable<LevelOptionId>` or `Variable<PreviewOptionId>`, which depends on current build mode.
 *
 * @see <https://wiki.sonolus.com/engine-specs/resources/engine-configuration-option.html>
 */
Variable SliderOption(
    string name = "",
    string description = "",
    bool standard = false,
    bool advanced = false,
    string scope = "",
    double def = 0,
    double min = 0,
    double max = 100,
    double step = 1,
    string unit = ""
) {
    SonolusAssert(
        min <= def && def <= max, 
        "`def` value must be equal to or greater than `min` value and be equal to or smaller than `max` value!"
    );
    SonolusAssert(
        min <= max, 
        "`max` value must be equal to or greater than `min` value!"
    );
    SonolusAssert(
        step > 0, 
        "`step` value must be greater than `0`!"
    );
    Json::Value res;
    res["name"] = name;
    res["description"] = description;
    res["standard"] = standard;
    res["advanced"] = advanced;
    res["scope"] = scope;
    res["type"] = "slider";
    res["def"] = def;
    res["min"] = min;
    res["max"] = max;
    res["step"] = step;
    res["unit"] = unit;
    engineConfigurationOptions.push_back(res);
    return Variable(OptionId, engineConfigurationOptions.size() - 1);
}

/**
 * @brief Engine configuration option is used by Sonolus app to populate options section in level and engine configuration interface.
 *
 * This function can help you to create a `toggle option` in Sonolus app, and it will return a proper `Variable` pointer which point to one memory in `LevelOption` or `PreviewOption` block.
 *
 * @param name The name of this option. Standardized option names starts with `#` and will be translated into client language when displayed. Special options names will have its effect applied automatically.
 * @param description Description will be displayed below this option. If you do not specify any description, it will not be displayed.
 * @param standard Whether this option is considered as a standard option. See wiki website for detailed information.
 * @param advanced If `advanced` is `true`, a sentence `This option is for advanced players.` will be displayed below this option.
 * @param scope Option values are automatically saved and shared between all levels. When a saved value matching the scope and name exists, it will be recalled.
 * @param def Default value of this slider option. Only `0` or `1` was accepted.
 * @return `Variable<LevelOptionId>` or `Variable<PreviewOptionId>`, which depends on current build mode.
 *
 * @see <https://wiki.sonolus.com/engine-specs/resources/engine-configuration-option.html>
 */
Variable ToggleOption(
    string name = "",
    string description = "",
    bool standard = false,
    bool advanced = false,
    string scope = "",
    bool def = false
) {
    Json::Value res;
    res["name"] = name;
    res["description"] = description;
    res["standard"] = standard;
    res["advanced"] = advanced;
    res["scope"] = scope;
    res["type"] = "toggle";
    res["def"] = def ? 1 : 0;
    engineConfigurationOptions.push_back(res);
    return Variable(OptionId, engineConfigurationOptions.size() - 1);
}

/**
 * @brief Engine configuration option is used by Sonolus app to populate options section in level and engine configuration interface.
 *
 * This function can help you to create a `select option` in Sonolus app, and it will return a proper `Variable` pointer which point to one memory in `LevelOption` or `PreviewOption` block.
 *
 * @param name The name of this option. Standardized option names starts with `#` and will be translated into client language when displayed. Special options names will have its effect applied automatically.
 * @param description Description will be displayed below this option. If you do not specify any description, it will not be displayed.
 * @param standard Whether this option is considered as a standard option. See wiki website for detailed information.
 * @param advanced If `advanced` is `true`, a sentence `This option is for advanced players.` will be displayed below this option.
 * @param scope Option values are automatically saved and shared between all levels. When a saved value matching the scope and name exists, it will be recalled.
 * @param def Default value of this slider option. `def` value must be equal to or granter than `0` and be smaller than `values.size()`
 * @param values Option values of this option. Standardized option values starts with `#` and will be translated into client language when displayed.
 * @return `Variable<LevelOptionId>` or `Variable<PreviewOptionId>`, which depends on current build mode.
 *
 * @see <https://wiki.sonolus.com/engine-specs/resources/engine-configuration-option.html>
 */
Variable SelectOption(
    string name = "",
    string description = "",
    bool standard = false,
    bool advanced = false,
    string scope = "",
    int def = 0,
    vector<string> values = {}
) {
    SonolusAssert(
        def >= 0 && def < values.size(),
        "`def` value must be equal to or granter than `0` and be smaller than `values.size()`!"
    );
    Json::Value res;
    res["name"] = name;
    res["description"] = description;
    res["standard"] = standard;
    res["advanced"] = advanced;
    res["scope"] = scope;
    res["type"] = "toggle";
    res["def"] = def;
    res["values"].size();
    for (int i = 0; i < values.size(); i++) res["values"].append(values[i]);
    engineConfigurationOptions.push_back(res);
    return Variable(OptionId, engineConfigurationOptions.size() - 1);
}

class Visibility {
    private:

    double scale = 1;
    double alpha = 0;

    public:

    /**
     * @brief Construct a new Visibility object
     * 
     * @param scale The scale size of the item. The `scale` value must be between `0.5` and `2`.
     * @param alpha The alpha value of the item. The `alpha` value must be between `0` and `1`.
     */
    Constructor Visibility(double scale = 1, double alpha = 0) {
        SonolusAssert(
            scale >= 0.5 && scale <= 2, 
            "`scale` value must be between `0.5` and `2`!"
        );
        SonolusAssert(
            alpha >= 0 && alpha <= 1, 
            "`alpha` value must be between `0` and `1`!"
        );
        this->scale = scale;
        this->alpha = alpha;
    }

    /**
     * @brief Convert Visibility object to json object
     * 
     * @return Json::Value 
     */
    Json::Value toJsonObject() {
        Json::Value res;
        res["scale"] = scale;
        res["alpha"] = alpha;
        return res;
    }
};

class AnimationTween {
    private:

    double from;
    double to;
    double duration;
    string ease;

    public:

    /**
     * @brief Construct a new AnimationTween object
     * 
     * @param from Start value of current animation tween. `from` value must be between `0` and `1`.
     * @param to End value of current animation tween. `to` value must be between `0` and `1`.
     * @param duration Duration of current animation tween. `duration` value must be equal to or greater than `0`.
     * @param ease Easing type of current animation tween. Only members of `EngineConfigurationAnimationTweenEase` are accepted.
     */
    Constructor AnimationTween(
        double from = 0, 
        double to = 1, 
        double duration = 1, 
        string ease = EngineConfigurationAnimationTweenEase.None
    ) {
        SonolusAssert(
            from >= 0 && from <= 1, 
            "`from` value must be between `0` and `1`!"
        );
        SonolusAssert(
            to >= 0 && to <= 1, 
            "`to` value must be between `0` and `1`!"
        );
        SonolusAssert(
            duration >= 0, 
            "`duration` value must be equal to or greater than `0`!"
        );
        SonolusAssert(
            EngineConfigurationAnimationTweenEaseMembers.count(ease), 
            "For `ease`, only members of `EngineConfigurationAnimationTweenEase` are accepted!"
        );
        this->from = from;
        this->to = to;
        this->duration = duration;
        this->ease = ease;
    }

    /**
     * @brief Convert AnimationTween object to json object
     * 
     * @return Json::Value 
     */
    Json::Value toJsonObject() {
        Json::Value res;
        res["from"] = from;
        res["to"] = to;
        res["duration"] = duration;
        res["ease"] = ease;
        return res;
    }
};

class Animation {
    private:

    AnimationTween scale;
    AnimationTween alpha;

    public:

    /**
     * @brief Construct a new Animation object
     * 
     * @param scale The scale animation tween of the item
     * @param alpha The alpha animation tween of the item
     */
    Constructor Animation(
        AnimationTween scale = AnimationTween(), 
        AnimationTween alpha = AnimationTween()
    ) {
        this->scale = scale;
        this->alpha = alpha;
    }

    /**
     * @brief Convert Animation object to json object
     * 
     * @return Json::Value 
     */
    Json::Value toJsonObject() {
        Json::Value res;
        res["scale"] = scale.toJsonObject();
        res["alpha"] = alpha.toJsonObject();
        return res;
    }
};

/**
 * @brief Engine configuration UI is used by Sonolus app to populate UI section in level and engine configuration interface.
 * 
 */
class UI {
    private:

    string scope = "";
    string primaryMetric = EngineConfigurationMetric.Arcade;
    string secondaryMetric = EngineConfigurationMetric.Life;
    Visibility menuVisibility;
    Visibility judgmentVisibility;
    Visibility comboVisibility;
    Visibility primaryMetricVisibility;
    Visibility secondaryMetricVisibility;
    Visibility progressVisibility;
    Visibility tutorialNavigationVisibility;
    Visibility tutorialInstructionVisibility;
    Animation judgmentAnimation;
    Animation comboAnimation;
    string judgmentErrorStyle = EngineConfigurationJudgmentErrorStyle.None;
    string judgmentErrorPlacement = EngineConfigurationJudgmentErrorPlacement.LeftRight;
    double judgmentErrorMin = 0;

    public:

    /**
     * @brief Set UI scope.
     * 
     * @param scope UI values are automatically saved and shared between all engines. When a saved value matching the scope exists, it will be recalled. 
     */
    void SetScope(string scope) {
        this->scope = scope;
    } 

    /**
     * @brief Set UI primary metric and secondary metric.
     * 
     * @param primary Primary metric to show. Only members of `EngineConfigurationMetric` are accepted.
     * @param primaryVisibility Visibility property of primary metric.
     * @param secondary Secondary metric to show. Only members of `EngineConfigurationMetric` are accepted.
     * @param secondaryVisibility Visibility property of secondary metric.
     */
    void SetMetric(
        string primary = EngineConfigurationMetric.Arcade, 
        Visibility primaryVisibility = Visibility(),
        string secondary = EngineConfigurationMetric.Life, 
        Visibility secondaryVisibility = Visibility()
    ) {
        SonolusAssert(
            EngineConfigurationMetricMembers.count(primary),
            "For `primaryMetric`, only members of `EngineConfigurationMetric` are accepted!"
        );
        SonolusAssert(
            EngineConfigurationMetricMembers.count(secondary),
            "For `secondaryMetric`, only members of `EngineConfigurationMetric` are accepted!"
        );
        primaryMetric = primary;
        primaryMetricVisibility = primaryVisibility;
        secondaryMetric = secondary;
        secondaryMetricVisibility = secondaryVisibility;
    }

    /**
     * @brief Set UI menu.
     * 
     * @param visibility Visibility property of menu.
     */
    void SetMenu(Visibility visibility = Visibility()) {
        menuVisibility = visibility;
    }

    /**
     * @brief Set UI judgment.
     * 
     * @param visibility Visibility property of judgment.
     * @param animation Animation of judgment.
     * @param errorStyle Style of positive judgment error, while the negative judgment error is opposite to the positive judgment error. Only members of `EngineConfigurationJudgmentErrorStyle` are accepted.
     * @param errorPlacement Placement of judgment error. Only members of `EngineConfigurationJudgmentErrorPlacement` are accepted.
     * @param errorMin Minimum judgment error. Only judgment errors larger than this will be shown. `errorMin` value must be equal to or greater than `0`.
     */
    void SetJudgment(
        Visibility visibility = Visibility(), 
        Animation animation = Animation(),
        string errorStyle = EngineConfigurationJudgmentErrorStyle.None,
        string errorPlacement = EngineConfigurationJudgmentErrorPlacement.LeftRight,
        double errorMin = 0
    ) {
        SonolusAssert(
            EngineConfigurationJudgmentErrorStyleMembers.count(errorStyle),
            "For `errorStyle`, only members of `EngineConfigurationJudgmentErrorStyle` are accepted!"
        );
        SonolusAssert(
            EngineConfigurationJudgmentErrorPlacementMembers.count(errorPlacement),
            "For `errorPlacement`, only members of `EngineConfigurationJudgmentErrorPlacement` are accepted!"
        );
        SonolusAssert(
            errorMin >= 0,
            "`errorMin` value must be equal to or greater than `0`!"
        );
        judgmentVisibility = visibility;
        judgmentAnimation = animation;
        judgmentErrorStyle = errorStyle;
        judgmentErrorPlacement = errorPlacement;
        judgmentErrorMin = errorMin;
    }

    /**
     * @brief Set UI combo.
     * 
     * @param visibility Visibility property of combo.
     * @param animation Animation of combo.
     */
    void SetCombo(Visibility visibility = Visibility(), Animation animation = Animation()) {
        comboVisibility = visibility;
        comboAnimation = animation;
    }

    /**
     * @brief Set UI progress.
     * 
     * @param visibility Visibility property of progress.
     */
    void SetProgress(Visibility visibility = Visibility()) {
        progressVisibility = visibility;
    }

    /**
     * @brief Set UI in tutorial mode.
     * 
     * @param navigation Visibility property of navigation in tutorial mode.
     * @param instruction Visibility property of instruction in tutorial mode.
     */
    void SetTutorial(Visibility navigation = Visibility(), Visibility instruction = Visibility()) {
        tutorialNavigationVisibility = navigation;
        tutorialInstructionVisibility = instruction;
    }

    /**
     * @brief Convert UI object to json object
     * 
     * @return Json::Value 
     */
    Json::Value toJsonObject() {
        Json::Value res;
        res["scope"] = scope;
        res["primaryMetric"] = primaryMetric;
        res["secondaryMetric"] = secondaryMetric;
        res["menuVisibility"] = menuVisibility.toJsonObject();
        res["judgmentVisibility"] = judgmentVisibility.toJsonObject();
        res["comboVisibility"] = comboVisibility.toJsonObject();
        res["primaryMetricVisibility"] = primaryMetricVisibility.toJsonObject();
        res["secondaryMetricVisibility"] = secondaryMetricVisibility.toJsonObject();
        res["progressVisibility"] = progressVisibility.toJsonObject();
        res["tutorialNavigationVisibility"] = tutorialNavigationVisibility.toJsonObject();
        res["tutorialInstructionVisibility"] = tutorialInstructionVisibility.toJsonObject();
        res["judgmentAnimation"] = judgmentAnimation.toJsonObject();
        res["comboAnimation"] = comboAnimation.toJsonObject();
        res["judgmentErrorStyle"] = judgmentErrorStyle;
        res["judgmentErrorPlacement"] = judgmentErrorPlacement;
        res["judgmentErrorMin"] = judgmentErrorMin;
        return res;
    }
}UI;

/**
 * @brief Build Engine Configuration
 * 
 * @param path Output path of Engine Configuration.
 */
void BuildConfiguration() {
    Json::Value configuration;
    configuration["ui"] = UI.toJsonObject();
    configuration["options"].resize(0);
    for (int i = 0; i < engineConfigurationOptions.size(); i++)
        configuration["options"].append(engineConfigurationOptions[i]);
    string EngineConfiguration = compress_gzip(json_encode(configuration));
    ofstream fout = ofstream(dist + "/EngineConfiguration");
    fout.write(EngineConfiguration.c_str(), EngineConfiguration.size());
}
#endif