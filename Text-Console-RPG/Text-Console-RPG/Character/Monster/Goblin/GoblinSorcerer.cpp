#include "GoblinSorcerer.h"
#include <iostream>

void GoblinSorcerer::PrintAsciiArt(short startX, short startY) {
	PrintBossGoblinAsciiArt(startX, startY);
}
void GoblinSorcerer::BasicAttack(Player* player) {
	cout << "고블린 주술사의 기본 공격!" << endl;
	cout << "매직 미사일!!" << endl;
	player->TakeDamage(GetAttack());
}

void GoblinSorcerer::SpecialAttack(Player* player) {
	cout << "어둠의 힘이여, 저 자를 저주하라" << endl;
	cout << "고블린 주술사의 특수 공격!" << endl;
	cout << "다크 커스!!" << endl;
	player->TakeDamage(GetAttack() * 2);
}

void GoblinSorcerer::HyperAttack(Player* player) {
	cout << "이것이... 금단의 흑마법이다!!" << endl;
	cout << "고블린 주술사의 궁극기!" << endl;
	cout << "데스 블래스터!!" << endl;
	player->TakeDamage(GetAttack() * 3);
}

void GoblinSorcerer::MonsterAppearanceScript() {
	cout << "키히히... 어리석은 침입자여, 저주를 받아라." << endl;
}

void GoblinSorcerer::MonsterDeadScript() {
	cout << "말도...안돼... 내 주문이 통하지 않다니..." << endl;
}