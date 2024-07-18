#pragma once

struct Level {
	const int MAX_LEVEL = 99;
	int _level;
public:
	Level() { _level = 1; }
	Level(int level) {
		if (level > MAX_LEVEL) return;
		_level = level;
	}
	virtual ~Level() {};

	Level Get_Level() { return _level; }

	void Add_Level() {
		_level++;
	}
};