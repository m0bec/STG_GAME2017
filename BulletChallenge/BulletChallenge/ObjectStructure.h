#pragma once

struct Bullet {
	int gr;
	int x, y;
	int height, width;
	int move_speed;
	int move_var;
	double move_angle;
};

struct Enemy {
	Enemy() {

	}
	int hight, width;
	int x, y;
	int gr;
	int shot_var;
	int move_var;
};