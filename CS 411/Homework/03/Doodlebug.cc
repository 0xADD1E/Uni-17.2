#include "Doodlebug.hh"
Doodlebug::Doodlebug(Point position) : Critter(position) {}
void Doodlebug::Move() {
  for (auto const &ant : Simulation::get_ants()) {
    Point otherPosition = ant.get_position();
    if ((otherPosition.X == _position.X + 1 && otherPosition.Y == _position.Y) ||
        (otherPosition.X == _position.X - 1 && otherPosition.Y == _position.Y) ||
        (otherPosition.X == _position.X && otherPosition.Y == _position.Y + 1) ||
        (otherPosition.X == _position.X && otherPosition.Y == _position.Y - 1)) {
      _position = otherPosition;
      _stepsSinceFeeding = 0;
      Simulation::kill_ant(otherPosition);
      return;
    }
  }
  Critter::Move();
}
void Doodlebug::Survival() {
  if (_stepsSinceBreeding >= 8) {
    Point childPosition = Simulation::get_adjacent_position(_position);
    if (childPosition != Point(-1, -1)) {
      Simulation::get_doodlebugs().push_back(Doodlebug(childPosition));
      _stepsSinceBreeding = 0;
      return;
    }
  }
  _stepsSinceBreeding++;
}
bool Doodlebug::get_starved() { return _stepsSinceFeeding > 3; }