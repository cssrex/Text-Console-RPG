#include "OwkWarrior.h"
#include <iostream>

void OwkWarrior::PrintAsciiArt(short startX, short startY) {
	PrintNormalOrcAsciiArt(startX, startY);
}
void OwkWarrior::BasicAttack(Player* player) {
	cout << "오크 전사의 기본 공격!" << endl;
	cout << "돌진!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack());
}

void OwkWarrior::SpecialAttack(Player* player) {
	RandCry(owkCry_);
	cout << "오크 전사의 특수 공격!" << endl;
	cout << "깨물어 부수기!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack() * 2);
}

void OwkWarrior::MonsterAppearanceScript() {
	RandCry(owkCry_);
}

void OwkWarrior::MonsterDeadScript() {
	cout << "그르르..." << endl;
}