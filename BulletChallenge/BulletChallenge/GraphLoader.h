#pragma once
#include "DxLib.h"

class GraphLoader {
private:
	int ziki_gr;

public:
	GraphLoader() {}


	void Load() {
		SetUseASyncLoadFlag(TRUE);
		ziki_gr = LoadGraph("Graph/ziki.png");
	}

	int GetZikiGr() { return ziki_gr; }
};