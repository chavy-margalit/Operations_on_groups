my_set: set.o myset.o errors.o helpfunct.o
	gcc -ansi -pedantic -Wall set.o myset.o errors.o helpfunct.o -o my_set

set.o: set.c set.h
	gcc -c -ansi -pedantic -Wall set.c -o set.o

myset.o: myset.c 
	gcc -c -ansi -pedantic -Wall myset.c -o myset.o

errors.o: errors.c errors.h
	gcc -c -ansi -pedantic -Wall errors.c -o errors.o

helpfunct.o: helpfunct.c helpfunct.h
	gcc -c -ansi -pedantic -Wall helpfunct.c -o helpfunct.o


