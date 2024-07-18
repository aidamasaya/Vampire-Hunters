#pragma once

struct Power {
	int _power;

	Power() { _power = 0; }
	virtual ~Power() {};

	Power operator + (Power p) {
		_power += p._power;
		return *this;
	}

	Power operator += (Power p) {
		_power += p._power;
		return *this;
	}

	Power operator - (Power p) {
		_power -= p._power;
		return *this;
	}

	Power operator -= (Power p) {
		_power -= p._power;
		return *this;
	}

	Power operator * (Power p) {
		_power *= p._power;
		return *this;
	}
};