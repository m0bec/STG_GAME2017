#pragma once
#include "DxLib.h"

class StateInGame {
public:
	enum Is {
		Play, Stop, GameOver, NextStage
	};
};

class GameSystem {
private:
	GameSystem() {
		SetVar();
	}
	~GameSystem() {}

	int score;
public:
	static GameSystem& GetInstance()
	{
		static GameSystem inst;
		return inst;
	}

	int state;
	void SetVar();
	void ScoreAdd(int add_);
	int GetScore() { return score; }
};