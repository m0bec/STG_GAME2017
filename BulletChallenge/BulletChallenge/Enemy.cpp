#include "Enemy.h"

void Enemy::SetShotVar(int const& shot_var_) {
	shot_var = shot_var_;
}

void Enemy::SetMoveVar(int const& move_var_) {
	move_var = move_var_;
}

void Enemy::SetGr(int const& gr_) {
	gr = gr_;
	GetGraphSize(gr, &width, &hight);
}

void Enemy::SetPos(int const& x_, int const& y_) {
	x = x_;
	y = y_;
}

void Enemy::Damage() {
	--hp;
	if (hp <= 0) {
		move_var = EnemyMoveEnum::Death;
	}
}