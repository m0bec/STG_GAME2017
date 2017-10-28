#pragma once
#include "DxLib.h"
#include "ObjectStructure.h"
#include "GameBaseRule.h"
const double PI = 3.141592;

struct Ziki {
	Ziki() {
		avoid_num = 2;
		hp = 2;
		rota = 0.0;
		x = 400 - width / 2;
		y = 700 + height / 2;
	}
	int height, width;
	int x, y;
	double rota;
	int gr;
	int avoid_num;
	int hp;
};

class Player {
private:
	const int MOVE_SPEED = 5;
	const double ROTA_SPEED = PI / 90;
	Ziki ziki;
	const double BULLET_RADI = PI / 10;
	const int BULLET_COUNTER_MAX = 3;
	const int BULLET_SPEED = 15;
	const int NO_BULLET = -1;
	Bullet sample_bullet;
	int bullet_count;

public:
	Player(){
		ziki.avoid_num = 2;
		ziki.hp = 2;
		ziki.rota = 0.0;
		sample_bullet.move_var = 0;
		sample_bullet.move_speed = BULLET_SPEED;
		sample_bullet.move_angle = 0.0;
		for (Bullet &t_ : bullet)	t_.move_var = NO_BULLET;
		bullet_count = 0;
	}
	Bullet bullet[100];
	void Exe();
	void Move();
	void SetPlayerData(int const& gr_, int const& player_bullet_);
	void BulletMove();
};