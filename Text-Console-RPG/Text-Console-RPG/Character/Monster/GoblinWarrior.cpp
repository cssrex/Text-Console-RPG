#include "GoblinWarrior.h"
#include <iostream>

void GoblinWarrior::Attack(Character& target){
	target.TakeDamage(attack_);
}