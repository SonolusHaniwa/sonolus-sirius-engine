pair<var, var> getPos(var t) {
	var id = Floor(t / stageTimeLength);
	var less = t % stageTimeLength;
	var x = screen.l + id * stageFullWidth + stageFullWidth / 2.0;
	var y = Lerp(-1.0 + noteHeight / 2.0, 1.0 - noteHeight / 2, less / stageTimeLength);
	return { x, y };
}

SonolusApi printNumber(var x, var y, var value, var format, var decimalPlaces, var color, int center = 0) {
	var pivotX = 0, pivotY = 0.5, ha = HorizontalAlign.Left;
	if (center > 0) pivotX = 1, ha = HorizontalAlign.Right;
	else if (center == 0) pivotX = 0.5, ha = HorizontalAlign.Center;
	Print(value, format, decimalPlaces, x, y, pivotX, pivotY, screen.h / 10, screen.h / 20, 0, color, 1, ha, 0);
}

SonolusApi drawStage(var id) {
	var l = screen.l + id * stageFullWidth + (stageFullWidth - stageWidth) / 2;
	var r = screen.l + (id + 1) * stageFullWidth - (stageFullWidth - stageWidth) / 2;
	var t = stageHeight / 2;
	var b = -1 * stageHeight / 2;
	Draw(Sprites.Stage, { l, b }, { l, t }, { r, t }, { r, b }, 1, 1);
	Draw(Sprites.StageBackground, { l, b }, { l, t }, { r, t }, { r, b }, 0, 0.3);
}

SonolusApi drawTime(var t) {
	var x = getPos(t).first, y = getPos(t).second;
	printNumber(x - stageWidth / 2.0, y, t, PrintFormat.Time, -1, PrintColor.Neutral, 1);
}

SonolusApi drawNoteCount(var t, var value) {
	var x = getPos(t).first, y = getPos(t).second;
	printNumber(x + stageWidth / 2.0, y, value, PrintFormat.Number, -1, PrintColor.Neutral, -1);
}

SonolusApi drawHiSpeed(var t, var value) {
	var x = getPos(t).first, y = getPos(t).second;
	printNumber(x + stageWidth / 2.0, y, value, PrintFormat.TimeScale, -1, PrintColor.Yellow, -1);
}

SonolusApi drawLine(var sprite, var t) {
	var cx = getPos(t).first, cy = getPos(t).second;
	var dx = stageWidth / 2.0, dy = lineHeight / 2.0;
	Draw(sprite, { cx - dx, cy - dy }, { cx - dx, cy + dy }, { cx + dx, cy + dy }, { cx + dx, cy - dy }, 10, 0.8);
}

SonolusApi drawNormalNote_fallback(var sprite, var time, var st, var en) {
	var x = getPos(time).first, y = getPos(time).second;
	var len = stageWidth / 12.0;
	var l = x + (st - 7) * len + adjustDistance, r = x + (en - 6) * len - adjustDistance;
	var t = y + noteHeight / 2.0, b = y - noteHeight / 2.0;
	Draw(sprite, { l, b }, { l, t }, { r, t }, { r, b }, 4, 1);
}

SonolusApi drawNormalNote(var sprite, var time, var st, var en) {
	if (!HasSkinSprite(sprite)) {
		drawNormalNote_fallback(sprite - 1, time, st, en);
        return;
	}
	var x = getPos(time).first, y = getPos(time).second;
	var len = stageWidth / 12.0;
	var l = x + (st - 7) * len + adjustDistance, r = x + (en - 6) * len - adjustDistance;
	var t = y + noteHeight / 2.0, b = y - noteHeight / 2.0;
    var border_len = stageFullWidth * noteBorderPercent;
	Draw(sprite, { l, b }, { l, t }, { l + border_len, t }, { l + border_len, b }, 4, 1);
    Draw(sprite + 1, { l + border_len, b }, { l + border_len, t }, { r - border_len, t }, { r - border_len, b }, 4, 1);
    Draw(sprite + 2, { r - border_len, b }, { r - border_len, t }, { r, t }, { r, b }, 4, 1);
}

SonolusApi drawArrow(var time, var st, var en) {
	var cx = getPos(time).first, b = getPos(time).second;
	var len = stageWidth / 12.0, w = arrowWidth;
	var l = cx - (7 - st) * len + adjustDistance, r = cx - (6 - en) * len - adjustDistance;
	var t = b + arrowHeight, num = (r - l) / 2 * arrowPercent / arrowWidth;
    for (var i = 1; i < num; i++) {
        Draw(
        	Sprites.ScratchArrow, 
        	{ l + (i - 1) * w / 2, b }, 
        	{ l + (i - 1) * w / 2, t }, 
            { l + (i + 1) * w / 2, t }, 
            { l + (i + 1) * w / 2, b }, 
            1000, 
            1
        );
        Draw(
        	Sprites.ScratchArrow, 
        	{ r - (i - 1) * w / 2, b }, 
        	{ r - (i - 1) * w / 2, t }, 
            { r - (i + 1) * w / 2, t }, 
            { r - (i + 1) * w / 2, b }, 
            1000, 
            1
        );
    }
}

