class Stage: public Archetype {
    public:

    static constexpr const char*  name = "Sirius Stage";
    bool input = false;

    SonolusApi spawnOrder() { return 2; }

    SonolusApi shouldSpawn() { return 1; }

  //   var drawJudgeText() {
		// var H = judgeTextHeight * ui.judgmentConfiguration.scale;
  //       var T = H / 2.0, B = -1 * T;
  //       var W = H * SwitchWithDefault(currentJudge.get(), {
  //           {Sprites.JudgePerfectPlus, judgePerfectPlusRatio},
  //           {Sprites.JudgePerfect, judgePerfectRatio},
  //           {Sprites.JudgeGreat, judgeGreatRatio},
  //           {Sprites.JudgeGood, judgeGoodRatio},
  //           {Sprites.JudgeBad, judgeBadRatio},
  //           {Sprites.JudgeMiss, judgeMissRatio},
  //           {Sprites.JudgeAuto, judgeAutoRatio}
  //       }, 0);
  //       var R = W / 2.0, L = -1 * R;
  //       var scale = 0.4 + 0.6 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
  //       var a = 0.4 + 0.6 * Ease(Min(1, (times.now - currentJudgeStartTime.get()) / judgeTextDuration), RuntimeFunction.EaseInSine);
  //       L *= scale, R *= scale, T *= scale, B *= scale;
  //       return Draw(currentJudge.get(), L, B, L, T, R, T, R, B, 1e8, a * ui.judgmentConfiguration.alpha);
  //   }

    SonolusApi updateParallel() {
    	FUNCBEGIN
        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1);
	    Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, 0.6);
		// IF (LevelOption.get(Options.Hidden) != 0) { drawHiddenLine(); } FI, 
		Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1);
		// drawJudgeText()
		return VOID;
    }

    int touchOrder = 10000;
	// var playStageParticle(Touch touch) {
	// 	vector<var> args;
	// 	for (int i = 1; i <= 12; i++) {
	// 		args.push_back(Execute({
	// 			IF (lines.inClickBox(touch, i, i, true)) {
	// 				spawnLineEffect(i, i)
	// 			} FI
	// 		}));
	// 	}; return Execute(args);
	// }

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
