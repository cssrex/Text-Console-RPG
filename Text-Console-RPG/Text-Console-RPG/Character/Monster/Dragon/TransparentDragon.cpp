#include "TransparentDragon.h"
#include <iostream>

void TransparentDragon::PrintAsciiArt(short startX, short startY) {
	PrintBossDragonAsciiArt(startX, startY);
}
void TransparentDragon::BasicAttack(Player* player) {
	cout << "투명 드래곤의 기본 공격!" << endl;
	cout << "드래곤 브레스!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack());
}

void TransparentDragon::SpecialAttack(Player* player) {
	cout << "느껴지는가? 네 곁에 있는 죽음이." << endl;
	cout << "투명 드래곤의 특수 공격!" << endl;
	cout << "절대영도!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack() * 2);
}

void TransparentDragon::HyperAttack(Player* player) {
	cout << "보여주마.. 내 진정한 힘을!!" << endl;
	cout << "투명 드래곤의 궁극기!" << endl;
	cout << "메테오 스트라이크!!" << endl;
	player->TakeDamage(CalculatePowerUpAttack() * 3);
}

void TransparentDragon::MonsterAppearanceScript() {
	cout << "인간 주제에.. 감히 날 깨우다니... 후회하게 해주지." << endl;
}

void TransparentDragon::MonsterDeadScript() {
	cout << "여기까진가... 대단하구나 인간.." << endl;
}