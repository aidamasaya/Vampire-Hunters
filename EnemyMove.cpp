#include "stdafx.h"
#include "EnemyMove.h"
#include "EnemyData.h"
#include "keyboard.h"

using namespace std;

/// <summary>
/// コンストラクタで500体の敵をインスタンス化し、エネミープールで管理
/// </summary>
/// <param name="player">敵のアクティブ時に参照を渡す</param>
/// <param name="manager">敵のアクティブ時に参照を渡す</param>
EnemyMove::EnemyMove(std::shared_ptr<IGameObject> player, std::shared_ptr<ItemManager> manager) {
	_player = player;
	_manager = manager;
	enemy_Pool = std::make_shared<EnemyPool>();
	enemy_Pool->Enemy_Create(500);

	//死神はプール管理外なのでここで初期化と参照渡しで非アクティブ化
	_reaper = std::make_shared<Reaper>();
	_reaper->Start(3);
	_reaper->Set_Player(player);
	_reaper->Set_ItemManager(manager);
	_reaper->Transform.Position = Random_SetPos();

	_flag = true;
}

/// <summary>
/// アクティブな敵の処理
/// </summary>
void EnemyMove::Run() {
	if (enemy_Pool->Count() > 0) {
		if (_flag == true) {
			enemy_Pool->Update();
		}
		enemy_Pool->Draw();
	}
	if (_reaper->Get_Flag() == true) {
		_reaper->Update();
		_reaper->Draw();
	}
}

//アクティブな敵を全て非アクティブ化
void EnemyMove::Clean() {
	auto enemy = enemy_Pool->Get_Pool();
	for (auto e : enemy) {
		if (e->Get_Flag() == true) {
			e->Release();
		}
	}
}

//死神でゲームを強制終了
void EnemyMove::Death() {
	_reaper->Set_Flag(true);
}

/// <summary>
/// プールから敵をアクティブにし、初期化処理を行う
/// </summary>
/// <param name="id">敵のID</param>
/// <param name="num">生成する個数</param>
void EnemyMove::SetUp_Enemy(int id, int num) {
	for (int i = 0; i < num; i++) {
		auto e = enemy_Pool->Recycle();
		if (e != nullptr) {
			e->Start(id);
			e->Set_Player(_player);
			e->Set_ItemManager(_manager);
			e->Transform.Position = Random_SetPos();
		}
	}
}

Vector2 EnemyMove::Random_SetPos() {
	std::random_device seed_gen;
	std::mt19937 mt(seed_gen());

	return Vector2((float)(280 + mt() % Define::WIN_W), (float)(350 - (int)mt() % Define::WIN_H));
}

//疑似的なスクロール
void EnemyMove::Scroll() {
	if (_flag == false) return;
	auto enemy = enemy_Pool->Get_Pool();
	for (auto e : enemy) {
		if (Keyboard::getPressingCount(KEY_INPUT_LEFT) > 0) {
			e->Transform.Position.X += 2;
		}if (Keyboard::getPressingCount(KEY_INPUT_RIGHT) > 0) {
			e->Transform.Position.X -= 2;
		}if (Keyboard::getPressingCount(KEY_INPUT_DOWN) > 0) {
			e->Transform.Position.Y -= 2;
		}if (Keyboard::getPressingCount(KEY_INPUT_UP) > 0) {
			e->Transform.Position.Y += 2;
		}
	}
}