# Classes
Simulation.hpp
    - static State2D
    - static get_state()
    - Run()
Critter.hpp
    - Position
    - StepsSinceBreed
    - 
    - Move()
    - Survival() -> StepsSinceBreed++

Ant.hpp: Critter.hpp
    - 
    - Move() -> Super._Move()
    - Survival() -> 3 turns to breed
Doodlebug.hpp: Critter.hpp
    - StepsSinceFeed
    - 
    - Move() -> Eat ant, else Super._Move()
    - Survival() -> 8 turns to breed; 3 to starve; StepsSinceFeed++