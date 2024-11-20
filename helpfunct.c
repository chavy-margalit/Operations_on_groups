#include "helpfunct.h"

/*A method that receives the six "sets" and resets them by sending them to the reset method.*/
void initial(set * SETA, set * SETB, set * SETC, set * SETD, set * SETE, set * SETF)
{
		zero(SETA);
		zero(SETB);
		zero(SETC);
		zero(SETD);
		zero(SETE);
		zero(SETF);
}

/*a method that reset*/
void zero(set * setx)
{
	int i;
	for(i=0; i<LENGTH_ARR; i++)
	{
		setx -> arr[i] = 0;
	}
}

/*A function to receive a command from the user*/
char * readCommand() 
{
	int bufferSize, position;
	int c;
	char * temp;
	char * buffer;

	position = 0;
	bufferSize = BUFFER_SIZE; /*The size of the starting character array*/

	buffer =(char *) malloc(bufferSize * sizeof(char)); /* Creating a dynamic array*/

	if (!buffer)  /* The assignment check*/
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	memset(buffer, '\0', sizeof(BUFFER_SIZE));

	while (1) 
	{
		c = getchar(); /*Reading a character from the input*/
		if (c == EOF || c == '\n')  /*Check for end of line or input*/
		{
			if(c == EOF)
			{
				printf("The code should end with a stop() command\n");
				exit(1);
			}
			buffer[position] = '\0'; /* Add a string termination character*/
			break;
		}
		else 
			buffer[position] = c; /* Adding the character to the dynamic array*/

		position++;

			
		if (position >= bufferSize) /* Checking if the character set needs to be increased*/
		{
			bufferSize += BUFFER_SIZE; 
			   
			temp = realloc(buffer, bufferSize * sizeof(char)); /* Saving the new address in a temporary variable*/
			  
			if (temp == NULL)   /* Checking whether the realloc was successful*/
			{
				printf("Memory allocation error\n");
				free(buffer); /* Freeing the memory that encountered the problem*/
				exit(1);
			}
			buffer = temp; /* Transferring the new address to the original array*/
		}
	}
	    return buffer;
}

