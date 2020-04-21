ej10: ej10.o racional.o
	g++ ej10.o racional.o -o ej10

ej10.o: ej10.cpp racional.h
	g++ -c ej10.cpp -o ej10.o

racional.o: racional.cpp racional.h
	g++ -c racional.cpp -o racional.o