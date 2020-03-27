#include "Under_Bed_Monster.h"
using namespace std;

Under_Bed_Monster::Under_Bed_Monster() : Darkness_Monster() {
}

Under_Bed_Monster::Under_Bed_Monster(int noe) : Darkness_Monster(noe) {
}

//implement the scare method here
string Under_Bed_Monster::scare() {
    return "The monster reaches up yanks your foot!";
}