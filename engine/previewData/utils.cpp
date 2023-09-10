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
	return Draw(sprite, l, b, l, t, r, t, r, b, 4, 1);
}

var drawTick(var sprite, var time, var st, var en) {
	var x = getPos(time).first, cy = getPos(time).second;
	var len = stageWidth / 12.0;
	var cx = x - (6.5 - (st + en) / 2.0) * len;
	var l = cx - tickWidth / 2.0, r = cx + tickWidth / 2.0;
	var t = cy + tickHeight / 2.0, b = cy - tickHeight / 2.0;
	return Draw(sprite, l, b, l, t, r, t, r, b, 4, 1);
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

var drawSyncLine(var time, var st, var en) {
	var cx = getPos(time).first, y = getPos(time).second;
	var len = stageWidth / 12.0;
	var l = cx - (6.5 - st) * len, r = cx - (6.5 - en) * len;
	var t = y + syncLineHeight / 2.0, b = y - syncLineHeight / 2.0;
	return Draw(Sprites.SyncLine, l, b, l, t, r, t, r, b, 3, 1);
}

var drawArrow(var time, var st, var en) {
	var cx = getPos(time).first, b = getPos(time).second;
	var len = stageWidth / 12.0, w = arrowWidth;
	var l = cx - (7 - st) * len + adjustDistance, r = cx - (6 - en) * len - adjustDistance;
	var t = b + arrowHeight, num = (r - l) / 2 * arrowPercent / arrowWidth;
	return Execute({
		FOR (i, 1, num, 1) {
			Draw(Sprites.ScratchArrow, l + (i - 1) * w / 2, b, l + (i - 1) * w / 2, t, l + (i + 1) * w / 2, t, l + (i + 1) * w / 2, b, 1000, 1),
			Draw(Sprites.ScratchArrow, r - (i - 1) * w / 2, b, r - (i - 1) * w / 2, t, r - (i + 1) * w / 2, t, r - (i + 1) * w / 2, b, 1000, 1)
		} DONE
	});
}

var drawLeftArrow(var time, var st, var en) {
	var cx = getPos(time).first, b = getPos(time).second;
	var len = stageWidth / 12.0, w = arrowWidth;
	var l = cx - (7 - st) * len + adjustDistance, r = cx - (6 - en) * len - adjustDistance;
	var t = b + arrowHeight, num = (r - l) * arrowPercent / arrowWidth;
	return Execute({
		FOR (i, 1, num, 1) {
			Draw(Sprites.ScratchArrow, l + (i - 1) * w / 2, b, l + (i - 1) * w / 2, t, l + (i + 1) * w / 2, t, l + (i + 1) * w / 2, b, 1000, 1)
		} DONE
	});
}

var drawRightArrow(var time, var st, var en) {
	var cx = getPos(time).first, b = getPos(time).second;
	var len = stageWidth / 12.0, w = arrowWidth;
	var l = cx - (7 - st) * len + adjustDistance, r = cx - (6 - en) * len - adjustDistance;
	var t = b + arrowHeight, num = (r - l) * arrowPercent / arrowWidth;
	return Execute({
		FOR (i, 1, num, 1) {
			Draw(Sprites.ScratchArrow, r - (i - 1) * w / 2, b, r - (i - 1) * w / 2, t, r - (i + 1) * w / 2, t, r - (i + 1) * w / 2, b, 1000, 1)
		} DONE
	});
}

var drawLine(var id, var st, var en, var sprite) {
	var id1 = Floor(st / stageTimeLength), id2 = Floor(en / stageTimeLength);
	return Execute({
		FOR (i, id1, id2 + 1, 1) {
			[&](var i){
				var width = adjustDistance * 2;
				var b = IF (st > i * stageTimeLength) { getPos(st).second } ELSE { -1 * stageHeight / 2.0 } FI, 
					t = IF (en < (i + 1) * stageTimeLength) { getPos(en).second } ELSE { stageHeight / 2.0 } FI;
				var c = getPos(i * stageTimeLength).first - (6 - id) * stageWidth / 12.0;
				var l = c - width, r = c + width;
				return Draw(sprite, l, b, l, t, r, t, r, b, 1000, 1);
			}(i)
		} DONE
	});
}

var drawSplitLine(var st, var en, var extra, var split) {
	return Execute({
        drawLine(0, st, en, splitLineMemory[0] + extra),
        drawLine(12, st, en, splitLineMemory[split] + extra),
        Switch(split, {
            {1, {}},
            {2, drawLine(6, st, en, splitLineMemory[1] + extra)},
            {3, {
                drawLine(4, st, en, splitLineMemory[1] + extra), 
                drawLine(8, st, en, splitLineMemory[2] + extra)
            }}, {4, {
                drawLine(3, st, en, splitLineMemory[1] + extra), 
                drawLine(6, st, en, splitLineMemory[2] + extra), 
                drawLine(9, st, en, splitLineMemory[3] + extra)
            }}, {5, {
                drawLine(3, st, en, splitLineMemory[1] + extra), 
                drawLine(5, st, en, splitLineMemory[2] + extra), 
                drawLine(7, st, en, splitLineMemory[3] + extra), 
                drawLine(9, st, en, splitLineMemory[4] + extra)
            }}, {6, {
                drawLine(2, st, en, splitLineMemory[1] + extra), 
                drawLine(4, st, en, splitLineMemory[2] + extra), 
                drawLine(6, st, en, splitLineMemory[3] + extra), 
                drawLine(8, st, en, splitLineMemory[4] + extra), 
                drawLine(10, st, en, splitLineMemory[5] + extra)
			}}
        })
    });
}

var setSplitLine(vector<var> lines) {
    var res = Execute({
        splitLineMemory.clear()
    });
    for (int i = 0; i < 16; i++) {
        res.args.push_back(splitLineMemory.add(lines[i % lines.size()]));
    } return res;
}

var getSplitLine(var id) {
    return Switch(id, {
        {1, setSplitLine({Sprites.SplitLine_1})},
        {2, setSplitLine({Sprites.SplitLine_2})},
        {3, setSplitLine({Sprites.SplitLine_3})},
        {4, setSplitLine({Sprites.SplitLine_4})},
        {5, setSplitLine({Sprites.SplitLine_5})},
        {6, setSplitLine({Sprites.SplitLine_6})},
        {7, setSplitLine({Sprites.SplitLine_7})},
        {8, setSplitLine({Sprites.SplitLine_8})},
        {9, setSplitLine({Sprites.SplitLine_9})},
        {1010, setSplitLine({Sprites.SplitLine_1010})},
        {1020, setSplitLine({Sprites.SplitLine_1020})},
        {1030, setSplitLine({Sprites.SplitLine_1030})},
        {1040, setSplitLine({Sprites.SplitLine_1040})},
        {1050, setSplitLine({Sprites.SplitLine_1050})},
        {1060, setSplitLine({Sprites.SplitLine_1060a, Sprites.SplitLine_1060b})},
        {2010, setSplitLine({Sprites.SplitLine_2010})},
        {2020, setSplitLine({Sprites.SplitLine_2020})},
        {2030, setSplitLine({Sprites.SplitLine_2030})},
        {2040, setSplitLine({Sprites.SplitLine_2040a, Sprites.SplitLine_2040b})},
        {2050, setSplitLine({Sprites.SplitLine_2050})},
        {3010, setSplitLine({Sprites.SplitLine_3010})},
        {3020, setSplitLine({Sprites.SplitLine_3020})},
        {3030, setSplitLine({Sprites.SplitLine_3030})},
        {3040, setSplitLine({Sprites.SplitLine_3040})},
        {3050, setSplitLine({Sprites.SplitLine_3050})},
        {4010, setSplitLine({Sprites.SplitLine_4010})},
        {4020, setSplitLine({Sprites.SplitLine_4020})},
        {4030, setSplitLine({Sprites.SplitLine_4030})},
        {4040, setSplitLine({Sprites.SplitLine_4040})},
        {4050, setSplitLine({Sprites.SplitLine_4050})},
        {10010, setSplitLine({Sprites.SplitLine_10010})},
        {10020, setSplitLine({Sprites.SplitLine_10020})},
        {10030, setSplitLine({Sprites.SplitLine_10030})},
        {10040, setSplitLine({Sprites.SplitLine_10040})},
        {10050, setSplitLine({Sprites.SplitLine_10050})},
        {10060, setSplitLine({Sprites.SplitLine_10060})},
        {10070, setSplitLine({Sprites.SplitLine_10070})},
        {10100, setSplitLine({Sprites.SplitLine_10100})},
        {10110, setSplitLine({Sprites.SplitLine_10110})},
        {10120, setSplitLine({Sprites.SplitLine_10120})},
        {10130, setSplitLine({Sprites.SplitLine_10130})},
        {10140, setSplitLine({Sprites.SplitLine_10140})},
        {10150, setSplitLine({Sprites.SplitLine_10150})},
        {10160, setSplitLine({Sprites.SplitLine_10160})},
        {10161, setSplitLine({Sprites.SplitLine_10161})},
        {10162, setSplitLine({Sprites.SplitLine_10162})},
        {10170, setSplitLine({Sprites.SplitLine_10170})},
        {10180, setSplitLine({Sprites.SplitLine_10180})},
        {10190, setSplitLine({Sprites.SplitLine_10190})},
        {10191, setSplitLine({Sprites.SplitLine_10191})},
        {10200, setSplitLine({Sprites.SplitLine_10200})},
        {10220, setSplitLine({Sprites.SplitLine_10220})},
        {10230, setSplitLine({Sprites.SplitLine_10230})},
        {10240, setSplitLine({Sprites.SplitLine_10240})},
        {10250, setSplitLine({Sprites.SplitLine_10250})},
        {10260, setSplitLine({Sprites.SplitLine_10260})},
        {10320, setSplitLine({Sprites.SplitLine_10320})},
        {10321, setSplitLine({Sprites.SplitLine_10321_1, Sprites.SplitLine_10321_2, Sprites.SplitLine_10321_3, Sprites.SplitLine_10321_4, Sprites.SplitLine_10321_5})},
        {10322, setSplitLine({Sprites.SplitLine_10322_1, Sprites.SplitLine_10322_2, Sprites.SplitLine_10322_3, Sprites.SplitLine_10322_4, Sprites.SplitLine_10322_5})},
        {10323, setSplitLine({Sprites.SplitLine_10323_1, Sprites.SplitLine_10323_2, Sprites.SplitLine_10323_3, Sprites.SplitLine_10323_4, Sprites.SplitLine_10323_5})},
        {10324, setSplitLine({Sprites.SplitLine_10324_1, Sprites.SplitLine_10324_2, Sprites.SplitLine_10324_3})},
        {10325, setSplitLine({Sprites.SplitLine_10325_1, Sprites.SplitLine_10325_2, Sprites.SplitLine_10325_3, Sprites.SplitLine_10325_4})},
        {10326, setSplitLine({Sprites.SplitLine_10326_1, Sprites.SplitLine_10326_2, Sprites.SplitLine_10326_3, Sprites.SplitLine_10326_4, Sprites.SplitLine_10326_5})},
        {10327, setSplitLine({Sprites.SplitLine_10327_1, Sprites.SplitLine_10327_2, Sprites.SplitLine_10327_3, Sprites.SplitLine_10327_4})},
        {10328, setSplitLine({Sprites.SplitLine_10328_1, Sprites.SplitLine_10328_2, Sprites.SplitLine_10328_3, Sprites.SplitLine_10328_4, Sprites.SplitLine_10328_5})},
        {10340, setSplitLine({Sprites.SplitLine_10340})},
        {10350, setSplitLine({Sprites.SplitLine_10350})},
        {10360, setSplitLine({Sprites.SplitLine_10360})},
        {10361, setSplitLine({Sprites.SplitLine_10361})},
        {10390, setSplitLine({Sprites.SplitLine_10390})},
        {10391, setSplitLine({Sprites.SplitLine_10391})},
        {10392, setSplitLine({Sprites.SplitLine_10392})},
        {10393, setSplitLine({Sprites.SplitLine_10393})},
    });
}