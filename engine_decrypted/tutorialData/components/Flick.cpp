class FlickTutorial {
	public:

	var Froze(var t) {
		var p = t / tutorialFrozeTime;
		var l1 = -0.5, r1 = 0.5, b1 = -0.05, t1 = 0.25;
		var l2 = -0.5, r2 = 0.5, b2 = 0.075, t2 = b2 + 0.45;
		var H = t2 - b2, W = H / 2.5, L = l2, R = r2;
		var num = (R - L) / 2 * arrowPercent / W;
		return {
			IF (p < 0.80) {
				Draw(Sprites.ScratchNote, l1, b1, l1, t1, r1, t1, r1, b1, 1000, 1),
				FOR (i, 1, num, 1) {
					Draw(Sprites.ScratchArrow, L + (i - 1) * W / 2, b2, L + (i - 1) * W / 2, t2,
						L + (i + 1) * W / 2, t2, L + (i + 1) * W / 2, b2, 1001, 1),
					Draw(Sprites.ScratchArrow, R - (i - 1) * W / 2, b2, R - (i - 1) * W / 2, t2,
						R - (i + 1) * W / 2, t2, R - (i + 1) * W / 2, b2, 1001, 1)
				} DONE
			} ELSE {
				Draw(Sprites.ScratchNote, l1, b1, l1, t1, r1, t1, r1, b1, 1000, (1 - p) * 5),
				FOR (i, 1, num, 1) {
					Draw(Sprites.ScratchArrow, L + (i - 1) * W / 2, b2, L + (i - 1) * W / 2, t2,
						L + (i + 1) * W / 2, t2, L + (i + 1) * W / 2, b2, 1001, (1 - p) * 5),
					Draw(Sprites.ScratchArrow, R - (i - 1) * W / 2, b2, R - (i - 1) * W / 2, t2,
						R - (i + 1) * W / 2, t2, R - (i + 1) * W / 2, b2, 1001, (1 - p) * 5)
				} DONE
			} FI
		};
	}

	var Fall(var t) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.ScratchNote, 5, 8, p - 1),
			drawArrow(5, 8, p - 1)
		};
	}

	var Click(var t) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.ScratchNote),
			drawNormalNote(Sprites.ScratchNote, 5, 8, 0),
			drawArrow(5, 8, 0),
			IF (Ceil(p * 4) % 2 == 1) {
				drawFrozenHand(5, 8, p * 400 % 100, true, false)
			} ELSE {
				drawUpperHand(5, 8, p * 400 % 100, handEndAngle)
			} FI
		};
	}

	var Disappear(var t) {
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
		return {
			IF (timesNow - t0 < splitLineAnimationStart) {
				IF (timesNow - t0 > 0) {
					drawAppearLine(timesNow - t0, 3)
				} FI
			} ELSE {
				IF (timesNow - t3 > 0) {
					IF (timesNow - t3 < splitLineAnimationEnd) { 
						drawDisappearLine(timesNow - t3, 3) 
					} FI
				} ELSE {
					drawSplitLine(3)
				} FI
			} FI,
			IF (timesNow < t0) { Froze(timesNow) } 
			ELSE { IF (timesNow < t4) {
				IF (timesNow < t2) { Fall(timesNow - t0) } 
				ELSE { IF (timesNow < t3) { Click(timesNow - t2) }
				ELSE { Disappear(timesNow - t3) } FI } FI
			} ELSE { nextTutorial() } FI } FI
		};
	}
}FlickTutorial;
