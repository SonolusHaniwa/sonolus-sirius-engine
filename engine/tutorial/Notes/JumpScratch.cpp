Blocked SonolusApi JumpScratchFroze(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    var p = t / tutorialFrozeTime;
    var l1 = -0.75, r1 = -0.40, b1 = -0.3, t1 = -0.15;
    var l2 = -0.7375, r2 = -0.4125, b2 = -0.15, t2 = 0.15;
    var l3 = -0.75, r3 = -0.05, b3 = 0.15, t3 = 0.3;
    var l4 = -0.3875, r4 = -0.0625, b4 = 0.3, t4 = 0.6;
    var l5 = -0.75, r5 = -0.05, b5 = 0.6, t5 = 0.75;
    var L1 = -0.75, R1 = -0.05, B1 = 0.3 - 0.225 / 3, T1 = B1 + 0.45 / 3;
    var L2 = -0.75, R2 = -0.05, B2 = 0.75 - 0.225 / 3, T2 = B2 + 0.45 / 3;
    var H1 = T1 - B1, W1 = H1 / 2.5, H2 = T2 - B2, W2 = H2 / 2.5;
    var num = (R1 - L1) * arrowPercent / W1;
    if (p < 0.80) {
        Draw(Sprites.ScratchNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1000, 1);
        Draw(Sprites.Scratch, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1000, 1);
        Draw(Sprites.ScratchNote, { l3, b3 }, { l3, t3 }, { r3, t3 }, { r3, b3 }, 1000, 1);
        Draw(Sprites.Scratch, { l4, b4 }, { l4, t4 }, { r4, t4 }, { r4, b4 }, 1000, 1);
        Draw(Sprites.ScratchNote, { l5, b5 }, { l5, t5 }, { r5, t5 }, { r5, b5 }, 1000, 1);
        Draw(Sprites.CriticalNote, { -1 * r1, b1 }, { -1 * r1, t1 }, { -1 * l1, t1 }, { -1 * l1, b1 }, 1000, 1);
        Draw(Sprites.Scratch, { -1 * r2, b2 }, { -1 * r2, t2 }, { -1 * l2, t2 }, { -1 * l2, b2 }, 1000, 1);
        Draw(Sprites.ScratchNote, { -1 * r3, b3 }, { -1 * r3, t3 }, { -1 * l3, t3 }, { -1 * l3, b3 }, 1000, 1);
        Draw(Sprites.Scratch, { -1 * r4, b4 }, { -1 * r4, t4 }, { -1 * l4, t4 }, { -1 * l4, b4 }, 1000, 1);
        Draw(Sprites.ScratchNote, { -1 * r5, b5 }, { -1 * r5, t5 }, { -1 * l5, t5 }, { -1 * l5, b5 }, 1000, 1);
        for (var i = 1; i < num; i++) {
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
                { R1 - (i - 1) * W1 / 2, B1 }, 
                { R1 - (i - 1) * W1 / 2, T1 },
                { R1 - (i + 1) * W1 / 2, T1 }, 
                { R1 - (i + 1) * W1 / 2, B1 }, 
                1001, 
                1
            );
            Draw(
                Sprites.ScratchArrow, 
                { -1 * R1 + (i - 1) * W1 / 2, B1 }, 
                { -1 * R1 + (i - 1) * W1 / 2, T1 },
                { -1 * R1 + (i + 1) * W1 / 2, T1 }, 
                { -1 * R1 + (i + 1) * W1 / 2, B1 }, 
                1001, 
                1
            );
            Draw(
                Sprites.ScratchArrow, 
                { -1 * L2 - (i - 1) * W2 / 2, B2 }, 
                { -1 * L2 - (i - 1) * W2 / 2, T2 },
                { -1 * L2 - (i + 1) * W2 / 2, T2 }, 
                { -1 * L2 - (i + 1) * W2 / 2, B2 }, 
                1001, 
                1
            );
        }
    } else {
        Draw(Sprites.ScratchNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1000, (1 - p) * 5);
        Draw(Sprites.Scratch, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1000, (1 - p) * 5);
        Draw(Sprites.ScratchNote, { l3, b3 }, { l3, t3 }, { r3, t3 }, { r3, b3 }, 1000, (1 - p) * 5);
        Draw(Sprites.Scratch, { l4, b4 }, { l4, t4 }, { r4, t4 }, { r4, b4 }, 1000, (1 - p) * 5);
        Draw(Sprites.ScratchNote, { l5, b5 }, { l5, t5 }, { r5, t5 }, { r5, b5 }, 1000, (1 - p) * 5);
        Draw(Sprites.CriticalNote, { -1 * r1, b1 }, { -1 * r1, t1 }, { -1 * l1, t1 }, { -1 * l1, b1 }, 1000, (1 - p) * 5);
        Draw(Sprites.Scratch, { -1 * r2, b2 }, { -1 * r2, t2 }, { -1 * l2, t2 }, { -1 * l2, b2 }, 1000, (1 - p) * 5);
        Draw(Sprites.ScratchNote, { -1 * r3, b3 }, { -1 * r3, t3 }, { -1 * l3, t3 }, { -1 * l3, b3 }, 1000, (1 - p) * 5);
        Draw(Sprites.Scratch, { -1 * r4, b4 }, { -1 * r4, t4 }, { -1 * l4, t4 }, { -1 * l4, b4 }, 1000, (1 - p) * 5);
        Draw(Sprites.ScratchNote, { -1 * r5, b5 }, { -1 * r5, t5 }, { -1 * l5, t5 }, { -1 * l5, b5 }, 1000, (1 - p) * 5);
        
        for (var i = 1; i < num; i++) {
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
                { R1 - (i - 1) * W1 / 2, B1 }, 
                { R1 - (i - 1) * W1 / 2, T1 },
                { R1 - (i + 1) * W1 / 2, T1 }, 
                { R1 - (i + 1) * W1 / 2, B1 }, 
                1001, 
                (1 - p) * 5
            );
            Draw(
                Sprites.ScratchArrow, 
                { -1 * R1 + (i - 1) * W1 / 2, B1 }, 
                { -1 * R1 + (i - 1) * W1 / 2, T1 },
                { -1 * R1 + (i + 1) * W1 / 2, T1 }, 
                { -1 * R1 + (i + 1) * W1 / 2, B1 }, 
                1001, 
                (1 - p) * 5
            );
            Draw(
                Sprites.ScratchArrow, 
                { -1 * L2 - (i - 1) * W2 / 2, B2 }, 
                { -1 * L2 - (i - 1) * W2 / 2, T2 },
                { -1 * L2 - (i + 1) * W2 / 2, T2 }, 
                { -1 * L2 - (i + 1) * W2 / 2, B2 }, 
                1001, 
                (1 - p) * 5
            );
        }
    }
}

