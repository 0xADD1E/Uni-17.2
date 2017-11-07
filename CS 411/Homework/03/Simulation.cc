#include "Simulation.hh"

Critter *Simulation::_state[GRID_BOUND][GRID_BOUND];

Simulation::Simulation() {
  for (int i = 0; i < N_ANTS; i++) {
    Point position = get_valid_position();
    Ant *to_insert = new Ant(position);
    _state[position.X][position.Y] = to_insert;
  }
  for (int i = 0; i < N_DOODLEBUGS; i++) {
    Point position = get_valid_position();
    Doodlebug *to_insert = new Doodlebug(position);
    _state[position.X][position.Y] = to_insert;
  }
}
void Simulation::Run() {
  srand(0); // TODO: Actually seed
  print_state("Initial State");
  while (true) {
    ants_eaten = 0;
    ants_born = 0;
    doodlebugs_starved = 0;
    doodlebugs_born = 0;
    total_ants = 0;
    total_doodlebugs = 0;

    run_step();
    print_step_stats();
    if (total_ants == 0) {
      std::cout << "No ants remaining" << std::endl
                << "All doodlebugs will starve shortly" << std::endl
                << "Ending simulation to avoid the loneliness" << std::endl;
      break;
    }
    if (total_doodlebugs == 0) {
      std::cout << "No doodlebugs remaining" << std::endl
                << "Ants will proceed to take over the world" << std::endl
                << "Ending simulation to avoid world overpopulation"
                << std::endl;
      break;
    }
  }
}
void Simulation::run_step() {
  for (int i = 0; i < GRID_BOUND; i++) {
    for (int j = 0; j < GRID_BOUND; j++) {
      Critter *bug = _state[i][j];
      if (bug != nullptr) {
        bug->let_move();
      }
    }
  }

  for (int i = 0; i < GRID_BOUND; i++) {
    for (int j = 0; j < GRID_BOUND; j++) {
      Critter *bug = _state[i][j];
      if (bug != nullptr && bug->get_isdoodlebug() && bug->can_move()) {
        bug->Move();
        Point newPosition = bug->get_position();
        _state[i][j] = nullptr;
        _state[newPosition.X][newPosition.Y] = bug;
      }
    }
  }
  print_state("Doodlebug Movement:");

  for (int i = 0; i < GRID_BOUND; i++) {
    for (int j = 0; j < GRID_BOUND; j++) {
      Critter *bug = _state[i][j];
      if (bug != nullptr && !bug->get_isdoodlebug() && bug->can_move()) {
        bug->Move();
        Point newPosition = bug->get_position();
        _state[i][j] = nullptr;
        _state[newPosition.X][newPosition.Y] = bug;
      }
    }
  }
  print_state("Ant Movement:");

  for (int i = 0; i < GRID_BOUND; i++) {
    for (int j = 0; j < GRID_BOUND; j++) {
      Critter *bug = _state[i][j];
      if (bug != nullptr && !bug->Survival()) {
        if (bug->get_isdoodlebug())
          Simulation::doodlebug_starved();
        kill(bug->get_position());
      }
    }
  }
  print_state("Breeding/Starvation:");
}
Point Simulation::get_valid_position() {
  bool isPointAvailable = false;
  Point candidatePosition(0, 0);
  while (!isPointAvailable) {
    candidatePosition = Point(randnum(0, GRID_BOUND), randnum(0, GRID_BOUND));
    isPointAvailable =
        (_state[candidatePosition.X][candidatePosition.Y] == nullptr);
  }
  return candidatePosition;
}

void Simulation::kill(const Point position) {
  delete _state[position.X][position.Y];
  _state[position.X][position.Y] = nullptr;
}
Point Simulation::get_adjacent_position(const Point position) {
  Point _position = position;

  if ((position.X + 1 < GRID_BOUND) &&
      (_state[position.X + 1][position.Y] == nullptr)) {
    _position.X++;
    return _position;
  }
  if ((position.X - 1 >= 0) &&
      (_state[position.X - 1][position.Y] == nullptr)) {
    _position.X--;
    return _position;
  }
  if ((position.Y + 1 < GRID_BOUND) &&
      (_state[position.X][position.Y + 1] == nullptr)) {
    _position.Y++;
    return _position;
  }
  if ((position.Y - 1 >= 0) &&
      (_state[position.X][position.Y - 1] == nullptr)) {
    _position.Y--;
    return _position;
  }
  return Point(-1, -1);
}

Critter *Simulation::get_state(Point position) {
  return _state[position.X][position.Y];
}
void Simulation::set_state(Point position, Critter *bug) {
  _state[position.X][position.Y] = bug;
}

void Simulation::print_step_stats() {
  for (int i = 0; i < GRID_BOUND; i++) {
    for (int j = 0; j < GRID_BOUND; j++) {
      Critter *bug = _state[i][j];
      if (bug != nullptr) {
        if (bug->get_isdoodlebug())
          total_doodlebugs++;
        else
          total_ants++;
      }
    }
  }
  std::cout << "Ants Eaten:         " << ants_eaten << std::endl
            << "Ants Born:          " << ants_born << std::endl
            << "Doodlebugs Starved: " << doodlebugs_starved << std::endl
            << "Doodlebugs Born:    " << doodlebugs_born << std::endl
            << "Total Ants:         " << total_ants << std::endl
            << "Total Doodlebugs:   " << total_doodlebugs << std::endl
            << std::endl;
}
void Simulation::print_state(std::string heading) {
  std::cout << heading << std::endl;
  std::string line = "";
  for (; line.length() < GRID_BOUND + 2; line += '-') {
  }
  std::cout << line << std::endl;
  for (int i = 0; i < GRID_BOUND; i++) {
    std::cout << "|";
    for (int j = 0; j < GRID_BOUND; j++) {
      Critter *bug = _state[i][j];
      if (bug == nullptr) {
        std::cout << " ";
      } else if (bug->get_isdoodlebug()) {
        std::cout << "O";
      } else {
        std::cout << "X";
      }
    }
    std::cout << "|" << std::endl;
  }
  std::cout << line << std::endl;
  std::cout << "Press return to continue";
  std::cin.get();
  std::cout << std::endl;
}
int Simulation::ants_eaten = 0;
int Simulation::ants_born = 0;
int Simulation::doodlebugs_starved = 0;
int Simulation::doodlebugs_born = 0;
int Simulation::total_ants = 0;
int Simulation::total_doodlebugs = 0;
void Simulation::ant_eaten() { ants_eaten++; }
void Simulation::ant_born() { ants_born++; }
void Simulation::doodlebug_starved() { doodlebugs_starved++; }
void Simulation::doodlebug_born() { doodlebugs_born++; }
