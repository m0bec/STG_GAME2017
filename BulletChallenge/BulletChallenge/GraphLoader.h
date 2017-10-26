#pragma once
#include "DxLib.h"

class GraphLoader {
private:
	bool error_flag = false;

	int load_gr = 0;

	//Ziki
	int ziki_gr;
	int ziki_rgr;
	int ziki_lgr;

	//Title
	int exit_gr;
	int start_gr;
	int manual_gr;
	int title_back_gr;

public:
	GraphLoader() {}

	void LoadCheck(int &gr, char* gr_name);
	void Load();
	void TitleDraw();
	void LoadError();

	int LoadGr() { return load_gr; }

	int GetZikiGr() { return ziki_gr; }
	int GetZikiRGr() { return ziki_rgr; }
	int GetZikiLGr() { return ziki_lgr; }

	int ExitGr() { return exit_gr; }
	int StartGr() { return start_gr; }
	int ManualGr() { return manual_gr; }
	int TitleBackGr() { return title_back_gr; }
};