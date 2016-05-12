#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

void ExchangeSort(int mass[], int massLength) {
	printf("Exchange Sort\n");
	int i, j, temp;

	for (i = 0; i < massLength - 1; i++) {
		for (j = i + 1; j < massLength; j++) {
			if (mass[i]<mass[j]) {
				printf("\n%d true mass[%d]=%d < mass[%d]=%d  : ", i, i, mass[i], j, mass[j]);
				printf("\n%d Exchange mass[%d]=%d <-> mass[%d]=%d  : ", i, i, mass[i], j, mass[j]);
				temp = mass[i];
				mass[i] = mass[j];
				mass[j] = temp;

			}
			else {
				printf("\n%d false mass[%d]=%d > mass[%d]=%d  : ", i, i, mass[i], j, mass[j]);
			}

		}
		printf("\n");
	}

	int a;
	for (a = 0; a<massLength; a++) {
		printf("%d ", mass[a]);
	}
}

void amstrongNumber() {
	int i=0, temp = 0, num = 0, rem = 0, sk = 0, a = 0, k = 0, digits = 0;
	int mass[100];
	printf("Armstrong numbers between 100 an 999 are: ");

	for (i = 101; i<999; i++) {

		temp = i;
		num = 0;
		while (temp != 0)
		{
			rem = temp % 10;
			num += rem*rem*rem;
			temp = temp / 10;
		}
		if (i == num)
		{
			mass[sk] = i;
			printf("%d ", i);
			sk++;
		}
	}

	printf("\nEnter a number : ");
	scanf("%d", &a);
	
	printf("\n Checking a : %d",a);
	int j;
	for (j = 0; j<99; j++) {

		if (a == mass[j])
		{
			printf("\n Amstrong founded ");
		}

	}

}

int main()
{
	int i, ilg,n1,n2;
	int chos=0;
	printf("Hello world!\n");

	printf("A=1 or B=2 : \n");
	scanf("%d", &chos);
	if (chos == 1) {
		printf("array length : \n");
		scanf("%d", &ilg);

		srand(time(NULL));
		int r;


		int mass[10];

		for (i = 0; i<ilg; i++) {
			r = rand() % 15;
			mass[i] = r;
		}
		int a;
		for (a = 0; a<ilg; a++) {
			printf("%d ", mass[a]);
		}
		printf("\n");
		ExchangeSort(mass, ilg);
	}
	if (chos == 2) {
		amstrongNumber();
	}
	else {
		printf("Not found \n");
	}

	_getch();
	return 0;
}
