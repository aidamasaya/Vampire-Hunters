#include "stdafx.h"
#include "ScrollController.h"

//スクロールさせる
void ScrollController::Move() {
	for (auto s : _scrolls) {
		s->Scroll();
	}
}