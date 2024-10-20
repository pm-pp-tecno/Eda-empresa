all: main.o empresa.o cargo.o empleado.o organigrama.o
	g++ -o programa.bin main.o empresa.o cargo.o empleado.o organigrama.o
main.o: main.c empresa.h cargo.h empleado.h organigrama.h
	g++ -c main.c
empresa.o: empresa.c empresa.h cargo.h empleado.h
	g++ -c empresa.c
cargo.o: cargo.c cargo.h empleado.h empresa.h
	g++ -c cargo.c
empleado.o: empleado.c empleado.h
	g++ -c empleado.c
organigrama.o: organigrama.c organigrama.h cargo.h empresa.h
	g++ -c organigrama.c
clean:
	rm *.o
	rm programa.bin