FuncNode x = Lerp(stage.r, stage.r * highWidth, judgelineMarginBottom) / 4;

Blocked SonolusApi NormalJumpScratchFall(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    spawnedEffect = 0;
    drawNormalNote(Sprites.NormalNoteLeft, 4, 6, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Scratch, 4, 6, tutorialStartTime + appearTime, tutorialStartTime + appearTime * 2, false);
}

Blocked SonolusApi NormalJumpScratchClick(var t, var s) {
    instruction = int(iTexts.JumpScratchStartNote);
    drawNormalNote(Sprites.NormalNoteLeft, 4, 6, times.now);
    drawHoldEighth(Sprites.Scratch, 4, 6, times.now, times.now + appearTime, false);
    drawFrozenHand(iIcons.Hand, -x, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, true, false);
}

Blocked SonolusApi NormalJumpScratchDisappear(var t, var s) {
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 6, times.now);
    drawHoldEighth(Sprites.Scratch, 4, 6, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, -x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.NormalLinear, Effects.NormalCircular, 4, 6);
        Play(Clips.Perfect, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Scratch, 4, 6);
    }
}

Blocked SonolusApi NormalJumpScratchFall2(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 6, times.now);
    drawHoldEighth(Sprites.Scratch, 4, 6, tutorialStartTime, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, tutorialStartTime + appearTime);
    drawRightArrow(4, 9, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Scratch, 7, 9, tutorialStartTime + appearTime, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, -x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi NormalJumpScratchClick2(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = int(iTexts.JumpScratchMiddleNote);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, times.now);
    drawRightArrow(4, 9, times.now);
    drawHoldEighth(Sprites.Scratch, 7, 9, times.now, times.now + appearTime, false);
    drawHorizontalHand(iIcons.Hand, -x, stage.b + judgelineMarginBottom * stage.h, x * 2, t / s * 4 % 1, handEndAngle);
}

Blocked SonolusApi NormalJumpScratchDisappear2(var t, var s) {
    drawNormalNote(Sprites.ScratchNoteLeft, 7, 9, times.now);
    drawHoldEighth(Sprites.Scratch, 7, 9, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 4, 9);
        Play(Clips.Scratch, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Scratch, 7, 9);
    }
}

Blocked SonolusApi NormalJumpScratchFall3(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.ScratchNoteLeft, 7, 9, times.now);
    drawHoldEighth(Sprites.Scratch, 7, 9, times.now, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, tutorialStartTime + appearTime);
    drawLeftArrow(4, 9, tutorialStartTime + appearTime);
    drawFrozenHand(iIcons.Hand, x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi NormalJumpScratchClick3(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = int(iTexts.JumpScratchEndNote);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, times.now);
    drawLeftArrow(4, 9, times.now);
    drawHorizontalHand(iIcons.Hand, x, stage.b + judgelineMarginBottom * stage.h, -x * 2, t / s * 4 % 1, handEndAngle);
}

Blocked SonolusApi NormalJumpScratchDisappear3(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 4, 9);
        Play(Clips.Scratch, minSFXDistance);
        spawnedEffect = 1;
    }
}

Blocked SonolusApi CriticalJumpScratchFall(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    spawnedEffect = 0;
    drawNormalNote(Sprites.CriticalNoteLeft, 7, 9, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Scratch, 7, 9, tutorialStartTime + appearTime, tutorialStartTime + appearTime * 2, false);
}

