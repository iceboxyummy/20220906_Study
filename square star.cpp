// ���簢�� �׸���

#include <stdio.h>

int main() {

	int a = 0;

	printf("���簢���� ũ�⸦ �Է��ϼ��� : ");
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