#pragma once

struct Health {
	float _health;

	Health() : _health(0) {};
	virtual ~Health() {};


	Health operator + (Health health) {
		_health += health._health;
		return *this;
	}

	Health operator += (Health health) {
		_health += health._health;
		return *this;
	}

	Health operator - (Health health) {
		_health -= health._health;
		return *this;
	}

	Health operator -= (Health health) {
		_health -= health._health;
		return *this;
	}

	Health operator * (Health health) {
		_health *= health._health;
		return *this;
	}
};