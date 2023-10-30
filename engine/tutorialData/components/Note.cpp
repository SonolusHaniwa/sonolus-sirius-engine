class NoteTutorial {
	public:

	var Froze(var t) {
		var p = t / tutorialFrozeTime;
		var l1 = -0.5, r1 = 0.5, b1 = 0.3, t1 = 0.7;
		var l2 = -0.5, r2 = 0.5, b2 = -0.3, t2 = 0.1;
		return {
			IF (p < 0.80) {
				Draw(Sprites.NormalNote, l1, b1, l1, t1, r1, t1, r1, b1, 1e8, 1),
				Draw(Sprites.CriticalNote, l2, b2, l2, t2, r2, t2, r2, b2, 1e8, 1)
			} ELSE {
				Draw(Sprites.NormalNote, l1, b1, l1, t1, r1, t1, r1, b1, 1e8, (1 - p) * 5),
				Draw(Sprites.CriticalNote, l2, b2, l2, t2, r2, t2, r2, b2, 1e8, (1 - p) * 5)
			} FI
		};
	}

	var NormalFall(var t) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.NormalNote, 5, 8, p - 1)
		};
	}

	var NormalClick(var t) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.NormalNote),
			drawNormalNote(Sprites.NormalNote, 5, 8, 0),
			drawFrozenHand(5, 8, p * 400 % 100)
		};
	}

	var NormalDisappear(var t) {
		return {
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				spawnEffect(Effects.NormalLinear, Effects.NormalCircular, 5, 8),
				Play(Clips.Perfect, minSFXDistance),
				spawnedEffect.set(1)
			} FI
		};
	}

	var CriticalFall(var t) {
		var p = t / tutorialFallTime;
		return {
			spawnedEffect.set(0),
			drawNormalNote(Sprites.CriticalNote, 5, 8, p - 1)
		};
	}

	var CriticalClick(var t) {
		var p = t / tutorialClickTime;
		return {
			instruction.set(Texts.CriticalNote),
			drawNormalNote(Sprites.CriticalNote, 5, 8, 0),
			drawFrozenHand(5, 8, p * 400 % 100)
		};
	}

	var CriticalDisappear(var t) {
		return {
			IF (spawnedEffect.get() == 0) {
				instruction.set(-1),
				spawnEffect(Effects.CriticalLinear, Effects.CriticalCircular, 5, 8),
				Play(Clips.CriticalPerfect, minSFXDistance),
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
		return IF (timesNow < t0) { Froze(timesNow) } 
		ELSE { IF (timesNow < t4) {
			IF (timesNow < t2) { NormalFall(timesNow - t0) } 
			ELSE { IF (timesNow < t3) { NormalClick(timesNow - t2) }
			ELSE { NormalDisappear(timesNow - t3) } FI } FI
		} ELSE { IF (timesNow < t7) {
			IF ( timesNow < t5 ) { CriticalFall(timesNow - t4) }
			ELSE { IF (timesNow < t6) { CriticalClick(timesNow - t5) }
			ELSE { CriticalDisappear(timesNow - t6) } FI } FI
		} ELSE { nextTutorial() } FI } FI } FI;
	}
}NoteTutorial;
