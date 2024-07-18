#pragma once

//スクロールを実装するためのクラス
class IScroll {
public:
	IScroll() {};
	virtual ~IScroll() {};
	virtual void Scroll() {};
};