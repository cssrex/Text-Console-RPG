#include "OwkWarrior.h"
#include <iostream>

void OwkWarrior::Attack(Character& target){
	target.TakeDamage(attack_);
}