SonolusApi setSplitLine(vector<int> lines) {
	FUNCBEGIN
	for (int i = 0; i < 16; i++) splitLineMemory.set(i, lines[i % lines.size()]);
	return VOID;
}
