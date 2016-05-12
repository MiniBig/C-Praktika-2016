#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
				   
int size = 6;	   
void printArr(int mass[],int sizu) {
	int i;
	printf("\n%d: ", sizu);
	for (i = 0; i <sizu; i++)
	{
		printf("%d, ", mass[i]);
	}
	printf("\n");
}

void del45(int *mass,int size) 
{
	int i,j,del,n=0;
	printf("\nDelete entered number: ");
	scanf("%d",&del);

	for (i = 0; i <= size; i++)
	{
		if (mass[i] == del)
		{
			for (j = i; j < size; j++)
			{
				mass[j] = mass[j + 1];
				
			}
		}
		else
			n++;
	}
	if (n > size) 
	{
		printf(" not found\n ");
	}

	printArr(mass, size);
}

void place17(int *mass,int size) {
	int i, j, del;
	int *arr = (int *)calloc(size, sizeof(int *));
	for (i = 0; i < size-1; i++)
	{
		arr[i] = mass[i];
	}

	printf("\nPlace entered number to end: ");
	scanf("%d", &del);

	for (i = 0; i <= size; i++)
	{
		if (i == 6) {
			int const sk = i-1;
			arr[sk] = del;
			printf("mass[%d] = %d", i, arr[sk]);
		}
	}
	for (i = 0; i < size; i++)
	{
		mass[i] = arr[i];
	}

	printArr(mass, size);
}

void replace73(int *mass,int size) {
	int i,del,del2,n=0;
	printf("\nPlace entered number to replace: ");
	scanf("%d", &del);
	printf("\nReplace with: ");
	scanf("%d", &del2);
	for (i = 0; i < size; i++)
	{
		if (mass[i] == del)
		{
			mass[i] = del2;
		}
		else
			n++;
	}
	if (n == 6) 
	{
		printf(" not found \n");
	}
	printArr(mass, size);
}

int main()
{
	int i, j;
	int *mass = (int *)calloc(size , sizeof(int));
	
	mass[0] = 45;
	mass[1] = 18;
	mass[2] = 10;
	mass[3] = 73;
	mass[4] = 6;
	mass[5] = 19;

	for (i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}

	printf("\n");

	del45(mass,size);
	printf("%d",mass);

	place17(mass, size);
	replace73(mass, size);
	
	_getch();
    return 0;
}