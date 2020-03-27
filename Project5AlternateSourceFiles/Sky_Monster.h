#ifndef PROJECT5ALTERNATE_SKY_MONSTER_H
#define PROJECT5ALTERNATE_SKY_MONSTER_H
#include <string>

class Sky_Monster {
public:
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: creates a sky_monster with random number of wings
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
     * Effects: calls set_number_of_wings with wings
     */
    explicit Sky_Monster(int wings);
    /**
        * Requires: nothing
        * Modifies: nothing
        * Effects: returns number_of_wings
        */
    virtual int get_number_of_wings() const;

    /**
     * Requires: nothing
     * Modifies: number_of wings 
     * Effects: sets number_of_wings to wings if wings is in range
     *          2-200. Otherwise sets number_of wings to 2 if < 2 or to 200 if > 200.
     */
    void set_number_of_wings(int wings);

    /**
     * Requires: nothing
     * Modifies: number_of_wings
     * Effects: increases number_of_wings by 2
     */
    void growth_spurt(int wings);

    // pure virtual method to return a scary string
    virtual std::string scare() = 0;

    static const int MIN_WINGS = 2;
    static const int MAX_NUMBER_WINGS = 200;
protected:
    int number_wings;
};


#endif //PROJECT5ALTERNATE_SKY_MONSTER_H