SonolusApi drawLeftArrow(var time, var st, var en) {
	var cx = getPos(time).first, b = getPos(time).second;
	var len = stageWidth / 12.0, w = arrowWidth;
	var l = cx - (7 - st) * len + adjustDistance, r = cx - (6 - en) * len - adjustDistance;
	var t = b + arrowHeight, num = (r - l) * arrowPercent / arrowWidth;
    for (var i = 1; i < num; i++) {
        Draw(
        	Sprites.ScratchArrow, 
        	{ l + (i - 1) * w / 2, b }, 
        	{ l + (i - 1) * w / 2, t }, 
            { l + (i + 1) * w / 2, t }, 
            { l + (i + 1) * w / 2, b }, 
            1000, 
            1
        );
    }
}

SonolusApi drawRightArrow(var time, var st, var en) {
	var cx = getPos(time).first, b = getPos(time).second;
	var len = stageWidth / 12.0, w = arrowWidth;
	var l = cx - (7 - st) * len + adjustDistance, r = cx - (6 - en) * len - adjustDistance;
	var t = b + arrowHeight, num = (r - l) * arrowPercent / arrowWidth;
    for (var i = 1; i < num; i++) {
        Draw(
        	Sprites.ScratchArrow, 
        	{ r - (i - 1) * w / 2, b }, 
        	{ r - (i - 1) * w / 2, t }, 
            { r - (i + 1) * w / 2, t }, 
            { r - (i + 1) * w / 2, b }, 
            1000, 
            1
        );
    }
}

SonolusApi drawHoldEighth(var sprite, var stt, var ent, var st, var en) {
	var id1 = Floor(stt / stageTimeLength), id2 = Floor(ent / stageTimeLength);
	for (var i = id1; i <= id2; i++) {
		var b = If(stt > i * stageTimeLength, getPos(stt).second, -1 * stageHeight / 2.0),
			t = If(ent < (i + 1) * stageTimeLength, getPos(ent).second, stageHeight / 2.0);
		var c = getPos(i * stageTimeLength).first, len = stageWidth / 12.0;
		var l = c + (st - 7) * len + adjustDistance, r = c + (en - 6) * len - adjustDistance;
		Draw(sprite, { l, b }, { l, t }, { r, t }, { r, b }, 2, 1);
	}
}

SonolusApi drawTick(var sprite, var time, var st, var en) {
	var x = getPos(time).first, cy = getPos(time).second;
	var len = stageWidth / 12.0;
	var cx = x - (6.5 - (st + en) / 2.0) * len;
	var l = cx - tickWidth / 2.0, r = cx + tickWidth / 2.0;
	var t = cy + tickHeight / 2.0, b = cy - tickHeight / 2.0;
	Draw(sprite, { l, b }, { l, t }, { r, t }, { r, b }, 4, 1);
}

SonolusApi drawSyncLine(var time, var st, var en) {
	var cx = getPos(time).first, y = getPos(time).second;
	var len = stageWidth / 12.0;
	var l = cx - (6.5 - st) * len, r = cx - (6.5 - en) * len;
	var t = y + syncLineHeight / 2.0, b = y - syncLineHeight / 2.0;
	Draw(Sprites.SyncLine, { l, b }, { l, t }, { r, t }, { r, b }, 3, 1);
}

SonolusApi drawLine(var id, var st, var en, var sprite) {
	var id1 = Floor(st / stageTimeLength), id2 = Floor(en / stageTimeLength);
    for (var i = id1; i <= id2; i++) {
		var width = adjustDistance * 2;
		var b = If(st > i * stageTimeLength, getPos(st).second, -1 * stageHeight / 2.0), 
			t = If(en < (i + 1) * stageTimeLength, getPos(en).second, stageHeight / 2.0);
		var c = getPos(i * stageTimeLength).first - (6 - id) * stageWidth / 12.0;
		var l = c - width, r = c + width;
		Draw(sprite, { l, b }, { l, t }, { r, t }, { r, b }, 10000 + EntityData[0], 1);
	}
}

SonolusApi drawSplitLine(var st, var en, var extra, var split) {
    drawLine(0, st, en, splitLineMemory[0] + extra);
    drawLine(12, st, en, splitLineMemory[split] + extra);
    switch(split) {
        case 2: {
            drawLine(6, st, en, splitLineMemory[1] + extra);
        } break;
        case 3: {
            drawLine(4, st, en, splitLineMemory[1] + extra); 
            drawLine(8, st, en, splitLineMemory[2] + extra);
        } break;
        case 4: {
            drawLine(3, st, en, splitLineMemory[1] + extra); 
            drawLine(6, st, en, splitLineMemory[2] + extra); 
            drawLine(9, st, en, splitLineMemory[3] + extra);
        } break;
        case 5: {
            drawLine(3, st, en, splitLineMemory[1] + extra); 
            drawLine(5, st, en, splitLineMemory[2] + extra); 
            drawLine(7, st, en, splitLineMemory[3] + extra); 
            drawLine(9, st, en, splitLineMemory[4] + extra);
        } break;
        case 6: {
            drawLine(2, st, en, splitLineMemory[1] + extra); 
            drawLine(4, st, en, splitLineMemory[2] + extra); 
            drawLine(6, st, en, splitLineMemory[3] + extra); 
            drawLine(8, st, en, splitLineMemory[4] + extra);
            drawLine(10, st, en, splitLineMemory[5] + extra);
        } break;
    }
}

SonolusApi setSplitLine(vector<var> lines) {
    for (CppLoop int i = 0; i < 16; i++)
        splitLineMemory[i] = lines[i % lines.size()];
}