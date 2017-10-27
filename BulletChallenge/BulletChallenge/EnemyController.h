#pragma once
#include "Enemy.h"
#include "GameBaseRule.h"
#include <random>
#include <vector>

class EnemyController {
private:
	const int ENEMY_HP = 100;
	std::random_device rd;
	std::vector<Enemy> enemy_array;
	Enemy base_enemy;
	int enemy_create_num;

public:
	EnemyController(){
		std::mt19937 mt(rd());
		enemy_create_num = 1;
	}
	void SetEnemy();
	void EnemyExe();
	void EnemyMove(Enemy& enemy_);
	void EnemyHit();
};