#pragma once

class FontData {
	int _font;
public:
	FontData(const char* font, int size, int thick) {
		_font = CreateFontToHandle(font, size, thick);
	}
	virtual ~FontData() {};

	int Get_Font() { return _font; }
};