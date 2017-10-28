#pragma once
#include "DxLib.h"

class GraphLoader {
private:
	bool error_flag = false;
	GraphLoader() {}
	
public:
	static GraphLoader& GetInstance()
	{
		static GraphLoader inst;
		return inst;
	}

	void LoadCheck(int &gr, char* gr_name);
	void ThreadLoadDisp();
	void Load();
	void TitleDraw();
	void LoadError();
	int load_gr;
	//Ziki
	int ziki_gr;
	int player_bullet_gr;
	//Enemy
	int enemy_gr;
	//Title
	int exit_gr;
	int start_gr;
	int manual_gr;
	int title_back_gr;
	int manual_disp;
	//Game
	int game_back_gr;
};