class Stage: public Archetype {
    public:

    static constexpr const char*  name = "Sirius Stage";
    bool input = false;

    SonolusApi spawnOrder() { return 2; }

    SonolusApi shouldSpawn() { return 1; }

    SonolusApi drawJudgeText() {
    	FUNCBEGIN
		let H = judgeTextHeight * ui.judgmentConfiguration.scale;
        let T = H / 2.0, B = -1 * T;
        let W = H * SwitchWithDefault(currentJudge.get(), {
            {Sprites.JudgePerfectPlus, judgePerfectPlusRatio},
            {Sprites.JudgePerfect, judgePerfectRatio},
            {Sprites.JudgeGreat, judgeGreatRatio},
            {Sprites.JudgeGood, judgeGoodRatio},
            {Sprites.JudgeBad, judgeBadRatio},
            {Sprites.JudgeMiss, judgeMissRatio},
            {Sprites.JudgeAuto, judgeAutoRatio}
        }, 0);
        let R = W / 2.0, L = -1 * R;
        let scale = 0.4 + 0.6 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
        let a = 0.4 + 0.6 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
        L *= scale, R *= scale, T *= scale, B *= scale;
        Draw(currentJudge.get(), L, B, L, T, R, T, R, B, 1e8, a * ui.judgmentConfiguration.alpha);
        return VOID;
    }

    SonolusApi updateParallel() {
    	FUNCBEGIN
        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1);
	    Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, 0.6);
		// IF (LevelOption.get(Options.Hidden) != 0) { drawHiddenLine(); } FI, 
		Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1);
		drawJudgeText();
		return VOID;
    }

    int updateSequentialOrder = 10000;
	SonolusApi xToL(let x) {
		let L = getHitbox(1, 12).l, R = getHitbox(1, 12).r;
		return Floor((x - L) / (R - L) * 12 + 1);
	}
	SonolusApi updateSequential() {
		FUNCBEGIN
		Rect hitbox = getHitbox(1, 12);
		FOR (i, 0, touches.size, 1) {
			IF (hitbox.contain(touches[i].x, touches[i].y) == 0) CONTINUE; FI 
			IF (usedTouchId.indexOf(touches[i].id) != -1) CONTINUE; FI
			IF (touches[i].started == 1) spawnLineEffect(xToL(touches[i].x), xToL(touches[i].x));
			ELSE {
				let lastL = xToL(touches[i].x - touches[i].dx);
				let L = xToL(touches[i].x);
				Debuglog(L), Debuglog(lastL);
				IF (L != lastL) spawnLineEffect(L, L); FI
			} FI
		} DONE
		return VOID;
	}
	// var playStageParticle(Touch touch) {
	// 	vector<var> args;
	// 	for (int i = 1; i <= 12; i++) {
	// 		args.push_back(Execute({
	// 			IF (lines.inClickBox(touch, i, i, true)) {
	// 				spawnLineEffect(i, i)
	// 			} FI
	// 		}));
	// 	}; return Execute(args);
	// }W

 //    var touch() {
	// 	return {
	// 		FOR (i, 0, touches.size, 1) {
	// 		    IF (touches[i].started == false) { CONTINUE } FI,
	// 		    IF (lines.inClickBox(touches[i], 1, 12) == false) { CONTINUE } FI,
	// 		    IF (isUsed(touches[i])) { CONTINUE } FI,
	// 		    markAsUsed(touches[i]),
	// 		    Play(Clips.Stage, minSFXDistance),
	// 			playStageParticle(touches[i])
	// 		} DONE
	// 	};
	// }
};
