Blocked SonolusApi HoldNoteFroze(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    var p = t / tutorialFrozeTime;
    var l1 = -0.55, r1 = -0.05, b1 = -0.3, t1 = -0.1;
    var l2 = -0.525, r2 = -0.075, b2 = -0.1, t2 = 0.5;
    var l3 = -0.55, r3 = -0.05, b3 = 0.5, t3 = 0.7;
    var l4 = 0.05, r4 = 0.55, b4 = -0.3, t4 = -0.1;
    var l5 = 0.075, r5 = 0.525, b5 = -0.1, t5 = 0.5;
    var l6 = 0.06, r6 = 0.55, b6 = 0.5, t6 = 0.7;
    if (p < 0.80) {
        Draw(Sprites.HoldNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1e8, 1);
        Draw(Sprites.Hold, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1e8, 1);
        Draw(Sprites.HoldNote, { l3, b3 }, { l3, t3 }, { r3, t3 }, { r3, b3 }, 1e8, 1);
        Draw(Sprites.CriticalNote, { l4, b4 }, { l4, t4 }, { r4, t4 }, { r4, b4 }, 1e8, 1);
        Draw(Sprites.Hold, { l5, b5 }, { l5, t5 }, { r5, t5 }, { r5, b5 }, 1e8, 1);
        Draw(Sprites.HoldNote, { l6, b6 }, { l6, t6 }, { r6, t6 }, { r6, b6 }, 1e8, 1);
    } else {
        Draw(Sprites.HoldNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1e8, (1 - p) * 5);
        Draw(Sprites.Hold, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1e8, (1 - p) * 5);
        Draw(Sprites.HoldNote, { l3, b3 }, { l3, t3 }, { r3, t3 }, { r3, b3 }, 1e8, (1 - p) * 5);
        Draw(Sprites.CriticalNote, { l4, b4 }, { l4, t4 }, { r4, t4 }, { r4, b4 }, 1e8, (1 - p) * 5);
        Draw(Sprites.Hold, { l5, b5 }, { l5, t5 }, { r5, t5 }, { r5, b5 }, 1e8, (1 - p) * 5);
        Draw(Sprites.HoldNote, { l6, b6 }, { l6, t6 }, { r6, t6 }, { r6, b6 }, 1e8, (1 - p) * 5);
    }
}

Blocked SonolusApi NormalHoldNoteFall(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    spawnedEffect = 0;
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Hold, 5, 8, tutorialStartTime + appearTime, tutorialStartTime + appearTime * 2, false);
}

Blocked SonolusApi NormalHoldNoteClick(var t, var s) {
    instruction = FuncNode(iTexts.HoldStartNote);
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Hold, 5, 8, times.now, times.now + appearTime, false);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, true, false);
}

Blocked SonolusApi NormalHoldNoteDisappear(var t, var s) {
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Hold, 5, 8, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.HoldLinear, Effects.HoldCircular, 5, 8);
        Play(Clips.Perfect, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Hold, 5, 8);
    }
}

Blocked SonolusApi NormalHoldNoteFall2(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Hold, 5, 8, tutorialStartTime, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi NormalHoldNoteClick2(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = FuncNode(iTexts.HoldEndNote);
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, times.now);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1 - t / s * 4 % 1, true, false);
}

Blocked SonolusApi NormalHoldNoteDisappear2(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.HoldLinear, Effects.HoldCircular, 5, 8);
        Play(Clips.Perfect, minSFXDistance);
        spawnedEffect = 1;
    }
}

Blocked SonolusApi CriticalHoldNoteFall(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    spawnedEffect = 0;
    drawNormalNote(Sprites.CriticalNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Hold, 5, 8, tutorialStartTime + appearTime, tutorialStartTime + appearTime * 2, false);
}

Blocked SonolusApi CriticalHoldNoteClick(var t, var s) {
    instruction = FuncNode(iTexts.CriticalHoldStartNote);
    drawNormalNote(Sprites.CriticalNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Hold, 5, 8, times.now, times.now + appearTime, false);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, true, false);
}

Blocked SonolusApi CriticalHoldNoteDisappear(var t, var s) {
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Hold, 5, 8, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.CriticalLinear, Effects.CriticalCircular, 5, 8);
        Play(Clips.Critical, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Hold, 5, 8);
    }
}

Blocked SonolusApi CriticalHoldNoteFall2(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Hold, 5, 8, tutorialStartTime, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi CriticalHoldNoteClick2(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = FuncNode(iTexts.CriticalHoldEndNote);
    drawNormalNote(Sprites.HoldNoteLeft, 5, 8, times.now);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1 - t / s * 4 % 1, true, false);
}

Blocked SonolusApi CriticalHoldNoteDisappear2(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.HoldLinear, Effects.HoldCircular, 5, 8);
        Play(Clips.Perfect, minSFXDistance);
        spawnedEffect = 1;
    }
}

defineTutorialSegment(HoldNoteFroze, tutorialFrozeTime);
defineTutorialSegment(NormalHoldNoteFall, appearTime.getNode().value);
defineTutorialSegment(NormalHoldNoteClick, tutorialClickTime);
defineTutorialSegment(NormalHoldNoteDisappear, tutorialDisappearTime);
defineTutorialSegment(NormalHoldNoteFall2, appearTime.getNode().value);
defineTutorialSegment(NormalHoldNoteClick2, tutorialClickTime);
defineTutorialSegment(NormalHoldNoteDisappear2, tutorialDisappearTime);
defineTutorialSegment(CriticalHoldNoteFall, appearTime.getNode().value);
defineTutorialSegment(CriticalHoldNoteClick, tutorialClickTime);
defineTutorialSegment(CriticalHoldNoteDisappear, tutorialDisappearTime);
defineTutorialSegment(CriticalHoldNoteFall2, appearTime.getNode().value);
defineTutorialSegment(CriticalHoldNoteClick2, tutorialClickTime);
defineTutorialSegment(CriticalHoldNoteDisappear2, tutorialDisappearTime);
defineTutorialSegmentsGroup(Hold);