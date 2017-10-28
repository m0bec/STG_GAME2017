#pragma once
#include "DxLib.h"
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

	void SetShotVar(int const& shot_var_);
	void SetMoveVar(int const& shot_var_);
	void SetGr(int const& gr_);
	void SetPos(int const& x_, int const& y_);
	void Sethp(int const& hp_) { hp = hp_; }	int Gethp() { return hp; }
	void Damage() {}
};