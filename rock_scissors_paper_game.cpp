// ����������

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int user = 0, com = 0 ;
	int win_user = 0, win_com = 0;

	while (1) {
		printf("1.���� 2.���� 3.�� 4.�����ϱ� \n");
		scanf_s(" %d", &user);
		com = rand() % 3 + 1;

		switch (user)
		{
		case 1:
			if (com == 1)
			{
				printf("��ǻ�ʹ� ����! �����ϴ�!\n");
				break;
			}


			else if (com == 2)
			{
				printf("��ǻ�ʹ� ����! ��ǻ�Ͱ� �̰���ϴ�!\n");
				win_com++;
				break;
			}

			else
			{
				printf("��ǻ�ʹ� ��! ����� �̰���ϴ�!\n");
				win_user++;
				break;
			}

		case 2:
			if (com == 1)
			{
				printf("��ǻ�ʹ� ����! ����� �̰���ϴ�!\n");
				win_user++;
				break;
			}

			else if (com == 2)
			{
				printf("��ǻ�ʹ� ����! �����ϴ�!\n");
				break;
			}

			else
			{
				printf("��ǻ�ʹ� ��! ��ǻ�Ͱ� �̰���ϴ�!\n");
				win_com++;
				break;
			}

		case 3:
			if (com == 1)
			{
				printf("��ǻ�ʹ� ����! ��ǻ�Ͱ� �̰���ϴ�!\n");
				win_com++;
				break;
			}

			else if (com == 2)
			{
				printf("��ǻ�ʹ� ����! ����� �̰���ϴ�!\n");
				win_user++;
				break;
			}

			else
			{
				printf("��ǻ�ʹ� ��! �����ϴ�!\n");
				break;
			}

		case 4: 
			break;

		default:
			printf("�߸��� �Է��Դϴ� �ٽ��Է��ϼ���\n");
			break;

		}

		if (win_com == 3)
		{
			printf("��ǻ���� �¸�!\n");
			break;
		}

		if (win_user == 3)
		{
			printf("����� �¸�!\n");
			break;
		}
	}
	return 0;
}