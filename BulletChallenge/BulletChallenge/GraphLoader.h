#pragma once
#include "DxLib.h"

class GraphLoader {
private:
	bool error_flag = false;

	
public:
	GraphLoader() {}

	void LoadCheck(int &gr, char* gr_name);
	void Load();
	void TitleDraw();
	void LoadError();

	int load_gr;

	//Ziki
	int ziki_gr;
	int ziki_rgr;
	int ziki_lgr;

	//Title
	int exit_gr;
	int start_gr;
	int manual_gr;
	int title_back_gr;
	int manual_disp;

	//Game
	int game_back_gr;
};