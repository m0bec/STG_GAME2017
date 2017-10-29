#pragma once
#include "Enemy.h"
#include "GameBaseRule.h"
#include "EnemyMoveEnum.h"
#include "Player.h"
#include "GameSytem.h"
#include <random>
#include <vector>

class EnemyController {
private:
	const int START_CREATE_ENEMY_NUM = 10;
	const int ENEMY_HP = 100;
	const int HIT_SCORE = 10;
	const int KILL_ENEMY_SCORE = 300;
	std::random_device rd;	
	Enemy base_enemy;
	int enemy_create_num;
	GameSystem& game_system = GameSystem::GetInstance();
	int enemy_death_num;

public:
	EnemyController(){
		std::mt19937 mt(rd());
		SetVar();
	}
	std::vector<Enemy> enemy_array;
	void SetVar();
	void SetEnemy();
	void SetEnemyGr(int &enemy_gr_) { base_enemy.gr = enemy_gr_; GetGraphSize(enemy_gr_, &base_enemy.width, &base_enemy.hight); }
	void EnemyExe();
	void EnemyMove(Enemy& enemy_);
	void EnemyHit(Enemy& enemy_, Bullet& bullet_);
	void PlayerHit(Ziki& ziki_);
	void AddKillScore(Enemy& enemy_);
	void OnlyDraw();
	void EnemyDeathNumCheck(int& game_state_ );
	void EnemyDeathNumCount(Enemy& enemy_);
};