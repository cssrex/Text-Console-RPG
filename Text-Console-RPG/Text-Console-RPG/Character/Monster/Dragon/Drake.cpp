#include "Drake.h"
#include <iostream>

void Drake::PrintAsciiArt(short startX, short startY) {
	PrintNormalDragonAsciiArt(startX, startY);
}
void Drake::BasicAttack(Player* player) {
	cout << "드레이크의 기본 공격!" << endl;
	cout << "꼬리 휘두르기!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack());
}

void Drake::SpecialAttack(Player* player) {
	RandCry(dragonCry_);
	cout << "드레이크의 특수 공격!" << endl;
	cout << "화염 브레스!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack() * 2);
}

void Drake::MonsterAppearanceScript() {
	RandCry(dragonCry_);
}

void Drake::MonsterDeadScript() {
	cout << "쉬이이익..." << endl;
}