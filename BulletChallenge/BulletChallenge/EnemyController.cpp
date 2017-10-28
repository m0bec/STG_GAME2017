#include "EnemyController.h"
#include <thread>
void EnemyController::SetEnemy() {
	int num_ = 0;
	for (Enemy &t_ : enemy_array) {
		if (num_ < enemy_create_num) {
			std::uniform_int_distribution<int> randx(DISP_AREA_MIN_X, DISP_AREA_ENEMY_MAX_X);
			std::uniform_int_distribution<int> randy(DISP_AREA_MIN_Y, DIPS_AREA_ENEMY_MAX_Y);
			base_enemy.Sethp(ENEMY_HP);
			base_enemy.SetPos(randx(rd), randy(rd));
			base_enemy.SetMoveVar(1);
			base_enemy.add_score = false;
			t_ = base_enemy;
			++num_;
		}
		else { break; }
	}
	for (int i = 0; i < enemy_create_num - num_; i++) {
		std::uniform_int_distribution<int> randx(DISP_AREA_MIN_X, DISP_AREA_ENEMY_MAX_X);
		std::uniform_int_distribution<int> randy(DISP_AREA_MIN_Y, DIPS_AREA_ENEMY_MAX_Y);
		base_enemy.Sethp(ENEMY_HP);
		base_enemy.SetPos(randx(rd), randy(rd));
		base_enemy.SetMoveVar(1);
		base_enemy.add_score = false;
		enemy_array.push_back(base_enemy);
	}
	++enemy_create_num;
}

void EnemyController::EnemyExe() {
	for (Enemy &enemy_ : enemy_array) {
		EnemyMove(enemy_);
		AddKillScore(enemy_);
	}
}

void EnemyController::EnemyMove(Enemy& enemy_) {
	if (enemy_.GetMoveVar() != EnemyMoveEnum::Death) {
		DrawGraph(enemy_.x, enemy_.y, enemy_.gr, TRUE);
	}
}

void EnemyController::EnemyHit(Enemy& enemy_, Bullet& bullet_) {
	if (enemy_.Gethp() > 0) {
		if (bullet_.x <= enemy_.x + enemy_.width && bullet_.x + bullet_.width >= enemy_.x
			&& bullet_.y <= enemy_.y + enemy_.hight && bullet_.y + bullet_.height >= enemy_.y) {
			enemy_.Damage();
			bullet_.x = -1000;
			bullet_.y = -1000;
			game_system.ScoreAdd(HIT_SCORE);
		}
	}
}

void EnemyController::PlayerHit(Ziki& ziki_) {
	if (!ziki_.invalid) {
		for (Enemy& enemy_ : enemy_array){
			if (ziki_.x <= enemy_.x + enemy_.width && ziki_.x + ziki_.width >= enemy_.x
			&& ziki_.y <= enemy_.y + enemy_.hight && ziki_.y + ziki_.height >= enemy_.y
				&& enemy_.GetMoveVar() != EnemyMoveEnum::Death) {
				enemy_.Sethp(-1);
				enemy_.SetMoveVar(EnemyMoveEnum::Death);
				--ziki_.hp;
			}
		}
	}
}

void EnemyController::AddKillScore(Enemy& enemy_) {
	if (!enemy_.add_score && enemy_.Gethp() <= 0) {
		game_system.ScoreAdd(KILL_ENEMY_SCORE);
		enemy_.add_score = true;
	}
}