#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//#include "IIHeader.h"

const int sk;

struct student {
	char name[16];
	int id;
};

struct studentss {
	char name[16];
	char course[16];
	int grade;
	int id;
};

void masyvas(int mass[], int ilgis) {
	int i;
	srand(time(NULL));
	for (i = 0; i<ilgis; i++) {
		mass[i] = rand() % 50 + 1;
	}
}

void mass_isvedimas(int mass[], int ilgis) {
	for (int i = 0; i<ilgis; i++) {
		printf("%d ", mass[i]);
	}
	printf("\n");
}

//--------------------------------------------

void IIa(int size) {
	int n = size;
	int i = 0;
	char name;
	struct student *mass;
	mass = (struct student *)calloc(size, sizeof(struct student));

	for (i = 0; i < n; i++)
	{
		printf("\n%d Enter name : ", i);
		mass[i].id = i + 1;
		scanf(" %s", mass[i].name);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("Student name : %s\t ID:%d\n", mass[i].name, mass[i].id);
	}
	free(mass);
}

void IIb(int size) {
	int n = size;
	int i;
	char *name;
	struct student *mass;
	mass = (struct student *)calloc(size, sizeof(struct student));

	char kek[23][23] = { "Tocahontas", "Henry W Lungfiller", "Hit-ler"," Mao Zebong"," Chronica Lewinsky", "Budyard Piffling", "Rosa Sparks", "Dankston Hughes", "Ban Kief-Moon", "Abraham Stinkin" , "George W. Kush "," Karl Drove", "Kief Bowlbermann"," Neil Armsbong", "Buzzkill Aldrin"," Alexander GramBag", "Jack the Ripper", "Barack Drobama/Obonga", "Joe Highden"," James K. Toke", "Buddha Maccabee"," Arispotle" };

	srand(time(NULL));
	int sk = 0;

	for (i = 0; i < n; i++)
	{
		sk = rand() % 10 + 1;
		mass[i].id = sk;
		strcpy(mass[i].name, kek[rand() % 22 + 1], kek[rand() % 22 + 1]);
		printf("\n Student name : %s\t ID:%d", mass[i].name, mass[i].id);
	}

	free(mass);
}

void IIc(int size) {
	int i = 0;
	int n = size;
	char *name;
	struct studentss *mass;
	mass = (struct studentss *)calloc(size, sizeof(struct studentss));
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		printf("\n%d Enter name : ", i + 1);
		mass[i].id = i + 1;
		scanf(" %s", mass[i].name);
		printf("Enter course : ");
		scanf(" %s", mass[i].course);
		mass[i].grade = rand() % 10 + 1;
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("\nID:%d Student name : %s\t Course : %s\t Grade:%d ", mass[i].id, mass[i].name, mass[i].course, mass[i].grade);
	}
	free(mass);
}

//------------------------------------------------------

int fibonacci(unsigned int n) {
	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(unsigned int n)
{
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}


int PascalTriangle(int row, int col) {
	if (col == 0)
		return 0;

	else if (row == 1 && col == 1)
		return 1;

	else if (col>row)
		return 0;

	else
		return (PascalTriangle(row - 1, col - 1) + PascalTriangle(row - 1, col));

}

void spaceInBetween(int num, int mul)
{
	int i;
	num *= mul;
	for (i = 0; i<num; i++)
		printf(" ");
}

void Merge(int *arr[], int ilgis, int beg, int middle, int endd) {
	int temp[10], i;

	for (i = beg; i <= endd; i++) {
		temp[i] = arr[i];
	}

	i = beg;
	int j = middle + 1;
	int k = beg;

	while (i <= middle && j <= endd) {
		if (temp[i] <= temp[j]) {
			arr[k] = temp[i];
			i++;
		}
		else {
			arr[k] = temp[j];
			j++;
		}
		k++;
	}
	while (i <= middle) {
		arr[k] = temp[i];
		k++;
		i++;
	}

}

void mergeSort(int *arr[], int ilgis, int beg, int endd) {
	if (beg < endd) {
		int middle = (beg + endd) / 2;
		mergeSort(arr, ilgis, beg, middle);
		mergeSort(arr, ilgis, middle + 1, endd);
		Merge(arr, ilgis, beg, middle, endd);
	}
}

void IId() {
	int n, i, fag;
	int num, j;
	printf("\nFactorial -1\nFibbonaci - 2\nPascal Triangle - 3\nMergeSort - 4 \n");
	scanf("%d", &fag);
	switch (fag)
	{
	case 1:
		printf("Enter a number: ");
		scanf("%d", &n);
		printf("Factorial of %d = %ld", n, factorial(n));
		break;
	case 2:
		printf("\nFibbonaci: ");
		for (i = 0; i < n; i++) {
			printf("%d\t", fibonacci(i));
		}
		break;
	case 3:
		printf("\nEnter the no. of rows required: ");
		scanf("%d", &num);
		for (i = 1; i <= num; i++)
		{
			spaceInBetween(num - i, 3);
			for (j = 1; j <= i; j++)
			{
				printf("%3d", PascalTriangle(i, j));
				spaceInBetween(1, 3);
			}
			printf("\n");
		}
		break;
	case 4:
		printf("\nEnter array length : ");
		scanf("%d", &sk);
		int * mass;
		mass = calloc(sk, sizeof(mass));

		masyvas(mass, sk);
		mass_isvedimas(mass, sk);

		mergeSort(mass, sk, 0, sk - 1);
		mass_isvedimas(mass, sk);

		break;
	default:
		printf("top kek");
		break;
	}
}


int main()
{
	printf("Hello World \n");
	char n;
	printf("\n choose task a,b,c,d ");
	scanf(" %c", &n);
	int sk;
	switch(n) {
      case 'a':
		  printf("\nSize of array : ");
		  scanf("%d", &sk);
		  IIa(sk);
		  break;
	  case 'b':
		  printf("\nSize of array : ");
		  scanf("%d", &sk);
		  IIb(sk);
		  break;
	  case 'c':
		  printf("\nSize of array : ");
		  scanf("%d", &sk);
		  IIc(sk);
		  break;
	  case 'd':
		  IId();
		  break;
	  default:
		  printf("Invalid\n");
		  break;
	}


	_getch();
	return 0;
}