#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void gibNumbers(int mass[], int size,int sum) {
	int i,j,k;
	
	for (i = 0; i < size-2; i++)
	{
		for (j = i+1,k = size - 1;  j < k ;)
		{
			int newSum = mass[i]+mass[j]+mass[k];
			if (newSum == sum) 
			{
				printf("\n %d  %d  %d ", mass[i], mass[j], mass[k]);
				j++;
				k--;
			}
			else if (newSum < sum) 
			{
				j++;
			}
			else 
			{
				k--;
			}
		}
	}

}

int main()
{
	int arr[9] = {1,2,3,1,2,3,1,2,3};
	int size = sizeof(arr) / sizeof(int);
	gibNumbers(arr,size,222);

	_getch();
    return 0;
}