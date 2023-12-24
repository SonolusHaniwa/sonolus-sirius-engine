class JumpScratchTutorial {
	public:

	var Froze(var t) {
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
		return {
			IF (p < 0.80) {
				Draw(Sprites.ScratchNote, l1, b1, l1, t1, r1, t1, r1, b1, 1000, 1),
				Draw(Sprites.Scratch, l2, b2, l2, t2, r2, t2, r2, b2, 1000, 1),
				Draw(Sprites.ScratchNote, l3, b3, l3, t3, r3, t3, r3, b3, 1000, 1),
				Draw(Sprites.Scratch, l4, b4, l4, t4, r4, t4, r4, b4, 1000, 1),
				Draw(Sprites.ScratchNote, l5, b5, l5, t5, r5, t5, r5, b5, 1000, 1),
				Draw(Sprites.CriticalNote, -1 * r1, b1, -1 * r1, t1, -1 * l1, t1, -1 * l1, b1, 1000, 1),
				Draw(Sprites.Scratch, -1 * r2, b2, -1 * r2, t2, -1 * l2, t2, -1 * l2, b2, 1000, 1),
				Draw(Sprites.ScratchNote, -1 * r3, b3, -1 * r3, t3, -1 * l3, t3, -1 * l3, b3, 1000, 1),
				Draw(Sprites.Scratch, -1 * r4, b4, -1 * r4, t4, -1 * l4, t4, -1 * l4, b4, 1000, 1),
				Draw(Sprites.ScratchNote, -1 * r5, b5, -1 * r5, t5, -1 * l5, t5, -1 * l5, b5, 1000, 1),
				FOR (i, 1, num, 1) {
					Draw(Sprites.ScratchArrow, L2 + (i - 1) * W2 / 2, B2, L2 + (i - 1) * W2 / 2, T2,
											   L2 + (i + 1) * W2 / 2, T2, L2 + (i + 1) * W2 / 2, B2, 1001, 1),
					Draw(Sprites.ScratchArrow, R1 - (i - 1) * W1 / 2, B1, R1 - (i - 1) * W1 / 2, T1,
											   R1 - (i + 1) * W1 / 2, T1, R1 - (i + 1) * W1 / 2, B1, 1001, 1),
					Draw(Sprites.ScratchArrow, -1 * R1 + (i - 1) * W1 / 2, B1, -1 * R1 + (i - 1) * W1 / 2, T1,
							                   -1 * R1 + (i + 1) * W1 / 2, T1, -1 * R1 + (i + 1) * W1 / 2, B1, 1001, 1),
					Draw(Sprites.ScratchArrow, -1 * L2 - (i - 1) * W2 / 2, B2, -1 * L2 - (i - 1) * W2 / 2, T2,
							                   -1 * L2 - (i + 1) * W2 / 2, T2, -1 * L2 - (i + 1) * W2 / 2, B2, 1001, 1),
				} DONE
			} ELSE {
				Draw(Sprites.ScratchNote, l1, b1, l1, t1, r1, t1, r1, b1, 1000, (1 - p) * 5),
				Draw(Sprites.Scratch, l2, b2, l2, t2, r2, t2, r2, b2, 1000, (1 - p) * 5),
				Draw(Sprites.ScratchNote, l3, b3, l3, t3, r3, t3, r3, b3, 1000, (1 - p) * 5),
				Draw(Sprites.Scratch, l4, b4, l4, t4, r4, t4, r4, b4, 1000, (1 - p) * 5),
				Draw(Sprites.ScratchNote, l5, b5, l5, t5, r5, t5, r5, b5, 1000, (1 - p) * 5),
				Draw(Sprites.CriticalNote, -1 * r1, b1, -1 * r1, t1, -1 * l1, t1, -1 * l1, b1, 1000, (1 - p) * 5),
				Draw(Sprites.Scratch, -1 * r2, b2, -1 * r2, t2, -1 * l2, t2, -1 * l2, b2, 1000, (1 - p) * 5),
				Draw(Sprites.ScratchNote, -1 * r3, b3, -1 * r3, t3, -1 * l3, t3, -1 * l3, b3, 1000, (1 - p) * 5),
				Draw(Sprites.Scratch, -1 * r4, b4, -1 * r4, t4, -1 * l4, t4, -1 * l4, b4, 1000, (1 - p) * 5),
				Draw(Sprites.ScratchNote, -1 * r5, b5, -1 * r5, t5, -1 * l5, t5, -1 * l5, b5, 1000, (1 - p) * 5),
				FOR (i, 1, num, 1) {
					Draw(Sprites.ScratchArrow, L2 + (i - 1) * W2 / 2, B2, L2 + (i - 1) * W2 / 2, T2,
											   L2 + (i + 1) * W2 / 2, T2, L2 + (i + 1) * W2 / 2, B2, 1001, (1 - p) * 5),
					Draw(Sprites.ScratchArrow, R1 - (i - 1) * W1 / 2, B1, R1 - (i - 1) * W1 / 2, T1,
											   R1 - (i + 1) * W1 / 2, T1, R1 - (i + 1) * W1 / 2, B1, 1001, (1 - p) * 5),
					Draw(Sprites.ScratchArrow, -1 * R1 + (i - 1) * W1 / 2, B1, -1 * R1 + (i - 1) * W1 / 2, T1,
							                   -1 * R1 + (i + 1) * W1 / 2, T1, -1 * R1 + (i + 1) * W1 / 2, B1, 1001, (1 - p) * 5),
					Draw(Sprites.ScratchArrow, -1 * L2 - (i - 1) * W2 / 2, B2, -1 * L2 - (i - 1) * W2 / 2, T2,
							                   -1 * L2 - (i + 1) * W2 / 2, T2, -1 * L2 - (i + 1) * W2 / 2, B2, 1001, (1 - p) * 5),
				} DONE
			} FI
		};
	}

	var lane(var c, var o) {
		return IF (c) {
			IF (o) { 4 } ELSE { 7 } FI
		} ELSE {
			IF (o) { 7 } ELSE { 4 } FI
		} FI;
	}

	var enLane(var c, var o) {
		return IF (c) {
			IF (o) { 6 } ELSE { 9 } FI
		} ELSE {
			IF (o) { 9 } ELSE { 6 } FI
		} FI;
	}

	var Fall(var t, var c) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(IF (c) { Sprites.CriticalNote } ELSE { Sprites.ScratchNote } FI, lane(c, 0), enLane(c, 0), p - 1),
			drawHoldEighth(Sprites.Scratch, lane(c, 0), enLane(c, 0), p - 1, -1)
		};
	}

	var Click(var t, var c) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.JumpScratchStartNote),
			drawNormalNote(IF (c) { Sprites.CriticalNote } ELSE { Sprites.ScratchNote } FI, lane(c, 0), enLane(c, 0), 0),
			drawHoldEighth(Sprites.Scratch, lane(c, 0), enLane(c, 0), 0, -1),
			drawFrozenHand(lane(c, 0), enLane(c, 0), p * 400 % 100, true, false)
		};
	}

	var Disappear(var t, var c) {
		return {
			drawNormalNote(Sprites.ScratchNote, lane(c, 0), enLane(c, 0), 0),
			drawHoldEighth(Sprites.Scratch, lane(c, 0), enLane(c, 0), 0, -1),
			drawFrozenHand(lane(c, 0), enLane(c, 0), 100, false, false),
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane(c, 0), enLane(c, 0)),
				Play(Clips.Perfect, minSFXDistance),
				spawnedEffect.set(1)
			} FI
		};
	}

	var Fall2(var t, var c) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.ScratchNote, lane(c, 0), enLane(c, 0), 0),
			drawHoldEighth(Sprites.Scratch, lane(c, 0), enLane(c, 0), 0, p - 1),
			IF (c) { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 1), enLane(c, 0), p - 1),
				drawLeftArrow(lane(c, 1), enLane(c, 0), p - 1) 
			} ELSE { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 0), enLane(c, 1), p - 1),
				drawRightArrow(lane(c, 0), enLane(c, 1), p - 1) 
			} FI,
			drawHoldEighth(Sprites.Scratch, lane(c, 1), enLane(c, 1), -1, p - 1),
			drawFrozenHand(lane(c, 0), enLane(c, 0), 100, false, false)
		};
	}

	var Click2(var t, var c) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.JumpScratchMiddleNote),
			IF (c) { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 1), enLane(c, 0), 0),
				drawLeftArrow(lane(c, 1), enLane(c, 0), 0) 
			} ELSE { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 0), enLane(c, 1), 0),
				drawRightArrow(lane(c, 0), enLane(c, 1), 0)
			} FI,
			drawHoldEighth(Sprites.Scratch, lane(c, 1), enLane(c, 1), -1, 0),
			drawHorizontalHand(lane(c, 0), enLane(c, 0), lane(c, 1), enLane(c, 1), p * 400 % 100, handEndAngle)
		};
	}

	var Disappear2(var t, var c) {
		return {
			drawNormalNote(Sprites.ScratchNote, lane(c, 1), enLane(c, 1), 0),
			drawHoldEighth(Sprites.Scratch, lane(c, 1), enLane(c, 1), -1, 0),
			drawFrozenHand(lane(c, 1), enLane(c, 1), 100, false, false),
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				IF (c) { 
					spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane(c, 1), enLane(c, 0)),
				} ELSE { 
					spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane(c, 0), enLane(c, 1)),
				} FI,
				Play(Clips.Scratch, minSFXDistance),
				spawnedEffect.set(1)	
			} FI
		};
	}

	var Fall3(var t, var c) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.ScratchNote, lane(c, 1), enLane(c, 1), 0),
			drawHoldEighth(Sprites.Scratch, lane(c, 1), enLane(c, 1), 0, p - 1),
			IF (c) { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 1), enLane(c, 0), p - 1),
				drawRightArrow(lane(c, 1), enLane(c, 0), p - 1) 
			} ELSE { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 0), enLane(c, 1), p - 1),
				drawLeftArrow(lane(c, 0), enLane(c, 1), p - 1) 
			} FI,
			drawFrozenHand(lane(c, 1), enLane(c, 1), 100, false, false)
		};
	}

	var Click3(var t, var c) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.JumpScratchEndNote),
			IF (c) { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 1), enLane(c, 0), 0),
				drawRightArrow(lane(c, 1), enLane(c, 0), 0) 
			} ELSE { 
				drawNormalNote(Sprites.ScratchNote, lane(c, 0), enLane(c, 1), 0),
				drawLeftArrow(lane(c, 0), enLane(c, 1), 0)
			} FI,
			drawHorizontalHand(lane(c, 1), enLane(c, 1), lane(c, 0), enLane(c, 0), p * 400 % 100, handEndAngle)
		};
	}

	var Disappear3(var t, var c) {
		return {
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				IF (c) { 
					spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane(c, 1), enLane(c, 0)),
				} ELSE { 
					spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, lane(c, 0), enLane(c, 1)),
				} FI,
				Play(Clips.Scratch, minSFXDistance),
				spawnedEffect.set(1)	
			} FI
		};
	}
	
	var Run() {
		var t0 = tutorialFrozeTime;
//		var t1 = t0 + tutorialSplitLineTime;
		var t2 = t0 + tutorialFallTime;
		var t3 = t2 + tutorialClickTime;
		var t4 = t3 + tutorialDisappearTime;
		var t5 = t4 + tutorialFallTime;
		var t6 = t5 + tutorialClickTime;
		var t7 = t6 + tutorialDisappearTime;
		var t8 = t7 + tutorialFallTime;
		var t9 = t8 + tutorialClickTime;
		var t10 = t9 + tutorialDisappearTime;
		var tNow = IF (timesNow >= t10) { timesNow - (t10 - t0) } ELSE { timesNow } FI;
		var isCritical = IF (timesNow >= t10) { 1 } ELSE { 0 } FI;
		return {
			IF (timesNow - t0 < splitLineAnimationStart) {
				IF (timesNow - t0 > 0) {
					drawAppearLine(timesNow - t0, 1)
				} FI
			} ELSE {
				IF (timesNow - (t9 + t10 - t0) > 0) {
					IF (timesNow - (t9 + t10 - t0) < splitLineAnimationEnd) { 
						drawDisappearLine(timesNow - (t9 + t10 - t0), 1) 
					} FI
				} ELSE {
					drawSplitLine(1)
				} FI
			} FI,
			IF (tNow < t0) { Froze(tNow) } 
			ELSE { IF (tNow < t4) {
				IF (tNow < t2) { Fall(tNow - t0, isCritical) } 
				ELSE { IF (tNow < t3) { Click(tNow - t2, isCritical) }
				ELSE { Disappear(tNow - t3, isCritical) } FI } FI
			} ELSE { IF (tNow < t7) {
				IF ( tNow < t5 ) { Fall2(tNow - t4, isCritical) }
				ELSE { IF (tNow < t6) { Click2(tNow - t5, isCritical) }
				ELSE { Disappear2(tNow - t6, isCritical) } FI } FI
			} ELSE { IF (tNow < t10) {
				IF (tNow < t8) { Fall3(tNow - t7, isCritical) }
				ELSE { IF (tNow < t9) { Click3(tNow - t8, isCritical) }
				ELSE { Disappear3(tNow - t9, isCritical) } FI } FI 
			} ELSE { nextTutorial() } FI } FI } FI } FI
		};
	}
}JumpScratchTutorial;
