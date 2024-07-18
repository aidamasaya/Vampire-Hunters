#pragma once

struct Defence {
	int _def;

	Defence() { _def = 0; }
	virtual ~Defence() {};

	Defence operator + (Defence d) {
		_def += d._def;
		return *this;
	}

	Defence operator += (Defence d) {
		_def += d._def;
		return *this;
	}

	Defence operator -= (Defence d) {
		_def -= d._def;
		return *this;
	}

	Defence operator - (Defence d) {
		_def -= d._def;
		return *this;
	}

	Defence operator * (Defence d) {
		_def *= d._def;
		return *this;
	}
};