#pragma once

//ポーズインターフェイスを継承してポーズ処理を実装する
class IPause {
public:
	IPause() {};
	virtual ~IPause() {};

	virtual void Stop_All() = 0; //ポーズ
	virtual void Move_All() = 0; //ポーズ解除
};