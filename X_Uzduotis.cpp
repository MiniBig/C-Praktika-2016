#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct dict {
	int id;
	char litva[16];
	char engrihu[16];
};

struct dict *mass;
struct dict *arr;

void erRead();
int listSize();
char* fLowerCase(char *word);

void fCreateNewData(int n)
{
	int i, len, teger;
	float floater;
	char *word = (char*)malloc(16 * sizeof(char));
	char *wordT = (char*)malloc(16 * sizeof(char));
	FILE *file;
	file = fopen("duom.txt", "w");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	mass = (struct dict *)calloc(n, sizeof(struct dict));

	for (i = 0; i < n; i++)
	{
		mass[i].id = i;

		// CHAR
		while (true)
		{
			printf("\n%d Enter lithuanian word : ", i + 1);
			scanf(" %s", mass[i].litva);

			len = strlen(mass[i].litva);

			if (len < 16) {
				break;
			}
			else
			{
				printf("\nWord too long");
			}
		}
		// CHAR
		while (true)
		{
			printf("\n%d Enter translation : ", i + 1);
			scanf(" %s", mass[i].engrihu);

			len = strlen(mass[i].engrihu);

			if (len < 32) {

				break;
			}
			else
			{
				printf("\nWord too long");
			}
		}


	}

	for (i = 0; i < n; i++)
	{
		word = fLowerCase(mass[i].litva);
		wordT = fLowerCase(mass[i].engrihu);
		fprintf(file, "\n%-16s %s", word, wordT);
	}
	fclose(file);

	free(mass);

}

void fUpdateWord()
{
	int len;
	char *word = (char*)malloc(16 * sizeof(char));
	char *wordT = (char*)malloc(16 * sizeof(char));

	FILE *file;
	file = fopen("duom.txt", "a");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	// CHAR
	while (true)
	{
		printf("\nEnter new lithuanian word : ");
		scanf("%s", word);

		len = strlen(word);

		if (len < 16) {
			break;
		}
		else
		{
			printf("\nWord too long");
		}
	}
	// CHAR
	while (true)
	{
		printf("\nEnter translation for %s: ", word);
		scanf(" %s", wordT);

		len = strlen(wordT);

		if (len < 32) 
		{
			break;
		}
		else
		{
			printf("\nWord too long");
		}
	}
	word = fLowerCase(word);
	wordT = fLowerCase(wordT);
	fprintf(file, "\n%-16s %s", word , wordT);

	fclose(file);
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
	printf("\n%s %s", "Lithuania      -", "English");
	while (fgets(line, sizeof(line), file) != NULL) {
		fputs(line, stdout);
	}

	fclose(file);
}

void fWordTranslate(char *str)
{
	erRead();
	int i;
	int n = listSize();
	int id = -1;
	printf("\nTrasnlate '%s' ", str);

	for (i = 0; i < n; i++)
	{
		
		if (strcmp(arr[i].litva, str) == 0)
		{
			id = i;
			break;
		}
		
	}

	if (id != -1)
	{
		printf("\n%-16s --> %s", arr[id].litva, arr[id].engrihu);
	}
	else 
	{
		printf("\nWord '%s' not found", str);
		fUpdateWord();
	}

}

void fWordTranslate2(char *str)
{
	erRead();
	int i;
	int n = listSize();
	int id = -1;
	printf("\nTrasnlate '%s' ", str);

	for (i = 0; i < n; i++)
	{

		if (strcmp(arr[i].engrihu, str) == 0)
		{
			id = i;
			break;
		}

	}

	if (id != -1)
	{
		printf("\n%-16s --> %s", arr[id].engrihu, arr[id].litva);
	}
	else
	{
		printf("\nWord '%s' not found", str);
		fUpdateWord();
	}

}


int main()
{
	char *word = (char*)malloc(16 * sizeof(char));
	int h = -1 ;
	int sk = 0;
	while (h != 0) {
		
		printf("\nChose: ");
		scanf("%d", &h);

		switch (h)
		{
		case 1:
			printf("\nNew list size: ");
			scanf("%d", &sk);
			fCreateNewData(sk);
			break;
		case 2:
			printf("\nWord to translate english : ");
			scanf("\n%s", word);
			fWordTranslate(word);
			break;
		case 3:
			fRead();
			break;
		case 4:
			fUpdateWord();
			break;
		case 5:
			printf("\nWord to translate lithuanian : ");
			scanf("\n%s", word);
			fWordTranslate2(word);
			break;
		default:
			break;
		}
	}
	
	
	_getch();
    return 0;
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
	arr = (struct dict *)calloc(kek, sizeof(struct dict));

	while (fgets(line, sizeof(line), file) != NULL)
	{
		fscanf(file, "%s %s", arr[i].litva, &arr[i].engrihu);
		i++;
	}

	fclose(file);
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

char* fLowerCase(char *word)
{
	int i = 0;
	char *c = (char*)malloc(16 * sizeof(char));

	while (word[i])
	{
		word[i] = tolower(word[i]);
		i++;
	}
	return word;
	free(word);
}