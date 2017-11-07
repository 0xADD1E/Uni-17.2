#ifndef __DOODLEBUG__
#define __DOODLEBUG__

#include "Critter.hh"
#include "Simulation.hh"

class Doodlebug : public Critter {
private:
    int _stepsSinceFeeding;
    bool get_saited();
public:
    Doodlebug(Point);

    void Move();
    bool Survival();
};
bool operator==(const Doodlebug &, const Point &);
#endif