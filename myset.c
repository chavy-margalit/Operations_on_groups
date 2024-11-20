#include "set.h"
#include "helpfunct.h"
#include "errors.h"

/*
	name: chavy margalit & tehila durlacher
	date: 08/06/2024

*/


/*The main program, the program sends to other functions that check the data and do what is needed with them according to the data and the question.*/
int main()
{	
	/*Declaration of variables*/
	char * str;
	int d;

	set SETA, SETB, SETC, SETD, SETE, SETF;
	initial(&SETA, &SETB, &SETC, &SETD, &SETE, &SETF); /*initialization of groups*/

	d=0;

	/*A loop for reading commands from the user until STOP or EOF is pressed*/
	while(d == -1 || d == 0)
	{
		printf("\nPlease enter a command\n");
		str = readCommand();
		d = check_errors(str, &SETA, &SETB, &SETC, &SETD, &SETE, &SETF);
	}
	
	return 0;
}
