#ifndef __CRITTER__
#define __CRITTER__

#include "Point.hh"

class Critter{
protected:
    Point _position;
    int _stepsSinceBreeding;
    bool _isDoodlebug;
    bool movement_enabled;
public:
    Critter(Point, bool);
    virtual ~Critter();
    virtual bool Survival() = 0;
    virtual void Move();

    Point get_position() const;
    bool get_isdoodlebug() const;
    bool can_move() const;
    void let_move();
};
#endif