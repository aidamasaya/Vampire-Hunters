#pragma once

struct Coin {
	int _coin;

	Coin() { _coin = 0; }
	virtual ~Coin() {};

	Coin operator + (Coin c) {
		_coin += c._coin;
		return *this;
	}

	Coin operator += (Coin c) {
		_coin += c._coin;
		return *this;
	}

	Coin operator - (Coin c) {
		_coin -= c._coin;
		return *this;
	}

	Coin operator -= (Coin c) {
		_coin -= c._coin;
		return *this;
	}

	Coin operator * (Coin c) {
		_coin *= c._coin;
		return *this;
	}
};