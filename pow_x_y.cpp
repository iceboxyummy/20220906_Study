// x�� y������ ���ϴ� �Լ�

#include <stdio.h>

int get_pow(int, int);
int get_num();

int main() {

	int x = 0;
	int y = 0;

	x = get_num();
	y = get_num();

	int z = get_pow(x, y);

	printf("%d�� %d������ %d�Դϴ�.", x, y, z);
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

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	return num;
}