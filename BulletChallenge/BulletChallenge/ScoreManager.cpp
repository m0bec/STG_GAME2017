#include "ScoreManager.h"
#include <iostream>
#include <fstream>

void ScoreManager::LoadScore() {
	int str;
	std::fstream file("Data/Score.txt", std::ios::binary | std::ios::in);
	for (int &t_ : score) {
		file.seekg(sizeof(int), std::ios_base::cur);
		file.read((char*)&t_, sizeof(int));
	}
	file.close();
}