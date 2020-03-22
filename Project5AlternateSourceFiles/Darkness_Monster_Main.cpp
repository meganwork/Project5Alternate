#include "Closet_Monster.h"
#include "Under_Bed_Monster.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {


    unique_ptr<Darkness_Monster> monster;
    vector<unique_ptr<Darkness_Monster>> manyMonsters;
    for(int i = 0; i < 10; ++i) {
        int randomInt = rand() % 2;
        if (randomInt == 0) {
            Closet_Monster closetMonster();
            monster = make_unique<Closet_Monster>(closetMonster);
            manyMonsters.push_back(monster);
        }
        if (randomInt == 1) {
            Under_Bed_Monster bedMonster();
            monster = make_unique<Darkness_Monster>(bedMonster);
            manyMonsters.push_back(monster);
        }
    }

    cout << "There are monsters everywhere!"
    // Create a vector of Darkness Monster unique pointers and push a variety of ten Closet Monsters and Under Bed Monsters to it.
     // Tell the user that there are monsters everywhere!

     for(int i = 0; i < manyMonsters.size(); ++i) {
         manyMonsters[i]->scare();
     }
     //Loop through the vector and call the scare method on each. Print the return values.
   //This is polymorphism. Why? Answer in your README file.

     cout << "Do you want to poke their eyes or run?" << endl;
     cout << "1. Poke their eyes" << endl;
     cout << "2. Run" << endl;
     int choice = 0;
     cin >> choice;
     while (choice != 1 && choice != 2) {
         cout << "Please choose a valid option" << endl;
         cin >> choice;
     }
     //Poke eyes!
     if (choice == 1) {
         for(int i = 0; i < manyMonsters.size(); ++i) {
             manyMonsters[i]->poke_eye();
         }
         //After poking all eyes, loop and scare again
         for(int i = 0; i < manyMonsters.size(); ++i) {
             manyMonsters[i]->poke_eye();
         }
     }
     if (choice == 2) {
         cout << "You got away!" << endl;
         return(0);
     }
     

     //Repeatedly give the user options to poke the eyes or run away.
     //    - If they poke the eyes, loop through the vector and call the poke_eye method on each.
     //         - This is NOT polymorphism. Why? Answer in your README file.
     //         - After poking all the eyes, loop through the vector again and output the scare methods again.
     //    - If they choose to run away, the program ends
    return 0;
}

