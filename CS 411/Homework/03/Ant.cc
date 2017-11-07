#include "Ant.hh"
Ant::Ant(Point position) : Critter(position, false) {}
void Ant::Move() { Critter::Move(); }
bool Ant::Survival() {
  if (_stepsSinceBreeding >= 3) {
    Point childPosition = Simulation::get_adjacent_position(_position);
    if (childPosition != Point(-1, -1)) {
      Simulation::set_state(childPosition, new Ant(childPosition));
      Simulation::ant_born();
      _stepsSinceBreeding = 0;
      return true;
    }
  }
  _stepsSinceBreeding++;
  return true;
}
bool operator==(const Ant &a, const Point &p) { return a.get_position() == p; }