#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

int a[8];

int sum()
{
	int i, j, t, sum, k;
	sum = 0;
	k = 1;
	j = 0;
	
	
	for (i = 0, t = 1; i<8; i++)
	{
		if (a[i] == 0)
		{
			t = t * 10 + (i + 2);
		}
		else if (a[i] == 1)
		{
			if (k == 1) sum += t;
			else
				sum -= t;
			t = i + 2;
			k = 1;
		}
		else
		{
			if (k == 1) sum += t;
			else
				sum -= t;
			t = i + 2;
			k = 2;
		}
	}
	if (k == 1)
	{
		sum += t;
	}
	else    sum -= t;
	return sum;
}

void dfs(int cur)
{
	int i;
	if (cur == 8)
	{
		if (sum() == 100)
		{
			printf("1");
			for (i = 0; i<8; i++)
				if (a[i] == 0) 
				{
					printf("%d", i + 2);
				}
				else if (a[i] == 1) 
				{
					printf("+%d", i + 2);
				}
				else
					printf("-%d", i + 2);
					printf("\n");
		}
		return;
	}
	a[cur] = 0;
	dfs(cur + 1);
	a[cur] = 1;
	dfs(cur + 1);
	a[cur] = 2;
	dfs(cur + 1);
}
int main()
{
	dfs(0);
	_getch();
	return 0;
}