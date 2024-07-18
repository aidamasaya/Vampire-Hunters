#pragma once

struct Exp {
	int _exp;

	Exp() { _exp = 0; }
	virtual ~Exp() {};

	Exp operator + (Exp exp) {
		_exp += exp._exp;
		return *this;
	}

	Exp operator += (Exp exp) {
		_exp += exp._exp;
		return *this;
	}

	Exp operator - (Exp exp) {
		_exp -= exp._exp;
		return *this;
	}

	Exp operator -= (Exp exp) {
		_exp -= exp._exp;
		return *this;
	}

	Exp operator * (float f) {
		_exp *= f;
		return *this;
	}
};