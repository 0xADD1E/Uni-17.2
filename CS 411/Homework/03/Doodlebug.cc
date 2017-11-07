#include "Doodlebug.hh"
Doodlebug::Doodlebug(Point position) : Critter(position, true) {
  _stepsSinceFeeding = 0;
}
void Doodlebug::Move() {
  movement_enabled = false;
  Point candidatePoints[] = {
      Point(_position.X + 1, _position.Y), Point(_position.X - 1, _position.Y),
      Point(_position.X, _position.Y + 1), Point(_position.X, _position.Y - 1)};

  for (int i = 0; i < 4; i++) {
    Point candidate = candidatePoints[i];
    if (candidate.X >= GRID_BOUND || candidate.X < 0 ||
        candidate.Y >= GRID_BOUND || candidate.Y < 0)
      continue;
    Critter *bug = Simulation::get_state(candidate);
    if (bug == nullptr || bug->get_isdoodlebug())
      continue;
    Simulation::kill(candidate);
    Simulation::ant_eaten();
    _position = candidate;
    _stepsSinceFeeding = 0;
    return;
  }
  _stepsSinceFeeding++;
  Critter::Move();
}
bool Doodlebug::Survival() {
  if (_stepsSinceBreeding >= 8) {
    Point childPosition = Simulation::get_adjacent_position(_position);
    if (childPosition != Point(-1, -1)) {
      Simulation::set_state(childPosition, new Doodlebug(childPosition));
      Simulation::doodlebug_born();
      _stepsSinceBreeding = 0;
      return get_saited();
    }
  }
  _stepsSinceBreeding++;
  return get_saited();
}
bool Doodlebug::get_saited() { return _stepsSinceFeeding <= 3; }