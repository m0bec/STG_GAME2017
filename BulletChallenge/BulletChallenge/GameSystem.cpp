#include "GameSytem.h"

void GameSystem::SetVar() {
	score = 0;
	state = StateInGame::Play;
}

void GameSystem::ScoreAdd(int add_) {
	score += add_;
}