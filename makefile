all: limpiar compilar enlazar ejecutar

limpiar:


compilar:

	g++ -c *.cpp

enlazar:

	g++ *.o -o practica

ejecutar:

	./practica