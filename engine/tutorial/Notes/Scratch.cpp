Blocked SonolusApi ScratchNoteFroze(var t, var s) {
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
    var L1 = -0.55, R1 = -0.05, B1 = 0.5875, T1 = B1 + 0.225;
    var L2 = 0.05, R2 = 0.55, B2 = 0.5875, T2 = B2 + 0.225;
    var H1 = T1 - B1, W1 = H1 / 2.5, H2 = T2 - B2, W2 = H2 / 2.5;
    var num = (R1 - L1) / 2 * arrowPercent / W1;
    if (p < 0.80) {
        Draw(Sprites.ScratchNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1000, 1);
        Draw(Sprites.Scratch, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1000, 1);
        Draw(Sprites.ScratchNote, { l3, b3 }, { l3, t3 }, { r3, t3 }, { r3, b3 }, 1000, 1);
        Draw(Sprites.CriticalNote, { l4, b4 }, { l4, t4 }, { r4, t4 }, { r4, b4 }, 1000, 1);
        Draw(Sprites.Scratch, { l5, b5 }, { l5, t5 }, { r5, t5 }, { r5, b5 }, 1000, 1);
        Draw(Sprites.ScratchNote, { l6, b6 }, { l6, t6 }, { r6, t6 }, { r6, b6 }, 1000, 1);
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
                { L1 + (i - 1) * W1 / 2, B1 }, 
                { L1 + (i - 1) * W1 / 2, T1 },
                { L1 + (i + 1) * W1 / 2, T1 }, 
                { L1 + (i + 1) * W1 / 2, B1 }, 
                1001, 
                1
            );
            Draw(
                Sprites.ScratchArrow, 
                { R1 - (i - 1) * W1 / 2, B1 }, 
                { R1 - (i - 1) * W1 / 2, T1 },
                { R1 - (i + 1) * W1 / 2, T1 }, 
                { R1 - (i + 1) * W1 / 2, B1 }, 
                1001, 
                1
            );
            Draw(
                Sprites.ScratchArrow, 
                { L2 + (i - 1) * W2 / 2, B2 }, 
                { L2 + (i - 1) * W2 / 2, T2 },
                { L2 + (i + 1) * W2 / 2, T2 }, 
                { L2 + (i + 1) * W2 / 2, B2 }, 
                1001, 
                1
            );
            Draw(
                Sprites.ScratchArrow, 
                { R2 - (i - 1) * W2 / 2, B2 }, 
                { R2 - (i - 1) * W2 / 2, T2 },
                { R2 - (i + 1) * W2 / 2, T2 }, 
                { R2 - (i + 1) * W2 / 2, B2 }, 
                1001, 
                1
            );
        }
    } else {
        Draw(Sprites.ScratchNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1000, (1 - p) * 5);
        Draw(Sprites.Scratch, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1000, (1 - p) * 5);
        Draw(Sprites.ScratchNote, { l3, b3 }, { l3, t3 }, { r3, t3 }, { r3, b3 }, 1000, (1 - p) * 5);
        Draw(Sprites.CriticalNote, { l4, b4 }, { l4, t4 }, { r4, t4 }, { r4, b4 }, 1000, (1 - p) * 5);
        Draw(Sprites.Scratch, { l5, b5 }, { l5, t5 }, { r5, t5 }, { r5, b5 }, 1000, (1 - p) * 5);
        Draw(Sprites.ScratchNote, { l6, b6 }, { l6, t6 }, { r6, t6 }, { r6, b6 }, 1000, (1 - p) * 5);
        for (var i = 1; i < num; i++) {
            Draw(
                Sprites.ScratchArrow, 
                { L1 + (i - 1) * W1 / 2, B1 }, 
                { L1 + (i - 1) * W1 / 2, T1 },
                { L1 + (i + 1) * W1 / 2, T1 }, 
                { L1 + (i + 1) * W1 / 2, B1 }, 
                1001, 
                (1 - p) * 5
            );
            Draw(
                Sprites.ScratchArrow, 
                { R1 - (i - 1) * W1 / 2, B1 }, 
                { R1 - (i - 1) * W1 / 2, T1 },
                { R1 - (i + 1) * W1 / 2, T1 }, 
                { R1 - (i + 1) * W1 / 2, B1 }, 
                1001, 
                (1 - p) * 5
            );
            Draw(
                Sprites.ScratchArrow, 
                { L2 + (i - 1) * W2 / 2, B2 }, 
                { L2 + (i - 1) * W2 / 2, T2 },
                { L2 + (i + 1) * W2 / 2, T2 }, 
                { L2 + (i + 1) * W2 / 2, B2 }, 
                1001, 
                (1 - p) * 5
            );
            Draw(
                Sprites.ScratchArrow, 
                { R2 - (i - 1) * W2 / 2, B2 }, 
                { R2 - (i - 1) * W2 / 2, T2 },
                { R2 - (i + 1) * W2 / 2, T2 }, 
                { R2 - (i + 1) * W2 / 2, B2 }, 
                1001, 
                (1 - p) * 5
            );
        }
    }
}

