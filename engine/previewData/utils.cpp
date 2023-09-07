var printNumber(var x, var y, var value, var format, var decimalPlaces, var color, int center = 0) {
	var pivotX = 0, pivotY = 0.5, ha = playData::HorizontalAlign.Left;
	if (center > 0) pivotX = 1, ha = playData::HorizontalAlign.Right;
	else if (center == 0) pivotX = 0.5, ha = playData::HorizontalAlign.Center;
	return Print(value, format, decimalPlaces, x, y, pivotX, pivotY, screen.h / 10, screen.h / 20, 0, color, 1, ha, 0);
}

var drawStage(var id) {
	var l = screen.l + id * stageFullWidth + (stageFullWidth - stageWidth) / 2;
	var r = screen.l + (id + 1) * stageFullWidth - (stageFullWidth - stageWidth) / 2;
	var t = stageHeight / 2;
	var b = -1 * stageHeight / 2;
	return Execute({
		Draw(Sprites.Stage, l, b, l, t, r, t, r, b, 1, 1),
		Draw(Sprites.StageBackground, l, b, l, t, r, t, r, b, 0, 0.3)
	});
}

pair<var, var> getPos(var t) {
	var id = Floor(t / stageTimeLength);
	var less = t % stageTimeLength;
	var x = screen.l + id * stageFullWidth + stageFullWidth / 2.0;
	var y = Lerp(-1.0 + noteHeight / 2.0, 1.0 - noteHeight / 2, less / stageTimeLength);
	return {x, y};
}

var drawTime(var t) {
	var x = getPos(t).first, y = getPos(t).second;
	return printNumber(x - stageWidth / 2.0, y, t, PrintFormat.Time, -1, PrintColor.Neutral, 1);
}

var drawNoteCount(var t, var value) {
	var x = getPos(t).first, y = getPos(t).second;
	return printNumber(x + stageWidth / 2.0, y, value, PrintFormat.Number, -1, PrintColor.Neutral, -1);
}

var drawNote(var sprite, var time, var st, var en) {
	var x = getPos(time).first, y = getPos(time).second;
	var len = stageWidth / 12.0;
	var l = x + (st - 7) * len + adjustDistance, r = x + (en - 6) * len - adjustDistance;
	var t = y + noteHeight / 2.0, b = y - noteHeight / 2.0;
	return Draw(sprite, l, b, l, t, r, t, r, b, 3, 1);
}

var drawTick(var sprite, var time, var st, var en) {
	var x = getPos(time).first, cy = getPos(time).second;
	var len = stageWidth / 12.0;
	var cx = x - (6.5 - (st + en) / 2.0) * len;
	var l = cx - tickWidth / 2.0, r = cx + tickWidth / 2.0;
	var t = cy + tickHeight / 2.0, b = cy - tickHeight / 2.0;
	return Draw(sprite, l, b, l, t, r, t, r, b, 3, 1);
}

var drawHold(var sprite, var stt, var ent, var st, var en) {
	var id1 = Floor(stt / stageTimeLength), id2 = Floor(ent / stageTimeLength);
	return Execute({
		FOR (i, id1, id2 + 1, 1) {
			[&](var i){
				var b = IF (stt > i * stageTimeLength) { getPos(stt).second } ELSE { -1 * stageHeight / 2.0 } FI, 
					t = IF (ent < (i + 1) * stageTimeLength) { getPos(ent).second } ELSE { stageHeight / 2.0 } FI;
				var c = getPos(i * stageTimeLength).first, len = stageWidth / 12.0;
				var l = c + (st - 7) * len + adjustDistance, r = c + (en - 6) * len - adjustDistance;
				return Draw(sprite, l, b, l, t, r, t, r, b, 2, 1);
			}(i)
		} DONE
	});
}
