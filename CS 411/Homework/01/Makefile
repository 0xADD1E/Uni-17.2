OUTFILE = hw01
all: DayOfYear.o main.cpp
	g++ -Wall -g3 -std=c++11 -o $(OUTFILE) DayOfYear.o main.cpp
DayOfYear.o: DayOfYear.cpp DayOfYear.hpp
	g++ -Wall -g3 -std=c++11 -c DayOfYear.cpp DayOfYear.hpp
clean:
	rm -f  $(wildcard *.hpp.gch)
	rm -f  $(wildcard *.o)
	rm -rf $(wildcard *.dSYM)
	rm -f  $(OUTFILE)
test: all
	cat infile | ./$(OUTFILE)
handin: all clean
		# Set of tasks for handing things in automagically
		scp $(wildcard *.hpp) kira:~/tmp/
		scp $(wildcard *.cpp) kira:~/tmp/
		scp Makefile kira:~/tmp/
		ssh kira "cd ~/tmp/ && make all && make clean &&\
			~cs411/bin/handin -y 1 * &&\
			rm -f * ;\
			true"
