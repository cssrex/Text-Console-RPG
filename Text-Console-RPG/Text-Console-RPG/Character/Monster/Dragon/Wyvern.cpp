#include "Wyvern.h"
#include <iostream>

void Wyvern::Attack(Character& target){
	target.TakeDamage(attack_);
}