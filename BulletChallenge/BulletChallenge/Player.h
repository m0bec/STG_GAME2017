#pragma once
#include "DxLib.h"
#include "ObjectStructure.h"
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
	const int MOVE_SPEED = 4;
	Ziki ziki;
public:
	Player(){
		ziki.avoid_num = 2;
		ziki.hp = 2;
		ziki.rota = 0.0;
	}

	void Exe();
	void Move();
	void SetPlayerData(int const& gr_);
};