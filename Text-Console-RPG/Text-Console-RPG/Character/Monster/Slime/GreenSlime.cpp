#include "GreenSlime.h"
#include <iostream>

void GreenSlime::PrintAsciiArt(short startX, short startY) {
	PrintNormalSlimeAsciiArt(startX, startY);
}

void GreenSlime::BasicAttack(Player* player) {
	cout << "초록 슬라임의 기본 공격!" << endl;
	cout << "몸통 박치기!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack());
}

void GreenSlime::SpecialAttack(Player* player) {
	RandCry(slimeCry_);
	cout << "초록 슬라임의 특수 공격!" << endl;
	cout << "점액 분사!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack() * 2);
}

void GreenSlime::MonsterAppearanceScript() {
	RandCry(slimeCry_);
}

void GreenSlime::MonsterDeadScript() {
	cout << "물컹..." << endl;
}