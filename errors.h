#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "set.h"
#include "helpfunct.h"

#define LENGTH_COMMAND 13
#define LENGTH_SET 4
#define MAX_NUM 127
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define TEN 10

/*The method receives a pointer to a character array and six more pointers to character arrays for the "set". 
The method also completes sanity checks to check that the user has entered valid input, 
if the user has entered invalid input the method will return an error message. 
If the user entered valid input, the method does nothing.*/
int check_errors(char * str, set * SETA, set * SETB, set * SETC, set * SETD, set * SETE, set * SETF);

/*The method compares the input the user entered with what he is supposed to enter, 
there are 7 possible options the user can enter.*/
int chek_name(char * name);

/*The method compares the input "SET" that the user entered and what he is supposed to enter, 
there are 6 possible options that the user can enter.*/
int check_set(char * s);



#endif

