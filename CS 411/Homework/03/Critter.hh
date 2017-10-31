#ifndef __CRITTER__
#define __CRITTER__

#include "Point.hh"

class Critter{
protected:
    Point _position;
    int _stepsSinceBreeding;
public:
    Critter(Point);
    virtual void Survival() = 0;
    virtual void Move();

    Point get_position() const;
};
#endif