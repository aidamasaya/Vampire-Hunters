#include "stdafx.h"
#include "ScrollController.h"

//�X�N���[��������
void ScrollController::Move() {
	for (auto s : _scrolls) {
		s->Scroll();
	}
}