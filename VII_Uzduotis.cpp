#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int x=0,sum=0;
int *arr;

char *
strcpy(char *s1, const char *s2)
{
	char *s = s1;
	while ((*s++ = *s2++) != 0)
		;
	return (s1);
}



void gibNumbers()
{
	FILE *file;
	int c, i = 0, sk;
	file = fopen("duom.txt", "r");
	if (!file)
		printf("\nFile can not be opened");

	while ((c = fgetc(file)) != EOF)
	{
		if (isdigit(c))
		{
			x++;
		}
	}

	fclose(file);
	file = fopen("duom.txt", "r");

	arr = (int*)malloc(x * sizeof(int));

	while ((c = fgetc(file)) != EOF)
	{
		if (isdigit(c))
		{
			sk = c - '0';
			arr[i] = sk;
			i++;
		}
	}
	fclose(file);
}

void gibSum() {
	int i;
	for (i = 0; i < x; i++)
	{
		sum = sum + arr[i];
	}
}

void printuNumburs()
{
	FILE *file;
	int i,ch;
	file = fopen("duom.txt", "a");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	fprintf(file, "\n","");

	for (i = 0; i < x; i++)
	{
		fprintf(file,"%d ", arr[i]);
	}

	fclose(file);
}

int main()
{
	gibNumbers();
	gibSum();
	printf("%d sum ", sum);
	printuNumburs();
	

	_getch();
    return 0;
}

