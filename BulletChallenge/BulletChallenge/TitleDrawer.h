#pragma once
#include "DxLib.h"
#include "GraphLoader.h"

class TitleDrawer {
private:
	enum TitleState {
		Start, Manual, Exit, DispManual
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

	void DrawTitle(int const& title_back_gr_, int const& start_gr_, int const& exit_gr_, int const& manual_gr_, int const& manual_disp_);
	void TitleSystem();
	void Select(bool &f_, int &state_);
	void SetPushKeyFlag() { push_key_flag = true; }
};