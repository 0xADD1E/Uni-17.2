#include "Ant.hh"
Ant::Ant(Point position) : Critter(position) {}
void Ant::Move() { Critter::Move(); }
void Ant::Survival() {
  if (_stepsSinceBreeding >= 3) {
    Point childPosition = Simulation::get_adjacent_position(_position);
    if (childPosition != Point(-1, -1)) {
      Simulation::get_ants().push_back(Ant(childPosition));
      _stepsSinceBreeding = 0;
      return;
    }
  }
  _stepsSinceBreeding++;
}
bool operator==(const Ant &a, const Point &p) { return a.get_position() == p; }