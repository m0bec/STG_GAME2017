#include "GameBackDrawer.h"

void GameBackDrawer::GameBackDraw(int const& game_back_gr_) {
	DrawGraph(0, 0, game_back_gr_, TRUE);
}

void GameBackDrawer::WriteWord(Ziki const& ziki_) {
	DrawFormatString(640, 100, WORD_COLOR, "残機　：%d", ziki_.hp);
	DrawFormatString(640, 150, WORD_COLOR, "スコア：%d", game_system.GetScore());
}

void GameBackDrawer::StopDraw(int& stop_state_, int& state_, int& continue_gr_, int& exit_gr_, int& back_gr_) {
	if (CheckHitKeyAll() == 0)	push_key = false;
	if (push_key) {
		++push_timer;
		if (push_timer > 20) {
			push_key = false;
		}
	}
	if (!push_key)	push_timer = 0;

	switch(stop_state_) {
	case StateInStop::Continue:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, back_gr_, TRUE);
		DrawGraph(200, 300, exit_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(150, 200, continue_gr_, TRUE);
		if ((CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_UP)) && !push_key) {
			stop_state_ = StateInStop::Exit;
			push_key = true;
		}
		if (CheckHitKey(KEY_INPUT_RETURN))	state_ = StateInGame::Play;
		break;

	case StateInStop::Exit:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, back_gr_, TRUE);
		DrawGraph(150, 200, continue_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(200, 300, exit_gr_, TRUE);
		if ((CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_UP)) && !push_key) {
			stop_state_ = StateInStop::Continue;
			push_key = true;
		}
		if (CheckHitKey(KEY_INPUT_RETURN))	state_ = StateInGame::GameOver;
		break;
	}
}