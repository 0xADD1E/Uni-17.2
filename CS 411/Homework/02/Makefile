OUTFILE = hw01
TESTFILE = test.bin
CFLAGS = -Wall -g3 -std=c++11
GTEST_DIR = ./googletest
all: PFAString.o main.cpp
	g++ $(CFLAGS) -o $(OUTFILE) PFAString.o main.cpp
PFAString.o: PFAString.cpp PFAString.hpp
	g++ $(CFLAGS) -c PFAString.cpp
clean:
	rm -f  $(wildcard *.o)
	rm -rf $(wildcard *.dSYM)
	rm -f  $(OUTFILE)
	rm -f  $(TESTFILE)

gtest-all.o: ./googletest/src/gtest-all.cc
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
test: PFAString.o gtest-all.o test.cc
	g++ -Wall -isystem ${GTEST_DIR}/include test.cc PFAString.o gtest-all.o -o $(TESTFILE)
	./test.bin
handin: all clean
		# Set of tasks for handing things in automagically
		scp $(wildcard *.hpp) kira:~/tmp/
		scp $(wildcard *.cpp) kira:~/tmp/
		scp Makefile kira:~/tmp/
		ssh kira "cd ~/tmp/ &&\
			make all &&\
			make clean &&\
			~cs411/bin/handin -y 2 * &&\
			rm -f * ;\
			true"
