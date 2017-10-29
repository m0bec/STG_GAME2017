#include "EnemyController.h"

void EnemyController::SetVar() {
	enemy_create_num = START_CREATE_ENEMY_NUM;
	enemy_death_num = 0;
	enemy_create_num = START_CREATE_ENEMY_NUM;
}

void EnemyController::BulletGrSet(int const& blue_) {
	blue_bullet_gr.gr = blue_;
	GetGraphSize(blue_bullet_gr.gr, &blue_bullet_gr.w, &blue_bullet_gr.h);
}

void EnemyController::SetEnemyBase() {
	std::uniform_int_distribution<int> randx(DISP_AREA_MIN_X + 50, DISP_AREA_ENEMY_MAX_X - 50);
	std::uniform_int_distribution<int> randy(DISP_AREA_MIN_Y + 50, DIPS_AREA_ENEMY_MAX_Y);
	std::uniform_int_distribution<int> rand_speed(2, 5);
	base_enemy.Sethp(ENEMY_HP);
	base_enemy.SetPos(randx(rd), randy(rd));
	base_enemy.SetMoveVar(1);
	base_enemy.bullet_num = 0;
	base_enemy.rota = 0.0;
	base_enemy.timer = 0;
	base_enemy.bullet_rota = 0;
	base_enemy.bullet_speed = rand_speed(rd);//rand
	base_enemy.start_time = 0;//rand
	base_enemy.SetShotVar(EnemyShotEnum::LeftTurn);//rand
	base_enemy.add_score = false;
}

void EnemyController::SetEnemy() {
	int num_ = 0;
	for (Enemy &t_ : enemy_array) {
		if (num_ < enemy_create_num) {
			SetEnemyBase();
			t_ = base_enemy;
			++num_;
		}
		else { break; }
	}
	for (int i = 0; i < enemy_create_num - num_; i++) {
		SetEnemyBase();
		enemy_array.push_back(base_enemy);
	}
	++enemy_create_num;
}

void EnemyController::EnemyExe(Ziki& ziki_) {
	enemy_death_num = 0;
	str_bullet_note = 0;
	for (Enemy &enemy_ : enemy_array) {
		EnemyMove(enemy_);
		AddKillScore(enemy_);
		EnemyDeathNumCount(enemy_);
		EnemyShot(enemy_, ziki_);
	}
}

void EnemyController::EnemyDeathNumCheck(int& game_state_) {
	if (enemy_death_num == enemy_create_num - 1)	game_state_ = StateInGame::NextStage;
}

void EnemyController::EnemyDeathNumCount(Enemy& enemy_) {
	if (enemy_.GetMoveVar() == EnemyMoveEnum::Death)	++enemy_death_num;
}

void EnemyController::EnemyHit(Enemy& enemy_, Bullet& bullet_) {
	if (enemy_.Gethp() > 0) {
		if (abs(bullet_.x + bullet_.width / 2 - (enemy_.x + enemy_.width / 2)) <= bullet_.width / 2 + enemy_.width / 2 + 10
			&& abs(bullet_.y + bullet_.height / 2 - (enemy_.y + enemy_.hight / 2)) <= bullet_.height / 2 + enemy_.hight / 2 + 10) {
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
				ziki_.invalid = true;
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

void EnemyController::OnlyDraw() {
	for (Enemy enemy_ : enemy_array) {
		if(enemy_.GetMoveVar() != EnemyMoveEnum::Death)
			DrawRotaGraph(enemy_.x, enemy_.y, 1.0, enemy_.rota, enemy_.gr, TRUE, FALSE);
	}
}

void EnemyController::EnemyShotClean() {
	for (EneBullet& b_ : enemy_bullet) {
		b_.bullet_num = EnemyShotEnum::Non;
	}
}

void EnemyController::OnlyShotDraw() {
	for (EneBullet& b_ : enemy_bullet) {
		DrawGraph(b_.x, b_.y, b_.gr.gr, TRUE);
	}
}