Blocked SonolusApi CriticalJumpScratchClick(var t, var s) {
    instruction = int(iTexts.JumpScratchStartNote);
    drawNormalNote(Sprites.CriticalNoteLeft, 7, 9, times.now);
    drawHoldEighth(Sprites.Scratch, 7, 9, times.now, times.now + appearTime, false);
    drawFrozenHand(iIcons.Hand, x, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1, true, false);
}

Blocked SonolusApi CriticalJumpScratchDisappear(var t, var s) {
    drawNormalNote(Sprites.ScratchNoteLeft, 7, 9, times.now);
    drawHoldEighth(Sprites.Scratch, 7, 9, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.CriticalLinear, Effects.CriticalCircular, 7, 9);
        Play(Clips.Perfect, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Scratch, 7, 9);
    }
}

Blocked SonolusApi CriticalJumpScratchFall2(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.ScratchNoteLeft, 7, 9, times.now);
    drawHoldEighth(Sprites.Scratch, 7, 9, tutorialStartTime, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, tutorialStartTime + appearTime);
    drawLeftArrow(4, 9, tutorialStartTime + appearTime);
    drawHoldEighth(Sprites.Scratch, 4, 6, tutorialStartTime + appearTime, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi CriticalJumpScratchClick2(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = int(iTexts.JumpScratchMiddleNote);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, times.now);
    drawLeftArrow(4, 9, times.now);
    drawHoldEighth(Sprites.Scratch, 4, 6, times.now, times.now + appearTime, false);
    drawHorizontalHand(iIcons.Hand, x, stage.b + judgelineMarginBottom * stage.h, -x * 2, t / s * 4 % 1, handEndAngle);
}

Blocked SonolusApi CriticalJumpScratchDisappear2(var t, var s) {
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 6, times.now);
    drawHoldEighth(Sprites.Scratch, 4, 6, times.now, times.now + appearTime, true);
    drawFrozenHand(iIcons.Hand, -x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 4, 9);
        Play(Clips.Scratch, minSFXDistance);
        spawnedEffect = 1;
    }
    if (spawnedLoopEffect == 0) {
        spawnedLoopEffect = PlayLooped(Clips.Hold);
        spawnedParticleEffect = spawnHoldEffect(Effects.Scratch, 4, 6);
    }
}

Blocked SonolusApi CriticalJumpScratchFall3(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 6, times.now);
    drawHoldEighth(Sprites.Scratch, 4, 6, times.now, tutorialStartTime + appearTime, true);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, tutorialStartTime + appearTime);
    drawRightArrow(4, 9, tutorialStartTime + appearTime);
    drawFrozenHand(iIcons.Hand, -x, stage.b + judgelineMarginBottom * stage.h, 1, false, false);
}

Blocked SonolusApi CriticalJumpScratchClick3(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    instruction = int(iTexts.JumpScratchEndNote);
    drawNormalNote(Sprites.ScratchNoteLeft, 4, 9, times.now);
    drawRightArrow(4, 9, times.now);
    drawHorizontalHand(iIcons.Hand, -x, stage.b + judgelineMarginBottom * stage.h, x * 2, t / s * 4 % 1, handEndAngle);
}

Blocked SonolusApi CriticalJumpScratchDisappear3(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 4, 9);
        Play(Clips.Scratch, minSFXDistance);
        spawnedEffect = 1;
    }
}

defineTutorialSegment(JumpScratchFroze, tutorialFrozeTime);
defineTutorialSegment(NormalJumpScratchFall, appearTime.getNode().value);
defineTutorialSegment(NormalJumpScratchClick, tutorialClickTime);
defineTutorialSegment(NormalJumpScratchDisappear, tutorialDisappearTime);
defineTutorialSegment(NormalJumpScratchFall2, appearTime.getNode().value);
defineTutorialSegment(NormalJumpScratchClick2, tutorialClickTime);
defineTutorialSegment(NormalJumpScratchDisappear2, tutorialDisappearTime);
defineTutorialSegment(NormalJumpScratchFall3, appearTime.getNode().value);
defineTutorialSegment(NormalJumpScratchClick3, tutorialClickTime);
defineTutorialSegment(NormalJumpScratchDisappear3, tutorialDisappearTime);
defineTutorialSegment(CriticalJumpScratchFall, appearTime.getNode().value);
defineTutorialSegment(CriticalJumpScratchClick, tutorialClickTime);
defineTutorialSegment(CriticalJumpScratchDisappear, tutorialDisappearTime);
defineTutorialSegment(CriticalJumpScratchFall2, appearTime.getNode().value);
defineTutorialSegment(CriticalJumpScratchClick2, tutorialClickTime);
defineTutorialSegment(CriticalJumpScratchDisappear2, tutorialDisappearTime);
defineTutorialSegment(CriticalJumpScratchFall3, appearTime.getNode().value);
defineTutorialSegment(CriticalJumpScratchClick3, tutorialClickTime);
defineTutorialSegment(CriticalJumpScratchDisappear3, tutorialDisappearTime);
defineTutorialSegmentsGroup(JumpScratch);