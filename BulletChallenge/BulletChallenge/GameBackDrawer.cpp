#include "GameBackDrawer.h"

void GameBackDrawer::GameBackDraw(int const& game_back_gr_) {
	DrawGraph(0, 0, game_back_gr_, TRUE);
}

void GameBackDrawer::WriteWord(Ziki const& ziki_) {
	DrawFormatString(640, 100, WORD_COLOR, "�c�@�F%d", ziki_.hp);
}