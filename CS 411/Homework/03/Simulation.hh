#ifndef __SIMULATION__
#define __SIMULATION__

#include "Ant.hh"
#include "Doodlebug.hh"
#include <cstdlib>
#include <iostream>
#include <vector>

#define GRID_BOUND 5
#define N_ANTS 10
#define N_DOODLEBUGS 5

#define randnum(min, max) (rand()%(max-min) + min)

//Forward declarations due to circular dependency...
class Doodlebug;
class Ant;

class Simulation{
private:
  static Critter* _state[GRID_BOUND][GRID_BOUND];
  static void print_state(std::string);
  static void print_step_stats();
  static Point get_valid_position();
  static void run_step();

  //Stats
  static int ants_eaten;
  static int ants_born;
  static int doodlebugs_starved;
  static int doodlebugs_born;
  static int total_ants;
  static int total_doodlebugs;

public:
    Simulation();
    void Run();

    static Critter* get_state(Point);
    static void set_state(Point, Critter*);

    static void kill(const Point);
    static Point get_adjacent_position(const Point);

    static void ant_eaten();
    static void ant_born();
    static void doodlebug_starved();
    static void doodlebug_born();
};
#endif