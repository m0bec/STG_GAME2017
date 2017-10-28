#pragma once
#include "DxLib.h"
#include "Player.h"
#include "GameSytem.h"

class GameBackDrawer {
private:
	GameSystem& game_system = GameSystem::GetInstance();
public:
	GameBackDrawer(){}

	void GameBackDraw(int const& game_back_gr_);
	void WriteWord(Ziki const& ziki_);
};