APP = main.cpp
DEP = kmeans.cpp
EXECUTABLE = program

install: 
	g++ -o $(EXECUTABLE) $(APP) $(DEP) -std=c++11 -I /usr/include/eigen3/ -O3
