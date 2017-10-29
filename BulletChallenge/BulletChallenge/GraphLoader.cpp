#include "GraphLoader.h"

void GraphLoader::LoadCheck(int &gr_, char* gr_name_) {
	gr_ = LoadGraph(gr_name_);
	if (gr_ == -1) {
		error_flag = true;
	}
}

void GraphLoader::Load() {
	LoadCheck(load_gr, "Graph/load.png");
	SetUseASyncLoadFlag(TRUE);
	LoadCheck(ziki_gr, "Graph/ziki.png");
	LoadCheck(player_bullet_gr, "Graph/PlayerBullet.png");
	LoadCheck(enemy_gr, "Graph/Enemy.png");

	LoadCheck(exit_gr, "Graph/exit.png");
	LoadCheck(start_gr, "Graph/start.png");
	LoadCheck(manual_gr, "Graph/manual.png");
	LoadCheck(title_back_gr, "Graph/title.png");
	LoadCheck(manual_disp, "Graph/ManualDisp.png");

	LoadCheck(game_back_gr, "Graph/GameBack.png");
	LoadCheck(stop_back_gr, "Graph/StopBack.png");
	LoadCheck(stop_continue_gr, "Graph/continue_.png");
	LoadCheck(stop_exit_gr, "Graph/Exit_.png");
	LoadCheck(game_over_gr, "Graph/GameOver.png");
	LoadCheck(clear_gr, "Graph/Clear.png");
	LoadCheck(blue_bullet_gr, "Graph/ETama8.png");
}

void GraphLoader::ThreadLoadDisp() {
	DrawGraph(0, 0, load_gr, TRUE);
}

void GraphLoader::TitleDraw() {
	DrawGraph(0, 0, title_back_gr, TRUE);
	
}

void GraphLoader::LoadError(){
	if (error_flag) {
		printfDx("LoadGraphError");
	}
	error_flag = false;
}