Blocked SonolusApi NormalScratchNoteFall(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    spawnedEffect = 0;
    drawNormalNote(Sprites.NormalNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Scratch, 5, 8, tutorialStartTime + appearTime, tutorialStartTime + appearTime * 2, false);
}

Blocked SonolusApi NormalScratchNoteClick(var t, var s) {
    instruction = int(iTexts.ScratchStartNote);
    drawNormalNote(Sprites.NormalNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Scratch, 5, 8, times.now, times.now + appearTime, false);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, true, false);
}

Blocked SonolusApi NormalScratchNoteDisappear(var t, var s) {
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Scratch, 5, 8, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.NormalLinear, Effects.NormalCircular, 5, 8);
        Play(Clips.Perfect, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Scratch, 5, 8);
    }
}

Blocked SonolusApi NormalScratchNoteFall2(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Scratch, 5, 8, tutorialStartTime, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawArrow(5, 8, tutorialStartTime + appearTime);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi NormalScratchNoteClick2(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = int(iTexts.ScratchEndNote);
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, times.now);
    drawArrow(5, 8, times.now);
    drawUpperHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, handEndAngle, true, false);
}

Blocked SonolusApi NormalScratchNoteDisappear2(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 5, 8);
        Play(Clips.Scratch, minSFXDistance);
        spawnedEffect = 1;
    }
}

Blocked SonolusApi CriticalScratchNoteFall(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    spawnedEffect = 0;
    drawNormalNote(Sprites.CriticalNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Scratch, 5, 8, tutorialStartTime + appearTime, tutorialStartTime + appearTime * 2, false);
}

Blocked SonolusApi CriticalScratchNoteClick(var t, var s) {
    instruction = int(iTexts.ScratchStartNote);
    drawNormalNote(Sprites.CriticalNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Scratch, 5, 8, times.now, times.now + appearTime, false);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, true, false);
}

Blocked SonolusApi CriticalScratchNoteDisappear(var t, var s) {
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Scratch, 5, 8, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.CriticalLinear, Effects.CriticalCircular, 5, 8);
        Play(Clips.Critical, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Scratch, 5, 8);
    }
}

Blocked SonolusApi CriticalScratchNoteFall2(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, times.now);
    drawHoldEighth(Sprites.Scratch, 5, 8, tutorialStartTime, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, tutorialStartTime + appearTime);
    drawArrow(5, 8, tutorialStartTime + appearTime);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi CriticalScratchNoteClick2(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = int(iTexts.ScratchEndNote);
    drawNormalNote(Sprites.ScratchNoteLeft, 5, 8, times.now);
    drawArrow(5, 8, times.now);
    drawUpperHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, handEndAngle, true, false);
}

Blocked SonolusApi CriticalScratchNoteDisappear2(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 5, 8);
        Play(Clips.Scratch, minSFXDistance);
        spawnedEffect = 1;
    }
}

defineTutorialSegment(ScratchNoteFroze, tutorialFrozeTime);
defineTutorialSegment(NormalScratchNoteFall, appearTime.getNode().value);
defineTutorialSegment(NormalScratchNoteClick, tutorialClickTime);
defineTutorialSegment(NormalScratchNoteDisappear, tutorialDisappearTime);
defineTutorialSegment(NormalScratchNoteFall2, appearTime.getNode().value);
defineTutorialSegment(NormalScratchNoteClick2, tutorialClickTime);
defineTutorialSegment(NormalScratchNoteDisappear2, tutorialDisappearTime);
defineTutorialSegment(CriticalScratchNoteFall, appearTime.getNode().value);
defineTutorialSegment(CriticalScratchNoteClick, tutorialClickTime);
defineTutorialSegment(CriticalScratchNoteDisappear, tutorialDisappearTime);
defineTutorialSegment(CriticalScratchNoteFall2, appearTime.getNode().value);
defineTutorialSegment(CriticalScratchNoteClick2, tutorialClickTime);
defineTutorialSegment(CriticalScratchNoteDisappear2, tutorialDisappearTime);
defineTutorialSegmentsGroup(Scratch);