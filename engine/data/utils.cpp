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

var spawnLineEffect(var lane, var enLane) {
	var wt = lines[lane].getFullWidth(0), wb = lines[lane].getFullWidth(1);
	Vec lb = lines[lane].getFullPosition(1) + Vec(-1 * wb / 2.0, 0), rb = lines[enLane].getFullPosition(1) + Vec(wb / 2.0, 0);
	Vec lt = lines[lane].getFullPosition(0) + Vec(-1 * wt / 2.0, 0), rt = lines[enLane].getFullPosition(0) + Vec(wt / 2.0, 0);
	return SpawnParticleEffect(Effects.Lane, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, effectDurationTime, 0);
}

var spawnEffect(var linear, var circular, var lane, var enLane) {
	var w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec lb = c1 + Vec(-1 * w / 2, 0), lt = c1 + Vec(-1 * w / 2, effectLinearHeight);
	Vec rb = c2 + Vec(w / 2, 0), rt = c2 + Vec(w / 2, effectLinearHeight);
	Vec lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	Vec rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	return Execute({
		SpawnParticleEffect(linear, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, effectDurationTime, 0),
		SpawnParticleEffect(circular, lb2.x, lb2.y, lt2.x, lt2.y, rt2.x, rt2.y, rb2.x, rb2.y, effectDurationTime, 0),
		spawnLineEffect(lane, enLane)
	});
}

var spawnHoldEffect(var effect, var lane, var enLane) {
	var w = lines[lane].getWidth(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c1 = lines[lane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec c2 = lines[enLane].getPosition(1 + (effectCircularHeight + effectDistance) / 2 / stage.h);
	Vec lb2 = c1 + Vec(-1 * w / 2, 0), lt2 = c1 + Vec(-1 * w / 2, effectCircularHeight);
	Vec rb2 = c2 + Vec(w / 2, 0), rt2 = c2 + Vec(w / 2, effectCircularHeight);
	return Execute({
		SpawnParticleEffect(effect, lb2.x, lb2.y, lt2.x, lt2.y, rt2.x, rt2.y, rb2.x, rb2.y, effectDurationTime, 1),
	});
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

var drawLeftArrow(var lane, var enLane, var beat) {
    var w = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1));
    Vec c2 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1));
    var W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    var L = c1.x - w / 2, R = c2.x + w / 2;
    var num = w * (enLane - lane + 1) * arrowPercent / W;
    return Execute({
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, L + (i - 1) * W / 2, c1.y, L + (i - 1) * W / 2, c1.y + H / 2, 
                L + (i + 1) * W / 2, c1.y + H / 2, L + (i + 1) * W / 2, c1.y, 1001 - beat, 1 - 0.8 * Mod({i + times.now * arrowSpeed * 2, num}) / num)
        } DONE,
    });
}

var drawRightArrow(var lane, var enLane, var beat) {
    var w = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1));
    Vec c2 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1));
    var W = arrowWidth * multiplier, H = arrowHeight * multiplier;
    var L = c1.x - w / 2, R = c2.x + w / 2;
    var num = w * (enLane - lane + 1) * arrowPercent / W;
    return Execute({
        FOR (i, 1, num, 1) {
            Draw(Sprites.ScratchArrow, R - (i - 1) * W / 2, c2.y, R - (i - 1) * W / 2, c2.y + H / 2, 
                R - (i + 1) * W / 2, c2.y + H / 2, R - (i + 1) * W / 2, c2.y, 1001 - beat, 1 - 0.8 * Mod({i + times.now * arrowSpeed * 2, num}) / num)
        } DONE
    });
}

var JudgeNote(var t, var beat) {
    return Execute({
        EntityInput.set(1, t - beat),
		EntityInput.set(3, t - beat),
        Switch(JudgeSimple(t, beat, judgment.perfect, judgment.great, judgment.good), {
            {1, Execute({
                EntityInput.set(0, 1),
                Play(Clips.Perfect, minSFXDistance)
            })}, {2, Execute({
                EntityInput.set(0, 2),
                Play(Clips.Perfect, minSFXDistance)
            })}, {3, Execute({
                EntityInput.set(0, 3),
				Play(Clips.Good, minSFXDistance)
            })}, {0, Execute({
                EntityInput.set(0, 0),
            })}
        })
    });
}

