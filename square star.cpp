// 정사각형 그리기

#include <stdio.h>

int main() {

	int a = 0;

	printf("정사각형의 크기를 입력하세요 : ");
	scanf_s("%d", &a);
	printf("\n");

	for (int i = 1; i <= a; i++)
	{
		int j = 1;
		while (j <= a) 
		{
			printf("*");
			j++;
		}
		printf("\n");
	}
	return 0;
}