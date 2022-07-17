Compile:
	g++ -pedantic-errors -std=c++20 main.cpp -o main -lncurses
	./main
	rm -f main

test:
	g++ -pedantic-errors -std=c++20 Test.cpp -o t -lncurses
	./t
	rm -f t 
