#include "KingSlime.h"
#include <iostream>

void KingSlime::PrintAsciiArt(short startX, short startY) {
	PrintBossSlimeAsciiArt(startX, startY);
}
void KingSlime::BasicAttack(Player* player) {
	cout << "슬라임 킹의 기본 공격!" << endl;
	cout << "몸통 박치기!!" << endl;
	player->TakeDamage(GetAttack());
}

void KingSlime::SpecialAttack(Player* player) {
	cout << "끈적하게.. 달라붙어라!" << endl;
	cout << "슬라임 킹의 특수 공격!" << endl;
	cout << "튀어 오르기!!" << endl;
	player->TakeDamage(GetAttack() * 2);
}

void KingSlime::HyperAttack(Player* player) {
	cout << "모든 것을 녹여버리겠다..!" << endl;
	cout << "슬라임 킹의 궁극기!" << endl;
	cout << "점액 폭탄!!" << endl;
	player->TakeDamage(GetAttack() * 3);
}

void KingSlime::MonsterAppearanceScript() {
	cout << "물컹...물컹...모두 내 안에 가두어주마." << endl;
}

void KingSlime::MonsterDeadScript() {
	cout << "이렇게...흩어지다니...다시...뭉쳐서...돌아오마..." << endl;
}
