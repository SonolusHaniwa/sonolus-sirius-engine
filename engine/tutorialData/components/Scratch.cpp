class ScratchTutorial {
	public:

	var Froze(var t) {
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
		return {
			IF (p < 0.80) {
				Draw(Sprites.ScratchNote, l1, b1, l1, t1, r1, t1, r1, b1, 1000, 1),
				Draw(Sprites.Scratch, l2, b2, l2, t2, r2, t2, r2, b2, 1000, 1),
				Draw(Sprites.ScratchNote, l3, b3, l3, t3, r3, t3, r3, b3, 1000, 1),
				Draw(Sprites.CriticalNote, l4, b4, l4, t4, r4, t4, r4, b4, 1000, 1),
				Draw(Sprites.Scratch, l5, b5, l5, t5, r5, t5, r5, b5, 1000, 1),
				Draw(Sprites.ScratchNote, l6, b6, l6, t6, r6, t6, r6, b6, 1000, 1),
				FOR (i, 1, num, 1) {
					Draw(Sprites.ScratchArrow, L1 + (i - 1) * W1 / 2, B1, L1 + (i - 1) * W1 / 2, T1,
											   L1 + (i + 1) * W1 / 2, T1, L1 + (i + 1) * W1 / 2, B1, 1001, 1),
					Draw(Sprites.ScratchArrow, R1 - (i - 1) * W1 / 2, B1, R1 - (i - 1) * W1 / 2, T1,
											   R1 - (i + 1) * W1 / 2, T1, R1 - (i + 1) * W1 / 2, B1, 1001, 1),
					Draw(Sprites.ScratchArrow, L2 + (i - 1) * W2 / 2, B2, L2 + (i - 1) * W2 / 2, T2,
							                   L2 + (i + 1) * W2 / 2, T2, L2 + (i + 1) * W2 / 2, B2, 1001, 1),
					Draw(Sprites.ScratchArrow, R2 - (i - 1) * W2 / 2, B2, R2 - (i - 1) * W2 / 2, T2,
							                   R2 - (i + 1) * W2 / 2, T2, R2 - (i + 1) * W2 / 2, B2, 1001, 1),
				} DONE
			} ELSE {
				Draw(Sprites.ScratchNote, l1, b1, l1, t1, r1, t1, r1, b1, 1000, (1 - p) * 5),
				Draw(Sprites.Scratch, l2, b2, l2, t2, r2, t2, r2, b2, 1000, (1 - p) * 5),
				Draw(Sprites.ScratchNote, l3, b3, l3, t3, r3, t3, r3, b3, 1000, (1 - p) * 5),
				Draw(Sprites.CriticalNote, l4, b4, l4, t4, r4, t4, r4, b4, 1000, (1 - p) * 5),
				Draw(Sprites.Scratch, l5, b5, l5, t5, r5, t5, r5, b5, 1000, (1 - p) * 5),
				Draw(Sprites.ScratchNote, l6, b6, l6, t6, r6, t6, r6, b6, 1000, (1 - p) * 5),
				FOR (i, 1, num, 1) {
					Draw(Sprites.ScratchArrow, L1 + (i - 1) * W1 / 2, B1, L1 + (i - 1) * W1 / 2, T1, 
							                   L1 + (i + 1) * W1 / 2, T1, L1 + (i + 1) * W1 / 2, B1, 1001, (1 - p) * 5),
					Draw(Sprites.ScratchArrow, R1 - (i - 1) * W1 / 2, B1, R1 - (i - 1) * W1 / 2, T1,
							                   R1 - (i + 1) * W1 / 2, T1, R1 - (i + 1) * W1 / 2, B1, 1001, (1 - p) * 5),
					Draw(Sprites.ScratchArrow, L2 + (i - 1) * W2 / 2, B2, L2 + (i - 1) * W2 / 2, T2,
							                   L2 + (i + 1) * W2 / 2, T2, L2 + (i + 1) * W2 / 2, B2, 1001, (1 - p) * 5),
					Draw(Sprites.ScratchArrow, R2 - (i - 1) * W2 / 2, B2, R2 - (i - 1) * W2 / 2, T2,
											   R2 - (i + 1) * W2 / 2, T2, R2 - (i + 1) * W2 / 2, B2, 1001, (1 - p) * 5),
				} DONE
			} FI
		};
	}

	var NormalFall(var t) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.ScratchNote, 5, 8, p - 1),
			drawHoldEighth(Sprites.Scratch, 5, 8, p - 1, -1)
		};
	}

	var NormalClick(var t) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.ScratchStartNote),
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawHoldEighth(Sprites.Scratch, 5, 8, 0, -1),
			drawFrozenHand(5, 8, p * 400 % 100, true, false)
		};
	}

	var NormalDisappear(var t) {
		return {
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawHoldEighth(Sprites.Scratch, 5, 8, 0, -1),
			drawFrozenHand(5, 8, 100, false, false),
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 5, 8),
				Play(Clips.Perfect, minSFXDistance),
				spawnedEffect.set(1)
			} FI
		};
	}

	var NormalFall2(var t) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.ScratchNote, 5, 8, p - 1),
			drawHoldEighth(Sprites.Scratch, 5, 8, 0, p - 1),
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawArrow(5, 8, p - 1),
			drawFrozenHand(5, 8, 100, false, false)
		};
	}

	var NormalClick2(var t) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.ScratchEndNote),
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawArrow(5, 8, 0),
			drawUpperHand(5, 8, p * 400 % 100, handEndAngle)
		};
	}

	var NormalDisappear2(var t) {
		return {
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 5, 8),
				Play(Clips.Scratch, minSFXDistance),
				spawnedEffect.set(1)	
			} FI
		};
	}

	var CriticalFall(var t) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.CriticalNote, 5, 8, p - 1),
			drawHoldEighth(Sprites.Scratch, 5, 8, p - 1, -1)
		};
	}

	var CriticalClick(var t) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.CriticalScratchStartNote),
			drawNormalNote(Sprites.CriticalNote, 5, 8, 0),
			drawHoldEighth(Sprites.Scratch, 5, 8, 0, -1),
			drawFrozenHand(5, 8, p * 400 % 100, true, false)
		};
	}

	var CriticalDisappear(var t) {
		return {
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawHoldEighth(Sprites.Scratch, 5, 8, 0, -1),
			drawFrozenHand(5, 8, 100, false, false),
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				spawnEffect(Effects.CriticalLinear, Effects.CriticalCircular, 5, 8),
				Play(Clips.CriticalPerfect, minSFXDistance),
				spawnedEffect.set(1)
			} FI
		};
	}

	var CriticalFall2(var t) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.ScratchNote, 5, 8, p - 1),
			drawHoldEighth(Sprites.Scratch, 5, 8, 0, p - 1),
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawFrozenHand(5, 8, 100, false, false),
			drawArrow(5, 8, p - 1)
		};
	}

	var CriticalClick2(var t) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.CriticalScratchEndNote),
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawArrow(5, 8, 0),
			drawUpperHand(5, 8, p * 400 % 100, handEndAngle)
		};
	}

	var CriticalDisappear2(var t) {
		return {
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				spawnEffect(Effects.ScratchLinear, Effects.ScratchCircular, 5, 8),
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
		var t11 = t10 + tutorialFallTime;
		var t12 = t11 + tutorialClickTime;
		var t13 = t12 + tutorialDisappearTime;
		return IF (timesNow < t0) { Froze(timesNow) } 
		ELSE { IF (timesNow < t4) {
			IF (timesNow < t2) { NormalFall(timesNow - t0) } 
			ELSE { IF (timesNow < t3) { NormalClick(timesNow - t2) }
			ELSE { NormalDisappear(timesNow - t3) } FI } FI
		} ELSE { IF (timesNow < t7) {
			IF ( timesNow < t5 ) { NormalFall2(timesNow - t4) }
			ELSE { IF (timesNow < t6) { NormalClick2(timesNow - t5) }
			ELSE { NormalDisappear2(timesNow - t6) } FI } FI
		} ELSE { IF (timesNow < t10) {
			IF (timesNow < t8) { CriticalFall(timesNow - t7) }
			ELSE { IF (timesNow < t9) { CriticalClick(timesNow - t8) }
			ELSE { CriticalDisappear(timesNow - t9) } FI } FI 
		} ELSE { IF (timesNow < t13) { 
			IF (timesNow < t11) { CriticalFall2(timesNow - t10) }
			ELSE { IF (timesNow < t12) { CriticalClick2(timesNow - t11) }
			ELSE { CriticalDisappear2(timesNow - t12) } FI } FI
		} ELSE { nextTutorial() } FI } FI } FI } FI } FI;
	}
}ScratchTutorial;
