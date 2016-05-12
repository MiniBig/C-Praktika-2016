// III_Uzduotis.cpp : Defines the entry point for the console application.
//
#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void IIIa(int size) {
	int n = size;
	int i = 0;
	int *mass = (int *)malloc(size * sizeof(int));

	for (i = 0; i < n; i++)
	{
		mass[i] = rand() % 185 + 1;
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("\nmass[%d] ID:%d", i,mass[i]);
	}
	free(mass);
}

void IIIb(int size) {
	int n = size;
	int i = 0;
	int *mass =  (int *)calloc(size, sizeof(int));

	for (i = 0; i < n; i++)
	{
		printf("\nmass[%d] ID:%d", i, mass[i]);
	}
	free(mass);
}

void IIIc(int n){
	char *zdz;
	char *zdzdz;
	zdz   = (char *)malloc(n * sizeof(char));
	zdzdz = (char *)malloc(n * sizeof(char));
	printf("\nEnter first word :");
	scanf(" %s", zdz);
	printf("\nEnter second word :");
	scanf(" %s", zdzdz);

	char *pav;
	pav = (char *)malloc(n * sizeof(char));

	strcpy(pav , zdz);
	strcat(pav, " ");
	pav = (char *)realloc(pav,n*2);
	strcat(pav, zdzdz);
	printf("\n%s",pav);

	free(pav);
}


int main()
{
	int sk;
	int chos = 0;
	printf("\n1,2,3 :");
	scanf("%d", &chos);

	switch (chos)
	{
	case 1:
		printf("\nEnter size of array :");
		scanf("%d",&sk);
		IIIa(sk);
		break;
	case 2:
		printf("\nEnter size of array :");
		scanf("%d", &sk);
		IIIb(sk);
		break;
	case 3:		
		IIIc(65);
		break;
	default:
		printf("top kek");
		break;
	};
	
	_getch();
	return 0;
}