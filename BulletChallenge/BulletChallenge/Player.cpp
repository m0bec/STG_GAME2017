#include "Player.h"

void Player::Exe() {
	Move();
	DrawRotaGraph(ziki.x, ziki.y, 1.0, ziki.rota, ziki.gr, TRUE, FALSE);
}

void Player::SetPlayerData(int const& gr_) {
	ziki.gr = gr_;
	GetGraphSize(gr_, &ziki.width, &ziki.height);
	ziki.x = 400 - ziki.width / 2;
	ziki.y = 400 + ziki.height / 2;
}

void Player::Move() {
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		ziki.x += MOVE_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		ziki.x -= MOVE_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		ziki.y -= MOVE_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		ziki.y += MOVE_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		ziki.rota += ROTA_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		ziki.rota -= ROTA_SPEED;
	}
}