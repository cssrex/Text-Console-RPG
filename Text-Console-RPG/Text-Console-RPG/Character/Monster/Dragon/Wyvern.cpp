#include "Wyvern.h"
#include <iostream>

void Wyvern::PrintAsciiArt(short startX, short startY) {
	PrintNormalDragonAsciiArt(startX, startY);
}
void Wyvern::BasicAttack(Player* player) {
	cout << "와이번의 기본 공격!" << endl;
	cout << "날개치기!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack());
}

void Wyvern::SpecialAttack(Player* player) {
	RandCry(dragonCry_);
	cout << "와이번의 특수 공격!" << endl;
	cout << "아이스 브레스!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack() * 2);
}

void Wyvern::MonsterAppearanceScript() {
	RandCry(dragonCry_);
}

void Wyvern::MonsterDeadScript() {
	cout << "쉬이이익..." << endl;
}