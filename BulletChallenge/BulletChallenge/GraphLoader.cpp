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
	LoadCheck(ziki_rgr, "Graph/zikiR.png");
	LoadCheck(ziki_lgr, "Graph/zikiL.png");

	LoadCheck(exit_gr, "Graph/exit.png");
	LoadCheck(start_gr, "Graph/start.png");
	LoadCheck(manual_gr, "Graph/manual.png");
	LoadCheck(title_back_gr, "Graph/title.png");
	
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