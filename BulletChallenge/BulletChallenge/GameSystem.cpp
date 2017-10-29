#include "GameSytem.h"

void GameSystem::SetVar() {
	score = 0;
	state = StateInGame::Play;
	stop_state = StateInStop::Continue;
}

void GameSystem::ScoreAdd(int add_) {
	score += add_;
}

void GameSystem::CheckGoToStop() {
	if (CheckHitKey(KEY_INPUT_S))	state = StateInGame::Stop;
}