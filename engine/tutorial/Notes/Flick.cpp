Blocked SonolusApi FlickNoteFroze(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    var p = t / tutorialFrozeTime;
    var l1 = -0.5, r1 = 0.5, b1 = -0.05, t1 = 0.25;
    var l2 = -0.5, r2 = 0.5, b2 = 0.075, t2 = b2 + 0.45;
    var H = t2 - b2, W = H / 2.5, L = l2, R = r2;
    var num = (R - L) / 2 * arrowPercent / W;
    if (p < 0.80) {
        Draw(Sprites.ScratchNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1000, 1);
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
                { L + (i - 1) * W / 2, b2 }, 
                { L + (i - 1) * W / 2, t2 },
                { L + (i + 1) * W / 2, t2 }, 
                { L + (i + 1) * W / 2, b2 }, 
                1001, 
                1
            );
            Draw(
                Sprites.ScratchArrow, 
                { R - (i - 1) * W / 2, b2 }, 
                { R - (i - 1) * W / 2, t2 },
                { R - (i + 1) * W / 2, t2 }, 
                { R - (i + 1) * W / 2, b2 }, 
                1001, 
                1
            );
        }
    } else {
        Draw(Sprites.ScratchNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1000, (1 - p) * 5);
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
                { L + (i - 1) * W / 2, b2 }, 
                { L + (i - 1) * W / 2, t2 },
                { L + (i + 1) * W / 2, t2 }, 
                { L + (i + 1) * W / 2, b2 }, 
                1001, 
                (1 - p) * 5
            );
            Draw(
                Sprites.ScratchArrow, 
                { R - (i - 1) * W / 2, b2 }, 
                { R - (i - 1) * W / 2, t2 },
                { R - (i + 1) * W / 2, t2 }, 
                { R - (i + 1) * W / 2, b2 }, 
                1001, 
                (1 - p) * 5
            );
        }
    }
}

Blocked SonolusApi FlickNoteFall(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawArrow(5, 8, tutorialStartTime + appearTime);
}

Blocked SonolusApi FlickNoteClick(var t, var s) {
    var p = t / tutorialClickTime;
    instruction = FuncNode(iTexts.ScratchNote);
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, times.now);
    drawArrow(5, 8, times.now);
    if (Ceil(p * 4) % 2 == 1) drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, p * 4 % 1, true, false);
    else drawUpperHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, p * 4 % 1, handEndAngle);
}

Blocked SonolusApi FlickNoteDisappear(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.ScratchLinear, Effects.ScratchLinear, 5, 8);
        Play(Clips.Scratch, minSFXDistance);
        spawnedEffect = 1;
    }
}

defineTutorialSegment(FlickNoteFroze, tutorialFrozeTime);
defineTutorialSegment(FlickNoteFall, appearTime.getNode().value);
defineTutorialSegment(FlickNoteClick, tutorialClickTime);
defineTutorialSegment(FlickNoteDisappear, tutorialDisappearTime);
defineTutorialSegmentsGroup(Flick);