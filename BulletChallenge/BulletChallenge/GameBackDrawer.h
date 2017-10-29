#pragma once
#include "DxLib.h"
#include "Player.h"
#include "GameSytem.h"

class GameBackDrawer {
private:
	GameSystem& game_system = GameSystem::GetInstance();
	bool push_key;
	int push_timer;
public:
	GameBackDrawer(){
		push_key = false;
		push_timer = 0;
	}

	void GameBackDraw(int const& game_back_gr_);
	void WriteWord(Ziki const& ziki_);
	void StopDraw(int& stop_state_, int& state_, int& continue_gr_, int& exit_gr_, int& back_gr_);
};