var JudgeNoteMuted(var t, var beat) {
	return Execute({
		EntityInput.set(1, t - beat),
		EntityInput.set(3, t - beat),
		EntityInput.set(0, (JudgeSimple(t, beat, judgment.perfect, judgment.great, judgment.good)))
	});
}

var JudgeFlickNote(var t, var beat) {
	return Execute({
		EntityInput.set(1, t - beat),
		EntityInput.set(3, t - beat),
		Switch(JudgeSimple(t, beat, judgment.perfect, judgment.good, judgment.good), {
			{1, Execute({
				EntityInput.set(0, 1),
				Play(Clips.Scratch, minSFXDistance)
			})}, {2, Execute({
				EntityInput.set(0, 2),
				Play(Clips.Scratch, minSFXDistance)
			})}, {3, Execute({
				EntityInput.set(0, 3),
				Play(Clips.Good, minSFXDistance)
			})}, {0, Execute({
				EntityInput.set(0, 0)
			})}
		})
	});
}

var JudgeCriticalNote(var t, var beat) {
	return Execute({
		EntityInput.set(1, t - beat),
		EntityInput.set(3, t - beat),
		Switch(JudgeSimple(t, beat, judgment.perfect, judgment.great, judgment.good), {
			{1, Execute({
				EntityInput.set(0, 1),
				Play(Clips.CriticalPerfect, minSFXDistance)
			})}, {2, Execute({
				EntityInput.set(0, 2),
				Play(Clips.CriticalPerfect, minSFXDistance)
			})}, {3, Execute({
				EntityInput.set(0, 3),
				Play(Clips.Good, minSFXDistance)
			})}, {0, Execute({
				EntityInput.set(0, 0)
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

var drawTick(var sprite, var beat, var lane, var enLane) {
    var w = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) - tickHeight / 2 / stage.h * multiplier);
    Vec c2 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) + tickHeight / 2 / stage.h * multiplier);
    Vec c3 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) - tickHeight / 2 / stage.h * multiplier);
    Vec c4 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) + tickHeight / 2 / stage.h * multiplier);
    var m1 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) - tickHeight / 2 / stage.h * multiplier) / lines[lane].getWidth(1);
    var m2 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) + tickHeight / 2 / stage.h * multiplier) / lines[lane].getWidth(1);
	Vec cb = Vec((c2.x + c4.x) / 2, (c2.y + c4.y) / 2), ct = Vec((c1.x + c3.x) / 2, (c1.y + c3.y) / 2);
	Vec lb = cb + Vec(-1 * m2 * tickWidth / 2, 0), lt = ct + Vec(-1 * m1 * tickWidth / 2, 0);
	Vec rb = cb + Vec(m2 * tickWidth / 2, 0), rt = ct + Vec(m1 * tickWidth / 2, 0);
	return Draw(sprite, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 1000 - beat, 0.5);
}

var drawSyncLine(var beat, var lane, var enLane) {
    var w = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1));
    var multiplier = w / lines[lane].getWidth(1);
    Vec c1 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) - syncLineHeight / 2 / stage.h * multiplier);
    Vec c2 = lines[lane].getPosition(ease((times.now - beat) / appearTime + 1) + syncLineHeight / 2 / stage.h * multiplier);
    Vec c3 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) - syncLineHeight / 2 / stage.h * multiplier);
    Vec c4 = lines[enLane].getPosition(ease((times.now - beat) / appearTime + 1) + syncLineHeight / 2 / stage.h * multiplier);
    var w1 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) - syncLineHeight / 2 / stage.h * multiplier);
    var w2 = lines[lane].getWidth(ease((times.now - beat) / appearTime + 1) + syncLineHeight / 2 / stage.h * multiplier);
    Vec lb = c2 + Vec(-1 * w2 / 2 + noteMoveLength, 0), lt = c1 + Vec(-1 * w1 / 2 + noteMoveLength, 0);
    Vec rb = c4 + Vec(1 * w2 / 2 - noteMoveLength, 0), rt = c3 + Vec(w1 / 2 - noteMoveLength, 0);
    return Draw(Sprites.SyncLine, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 5, 0.8);
}

