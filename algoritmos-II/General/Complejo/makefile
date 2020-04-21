# Mi aplicación
app: main.o complejo.o
	g++ main.o complejo.o -o app

# Le digo como se compila c/u y sus dependencias
main.o: main.cpp complejo.h
	g++ -c main.cpp
complejo.o: complejo.cpp complejo.h
	g++ -c complejo.cpp