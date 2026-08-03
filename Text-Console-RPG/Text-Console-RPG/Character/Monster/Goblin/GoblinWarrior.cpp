#include "GoblinWarrior.h"
#include <iostream>

void GoblinWarrior::PrintAsciiArt(short startX, short startY) {
	PrintNormalGoblinAsciiArt(startX, startY);
}

void GoblinWarrior::BasicAttack(Player* player) {
	cout << "고블린 전사의 기본 공격!" << endl;
	cout << "독침!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack());
}

void GoblinWarrior::SpecialAttack(Player* player) {
	RandCry(goblinCry_);
	cout << "고블린 전사의 특수 공격!" << endl;
	cout << "비겁한 일격!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack() * 2);
}

void GoblinWarrior::MonsterAppearanceScript() {
	RandCry(goblinCry_);
}

void GoblinWarrior::MonsterDeadScript() {
	cout << "케케켁.." << endl;
}