#include "Simulation.hh"
int main(){
    /* Using two seperate lists instead of a 2D array
     * 1. It allows us to determine which Critters in the simulation are doodlebugs/ants in O(1) time instead of O(n)
     * 2. It keeps the position in the Critter itself, making finding your own position O(1) instead O(n)
     */
    Simulation sim;
    sim.Run();
}