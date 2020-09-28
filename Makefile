EXE := main_c main_cpp

CVER := -std=c11
CXXVER := -std=c++11

OPTS := -Wall -Wextra -pedantic -pedantic-errors

all : $(EXE)
	@echo C and C++ examples built
	@echo Running main_c
	./main_c
	@echo Running main_cpp
	./main_cpp

main_cpp : main.cpp cube.hpp libclasses.a Makefile
	@echo Linking a C++ program with libclasses.a
	$(CXX) $(CXXVER) $(OPTS) -o $@ $< -L. -lclasses

main_c : main.c cube.h libclasses.a Makefile
	@echo Linking a C program with libclasses.a and the C++ standard library
	$(CC) $(CVER) $(OPTS) -o $@ $< -L. -lclasses -lstdc++

libclasses.a : cube.o Makefile
	@echo Creating a static library of C++ classes and C functions
	$(AR) rcu $@ $<

%.o : %.cpp %.hpp Makefile
	$(CXX) $(CXXVER) $(OPTS) -c -o $@ $<

clean:
	rm -f $(EXE) *.o *.a
