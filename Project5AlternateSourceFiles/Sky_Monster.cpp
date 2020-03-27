#include "Sky_Monster.h"

Sky_Monster::Sky_Monster() {
    //Generate random number of wings, no less than 2
    number_wings = rand();
    if (number_wings < MIN_WINGS) {
        number_wings = MIN_WINGS;
    }
}

Sky_Monster::Sky_Monster(int wings) {
    set_number_of_wings(wings);
}

int Sky_Monster::get_number_of_wings() const {
    return number_wings;
}


void Sky_Monster::set_number_of_wings(int wings) {
   //want max num of wings??? will set min instead
   if (wings < MIN_WINGS) {
        wings = MIN_WINGS;
    }
   if (wings > MAX_NUMBER_WINGS) {
       wings = MAX_NUMBER_WINGS;
   }
    number_wings = wings;
}

void Sky_Monster::growth_spurt(int wings) {
    //Give the monster 2 more wings
    set_number_of_wings(wings += 2);
}