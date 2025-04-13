Blocked SonolusApi NormalNoteFroze(var t, var s) {
    if (spawnedLoopEffect) {
        StopLooped(spawnedLoopEffect), spawnedLoopEffect = 0;
        DestroyParticleEffect(spawnedParticleEffect), spawnedParticleEffect = 0;
    }
    var p = t / s;
    var l1 = -0.5, r1 = 0.5, b1 = 0.3, t1 = 0.7;
    var l2 = -0.5, r2 = 0.5, b2 = -0.3, t2 = 0.1;
    if (p < 0.80) {
        Draw(Sprites.NormalNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1e8, 1);
        Draw(Sprites.CriticalNote, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1e8, 1);
    } else {
        Draw(Sprites.NormalNote, { l1, b1 }, { l1, t1 }, { r1, t1 }, { r1, b1 }, 1e8, (1 - p) * 5);
        Draw(Sprites.CriticalNote, { l2, b2 }, { l2, t2 }, { r2, t2 }, { r2, b2 }, 1e8, (1 - p) * 5);
    }
}

Blocked SonolusApi NormalNoteFall(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.NormalNoteLeft, 5, 8, tutorialStartTime + appearTime);
}

Blocked SonolusApi NormalNoteClick(var t, var s) {
    instruction = int(iTexts.NormalNote);
    drawNormalNote(Sprites.NormalNoteLeft, 5, 8, times.now);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1);
}

Blocked SonolusApi NormalNoteDisappear(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.NormalLinear, Effects.NormalCircular, 5, 8),
        Play(Clips.Perfect, minSFXDistance),
        spawnedEffect = 1;
    }
}

Blocked SonolusApi CriticalNoteFall(var t, var s) {
    spawnedEffect = 0;
    drawNormalNote(Sprites.CriticalNoteLeft, 5, 8, tutorialStartTime + appearTime);
}

Blocked SonolusApi CriticalNoteClick(var t, var s) {
    instruction = int(iTexts.CriticalNote);
    drawNormalNote(Sprites.CriticalNoteLeft, 5, 8, times.now);
    drawFrozenHand(iIcons.Hand, 0, stage.b + judgelineMarginBottom * stage.h, t / s * 4 % 1);
}

Blocked SonolusApi CriticalNoteDisappear(var t, var s) {
    if (spawnedEffect == 0) {
        instruction = -1;
        spawnEffect(Effects.CriticalLinear, Effects.CriticalCircular, 5, 8),
        Play(Clips.Critical, minSFXDistance),
        spawnedEffect = 1;
    }
}

defineTutorialSegment(NormalNoteFroze, tutorialFrozeTime);
defineTutorialSegment(NormalNoteFall, appearTime.getNode().value);
defineTutorialSegment(NormalNoteClick, tutorialClickTime);
defineTutorialSegment(NormalNoteDisappear, tutorialDisappearTime);
defineTutorialSegment(CriticalNoteFall, appearTime.getNode().value);
defineTutorialSegment(CriticalNoteClick, tutorialClickTime);
defineTutorialSegment(CriticalNoteDisappear, tutorialDisappearTime);
defineTutorialSegmentsGroup(Note);