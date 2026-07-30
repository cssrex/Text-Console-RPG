#include "HornSlime.h"
#include <iostream>

void HornSlime::Attack(Character& target){
	target.TakeDamage(attack_);
}