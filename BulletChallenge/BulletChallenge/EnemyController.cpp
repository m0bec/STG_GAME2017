#include "EnemyController.h"

void EnemyController::SetEnemy() {
	int num_ = 0;
	for (Enemy &t_ : enemy_array) {
		if (num_ < enemy_create_num) {
			t_.Sethp(ENEMY_HP);
		}
		else { break; }
	}
	for (int i = 0; i < num_; i++) {
		std::uniform_int_distribution<int> randx(DISP_AREA_MIN_X, DISP_AREA_ENEMY_MAX_X);
		std::uniform_int_distribution<int> randy(DISP_AREA_MIN_Y, DIPS_AREA_ENEMY_MAX_Y);
		base_enemy.SetGr(ENEMY_HP);
		base_enemy.SetPos(randx(rd), randy(rd));
		enemy_array.push_back(base_enemy);
	}
}

void EnemyController::EnemyMove(Enemy& enemy_) {
	DrawGraph(enemy_.x, enemy_.y, enemy_.gr, TRUE);
}