#pragma once
#include "Enemy.h"
#include "GameBaseRule.h"
#include "EnemyMoveEnum.h"
#include "Player.h"
#include <random>
#include <vector>

class EnemyController {
private:
	const int ENEMY_HP = 100;
	std::random_device rd;	
	Enemy base_enemy;
	int enemy_create_num;

public:
	EnemyController(){
		std::mt19937 mt(rd());
		enemy_create_num = 10;
	}
	std::vector<Enemy> enemy_array;
	void SetEnemy();
	void SetEnemyGr(int &enemy_gr_) { base_enemy.gr = enemy_gr_; GetGraphSize(enemy_gr_, &base_enemy.width, &base_enemy.hight); }
	void EnemyExe();
	void EnemyMove(Enemy& enemy_);
	void EnemyHit(Enemy& enemy_, Bullet& bullet_);
	void PlayerHit(Ziki& ziki_);
};