#pragma once
#include "DxLib.h"

class StateInGame {
public:
	enum Is {
		Play, Stop, GameOver, NextStage
	};
};

class StateInStop {
public:
	enum Is {
		Continue, Exit
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
	int stop_state;
	void SetVar();
	void ScoreAdd(int add_);
	int GetScore() { return score; }
	void CheckGoToStop();
	void ZikiHpCheck(int const& hp_);
};