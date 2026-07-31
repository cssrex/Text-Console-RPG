#include "HornSlime.h"
#include <iostream>

void HornSlime::PrintAsciiArt(short startX, short startY) {
	PrintNormalSlimeAsciiArt(startX, startY);
}
void HornSlime::BasicAttack(Player* player) {
	cout << "가시 슬라임의 기본 공격!" << endl;
	cout << "몸통 박치기!!" << endl;
	player->TakeDamage(GetAttack());
}

void HornSlime::SpecialAttack(Player* player) {
	RandCry(slimeCry_);
	cout << "가시 슬라임의 특수 공격!" << endl;
	cout << "가시 발사!!" << endl;
	player->TakeDamage(GetAttack() * 2);
}

void HornSlime::MonsterAppearanceScript() {
	RandCry(slimeCry_);
}

void HornSlime::MonsterDeadScript() {
	cout << "물컹..." << endl;
}