#include "Critter.hh"
#include "Simulation.hh"
Critter::Critter(Point position) : _position(position) {}
Point Critter::get_position() const { return _position; }
void Critter::Move() {
  Point newPos = Simulation::get_adjacent_position(_position);
  if(newPos != Point(-1,-1)){
      _position = newPos;
  }
}