// 정사각형그리기

#include <stdio.h>

int get_square_size();
void draw_square();

int main() {

	draw_square();
	
	return 0;
}

int get_square_size() {

	int square_size = 0;

	printf("정사각형의 크기를 입력하세요 : ");
	scanf_s("%d", &square_size);

	return square_size;
}

void draw_square() {

	int a = get_square_size();

	for (int i = 1; i <= a; i++)
	{
		int j = 1;
		while (j <= a)
		{
			printf("☆");
			j++;
		}
		printf("\n");
	}
}