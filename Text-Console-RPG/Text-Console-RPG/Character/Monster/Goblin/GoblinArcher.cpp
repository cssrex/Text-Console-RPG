#include "GoblinArcher.h"
#include <iostream>

void GoblinArcher::Attack(Character& target){

	target.TakeDamage(attack_);
}