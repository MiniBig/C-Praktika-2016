#define _GNU_SOURCE
#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

bool fileExists(const char* file) 
{
	struct stat buf;
	return (stat(file, &buf) == 0);
}

char* strtokCu(char * str, char const * delims)
{
	static char  * src = NULL;
	char  *  p;
	char * ret = 0;

	if (str != NULL)
		src = str;

	if (src == NULL)
		return NULL;

	if ((p = strpbrk(src, delims)) != NULL) {
		*p = 0;
		ret = src;
		src = ++p;

	}
	else if (*src) {
		ret = src;
		src = NULL;
	}

	return ret;
}

int csvReadCollums()
{
	FILE *file;
	char line[1000];
	char data[1];
	char *data2;
	int sk = 0;

	if (fileExists("CRISP_PRJ_C_FY2009.csv"))
	{
		file = fopen("CRISP_PRJ_C_FY2009.csv", "r");
		if (file == NULL)
		{
			printf("Error opening file\n");
			exit(1);
		}


		while (fgets(line, sizeof(line), file) != NULL)
		{
			fscanf(file, data);
			data2 = strtok(data, ",");

			while (data2 != NULL)
			{
				data2 = strtok(NULL, ",");
				sk++;
			}
			break;

		}
		fclose(file);	
	}
	return sk;
	
}

char* getType(char* toCheck,int id) 
{
	int i;
	char *date;
	// Tikrinam ar skaicius
	const int len = strlen(toCheck);
	printf("Checking data '%s' ", toCheck);
	printf("length of data '%d' ", len);
	for (i = 0; i < len; i++)
	{

		if (len <= 10)
		{
			if (len <= 1) {
				if (!isdigit(toCheck[i]))
				{
					return "Is Char";
					break;
				}
				if (isdigit(toCheck[i]))
				{
					return "Is Integer";
					break;
				}
			}
			date = strpbrk(toCheck, "/");
			if (date)
			{
				return "Is Date"; break;
			}
			date = strpbrk(toCheck, "-");
			if (date)
			{
				return "Is Date";break;
			}

			else{
				if (!isdigit(toCheck[i]))
				{
					return "Is String";
					break;
				}
				if (isdigit(toCheck[i]))
				{
					return "Is Integer";
					break;
				}
			}
		}
		if (!isdigit(toCheck[i]))
		{
			return "Is String";
			break;
		}
		if (isdigit(toCheck[i]))
		{
			return "Is Integer";
			break;
		}
		
		
	}
	return NULL;


}

char* getTypeIF(char* toCheck, int id)
{
	int i;
	char *date;
	// Tikrinam ar skaicius
	const int len = strlen(toCheck);
	
	for (i = 0; i < len; i++)
	{
		if (len == 10)
		{
			date = strpbrk(toCheck, "/");
			if (date)
			{
				return "k";
				break;
			}
			date = strpbrk(toCheck, "-");
			if (date)
			{
				return "k";
				break;
			}
			break;
		}
		if (!isdigit(toCheck[i]))
		{
			return "k";
			break;
		}
		if (isdigit(toCheck[i]))
		{
			return "k";
			break;
		}
	}
	return NULL;


}

void csvRead()
{
	FILE *file;
	char line[10000];
	char data[100];
	char *data2;
	int a;
	char ch;
	
	int amount;
	if (fileExists("CRISP_PRJ_C_FY2009.csv"))
	{
		file = fopen("CRISP_PRJ_C_FY2009.csv","r");
		if (file == NULL)
		{
			printf("Error opening file\n");
			exit(1);
		}

		amount = csvReadCollums();
		printf(" Amount%d\n", amount);

		while (fgets(line, 10000, file) != NULL)
		{
			char * p = strtokCu(line, ",");

			while (p) {
				if (getTypeIF(p, amount)!=NULL) {
					printf("%s\n", getType(p, amount));
				}
				else
				{
					printf("Unknown\n");
				}

				p = strtokCu(NULL, ",");
			}

			printf("********************\n");
			
		}
		fclose(file);
	}
		
}

int main()
{

	csvRead();

	_getch();
    return 0;
}