#include "TitleDrawer.h"

void TitleDrawer::DrawTitle(int const& title_back_gr_, int const& start_gr_, int const& exit_gr_, int const& manual_gr_) {
	DrawGraph(0, 0, title_back_gr_, TRUE);
	switch (title_state) {
	case Start:
		DrawGraph(200, 200, start_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(200, 250, manual_gr_, TRUE);
		DrawGraph(200, 300, exit_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;

	case Manual:
		DrawGraph(200, 250, manual_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(200, 200, start_gr_, TRUE);
		DrawGraph(200, 300, exit_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;

	case Exit:
		DrawGraph(200, 300, exit_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(200, 200, start_gr_, TRUE);
		DrawGraph(200, 250, manual_gr_, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	}
}

void TitleDrawer::TitleSystem() {
	if (!push_key_flag) {
		if (CheckHitKey(KEY_INPUT_UP)) {
			if (title_state == Start)	title_state = Exit;
			else {
				title_state--;
			}
			push_key_flag = true;
		}
		else if (CheckHitKey(KEY_INPUT_DOWN)) {
			if (title_state == Exit)	title_state = Start;
			else {
				title_state++;
			}
			push_key_flag = true;
		}
	}
	else {
		push_key_timer++;
		if (push_key_timer > 20) {
			push_key_timer = 0;
			push_key_flag = false;
		}
		if (CheckHitKeyAll() == 0)	push_key_flag = false;
	}
}