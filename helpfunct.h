#ifndef HELPFUNCT_H
#define HELPFUNCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

#define BUFFER_SIZE 100
#define LENGTH_ARR 16

char* get_num(char* input);

/*A method that receives the six "sets" and resets them by sending them to the reset method.*/
void initial(set * SETA, set * SETB, set * SETC, set * SETD, set * SETE, set * SETF);

/*A method that receives a pointer to an array of type "set" and resets it*/
void zero(set * setx);

/*The function receives input from the user and with the help of dynamic memory allocation 
it inserts the characters into an array until it receives a line end character or a string end character. 
Finally it returns the array as a string.*/
char * readCommand();

#endif

