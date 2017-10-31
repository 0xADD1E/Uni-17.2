CC = g++
CFLAGS = -Wall -std=c++11
all: main.o Ant.o Critter.o Doodlebug.o Point.o Simulation.o
	$(CC) $(CFLAGS) main.o ant.o critter.o doodlebug.o point.o simulation.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
Ant.o: Ant.cc Ant.hh
	$(CC) $(CFLAGS) -c Ant.cc
Critter.o: Critter.cc Critter.hh
	$(CC) $(CFLAGS) -c Critter.cc
Doodlebug.o: Doodlebug.cc Doodlebug.hh
	$(CC) $(CFLAGS) -c Doodlebug.cc
Point.o: Point.cc Point.hh
	$(CC) $(CFLAGS) -c Point.cc
Simulation: Simulation.cc Simulation.hh
	$(CC) $(CFLAGS) -c Simulation.cc
clean:
	rm -f $(wildcard *.o)