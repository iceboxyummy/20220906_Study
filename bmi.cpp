#include <stdio.h>

//bmi ����

int main() {
	
	float kg, m, bmi;

	printf("������(kg)�� �Է��ϼ���.\n");
	scanf_s("%f", &kg);

	printf("Ű(m)�� �Է��ϼ���.\n");
	scanf_s("%f", &m);

	bmi = kg /(m * m);

	printf("bmi�� %.2f �Դϴ�.\n", bmi);

	return 0;
}