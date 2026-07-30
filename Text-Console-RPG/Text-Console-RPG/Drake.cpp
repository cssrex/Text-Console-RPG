#include "Drake.h"
#include <iostream>

void Drake::Attack(Character& target){
	target.TakeDamage(attack_);
}