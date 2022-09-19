// x의 y제곱을 구하는 함수

#include <stdio.h>

int get_pow(int, int);
int get_num();

int main() {

	int x = 0;
	int y = 0;

	x = get_num();
	y = get_num();

	int z = get_pow(x, y);

	printf("%d의 %d제곱은 %d입니다.", x, y, z);
}

int get_pow(int x, int y) {

	int z = 1 ; // z = x ^ y 
	int i = 1;

	while (i <= y) {
		z *= x;
		i++;
	}

	return z;
}

int get_num() {
	int num = 0;

	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &num);

	return num;
}