// 上面为 0，下面为 1
var drawLine(var id, var st, var en, var a = 1) {
    Vec c1 = lines[id + 1].getFullPosition(ease(st));
    Vec c2 = lines[id + 1].getFullPosition(ease(en));
	var w1 = lines[id + 1].getFullWidth(ease(st));
	var w2 = lines[id + 1].getFullWidth(ease(en));
	Vec c3 = c1 + Vec(-1 * w1 / 2 - noteMoveLength, 0);
	Vec c4 = c2 + Vec(-1 * w2 / 2 - noteMoveLength, 0);
	Vec lb = c4 + Vec(-1 * noteMoveLength, 0), lt = c3 + Vec(-1 * noteMoveLength, 0);
	Vec rb = c4 + Vec(noteMoveLength, 0), rt = c3 + Vec(noteMoveLength, 0);
	return Draw(Sprites.SyncLine, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 10000, a * LevelOption.get(Options.SplitLine));
}

var drawEndLine(var st, var en, var a = 1) {
    Vec c1 = lines[12].getFullPosition(ease(st));
    Vec c2 = lines[12].getFullPosition(ease(en));
	var w1 = lines[12].getFullWidth(ease(st));
	var w2 = lines[12].getFullWidth(ease(en));
	Vec c3 = c1 + Vec(1 * w1 / 2 + noteMoveLength, 0);
	Vec c4 = c2 + Vec(1 * w2 / 2 + noteMoveLength, 0);
	Vec lb = c4 + Vec(-1 * noteMoveLength, 0), lt = c3 + Vec(-1 * noteMoveLength, 0);
	Vec rb = c4 + Vec(noteMoveLength, 0), rt = c3 + Vec(noteMoveLength, 0);
	return Draw(Sprites.SyncLine, lb.x, lb.y, lt.x, lt.y, rt.x, rt.y, rb.x, rb.y, 10000, a * LevelOption.get(Options.SplitLine));
}

var drawSplitLine(var split) {
	return Execute({
        drawLine(0, 0, 1),
        drawEndLine(0, 1),
        Switch(split, {
            {1, {}},
            {2, drawLine(6, 0, 1)},
            {3, {drawLine(4, 0, 1), drawLine(8, 0, 1)}},
            {4, {drawLine(3, 0, 1), drawLine(6, 0, 1), drawLine(9, 0, 1)}},
            {5, {drawLine(3, 0, 1), drawLine(5, 0, 1), drawLine(7, 0, 1), drawLine(9, 0, 1)}},
            {6, {drawLine(2, 0, 1), drawLine(4, 0, 1), drawLine(6, 0, 1), drawLine(8, 0, 1), drawLine(10, 0, 1)}}
        })
    });
}

var drawDisappearLine(var t, var split) {
    var p = 1;
    var a = 1 - t / 0.2;
	return Execute({
        drawLine(0, 0, p, a),
        drawEndLine(0, p, a),
        Switch(split, {
            {1, {}},
            {2, drawLine(6, 0, p, a)},
            {3, {drawLine(4, 0, p, a), drawLine(8, 0, p, a)}},
            {4, {drawLine(3, 0, p, a), drawLine(6, 0, p, a), drawLine(9, 0, p, a)}},
            {5, {drawLine(3, 0, p, a), drawLine(5, 0, p, a), drawLine(7, 0, p, a), drawLine(9, 0, p, a)}},
            {6, {drawLine(2, 0, p, a), drawLine(4, 0, p, a), drawLine(6, 0, p, a), drawLine(8, 0, p, a), drawLine(10, 0, p, a)}}
        })
    });
}

var drawAppearLine(var t, var split) {
    var p = 1 - t / splitLineDumpLength;
    var a = 1;
	return Execute({
        drawLine(0, p, 1, a),
        drawEndLine(p, 1, a),
        Switch(split, {
            {1, {}},
            {2, drawLine(6, p, 1, a)},
            {3, {drawLine(4, p, 1, a), drawLine(8, p, 1, a)}},
            {4, {drawLine(3, p, 1, a), drawLine(6, p, 1, a), drawLine(9, p, 1, a)}},
            {5, {drawLine(3, p, 1, a), drawLine(5, p, 1, a), drawLine(7, p, 1, a), drawLine(9, p, 1, a)}},
            {6, {drawLine(2, p, 1, a), drawLine(4, p, 1, a), drawLine(6, p, 1, a), drawLine(8, p, 1, a), drawLine(10, p, 1, a)}}
        })
    });
}
