#include "OwkSorcerer.h"
#include <iostream>

void OwkSorcerer::Attack(Character& target){
	target.TakeDamage(attack_);
}