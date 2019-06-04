runMovies: movies.cpp main.cpp movies.h
	g++ -o runMovies movies.cpp main.cpp

tests: movies.cpp tests.cpp movies.h tests.h
	g++ -o tests tests.cpp movies.cpp
	./tests
