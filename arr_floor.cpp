// ���� floor �ϼ�
#include <stdio.h>

void floor();

int main() {
	floor();
	return 0;
}
void floor() {
	int floor[4][3] = { 0 };
	int floor_people = 0; // �� ���� �ο���
	int total_people = 0; // ��ü �ο���

	for (int i = 0; i < 4; i++) // �ο��� �Է�
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d�� %dȣ�� ����ִ� �ο����� �Է��ϼ��� : ", i + 1, j + 1);
			scanf_s("%d", &floor[i][j]);
		}
	}

	for (int i = 0; i < 4; i++) // �ο��� ���
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d�� %dȣ�� ����ִ� �ο��� %d���Դϴ�.\n", i + 1, j + 1,floor[i][j]);
		}
	}
	 
	for (int i = 0; i < 4; i++) // �� ���� �� �ο��� ���
	{
		for (int j = 0; j < 3; j++)
		{
			floor_people += floor[i][j];
		}
		printf("%d���� ����ִ� �ο��� %d���Դϴ�\n", i + 1, floor_people);
		floor_people = 0;
	}

	for (int i = 0; i < 4; i++) // ��ü �ο��� ���
	{
		for (int j = 0; j < 3; j++)
		{
			total_people += floor[i][j];
		}
	}
	printf("%����Ʈ�� ����ִ� �ο��� %d���Դϴ�", total_people);
}