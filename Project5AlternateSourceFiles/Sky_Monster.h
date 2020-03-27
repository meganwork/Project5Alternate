#ifndef PROJECT5ALTERNATE_SKY_MONSTER_H
#define PROJECT5ALTERNATE_SKY_MONSTER_H
#include <string>

class Sky_Monster {
public:
    /**
     * Requires: nothing
     * Modifies:
     * Effects:
     */
    Sky_Monster();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
     */
    virtual ~Sky_Monster() = default;

    /**
     * Requires: nothing
     * Modifies: number of wings
     * Effects: calls set_number_people_eaten with npe
     */
    explicit Sky_Monster(int wings);
    /**
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns number_people_eaten
        */
    virtual int get_number_of_wings() const;

    /**
     * Requires: nothing
     * Modifies: number_people_eaten 
     * Effects: sets number_people_eaten to npe if npe is in range
     *          0-100. Otherwise sets number_people_eaten to 100.
     */
    void set_number_of_wings(int wings);

    void growth_spurt(int wings);

    // pure virtual method to return a scary string
    //dont include in the cpp
    virtual std::string scare() = 0;

    static const int MIN_WINGS = 2;
    static const int MAX_NUMBER_WINGS = 200;
protected:
    int number_wings;
};


#endif //PROJECT5ALTERNATE_SKY_MONSTER_H
