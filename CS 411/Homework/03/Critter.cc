#include "Critter.hh"
#include "Simulation.hh"
Critter::Critter(Point position, bool isDoodlebug)
    : _position(position), _stepsSinceBreeding(0), _isDoodlebug(isDoodlebug) {}
Critter::~Critter() {}
Point Critter::get_position() const { return _position; }
bool Critter::get_isdoodlebug() const { return _isDoodlebug; }
void Critter::Move() {
  movement_enabled = false;
  Point newPos = Simulation::get_adjacent_position(_position);
  if (newPos != Point(-1, -1)) {
    _position = newPos;
  }
}
bool Critter::can_move() const { return movement_enabled; }
void Critter::let_move() { movement_enabled = true; }