ej6: ej6.o arreglo.o
	g++ ej6.o arreglo.o -o ej6

ej6.o: ej6.cpp arreglo.h
	g++ -c ej6.cpp -o ej6.o

arreglo.o: arreglo.cpp arreglo.h
	g++ -c arreglo.cpp -o arreglo.o