//����������-���°���

#include <stdio.h>

int main() {
	int user;

	printf("������������ �����մϴ�\n");
	printf("1.���� 2.���� 3.��\n");
	scanf_s("%d", &user);

	switch (user){
	case 1:
		printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
		printf("�����ϴ�.\n");
		break;

	case 2:
		printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
		printf("�̰���ϴ�.\n");
		break;
		
	case 3:
		printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
		printf("�����ϴ�.\n");
		break;

	default:
		printf("�߸����Է��Դϴ�.");
		break;
	}
	return 0;
}