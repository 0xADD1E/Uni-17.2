#include "Critter.hh"
#include "Simulation.hh"
#ifndef __ANT__
#define __ANT__

class Ant: public Critter{
private:
public:
  Ant(Point);

  void Move();
  bool Survival();
};
bool operator==(const Ant &, const Point &);
#endif