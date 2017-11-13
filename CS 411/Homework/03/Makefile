CXX = g++
CXXFLAGS = -Wall -std=c++11 -Wno-c++11-extensions -O3 #clang is very loud when you use cpp11
all: hw03
hw03: main.o Ant.o Critter.o Doodlebug.o Point.o Simulation.o
	$(CXX) $(CXXFLAGS) -o hw03 main.o ant.o critter.o doodlebug.o point.o simulation.o
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -o main.o -c main.cpp
Ant.o: Ant.cc Ant.hh
	$(CXX) $(CXXFLAGS) -o ant.o -c Ant.cc
Critter.o: Critter.cc Critter.hh
	$(CXX) $(CXXFLAGS) -o critter.o -c Critter.cc
Doodlebug.o: Doodlebug.cc Doodlebug.hh
	$(CXX) $(CXXFLAGS) -o doodlebug.o -c Doodlebug.cc
Point.o: Point.cc Point.hh
	$(CXX) $(CXXFLAGS) -o point.o -c Point.cc
Simulation.o: Simulation.cc Simulation.hh
	$(CXX) $(CXXFLAGS) -o simulation.o -c Simulation.cc
test: all
	./hw03
clean:
	rm -f $(wildcard *.o)
	rm -f hw03
handin: all clean
		# Set of tasks for handing things in automagically
		scp $(wildcard *.hpp) $(wildcard *.hh) kira:~/tmp/
		scp $(wildcard *.cpp) $(wildcard *.cc) kira:~/tmp/
		scp Makefile kira:~/tmp/
		ssh kira "cd ~/tmp/ &&\
			make all &&\
			make clean &&\
			~cs411/bin/handin -y 3 * &&\
			rm -f * ;\
			true"
