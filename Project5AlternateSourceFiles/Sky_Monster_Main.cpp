#include "Cloud_Monster.h"
#include "Comet_Monster.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {

     //Use polymorphism in a program of your choice, utilizing at least ten objects of the Cloud and Comet Monster classes.

    unique_ptr<Sky_Monster> monster;
    vector<unique_ptr<Sky_Monster>> severalMonsters;
    for(int i = 0; i < 10; ++i) {
        int randomInt = rand() % 2;
        if (randomInt == 0) {
            Cloud_Monster cloudMonster();
            monster = make_unique<Sky_Monster>(cloudMonster);
            severalMonsters.push_back(monster);
        }
        if (randomInt == 1) {
            Comet_Monster cometMonster();
            monster = make_unique<Sky_Monster>(cometMonster);
            severalMonsters.push_back(monster);
        }
    }

    cout << "Watch Out! There are monsters overhead!" << endl;

    //The monsters give a fright! (Polymorphism)
    string message;
    for(int i = 0; i < severalMonsters.size(); ++i) {
        message = severalMonsters[i]->scare();
    }

    //Time to grow! (not polymorphism)
    cout << "The monsters have grown stronger from scaring you!" << endl;
    for(int i = 0; i < severalMonsters.size(); ++i) {
        severalMonsters[i]->growth_spurt();
    }

    return 0;
}

