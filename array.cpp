//�迭 ����

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int arr[10];
	int x = 0;

	srand(time(NULL));

	printf("���� ���� �迭\n");
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 +1 ;
		printf("%d ", arr[i]);
	}

	printf("\n�������� ����\n");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] > arr[i])
			{
				x = arr[j] ;
				arr[j] = arr[i];
				arr[i] = x;
			}		
		}
	} 

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n�������� ����\n");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] < arr[i])
			{
				x = arr[j];
				arr[j] = arr[i];
				arr[i] = x;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
		return 0;
}