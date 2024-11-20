#include "set.h"
#include "helpfunct.h"

/*
The method receives a name of a group and a list of numbers to insert into the group.
 The end of the list is marked by -1
*/
void read_set (set * setx, char * num)
{	
	int i, temp;
	for(i=0; i<SIXTEEN; i++)/*Resets the array - the group*/
	{
		setx -> arr[i] = 0;
	}

	temp = -1;
	i= 0 ;

	while(num[i] != '\0' && num[i] != '-')/*end is -1*/
	{

		while(num[i] == ' ' || num[i] == ',')
		{
			i++;
		}
		
		while(num[i]>='0' && num[i] <='9')/*Saves the number in an auxiliary variable*/
		{
			if(temp == -1)
				temp = 0;
			temp *= TEN;
			temp += num[i] -'0';
			i++;
		}
		
		if(temp != -1)
			if(temp != 0 || num[i-1] != ' ')
				setx -> arr[temp/EIGHT] |= (1 << (temp % EIGHT));/*Updates the corresponding bit in the array to be 1*/
		

		while(num[i] != ',' && num[i] != '-' && num[i] !='\0')
		{
			i++;
		}
		if(num[i] == ',')
			i++;
		
		temp = -1;
	}
}


/*
The method receives a name of a group and prints the members of the group in ascending order,
 a maximum of 16 values ​​in each output line.
*/
void print_set(set * setx)
{
	int i, j, count;
	int b;
	b = 0;
	count =0;

	for(i=0; i<SIXTEEN; i++) /*every index in the array*/
	{
		for(j=0; j<EIGHT; j++) /*every bit in each index*/
		{	
			if((setx -> arr[i] >> j)& 1)/*Checks if the number exists in the array*/
			{
				if(count == SIXTEEN)/*Checks that there are up to 16 numbers in a row*/
				{			
					printf("\n");
					count =0;
				}
			
				printf("%d ", i*EIGHT +j);/*print the number*/
				count ++;
				b = 1;
			}
		}
	}

	if(b == 0)
	printf("%s","The set is empty\n");
	else
	printf("\n"); /*to ensure the output ends cleanly*/
}


/*
The method accepts three groups and performs a union between the first group and the second and enters the third.
*/
void union_set(set * setx, set * sety, set * setz)
{
	int i, j;
	zero(setz);
	for(i=0; i<SIXTEEN; i++) /*every index in the array*/
	{
		for(j=0; j<EIGHT; j++) /*every bit in each index*/
		{	
			setz -> arr[i] |= ((setx -> arr[i] >> j) & 1) << j;/*Adds group A to the array*/
			setz -> arr[i] |= ((sety -> arr[i] >> j) & 1) << j;/*Adds group B to the array*/
		}
	}
}


/*
The method accepts three groups and performs a cut between the first group and the second and enters the third.
*/
void intersect_set(set * setx, set * sety, set * setz)
{
	int i, j;
	zero(setz);
	for(i=0; i<SIXTEEN; i++) /*every index in the array*/
	{
		for(j=0; j<EIGHT; j++) /*every bit in each index*/
		{	
			setz->arr[i] |= ((setx->arr[i] >> j) & (sety->arr[i] >> j)) << j;/*A cutting operation on the groups*/
		}
	}
}


/*
The method accepts three groups and makes a difference between the first group and the second and enters the third.
*/
void sub_set(set * setx, set * sety, set * setz)
{
	set s;
	int i, j;
	zero(setz);
	zero(&s);
	intersect_set(setx, sety, &s);
	for(i=0; i<SIXTEEN; i++) /*every index in the array*/
	{
		for(j=0; j<EIGHT; j++) /*every bit in each index*/
		{
			setz -> arr[i] |= ((setx -> arr[i] >> j & 1)^(s.arr[i] >> j & 1)) << j;/*Makes a difference between the groups*/

		}
	}
}


/*
The method accepts three groups and performs a symmetrical difference between the first group
 and the second and enters the third.
*/
void symdiff_set(set * setx, set * sety, set * setz)
{
	set s1,s2,s3;
	int i, j;
	zero(setz);
	zero(&s1);
	zero(&s2);
	zero(&s3);
	union_set(setx, sety, &s1);
	intersect_set(setx, sety, &s2);
	sub_set(&s1, &s2, &s3);
	for(i=0; i<SIXTEEN; i++) /*every index in the array*/
	{
		for(j=0; j<EIGHT; j++) /*every bit in each index*/
		{	
			setz -> arr[i] |= ((s3.arr[i] >> j) & 1) << j;/*Performs a symmetrical difference on the groups*/
		}
	}
}


/*
The method results in an immediate termination of the program.
*/
void stop()
{
	exit(0);/*Exit the program*/
}
