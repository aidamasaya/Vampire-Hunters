#pragma once

//プレイヤーの詳細な動きを実装するためのインターフェイス
class IPlayerState {
public:
	virtual void Start(std::shared_ptr<IGameObject>) {};
	virtual void Update() {};
	virtual void Draw() {};
};