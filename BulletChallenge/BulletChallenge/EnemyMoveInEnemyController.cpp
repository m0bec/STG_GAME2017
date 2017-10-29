#include "EnemyController.h"

void EnemyController::EnemyMove(Enemy& enemy_) {
	switch (enemy_.GetMoveVar()) {
	case EnemyMoveEnum::StraightSide:
		break;
	}
	if (enemy_.GetMoveVar() != EnemyMoveEnum::Death) {
		DrawRotaGraph(enemy_.x, enemy_.y, 1.0, enemy_.rota, enemy_.gr, TRUE, FALSE);
		enemy_.rota += PI / 7;
		if (enemy_.rota > 2 * PI)	enemy_.rota -= 2 * PI;
	}
}