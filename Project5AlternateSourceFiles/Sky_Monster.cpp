#include "Sky_Monster.h"

Sky_Monster::Sky_Monster() {
    //Generate random number of wings, no less than 2
    number_of_wings = rand();
    if (number_of_wings < MIN_WINGS || number_of_wings > MAX_NUMBER_WINGS) {
        set_number_of_wings(MAX_NUMBER_WINGS);
    }
    set_number_of_wings(number_of_wings);
}

Sky_Monster::Sky_Monster(int wings) {
    if (wings < MIN_WINGS || wings > MAX_NUMBER_WINGS) {
        wings = MAX_NUMBER_WINGS;
    }
    set_number_of_wings(wings);
}

int Sky_Monster::get_number_of_wings() const {
    return number_of_wings;
}


void Sky_Monster::set_number_of_wings(int wings) {
    if (wings < MIN_WINGS || wings > MAX_NUMBER_WINGS || wings % 2 != 0) {
        wings = MAX_NUMBER_WINGS;
    }
    number_of_wings = wings;
}

void Sky_Monster::growth_spurt() {
    //Give the monster 2 more wings
    set_number_of_wings(get_number_of_wings() + 2);
    if (get_number_of_wings() >= MAX_NUMBER_WINGS) {
        set_number_of_wings(MAX_NUMBER_WINGS);
    }
}