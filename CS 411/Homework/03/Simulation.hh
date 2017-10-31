#ifndef __SIMULATION__
#define __SIMULATION__

#include "Ant.hh"
#include "Doodlebug.hh"
#include <vector>

//Forward declarations due to circular dependency...
class Doodlebug;
class Ant;

class Simulation{
private:
  static std::vector<Ant> _ants;
  static std::vector<Doodlebug> _doodlebugs;
  static Point get_valid_position();

public:
    Simulation();
    void Run();

    static std::vector<Ant> get_ants();
    static std::vector<Doodlebug> get_doodlebugs();

    static void kill_ant(const Point);
    static Point get_adjacent_position(const Point);
};
#endif