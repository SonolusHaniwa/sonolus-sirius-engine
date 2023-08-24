var drawNormalNote(var sprite, var lane, var enLane, var beat) {
    var w = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) - noteHeight / 2 / stage.h * multiplier);
    Vec c2 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) + noteHeight / 2 / stage.h * multiplier);
    Vec c3 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) - noteHeight / 2 / stage.h * multiplier);
    Vec c4 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) + noteHeight / 2 / stage.h * multiplier);
    var w1 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) - noteHeight / 2 / stage.h * multiplier);
    var w2 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) + noteHeight / 2 / stage.h * multiplier);
    Vec lb = c2 + Vec(-1 * w2 / 2 + noteMoveLength, 0), lt = c1 + Vec(-1 * w1 / 2 + noteMoveLength, 0);
    Vec rb = c4 + Vec(1 * w2 / 2 - noteMoveLength, 0), rt = c3 + Vec(w1 / 2 - noteMoveLength, 0);
    return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 1000 - beat, 1);
}

var drawArrow(var lane, var enLane, var beat) {
    var w = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1));
    Vec c2 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1));
    var W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    var L = c1.x - w / 2, R = c2.x + w / 2;
    var num = w * (enLane - lane + 1) / 2 * arrowPercent / W;
    return Execute({
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, L + (i - 1) * W / 2, c1.y, L + (i - 1) * W / 2, c1.y + H / 2, 
                L + (i + 1) * W / 2, c1.y + H / 2, L + (i + 1) * W / 2, c1.y, 1001 - beat, 1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num)
        } DONE, 
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, R - (i - 1) * W / 2, c2.y, R - (i - 1) * W / 2, c2.y + H / 2, 
                R - (i + 1) * W / 2, c2.y + H / 2, R - (i + 1) * W / 2, c2.y, 1001 - beat, 1 - 0.8 * Mod({i + times.now * arrowSpeed, num}) / num)
        } DONE
    });
}

var JudgeNote(var t, var beat) {
    return Execute({
        EntityInput.set(1, t - beat),
        Switch(JudgeSimple(t, beat, judgment.perfect, judgment.great, judgment.good), {
            {1, Execute({
                EntityInput.set(0, 1),
                Play(Clips.Perfect, minSFXDistance)
            })}, {2, Execute({
                EntityInput.set(0, 2),
                Play(Clips.Perfect, minSFXDistance)
            })}, {3, Execute({
                EntityInput.set(0, 3),
            })}, {0, Execute({
                EntityInput.set(0, 0),
                Play(Clips.Great, minSFXDistance)
            })}
        })
    });
}

var JudgeNoteMuted(var t, var beat) {
	return Execute({
		EntityInput.set(1, t - beat),
		EntityInput.set(0, (JudgeSimple(t, beat, judgment.perfect, judgment.great, judgment.good)))
	});
}

var JudgeFlickNote(var t, var beat) {
	return Execute({
		EntityInput.set(1, t - beat),
		Switch(JudgeSimple(t, beat, judgment.perfect, judgment.good, judgment.good), {
			{1, Execute({
				EntityInput.set(0, 1),
				Play(Clips.HoldStart, minSFXDistance)
			})}, {2, Execute({
				EntityInput.set(0, 2),
				Play(Clips.HoldStart, minSFXDistance)
			})}, {3, Execute({
				EntityInput.set(0, 3),
			})}, {0, Execute({
				EntityInput.set(0, 0),
				Play(Clips.Miss, minSFXDistance)
			})}
		})
	});
}

var JudgeCriticalNote(var t, var beat) {
	return Execute({
		EntityInput.set(1, t - beat),
		Switch(JudgeSimple(t, beat, judgment.perfect, judgment.great, judgment.good), {
			{1, Execute({
				EntityInput.set(0, 1),
				Play(Clips.Scratch, minSFXDistance)
			})}, {2, Execute({
				EntityInput.set(0, 2),
				Play(Clips.Scratch, minSFXDistance)
			})}, {3, Execute({
				EntityInput.set(0, 3),
			})}, {0, Execute({
				EntityInput.set(0, 0),
				Play(Clips.Miss, minSFXDistance)
			})}
		})
	});
}

var movedLast(Touch touch) {
    return Abs(touch.dx) >= 0.001 && Abs(touch.dy) >= 0.001;
}

var drawHoldEighth(var sprite, var lane, var enLane, var stBeat, var enBeat) {
	Vec c1 = lines[lane].getPosition(ease(Min(1, (times.now - stBeat) / appearTime + 1)));
	Vec c2 = lines[lane].getPosition(ease((Min(1, times.now - enBeat) / appearTime + 1)));
	Vec c3 = lines[enLane].getPosition(ease(Min(1, (times.now - stBeat) / appearTime + 1)));
	Vec c4 = lines[enLane].getPosition(ease(Min(1, (times.now - enBeat) / appearTime + 1)));
	var w1 = lines[lane].getWidth(ease(Min(1, (times.now - stBeat) / appearTime + 1)));
	var w2 = lines[lane].getWidth(ease(Min(1, (times.now - enBeat) / appearTime + 1)));
	Vec lb = c1 + Vec(-1 * w1 / 2 + noteMoveLength, 0), lt = c2 + Vec(-1 * w2 / 2 + noteMoveLength, 0);
	Vec rb = c3 + Vec(w1 / 2 - noteMoveLength, 0), rt = c4 + Vec(w2 / 2 - noteMoveLength, 0);
	return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 4, 0.8);
}
