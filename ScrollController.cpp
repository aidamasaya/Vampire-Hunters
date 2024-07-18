#include "stdafx.h"
#include "ScrollController.h"

//ƒXƒNƒ[ƒ‹‚³‚¹‚é
void ScrollController::Move() {
	for (auto s : _scrolls) {
		s->Scroll();
	}
}