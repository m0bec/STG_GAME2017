#include "EnemyController.h"

void EnemyController::EnemyShot(Enemy& enemy_, Ziki& ziki_) {
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
			if (enemy_.timer > 50) {
				base_bullet.bullet_num = enemy_.GetShotVar();
				base_bullet.gr = blue_bullet_gr;
				base_bullet.x = enemy_.x - base_bullet.gr.w / 2;
				base_bullet.y = enemy_.y - base_bullet.gr.h / 2;
				base_bullet.speed = enemy_.bullet_speed;
				str_bullet[str_bullet_note] = base_bullet;
				++str_bullet_note;
				enemy_.timer = 0;
			}
			break;

		case EnemyShotEnum::Target:
			if (enemy_.timer > 40) {
				base_bullet.bullet_num = enemy_.GetShotVar();
				base_bullet.gr = blue_bullet_gr;
				base_bullet.x = enemy_.x - base_bullet.gr.w / 2;
				base_bullet.y = enemy_.y - base_bullet.gr.h / 2;
				base_bullet.speed = enemy_.bullet_speed;
				base_bullet.rotate = atan2(ziki_.y - base_bullet.y, ziki_.x - base_bullet.x);
				str_bullet[str_bullet_note] = base_bullet;
				++str_bullet_note;
				enemy_.timer = 0;
			}
			break;

		case EnemyShotEnum::AvoidTwo:
			if (enemy_.timer > 100) {
				if (enemy_.bullet_num < 4) {
					enemy_.timer -= 3;
					++enemy_.bullet_num;
				}
				else {
					enemy_.timer = 0;
					enemy_.bullet_num = 0;
				}
				base_bullet.bullet_num = enemy_.GetShotVar();
				base_bullet.gr = blue_bullet_gr;
				base_bullet.x = enemy_.x - base_bullet.gr.w / 2;
				base_bullet.y = enemy_.y - base_bullet.gr.h / 2;
				base_bullet.speed = enemy_.bullet_speed;
				base_bullet.rotate = atan2(ziki_.y - base_bullet.y, ziki_.x - base_bullet.x);
				base_bullet.mark = 1;
				str_bullet[str_bullet_note] = base_bullet;
				++str_bullet_note;
				base_bullet.mark = 2;
				str_bullet[str_bullet_note] = base_bullet;
				++str_bullet_note;
			}
			break;
		}
	}
}