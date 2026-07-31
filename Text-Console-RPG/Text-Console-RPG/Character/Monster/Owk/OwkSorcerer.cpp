#include "OwkSorcerer.h"
#include <iostream>

void OwkSorcerer::PrintAsciiArt(short startX, short startY) {
	PrintNormalOrcAsciiArt(startX, startY);
}
void OwkSorcerer::BasicAttack(Player* player) {
	cout << "오크 주술사의 기본 공격!" << endl;
	cout << "파이어 볼!!" << endl;
	player->TakeDamage(GetAttack());
}

void OwkSorcerer::SpecialAttack(Player* player) {
	RandCry(owkCry_);
	cout << "오크 주술사의 특수 공격!" << endl;
	cout << "헬 파이어!!" << endl;
	player->TakeDamage(GetAttack() * 2);
}

void OwkSorcerer::MonsterAppearanceScript() {
	RandCry(owkCry_);
}

void OwkSorcerer::MonsterDeadScript() {
	cout << "그르르..." << endl;
}