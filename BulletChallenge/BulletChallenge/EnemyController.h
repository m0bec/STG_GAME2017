#pragma once
#include "Enemy.h"
#include "GameBaseRule.h"
#include "EnemyMoveEnum.h"
#include "EnemyShotEnum.h"
#include "Player.h"
#include "GameSytem.h"
#include <cmath>
#include <random>
#include <vector>

class EnemyController {
private:
	const int START_CREATE_ENEMY_NUM = 1;
	const int ENEMY_HP = 100;
	const int HIT_SCORE = 10;
	const int KILL_ENEMY_SCORE = 300;
	const double ENEMY_ROTA_SPEED = PI / 10;
	std::random_device rd;	
	Enemy base_enemy;
	int enemy_create_num;
	GameSystem& game_system = GameSystem::GetInstance();
	int enemy_death_num;
	
	struct GR {
		int gr, h, w;
	};
	struct EneBullet {
		int x, y;
		int bullet_num;
		GR gr;
		int speed;
		double rotate;
		int mark;
	};
	EneBullet str_bullet[1000];
	int str_bullet_note;
	EneBullet base_bullet;
	GR blue_bullet_gr;
public:
	EnemyController(){
		std::mt19937 mt(rd());
		SetVar();
	}
	std::vector<Enemy> enemy_array;
	std::vector<EneBullet> enemy_bullet;
	std::vector<EneBullet> sub_str_bullet;
	void BulletGrSet(int const& blue_);
	void SetVar();
	void SetEnemy();
	void SetEnemyGr(int &enemy_gr_) { base_enemy.gr = enemy_gr_; GetGraphSize(enemy_gr_, &base_enemy.width, &base_enemy.hight); }
	void EnemyExe(Ziki& ziki_);
	void SetEnemyBase();
	void EnemyMove(Enemy& enemy_);
	void EnemyHit(Enemy& enemy_, Bullet& bullet_);
	void PlayerHit(Ziki& ziki_);
	void AddKillScore(Enemy& enemy_);
	void OnlyDraw();
	void EnemyDeathNumCheck(int& game_state_ );
	void EnemyDeathNumCount(Enemy& enemy_);
	void EnemyShot(Enemy& enemy_, Ziki& ziki_);
	void EnemyShotMove(Ziki& ziki_);
	void EnemyShotClean();
	void OnlyShotDraw();
};