#pragma once
#include "DxLib.h"
#include "GraphLoader.h"

class TitleDrawer {
private:
	enum TitleState {
		Start, Manual, Exit
	};
	int title_state;
	int push_key_timer;
	bool push_key_flag;

public:
	TitleDrawer(){
		title_state = Start;
		push_key_flag = false;
		push_key_timer = 0;
	}

	void DrawTitle(int const& title_back_gr_, int const& start_gr_, int const& exit_gr_, int const& manual_gr_);
	void TitleSystem();
};