CC=g++
CFLAGS=-Wall -Wextra -Weffc++ -Wold-style-cast -Woverloaded-virtual -std=c++11 -pedantic -Werror -g

all: clean code
	./main 200000 10 0.01 24

code:
	$(CC) $(CFLAGS) main.cc Connection.cc Component.cc Battery.cc Resistor.cc Capacitor.cc -o main

clean:
	rm -rf *.o code
