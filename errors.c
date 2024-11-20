#include "errors.h"

/*A function that receives a command and SETS if there are errors sends alerts, otherwise sends a call to the function*/
int check_errors(char * str, set * SETA, set * SETB, set * SETC, set * SETD, set * SETE, set * SETF)
{
	/*Declaration of variables*/
	int num, i, j, n, n1, n2, temp, comma;
	char * numbers;
	char functname[LENGTH_COMMAND+1];
	char sets[FIVE];
	set * set_numbers[SIX];
	set_numbers[0] = SETA;
	set_numbers[1] = SETB;
	set_numbers[TWO] = SETC;
	set_numbers[THREE] = SETD;
	set_numbers[FOUR] = SETE;
	set_numbers[FIVE] = SETF;

    	i = 0;
	j = 0;
	temp = 0;
	comma = 0;

	while(str[i] != '\0' && isspace(str[i]))/*As long as we haven't reached the end of a string, move forward.*/
	{
		i++;
	}

	if(str[i] == '\0')/*If we reached the end of a string before a command was given print the printout.*/
	{
		printf("no command was issued\n");
		return -1;
	}

    
   	 while (str[i] != '\0' && j<=LENGTH_COMMAND && !isspace(str[i]) && str[i] != ',') /*As long as everything is ok, move forward*/
	{
		functname[j] = str[i];
       		i++;
		j++;
        }
    	
	functname[j] = '\0'; /* הוספת תו סיום למחרוזת*/

	num = chek_name(functname);/*Send the name of the command to chek_name.*/
	
	if(num == 0)/*If I don't have any command that matches the commands given in the code*/
	{
		printf("Undefined command name\n");
		return -1;
	}

	if(num == SEVEN)/*If the command is stop*/
	{
		while(str[i] != '\0' && isspace(str[i]))
		{
			i++;
		}

		if(str[i] != '\0')
		{
			printf("Extraneous text after end of command\n");
			return -1;
		}
			
		stop();
		return 0;
	}

	while(str[i] != '\0' && isspace(str[i]))/*As long as everything is ok, move forward*/
	{
		i++;
	}

	/*Two "if" tests that check normality for continued input*/
	if(str[i] == ',')
	{
		printf("Illegal comma\n");
		return -1;
		
	}
	
	if(str[i] == '\0')
	{
		printf("Missimg parameter\n");
		return -1;
	}

	j = 0;
	while(str[i] != '\0' && j<=LENGTH_SET-1 && !isspace(str[i]) && str[i]!= ',' )/*As long as everything is ok, move forward*/
	{
		sets[j] = str[i];
		i++;
		j++;
	}

	sets[j] = '\0';
	
	/*Test on the first parameter*/
	n = check_set(sets);/*Checking which "set" they sent*/

	if(n == 0)/*If they sent a "set" that does not exist in the code*/
	{
		printf("Undefined set name\n");
		return -1;
	}

	while(str[i] != '\0' && isspace(str[i]))
	{
		i++;
	}
	
	
	if(num == TWO)/*If the command is print_set*/
	{
		while(str[i] != '\0' && isspace(str[i]))
		{
			i++;
		}

		if(str[i] != '\0')
		{
			printf("Extraneous text after end of command\n");
			return -1;
		}

		if(n == ONE)/*if the "set" is SETA*/
			print_set(SETA);
		if(n == TWO)/*if the "set" is SETB*/
			print_set(SETB);
		if(n == THREE)/*if the "set" is SETC*/
			print_set(SETC);
		if(n == FOUR)/*if the "set" is SETD*/
			print_set(SETD);
		if(n == FIVE)/*if the "set" is SETE*/
			print_set(SETE);
		if(n == SIX)/*if the "set" is SETF*/
			print_set(SETF);
		return 0;
	}

	while(str[i] != '\0' && isspace(str[i]))
	{
		i++;
	}

	/*Two "if" tests that check normality for continued input*/
	if(str[i] == '\0')
	{
		printf("Missimg parameter\n");
		return -1;
	}	
	
	if(str[i] != ',')
	{
		printf("Missing comma\n");
		return -1;
	}

	if(num == 1)/*If the command is read_set*/
	{
		numbers = str + i -1;
		j=0;

		while(str[i] != '\0' && isspace(str[i]))
		{
			i++;
		}

		while(str[i] != '\0' && str[i] != '-')/*As long as we haven't reached the end of the string*/
		{
			while(str[i]>='0' && str[i] <='9')/*As long as there are digits, in case the number is not single digit*/
			{
				temp *= TEN;/*Adds the digit to the number*/
				temp += str[i] -'0';
				i++;
			}

			/*three "if" tests that check normality for continued input*/
			if(temp > MAX_NUM || (str[i] == '-' && str[i+1] !='1'))
			{
				printf("Invalid set member – value out of range\n");
				return -1;
			}

			if(str[i] == '\0')
			{
				printf("List of set members is not terminated correctly\n");
				return -1;
			}

			if((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != ',')	
			{
				printf("Invalid set member – not an integer\n");
				return -1;
			}

			/*Checks that there are not two commas one after the other*/
			while(isspace(str[i]) || str[i] == ',')
			{
				if(str[i] == ',')
					comma++;
				i++;
			}
			if(comma > 1)
			{

				printf("Multiple consecutive commas\n");
				return -1;
			}
			temp = 0;
			comma = 0;
		}
		

		if(str[i] == '-' && str[i+1] !='1')/*Checks that there are not two commas one after the other*/
		{
			printf("Invalid set member – value out of range\n");
			return -1;
		}

		if(str[i] == '-' && str[i+1] == '1')/*if terminated the character string*/
		{	

			while(str[i] != '\0' && isspace(str[i]))
			{
				i++;
			}

			if(str[i+2] != '\0')
			{
				printf("List of set members is not terminated correctly\n");
				return -1;
			}
			if(n == ONE)/*if the "set" is SETA*/
				read_set(SETA, numbers);
			if(n == TWO)/*if the "set" is SETB*/
				read_set(SETB, numbers);
			if(n == THREE)/*if the "set" is SETC*/
				read_set(SETC, numbers);
			if(n == FOUR)/*if the "set" is SETD*/
				read_set(SETD, numbers);
			if(n == FIVE)/*if the "set" is SETE*/
				read_set(SETE, numbers);
			if(n == SIX)/*if the "set" is SETF*/
				read_set(SETF, numbers);
			return 0;
		}
	}


	if(num >=THREE && num <= SIX)/*If the command is union_set or intersect_set or sub_set or symdiff_set */
    	{
       	 	j=0;
        	i++;
		while(str[i] != '\0' && isspace(str[i]))
		{
			i++;
		}

		/*Two "if" tests that check normality for continued input*/		
		if(str[i] == '\0')
		{
			printf("Missimg parameter\n");
			return -1;
		}

		if(str[i] == ',')
		{
			printf("Multiple consecutive commas\n");
			return -1;
		}

		while(str[i] != '\0' && j<=LENGTH_SET && !isspace(str[i]) && str[i]!= ',' )/*As long as everything is ok, move forward*/
		{
		    sets[j] = str[i];
		    i++;
		    j++;
		}

		sets[j] = '\0';
		/*Test on the second parameter*/
		n1 = check_set(sets);

		if(n1 == 0)/*If there is no name of "set"*/
		{
		    printf("Undefined set name\n");
		    return -1;
		}

		while(str[i] != '\0' && isspace(str[i]))
		{
		    i++;
		}
	    
		if(str[i] != ',')/*"if" tests that check normality for continued input*/
		{
		    printf("Missing comma\n");
		    return -1;
		}


		j=0;
		i++;
		while(str[i] != '\0' && isspace(str[i]))
		{
		    i++;
		}

		if(str[i] == '\0')/*"if" tests that check normality for continued input*/
		{
			printf("Missimg parameter\n");
			return -1;
		}

		if(str[i] == ',')/*"if" tests that check normality for continued input*/
		{
			printf("Multiple consecutive commas\n");
			return -1;
		}

		while(str[i] != '\0' && j<=LENGTH_SET && !isspace(str[i]) && str[i]!= ',' )/*As long as everything is ok, move forward*/
		{
		    sets[j] = str[i];
		    i++;
		    j++;
		}

		sets[j] = '\0';

		/*Test on the third parameter*/
		n2 = check_set(sets);

		if(n2 == 0)/*If there is no name of "set"*/
		{
		    printf("Undefined set name\n");
		    return -1;
		}

		while(str[i] != '\0' && isspace(str[i]))
		{
		    i++;
		}
	    
		if(str[i] != '\0')/*"if" tests that check normality for continued input*/
		{
		    printf("Extraneous text after end of command\n");
		    return -1;
		}

		if(num == THREE)/*If the command is union_set*/
		{
			union_set(set_numbers[n-1], set_numbers[n1-1], set_numbers[n2-1]);/*Sends to the method with the parameters*/
		}

		if(num == FOUR)/*If the command is intersect_set*/
		{
			intersect_set(set_numbers[n-1], set_numbers[n1-1], set_numbers[n2-1]);/*Sends to the method with the parameters*/
		}

		if(num == FIVE)/*If the command is set_numbers*/
		{
			sub_set(set_numbers[n-1], set_numbers[n1-1], set_numbers[n2-1]);/*Sends to the method with the parameters*/
		}

		if(num == SIX)/*If the command is symdiff_set*/
		{
			symdiff_set(set_numbers[n-1], set_numbers[n1-1], set_numbers[n2-1]);/*Sends to the method with the parameters*/
		}
	
	return 0;
	}
	
	return -1;
}

/*The function checks which of the methods offered in the entered user code.*/
int chek_name(char * name)
{
	if (strcmp(name, "read_set") == 0) 
		return ONE;
	if (strcmp(name, "print_set") == 0) 
		return TWO;
	if (strcmp(name, "union_set") == 0) 
		return THREE;
	if (strcmp(name, "intersect_set") == 0) 
		return FOUR;
	if (strcmp(name, "sub_set") == 0) 
		return FIVE;
	if (strcmp(name, "symdiff_set") == 0) 
		return SIX;
	if (strcmp(name, "stop") == 0) 
		return SEVEN; 
	return 0; 
}

/*The function checks which parameters the user entered*/
int check_set(char * s)
{
	if (strcmp(s, "SETA") == 0)	
		return ONE;
	if (strcmp(s, "SETB") == 0) 
		return TWO;
	if (strcmp(s, "SETC") == 0) 
		return THREE;
	if (strcmp(s, "SETD") == 0) 
		return FOUR;
	if (strcmp(s, "SETE") == 0) 
		return FIVE;
	if (strcmp(s, "SETF") == 0) 
		return SIX;
	return 0;
}
