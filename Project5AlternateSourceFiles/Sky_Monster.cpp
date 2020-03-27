#include "Sky_Monster.h"

class Sky_Monster {
public:
    /**
     * Requires: nothing
     * Modifies: number_people_eaten 
     * Effects: sets number_people_eaten to random int in range 0-100
     */
    Sky_Monster();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
     */
    virtual ~Water_Monster() = default;

    /**
     * Requires: nothing
     * Modifies: number_people_eaten 
     * Effects: calls set_number_people_eaten with npe
     */
    explicit Water_Monster(int npe);

