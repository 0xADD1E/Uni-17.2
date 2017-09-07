all: DayOfYear.o main.cpp
	g++ -Wall -g3 -std=c++11 -o hw01 DayOfYear.o main.cpp
DayOfYear.o: DayOfYear.cpp DayOfYear.hpp
	g++ -Wall -g3 -std=c++11 -c DayOfYear.cpp DayOfYear.hpp
clean:
	rm -f $(wildcard *.hpp.gch)
	rm -f $(wildcard *.o)
	rm -f hw01
	rm -rf hw01.dSYM
test: all
	./hw01
handin: all clean
		# Set of tasks for handing things in automagically
		scp $(wildcard *.hpp) kira:~/tmp/
		scp $(wildcard *.cpp) kira:~/tmp/
		scp Makefile kira:~/tmp/
		ssh kira "cd ~/tmp/ && make all && make clean &&\
			~cs411/bin/handin -y 1 * &&\
			rm -f * ;\
			true"
