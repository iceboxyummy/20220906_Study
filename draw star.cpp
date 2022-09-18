// 별그리기

#include <stdio.h>

int main(){

	for (int i = 5 ; i >= 1 ; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n------------\n");
	
	for (int a = 5 ; a >= 1 ; a--)
	{
		for (int b = 1 ; b <= 5 - a ; b++)
		{
			printf(" ");
		}

		for (int c = 1; c <= a ; c++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}