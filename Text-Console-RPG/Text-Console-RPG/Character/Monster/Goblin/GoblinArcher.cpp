#include "GoblinArcher.h"
#include <iostream>

void GoblinArcher::PrintAsciiArt(short startX, short startY) {
	PrintNormalGoblinAsciiArt(startX, startY);
}
void GoblinArcher::BasicAttack(Player* player) {
	cout << "고블린 궁수의 기본 공격!" << endl;
	cout << "화살 날리기!!" << endl;
	player->TakeDamage(GetAttack());
}

void GoblinArcher::SpecialAttack(Player* player) {
	RandCry(goblinCry_);
	cout << "고블린 궁수의 특수 공격!" << endl;
	cout << "급소 저격!!" << endl;
	player->TakeDamage(GetAttack() * 2);
}

void GoblinArcher::MonsterAppearanceScript() {
	RandCry(goblinCry_);
}

void GoblinArcher::MonsterDeadScript() {
	cout << "케케켁.." << endl;
}