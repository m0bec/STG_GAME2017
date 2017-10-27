#pragma once
#include "DxLib.h"
#include <array>

class ScoreManager{
private:
	ScoreManager(){}
	~ScoreManager(){}
public:
	static ScoreManager& GetInstance()
	{
		static ScoreManager inst;
		return inst;
	}

	std::array<int, 10> score;
	void LoadScore();
};