#include "Simulation.hh"
std::vector<Ant> Simulation::_ants;
std::vector<Doodlebug> Simulation::_doodlebugs;

Simulation::Simulation() {
  const int NUM_ANTS = 100;
  const int NUM_DOODLEBUGS = 5;

  for (int i = 0; i < NUM_ANTS; i++) {
    Ant to_insert = Ant(get_valid_position());
    Simulation::_ants.push_back(to_insert);
  }
  for (int i = 0; i < NUM_DOODLEBUGS; i++) {
    Doodlebug to_insert = Doodlebug(get_valid_position());
    Simulation::_doodlebugs.push_back(to_insert);
  }
}
void Simulation::Run() {
    for(auto &bug: _doodlebugs){
        bug.Move();
    }
}
Point Simulation::get_valid_position() {
  // TODO: Implement me!
  return Point(1, 1);
}

void Simulation::kill_ant(Point position) {
  auto it = std::find(_ants.begin(), _ants.end(), position);
  if (it != _ants.end()) {
    _ants.erase(it);
  }
}
Point Simulation::get_adjacent_position(const Point position){
  // This is not pretty
  // But neither is anything in grid-based game design

  // Right, Left, Down, Up
  Point _position = position;
  bool candidates[] = {true, true, true, true};

  for (Doodlebug &bug : Simulation::get_doodlebugs()) {
    Point otherPosition = bug.get_position();
    if (otherPosition.X == _position.X + 1 && otherPosition.Y == _position.Y) {
      candidates[0] = false;
    }
    if (otherPosition.X == _position.X - 1 && otherPosition.Y == _position.Y) {
      candidates[1] = false;
    }
    if (otherPosition.X == _position.X && otherPosition.Y == _position.Y + 1) {
      candidates[2] = false;
    }
    if (otherPosition.X == _position.X && otherPosition.Y == _position.Y - 1) {
      candidates[3] = false;
    }
  }
  for (Ant &ant : Simulation::get_ants()) {
    Point otherPosition = ant.get_position();
    if (otherPosition.X == _position.X + 1 && otherPosition.Y == _position.Y) {
      candidates[0] = false;
    }
    if (otherPosition.X == _position.X - 1 && otherPosition.Y == _position.Y) {
      candidates[1] = false;
    }
    if (otherPosition.X == _position.X && otherPosition.Y == _position.Y + 1) {
      candidates[2] = false;
    }
    if (otherPosition.X == _position.X && otherPosition.Y == _position.Y - 1) {
      candidates[3] = false;
    }
  }
  if (candidates[0]) {
    _position.X++;
    return _position;
  }
  if (candidates[1]) {
    _position.X--;
    return _position;
  }
  if (candidates[2]) {
    _position.Y++;
    return _position;
  }
  if (candidates[3]) {
    _position.Y--;
    return _position;
  }
  return Point(-1,-1);
}

std::vector<Ant> Simulation::get_ants() { return _ants; }
std::vector<Doodlebug> Simulation::get_doodlebugs() { return _doodlebugs; }