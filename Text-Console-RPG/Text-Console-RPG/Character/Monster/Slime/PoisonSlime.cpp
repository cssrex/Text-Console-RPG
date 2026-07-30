#include "PoisonSlime.h"
#include <iostream>

void PoisonSlime::Attack(Character& target){
	target.TakeDamage(attack_);
}