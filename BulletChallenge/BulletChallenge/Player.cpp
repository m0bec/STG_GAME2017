#include "Player.h"
#include <cmath>

void Player::SetVar() {
	ziki.avoid_num = 2;
	ziki.hp = 2;
	ziki.rota = 0.0;
	ziki.invalid = false;
	sample_bullet.move_var = 0;
	sample_bullet.move_speed = BULLET_SPEED;
	sample_bullet.move_angle = 0.0;
	for (Bullet &t_ : bullet)	t_.move_var = NO_BULLET;
	bullet_count = 0;
	ziki.x = 280 + ziki.width / 2;
	ziki.y = 600 - ziki.height / 2;
	core_x = ziki.x - core_w / 2;
	core_y = ziki.y - core_h / 2;
	ziki.r = core_w / 2;
	ziki.invalid_timer = 0;
}

void Player::Exe() {
	Move();
	BulletMove();
	DrawRotaGraph(ziki.x, ziki.y, 1.0, ziki.rota, ziki.gr, TRUE, FALSE);
	core_x = ziki.x - core_w / 2;
	core_y = ziki.y - core_h / 2;
	DrawGraph(core_x, core_y, core_gr, TRUE);
	InvalidMode();
}

void Player::SetPlayerData(int const& gr_, int const& player_bullet_gr_, int const& core_gr_) {
	ziki.gr = gr_;
	core_gr = core_gr_;
	GetGraphSize(gr_, &ziki.width, &ziki.height);
	GetGraphSize(core_gr, &core_w, &core_h);

	sample_bullet.gr = player_bullet_gr_;
	GetGraphSize(player_bullet_gr_, &sample_bullet.width, &sample_bullet.height);
}

void Player::Move() {
	if (CheckHitKey(KEY_INPUT_RIGHT))	ziki.x += MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_LEFT))	ziki.x -= MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_UP)) 	ziki.y -= MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_DOWN))	ziki.y += MOVE_SPEED;
	if (CheckHitKey(KEY_INPUT_D))	ziki.rota += ROTA_SPEED;
	if (CheckHitKey(KEY_INPUT_A))	ziki.rota -= ROTA_SPEED;

	if (ziki.y - ziki.height/2 <= DISP_AREA_MIN_Y)	ziki.y = DISP_AREA_MIN_Y + ziki.height / 2;
	else if (ziki.y + ziki.height / 2 >= DISP_AREA_MAX_Y) ziki.y = DISP_AREA_MAX_Y - ziki.height / 2;
	if (ziki.x + ziki.width / 2 >= DISP_AREA_MAX_X)	ziki.x = DISP_AREA_MAX_X - ziki.width / 2;
	else if (ziki.x - ziki.width/2 <= DISP_AREA_MIN_X)	ziki.x = DISP_AREA_MIN_X + ziki.width / 2;
}

void Player::BulletMove() {
	int count = 0;
	++bullet_count;

	for (Bullet &t_ : bullet) {
		if (t_.move_var == NO_BULLET) {
			if (bullet_count > BULLET_COUNTER_MAX && count < 2) {
				t_ = sample_bullet;
				t_.x = ziki.x- t_.width / 2;
				t_.y = ziki.y - t_.height / 2;
				if (count == 1)	t_.move_angle += PI;
				++count;
			}
		}
		else if (t_.move_var == sample_bullet.move_var) {
			t_.x += static_cast<int>(7 * sin(t_.move_angle) * cos(ziki.rota) + t_.move_speed * sin(ziki.rota));
			t_.y -= static_cast<int>(t_.move_speed * cos(ziki.rota) + 7 * sin(t_.move_angle) * sin(-ziki.rota));
			t_.move_angle += BULLET_RADI;
			if (t_.move_angle > 2 * PI)	t_.move_angle -= 2 * PI;
			DrawGraph(t_.x, t_.y, t_.gr, TRUE);
			if (t_.y + t_.height / 2 <= DISP_AREA_MIN_Y || t_.x + t_.width >= DISP_AREA_MAX_X ||
				t_.y - t_.height / 2 >= DISP_AREA_MAX_Y || t_.x - t_.width + 10 <= DISP_AREA_MIN_X)	t_.move_var = NO_BULLET;
		}
	}
	if(bullet_count > 5)	bullet_count = 0;
}

void Player::OnltDraw() {
	for (Bullet &bul_ : bullet) {
		DrawGraph(bul_.x, bul_ .y, bul_.gr, TRUE);
	}
	DrawRotaGraph(ziki.x, ziki.y, 1.0, ziki.rota, ziki.gr, TRUE, FALSE);
	DrawGraph(core_x, core_y, core_gr, TRUE);
}

void Player::InvalidMode() {
	if (ziki.invalid) {
		++ziki.invalid_timer;
		if (ziki.invalid_timer > 100) {
			ziki.invalid_timer = 0;
			ziki.invalid = false;
		}
		DrawFormatString(640, 300, WORD_COLOR, "INVALID MODE");
	}
}