#pragma once
#include "DxLib.h"
#include "EnemyMoveEnum.h"
#include "ObjectStructure.h"

class Enemy {
private:
	int shot_var;
	int move_var;
	int hp;

public:
	Enemy(){}
	int gr;
	int x, y;
	int hight, width;
	double rota;
	bool add_score;
	int timer;
	int start_time;
	int bullet_num;
	int bullet_speed;
	double bullet_rota;

	void SetShotVar(int const& shot_var_);
	int  GetShotVar() { return shot_var; }
	void SetMoveVar(int const& shot_var_);
	void SetGr(int const& gr_);
	void SetPos(int const& x_, int const& y_);
	void Sethp(int const& hp_) { hp = hp_; }
	int Gethp() { return hp; }
	int GetMoveVar() { return move_var; }
	void Damage();
};