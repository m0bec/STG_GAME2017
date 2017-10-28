#pragma once
#include "DxLib.h"

class GameSystem {
private:
	GameSystem() {
		score = 0;
	}
	~GameSystem() {}

	int score;
public:
	static GameSystem& GetInstance()
	{
		static GameSystem inst;
		return inst;
	}

	void SetVar();
	void ScoreAdd(int add_);
	int GetScore() { return score; }
};