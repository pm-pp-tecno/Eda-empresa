all: main.o empresa.o cargo.o empleado.o
	g++ -o programa main.o empresa.o cargo.o empleado.o
main.o: main.c empresa.h cargo.h empleado.h
	g++ -c main.c
empresa.o: empresa.c empresa.h cargo.h empleado.h
	g++ -c empresa.c
cargo.o: cargo.c cargo.h empleado.h empresa.h
	g++ -c cargo.c
empleado.o: empleado.c empleado.h
	g++ -c empleado.c
clean:
	rm *.o
	rm programa