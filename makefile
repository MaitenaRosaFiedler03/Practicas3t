all: limpiar compilar enlazar ejecutar

limpiar:
	rm *.o
	echo "hola"

compilar:

	g++ -c *.cpp

enlazar:

	g++ *.o -o practica

ejecutar:

	./practica
	