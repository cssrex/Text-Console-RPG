#include "GreenSlime.h"
#include <iostream>

void GreenSlime::Attack(Character& target){
	target.TakeDamage(attack_);
}