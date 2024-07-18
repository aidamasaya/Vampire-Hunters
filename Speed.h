#pragma once

struct Speed {
	int _speed;

	Speed() { _speed = 0; }
	virtual ~Speed() {};

	Speed operator + (Speed s) {
		_speed += s._speed;
		return *this;
	}

	Speed operator += (Speed s) {
		_speed += s._speed;
		return *this;
	}

	Speed operator - (Speed s) {
		_speed -= s._speed;
		return *this;
	}

	Speed operator -= (Speed s) {
		_speed -= s._speed;
		return *this;
	}

	Speed operator * (Speed s) {
		_speed *= s._speed;
		return *this;
	}
};