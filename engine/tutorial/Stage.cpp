Blocked SonolusApi drawStage(var t, var s) {
    Draw(
        Sprites.Stage, 
        { stage.l, stage.b }, 
        { stage.l * highWidth, stage.t }, 
        { stage.r * highWidth, stage.t }, 
        { stage.r, stage.b }, 
        1, 
        1
    );
    Draw(
        Sprites.StageBackground, 
        { stage.l, stage.b }, 
        { stage.l * highWidth, stage.t }, 
        { stage.r * highWidth, stage.t }, 
        { stage.r, stage.b }, 
        2, 
        opacity
    );
    Draw(
        Sprites.Judgeline, 
        { judgline.lbX, judgline.lbY }, 
        { judgline.ltX, judgline.ltY }, 
        { judgline.rtX, judgline.rtY }, 
        { judgline.rbX, judgline.rbY }, 
        3, 
        1
    );
}

defineTutorialStatic(drawStage);