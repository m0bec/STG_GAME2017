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
		invalid = false;
	}
	int height, width;
	int x, y;
	double rota;
	int gr;
	int avoid_num;
	int hp;
	bool invalid;
};

class Player {
private:
	const int MOVE_SPEED = 5;
	const double ROTA_SPEED = PI / 90;
	const double BULLET_RADI = PI / 10;
	const int BULLET_COUNTER_MAX = 3;
	const int BULLET_SPEED = 15;
	const int NO_BULLET = -1;
	Bullet sample_bullet;
	int bullet_count;

public:
	Player(){
		SetVar();
	}
	void SetVar();
	Ziki ziki;
	Bullet bullet[100];
	void Exe();
	void Move();
	void SetPlayerData(int const& gr_, int const& player_bullet_);
	void BulletMove();
	void OnltDraw();
};