#include "EnemyController.h"

void EnemyController::EnemyShot(Enemy& enemy_) {
	if (enemy_.GetMoveVar() != EnemyMoveEnum::Death) {
		if (enemy_.start_time > 0) {
			--enemy_.start_time;
		}
		else {
			++enemy_.timer;
		}

		if (str_bullet_note >= 1000) {
			for (int i = 0; i < 1000; i++) {
				sub_str_bullet.push_back(str_bullet[i]);
				str_bullet[i].bullet_num = EnemyShotEnum::Non;
			}
			str_bullet_note = 0;
		}

		switch (enemy_.GetShotVar()) {
		case EnemyShotEnum::Straight:
			if (enemy_.timer > 30) {
				++enemy_.bullet_num;
				if (enemy_.bullet_num > 10) {
					enemy_.bullet_num = 0;
					enemy_.timer = 0;
				}
				else {
					base_bullet.bullet_num = enemy_.GetShotVar();
					base_bullet.gr = blue_bullet_gr;
					base_bullet.x = enemy_.x - base_bullet.gr.w / 2;
					base_bullet.y = enemy_.y - base_bullet.gr.h / 2;
					std::uniform_int_distribution<int> rand_speed(2, 5);
					base_bullet.speed = rand_speed(rd);
					str_bullet[str_bullet_note] = base_bullet;
					++str_bullet_note;
					enemy_.timer -= 5;
				}
			}
			break;
		}
	}
}