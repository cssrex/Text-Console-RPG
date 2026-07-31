#include "OwkChief.h"
#include <iostream>

void OwkChief::PrintAsciiArt(short startX, short startY) {
	PrintBossOrcAsciiArt(startX, startY);
}
void OwkChief::BasicAttack(Player* player) {
	cout << "오크 족장의 기본 공격!" << endl;
	cout << "대검 내려치기!!" << endl;
	player->TakeDamage(GetAttack());
}

void OwkChief::SpecialAttack(Player* player) {
	cout << "이 검 맛좀 봐라!" << endl;
	cout << "오크 족장의 특수 공격!" << endl;
	cout << "대검 던지기!!" << endl;
	player->TakeDamage(GetAttack() * 2);
}

void OwkChief::HyperAttack(Player* player) {
	cout << "부족의 이름을 걸고... 전력을 다한다!!" << endl;
	cout << "오크 족장의 궁극기!" << endl;
	cout << "파워 슬레시!!" << endl;
	player->TakeDamage(GetAttack() * 3);
}

void OwkChief::MonsterAppearanceScript() {
	cout << "크하하! 감히 내 영역에 발을 들이다니, 죽고 싶은 게로군!" << endl;
}

void OwkChief::MonsterDeadScript() {
	cout << "크윽... 이런 애송이에게... 말도 안 돼..." << endl;
}