#include <stdio.h>

//ȯ������

int main() {

	float won, dollar;

	printf("��ȭ�� �Է��ϼ���.\n");
	scanf_s("%f", &won);

	dollar = won * 0.00072;
	printf("%.1f���� %.3f�޷��Դϴ�.\n", won, dollar);

	return 0;
}