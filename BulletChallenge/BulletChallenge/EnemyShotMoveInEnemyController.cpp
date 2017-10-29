#include "EnemyController.h"

void EnemyController::EnemyShotMove(Ziki& ziki_) {
	int count_ = 0;
	for (EneBullet& b_ : enemy_bullet) {
		if (b_.bullet_num == EnemyShotEnum::Non) {
			if (str_bullet_note > count_) {
				b_ = str_bullet[count_];
				++count_;
			}
		}
		else {
			switch (b_.bullet_num) {
			case EnemyShotEnum::Straight:
				b_.y += b_.speed;
				break;
			}
			DrawGraph(b_.x, b_.y, b_.gr.gr, TRUE);
			if (b_.y + b_.gr.h / 2 <= DISP_AREA_MIN_Y || b_.x + b_.gr.w >= DISP_AREA_MAX_X ||
				b_.y - b_.gr.h / 2 >= DISP_AREA_MAX_Y || b_.x - b_.gr.w + 10 <= DISP_AREA_MIN_X)	b_.bullet_num = EnemyShotEnum::Non;
		}
	}
	if (str_bullet_note > count_) {
		for (int i = count_; i < str_bullet_note; i++) {
			enemy_bullet.push_back(str_bullet[i]);
			DrawGraph(str_bullet[i].x, str_bullet[i].y, str_bullet[i].gr.gr, TRUE);
		}
	}
}