#include "Lake_Monster.h"
#include "Sea_Monster.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
#include <random>

using namespace std;

int get_int_input(string prompt, string invalid, int low, int high);
void monster_mode();
void player_mode();

int main() {
    int choice = get_int_input("Enter 1 to play as a water monster or 2 to play as a person: ",
                             "Invalid choice. Enter 1 or 2: ",
                             1,
                             2);

    if (choice == 1) {
        cout << "You monster!" << endl;
        monster_mode();
    } else {
        cout << "Get ready to face the water monsters!" << endl;
        player_mode();
    }
    return 0;
}

int get_int_input(string prompt, string invalid, int low, int high) {
    cout << prompt;
    int choice = 0;
    string junk;
    while (!(cin >> choice) || choice < low || choice > high) {
        cout << invalid;
        cin.clear();
        getline(cin, junk);
    }
    return choice;
}

void monster_mode() {
    Lake_Monster champ(0);

    //Print welcome message that includes the name Champ the Lake Monster
    cout << "Welcome! Ready to hang out with Champ the Lake Monster and his friends?" << endl;

    // Create vector of unique pointers to Water Monsters called friends
    unique_ptr<Water_Monster> monster;
    vector<unique_ptr<Water_Monster>> friends;

    //Populate vector with 10 monsters, choosing Lake vs Sea randomly
    for(int i = 0; i < 10; ++i) {
        int randomInt = rand() % 2;
        if (randomInt == 0) {
            Lake_Monster lakeMonster();
            monster = make_unique<Water_Monster>(lakeMonster);
            friends.push_back(monster);
        }
        if (randomInt == 1) {
            Sea_Monster seaMonster();
            monster = make_unique<Water_Monster>(seaMonster);
            friends.push_back(monster);
        }
    }

    // Call get_int_input to prompt the user to choose 1 for meal time, 2 for scare time, or 3 to exit.
    int choice = get_int_input("What time is it?\n 1. Meal Time\n 2. Scare Time\n 3. Exit",
            "Please select a valid option",1,3);
    //Create a loop that runs until the user chooses option 3:
    while (choice != 3) {
        //If 1 is chosen, loop through populated vector and call eat_person on each.
        if (choice == 1) {
            for (int i = 0; i < friends.size(); ++i) {
                friends[i]->eat_person();
            }
        }
        //If 2 is chosen, print message saying "This is how my friends scare:"
        if (choice == 2) {
            cout << "This is how my friends scare: " << endl;
            //Loop through populated vector and call scare method on each pointer
            string message;
            for (int i = 0; i < friends.size(); ++i) {
                //printing return value to console
                message = friends[i]->scare();
            }

            //Print message saying how Champ scares
            cout << "This is how Champ scares: " << endl;
            string champMessage;
            champMessage = champ.scare();
        }

        //Call get_int_input again with the same options as before.
        int choice = get_int_input("What time is it?\n 1. Meal Time\n 2. Scare Time\n 3. Exit",
                                   "Please select a valid option",1,3);
    }
}

void player_mode() {
    vector<unique_ptr<Water_Monster>> monsters;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        if (rand() % 2) {
            monsters.push_back(make_unique<Lake_Monster>());
        } else {
            monsters.push_back(make_unique<Sea_Monster>());
        }
    }
    int index = get_int_input("Enter a number from 0 to " + to_string(monsters.size()-1) + ": ",
                            "Invalid input. Try again: ",
                            0,
                            monsters.size()-1);
    cout << "The monster approaches: " << monsters[index]->scare() << endl;
    int choice = get_int_input("Choose a number between 1 and 3: ",
                             "Invalid input. Pick a number from 1 to 3: ",
                             1,
                             3);
    if (rand() % 3 + 1 == choice) {
        cout << "You were lucky and beat the monster!" << endl;
        monsters.erase(monsters.begin() + index);
    } else {
        cout << "The monster ate you!" << endl;
        monsters[index]->eat_person();
    }
}