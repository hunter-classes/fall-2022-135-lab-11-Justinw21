main: main.o Profile.o Network.o
	g++ -o main -std=c++11 main.o Profile.o Network.o

tests: tests.o Profile.o Network.o
	g++ -o tests -std=c++11 tests.o Profile.o Network.o

clean: 
	rm -f a.out tests main

main.o: main.cpp Profile.hpp Network.hpp Profile.cpp Network.cpp
	g++ -c -std=c++11 main.cpp Profile.cpp Network.cpp

tests.o: tests.cpp Profile.hpp Network.hpp Profile.cpp Network.cpp
	g++ -c -std=c++11 tests.cpp Profile.cpp Network.cpp

Profile.o: Profile.cpp Profile.hpp
	g++ -c -std=c++11 Profile.cpp

Network.o: Network.cpp Network.hpp 
	g++ -c -std=c++11 Network.cpp Profile.cpp

