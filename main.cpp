#include <Novice.h>
#include "Enemy.h"
#include "Player.h"

const char kWindowTitle[] = "LC1B_06_オノ_ケンジピエール_タイトル";

bool Enemy::isAlive_;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Enemy* enemy[2];
	for (int i = 0; i < 2; i++) {
		enemy[i] = new Enemy({ 620,25 }, 10, 20, true);
		enemy[i]->pos_.x += (250 * i);
		enemy[i]->pos_.y += ((enemy[i]->radius_ * 2) + 250) * i;
	}

	Player* player = new Player({ 640,680 }, 5, 30);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Move(keys);
		for (int j = 0; j < 10; j++) {
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				if (!player->bullet_[j]->isShot_) {
					player->bullet_[j]->isShot_ = true;
					player->bullet_[j]->pos_.x = player->pos_.x;
					player->bullet_[j]->pos_.y = player->pos_.y;
					break;
				}
			}
			if (player->bullet_[j]->isShot_) {
				player->bullet_[j]->Move();
				if (player->bullet_[j]->pos_.y + player->bullet_[j]->radius_ < 0) {
					player->bullet_[j]->isShot_ = false;
				}
			}
		}

		for (int i = 0; i < 2; i++) {
			if (!enemy[i]->isAlive_) {
				if (keys[DIK_R] && preKeys[DIK_R] == 0) {
					enemy[i]->isAlive_ = true;
				}
			}
			enemy[i]->Move();
			for (int j = 0; j < 10; j++) {
				enemy[i]->Collision(player->bullet_[j]->pos_, player->bullet_[j]->radius_);
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		for (int j = 0; j < 10; j++) {
			player->bullet_[j]->Draw();
		}

		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
		}

		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemy[0]->isAlive_);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemy[1]->isAlive_);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
