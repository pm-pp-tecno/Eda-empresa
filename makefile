all: main.o empresa.o 
	g++ -o main main.o empresa.o 
main.o: main.c
	g++ -c main.c
empresa.o: empresa.h empresa.c
	g++ -c empresa.c
clean:
	rm *.o
	rm main

