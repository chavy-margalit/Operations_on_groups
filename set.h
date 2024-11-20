#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EIGHT 8
#define TEN 10
#define SIXTEEN 16

/*Building a set structure that contains an array of size 16 char 
and each bit in the array represents a number between 0 and 1.*/
typedef struct{
	unsigned char arr [16];
}set;

/*The method receives a "set" type and a pointer to an array of numbers, 
the method inserts the numbers in the array into the "set" it received*/
void read_set (set * setx, char * num);

/*The method receives a pointer to an array of type "set", 
the method prints all the elements of the array.*/
void print_set(set * setx);

/*The method receives 3 pointers to arrays of type "set", 
the method connects two arrays and unites the groups, 
the method inserts the united array into the third array.*/
void union_set(set * setx, set * sety, set * setz);

/*The method receives 3 pointers to arrays of type "set", 
the method performs a cutting operation - takes only the elements that are in both arrays, 
the method inserts the cut array into the third array.*/
void intersect_set(set * setx, set * sety, set * setz);

/*The method receives 3 pointers to arrays of type "set", 
the method performs a minus operation - subtracts the numbers that are in both arrays, 
the method inserts the array that passed the minus operation into the third array.*/
void sub_set(set * setx, set * sety, set * setz);

/*The method receives 3 pointers to arrays of type "set", 
the method performs a symmetric difference operation between the two arrays, 
the method inserts the array that passed the symmetric difference operation into the third array.*/
void symdiff_set(set * setx, set * sety, set * setz);

/*
The method results in an immediate termination of the program.
*/
void stop();

#endif
