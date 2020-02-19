### Makefile --- 

## Author: pascaz10@Matilda
## Version: $Id: Makefile,v 0.0 2019/12/17 06:38:13 pascaz10 Exp $
## Keywords: 
## X-URL: 

CC=g++

CFLAGS=-Wall -g

LDFLAGS= 

EXEC= main
SRC= main.cpp airport.cpp csv_parser.cpp tree.cpp profiler.cpp
OBJ= $(SRC=.o)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

all: $(EXEC)

main:  main.o airport.o csv_parser.o tree.o
	$(CC) -o $@ $^ $(LDFLAGS)


airport: airport.cpp airport.hpp
	$(CC) -o $@ $^ $(LDFLAGS)

csv_parser: csv_parser.cpp csv_parser.hpp
	$(CC) -o $@ $^ $(LDFLAGS)

tree: tree.cpp tree.hpp
	$(CC) -o $@ $^ $(LDFLAGS)

profiler: profiler.hpp ptofiler.cpp
	$(CC) -o $@ $^ $(LDFLAGS)



.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

### Makefile ends here
