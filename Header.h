#pragma once
#define _GNU_SOURCE
#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


void read_words(FILE *f);

struct KOLEGIJA {
	int id;
	char charas[16];
	int inte;
	float flotas;
};

struct KOLEGIJA *mass;
struct KOLEGIJA *arr;


unsigned numDigits(const unsigned n) {
	if (n < 10) return 1;
	return 1 + numDigits(n / 10);
}

bool fileExists(const char* file) {
	struct stat buf;
	return (stat(file, &buf) == 0);
}

int listSize() {
	char line[1000];
	int kek = 0;
	FILE *file;
	file = fopen("duom.txt", "r");

	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	while (fgets(line, sizeof(line), file) != NULL) {
		kek++;
	}
	fclose(file);
	return kek;
}

void fCreate()
{
	
	if (fileExists("duom.txt"))
	{
		printf("File already exists\n");
	}
	else 
	{
		FILE *file;
		file = fopen("duom.txt", "w");

		if (file == NULL)
		{
			printf("Error opening file!\n");
			exit(1);
		}

		fclose(file);
	}
	
}

void fCreateNewData(int n)
{

	int i, len, teger;
	float floater;

	FILE *file;
	file = fopen("duom.txt", "w");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	mass = (struct KOLEGIJA *)calloc(n, sizeof(struct KOLEGIJA));

	for (i = 0; i < n; i++)
	{
		mass[i].id = i;

		// CHAR
		while (true)
		{
			printf("\n%d Enter charas : ", i + 1);
			scanf(" %s", mass[i].charas);

			len = strlen(mass[i].charas);

			if (len < 16) {
				break;
			}
			else
			{
				printf("\nChar too long");
			}
		}


		// INT

		while (true)
		{
			printf("\nEnter inte : ");
			scanf(" %d", &teger);

			if (numDigits(teger) < 10) {
				mass[i].inte = teger;
				teger = 0;
				break;
			}
			else
			{
				printf("\nInteger too long");
				teger = 0;
			}
		}


		// FLOAT
		while (true)
		{
			printf("\nEnter flotas : ");
			scanf(" %f", &floater);

			if (numDigits(floater) < 5) {
				mass[i].flotas = floater;
				break;
			}
			else
			{
				printf("\nFloat too long");
				floater = 0;
			}
		}


	}

	for (i = 0; i < n; i++)
	{
		//printf("\nID:%d Student name : %s\t Course : %s\t Grade:%d ", mass[i]., mass[i].name, mass[i].course, mass[i].grade);
		fprintf(file, "\n%s %d %f", mass[i].charas, mass[i].inte, mass[i].flotas);
	}
	//fprintf(file, "\n%s", "--------------------------------------");
	fclose(file);

	free(mass);

}

void fUpdate(int n) {
	int i, len, teger;
	float floater;
	FILE *file;
	file = fopen("duom.txt", "a");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	mass = (struct KOLEGIJA *)calloc(n, sizeof(struct KOLEGIJA));

	for (i = 0; i < n; i++)
	{
		mass[i].id = i;

		// CHAR
		while (true)
		{
			printf("\n%d Enter charas : ", i + 1);
			scanf(" %s", mass[i].charas);
			
			len = strlen(mass[i].charas);

			if (len < 16) {
				break;
			}
			else
			{
				printf("\nChar too long");
			}
		}


		// INT

		while (true)
		{
			printf("\nEnter inte : ");
			scanf(" %d", &teger);

			if (numDigits(teger) < 10) {
				mass[i].inte = teger;
				teger = 0;
				break;
			}
			else
			{
				printf("\nInteger too long");
				teger = 0;
			}
		}


		// FLOAT
		while (true)
		{
			printf("\nEnter flotas : ");
			scanf(" %f", &floater);

			if (numDigits(floater) < 5) {
				mass[i].flotas = floater;
				break;
			}
			else
			{
				printf("\nFloat too long");
				floater = 0;
			}
		}


	}

	for (i = 0; i < n; i++)
	{
		fprintf(file,"\n%s %d %f",mass[i].charas,mass[i].inte,mass[i].flotas);
	}
	fclose(file);
	
	free(mass);
}

