#ifndef __DOODLEBUG__
#define __DOODLEBUG__

#include "Critter.hh"
#include "Simulation.hh"

class Doodlebug : public Critter {
private:
    int _stepsSinceFeeding;
public:
    Doodlebug(Point);

    void Move();
    void Survival();

    bool get_starved();
};
#endif