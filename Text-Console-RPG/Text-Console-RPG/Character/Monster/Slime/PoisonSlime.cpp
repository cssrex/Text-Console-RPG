#include "PoisonSlime.h"
#include <iostream>

void PoisonSlime::PrintAsciiArt(short startX, short startY) {
	PrintNormalSlimeAsciiArt(startX, startY);
}
void PoisonSlime::BasicAttack(Player* player) {
	cout << "독 슬라임의 기본 공격!" << endl;
	cout << "몸통 박치기!!" << endl;
	player->TakeDamage(GetAttack());
}

void PoisonSlime::SpecialAttack(Player* player) {
	RandCry(slimeCry_);
	cout << "독 슬라임의 특수 공격!" << endl;
	cout << "맹독성 부식!!" << endl;
	player->TakeDamage(GetAttack() * 2);
}

void PoisonSlime::MonsterAppearanceScript() {
	RandCry(slimeCry_);
}

void PoisonSlime::MonsterDeadScript() {
	cout << "물컹..." << endl;
}