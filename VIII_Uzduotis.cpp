#define  _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdlib.h>
#include "Header.h"
// Naudoti "Header.h" faila norint sita programa paleisti

int main()
{
	int i,sk;
	fCreate();
	int n=1;

	printf("\nNew 1");
	printf("\nShow file content 2");
	printf("\nUpdate file 3");
	printf("\nEdit 4");
	printf("\nPrint to console 5");
	printf("\nSum 6");
	printf("\nFind element 7");


	while (n != 0) 
	{
		printf("\nchose:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("\nNew data");
			printf("\nnumber of new data:");
			scanf("%d", &sk);
			fCreateNewData(sk);
			break;
		case 2:
			printf("\nPrint file data");
			fRead();
			break;
		case 3:
			printf("\nUpdate file");
			printf("\nnumber of new data:");
			scanf("%d", &sk);
			fUpdate(sk);
			break;
		case 4:
			printf("\nEdit data");
			fEdit();
			break;
		case 5:
			printf("\nPrint file to console");
			fRead();
			break;
		case 6:
			printf("\nSum of inte");
			printf("\nSum of inte = %d ", inteResult());
			break;
		case 7:
			printf("\nFind :");
			fFind();
			break;
		default:
			break;
		}
	}
	printf("\nend");

	_getch();
    return 0;
}