void erRead() {

	char line[1000];
	int kek = 0;
	FILE *file;
	file = fopen("duom.txt", "r");
	
	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
		int integer = 0;
		float flote = 0;
		int i = 0;
		char *numa = (char*)malloc(sizeof(char) * (16));
		numa[16] = 0;

		kek = listSize();
		arr = (struct KOLEGIJA *)calloc(kek, sizeof(struct KOLEGIJA));

		while (fgets(line, sizeof(line), file) != NULL) 
		{
			fscanf(file, "%s %d %f", arr[i].charas, &arr[i].inte, &arr[i].flotas);
			i++;
		}
	fclose(file);
}

void fEdit() {
	erRead();
	FILE *fp1, *fp2;
	char c = ' ';
	int ln,i;
	int n = listSize();
	printf("\nWhich line to edit :");
	scanf(" %d", &ln);


	for (i = 0; i < n; i++)
	{
		if (i == ln) 
		{
			printf("\nEditing %s %d %f", arr[i].charas, arr[i].inte, arr[i].flotas);
			printf("\n Change char : ");
			scanf(" %s", arr[i].charas);
			printf("\n Change inte : ");
			scanf(" %d", &arr[i].inte);
			printf("\n Change flota : ");
			scanf(" %f", &arr[i].flotas);
		}
	}

	fp1 = fopen("duom.txt", "r");
	if (fp1 == NULL) 
	{
		puts("cannot open this file");
		exit(1);
	}

	fp2 = fopen("duom2.txt", "w");
	if (fp2 == NULL)
	{
		puts("Not able to open this file");
		fclose(fp1);
		exit(1);
	}

	for (i = 0; i < n-1; i++)
	{
		fprintf(fp2, "\n%s %d %f", arr[i].charas, arr[i].inte, arr[i].flotas);
	}
		

	fclose(fp1);
	fclose(fp2);

	remove("duom.txt");
	rename("duom2.txt", "duom.txt");

	
}

int inteResult() 
{
	int res = 0;
	int i;
	erRead();
	int n = listSize();

	for (i = 0; i < n; i++)
	{
		res += arr[i].inte;
	}

	return res;
}

void fRead()
{
	FILE *file;

	char line[1000];
	size_t len = 0;
	size_t read;
	file = fopen("duom.txt", "r");
	if (file == NULL) 
	{
		printf("Error opening file!\n");
		exit(1);
	}
	printf("\n%s", "--------------------------------------");
	printf("\n%s %s %s", "CHAR", "INTE", "FLOTA");
	printf("\n%s", "--------------------------------------");
	while (fgets(line,sizeof(line),file) != NULL) {
		fputs(line, stdout);
	}
	
	fclose(file);
}

void fFind() 
{
	erRead();
	FILE *fp1, *fp2;
	char *a = (char*)malloc(16*sizeof(char));
	int c;
	int ln, i,sk;
	float fk;
	int n = listSize();
	printf("\nFind with c,i,f :");
	scanf(" %d", &c);
	
	switch (c) 
	{
	case 1:
		printf("\nFind :");
		scanf(" %s", a);
		printf("\nSearching for... %s",a);
		for (i = 0; i < n; i++)
		{
			if (strcmp(arr[i].charas,a) == 0 )
			{
				printf("\nFounded %s %d %f", arr[i].charas, arr[i].inte, arr[i].flotas);
				break;
			}
		}
		break;
	case 2:
		printf("\nFind  :");
		scanf(" %d", &sk);
		for (i = 0; i < n; i++)
		{
			if (arr[i].inte == sk)
			{
				printf("\nFounded %s %d %f", arr[i].charas, arr[i].inte, arr[i].flotas);
				break;
			}
		}
		break;
	case 3:
		printf("\nFind  :");
		scanf(" %f", &fk);
		for (i = 0; i < n; i++)
		{
			if (arr[i].flotas == fk)
			{
				printf("\nFounded %s %d %f", arr[i].charas, arr[i].inte, arr[i].flotas);
				break;
			}
		}
		break;
	default:
		break;
	}

	

}