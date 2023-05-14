myprj: main.o functions.o
	gcc -o myprj main.o functions.o
main.o: main.c
	gcc -c main.c
functions.o: functions.c header.h
	gcc -c functions.c
clean:
	rm *.o
