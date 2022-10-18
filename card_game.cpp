#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef enum {
	start,
	�Ͽ�, �̿�, ���, ���, ����, ����, ĥ��, �ȿ�, ����, �ʿ�,
	�Ͽ���, �̿�_, �����, ���Ư, ����_, ����_, ĥ��Ư, �ȿ���, ����Ư, �ʿ�_,
	end = �ʿ�_
}card_num; 

typedef enum {
	���� = 30, �Ѳ�_, �Ѳ�, �β�, ����, �ײ�, �ټ���, ������, �ϰ���, ������, ����,
	����, ���, ���, ����, ����, �˸�, �籸,
	�϶�, �̶�, �ﶯ, �綯, ����, ����, ĥ��, �ȶ�, ����, ���ֱ����籸, ��ĥ������, �嶯,
	���ȱ���, �ϻﱤ��, ������, ���ȱ���
}card_jokbo;

void print_menu();							// ����ȭ�� ���
void shuffle_card(int card[]);				// ī�弯� ��������
int check_card(int card_1, int card_2);		// ī�� ���� Ȯ�� 
void print_card_name(int card);				// ī�� �̸� ���
void print_jokbo_name(int jokbo);			// ���� �̸� ���
int check_jokbo(int jokbo_1, int jokbo_2);	// Ư������ ����Ȯ��

int main()
{
	int card[end] = { 0 };

	int user_jokbo = 0;
	int com_jokbo = 0;

	char start_game = 0;
	char restart = 0;

	int user_win = 0;
	int draw = 0;
	int com_win = 0;
	
	
	print_menu();

	while (restart != 'n') //���� ���� �� ���� Ȯ��
	{
	regame:

		shuffle_card(card);

		int user_card_1 = card[0];
		int user_card_2 = card[1];
		int com_card_1 = card[2];
		int com_card_2 = card[3];

		user_jokbo = check_card(user_card_1, user_card_2);
		com_jokbo = check_card(com_card_1, com_card_2);

		printf("����� �д� ");
		print_card_name(user_card_1);
		print_card_name(user_card_2);
		print_jokbo_name(user_jokbo);
		printf("�Դϴ�.\n");

		printf("�����Ͻðڽ��ϱ�?( y / n ) ");
		scanf_s(" %c", &start_game, sizeof(char));

		if (start_game == 'n')
		{
			printf("������ �����մϴ�.\n");
			return 0;
		}

		printf("��ǻ���� �д� ");
		print_card_name(com_card_1);
		print_card_name(com_card_2);
		print_jokbo_name(com_jokbo);
		printf("�Դϴ�.\n");

		user_jokbo = check_jokbo(user_jokbo, com_jokbo);
		com_jokbo = check_jokbo(com_jokbo, user_jokbo);

		Sleep(500);

		if (user_jokbo == �籸 || user_jokbo == ���ֱ����籸 || com_jokbo == �籸 || com_jokbo == ���ֱ����籸)
		{
			printf("\n����� �� : ");
			print_jokbo_name(user_jokbo);

			printf("\n��ǻ���� �� :");
			print_jokbo_name(com_jokbo);

			Sleep(500);

			printf("\n(���ֱ���)�籸���� ����!!\n");
			printf("�����Ͻðڽ��ϱ�? ( y / n )");
			scanf_s(" %c", &restart, sizeof(char));

			if (restart == 'n')
			{
				printf("������ �����մϴ�.\n");
				return 0;
			}

			else
				printf("���⸦ �����մϴ�.\n");

			Sleep(1000);

			goto regame;
		}

		else
		{
			if (user_jokbo > com_jokbo)
			{
				printf("\n����� �� : ");
				print_jokbo_name(user_jokbo);

				printf("\n��ǻ���� �� :");
				print_jokbo_name(com_jokbo);

				Sleep(500);

				printf("\n����� �¸��Դϴ�.^0^\n");

				Sleep(500);

				user_win++;
			}

			else if (user_jokbo == com_jokbo)
			{
				printf("\n����� �� : ");
				print_jokbo_name(user_jokbo);

				printf("\n��ǻ���� �� :");
				print_jokbo_name(com_jokbo);

				Sleep(500);

				printf("\n���º��Դϴ�.\n");

				Sleep(500);

				draw++;
			}

			else
			{
				printf("\n����� �� : ");
				print_jokbo_name(user_jokbo);

				printf("\n��ǻ���� �� :");
				print_jokbo_name(com_jokbo);

				Sleep(500);

				printf("\n��ǻ���� �¸��Դϴ�.��0��\n");

				Sleep(500);

				com_win++;
			}
		}
		Sleep(500);

		printf("\n�÷��̾� �¸� : %d\n���º� : %d\n��ǻ�� �¸� : %d\n", user_win, draw, com_win);
		printf("����Ͻðڽ��ϱ�? ( y / n )");

		scanf_s(" %c", &restart, sizeof(char));
	}
	return 0;
}

void print_menu()
{
	printf("==================================================\n");
	printf("                                                  \n");
	printf("                                                  \n");
	printf("             ��                   ��              \n");
	printf("                                                  \n");
	printf("                                                  \n");
	printf("         1.�����ϱ�            2. �����ϱ�        \n");
	printf("                                                  \n");
	printf("                                                  \n");
	printf("==================================================\n");

	int start = 0;
	scanf_s("%d", &start);

	if (start == 2)
		exit(0);

	else
	{
		system("cls");
		printf("����� ������ ���۵˴ϴ�.\n");
		Sleep(1000);
	}
}

void shuffle_card(int card[])
{
	system("cls");
	printf("ī�带 �����ֽ��ϴ�.....\n");
	Sleep(1000);
	system("cls");

	for (int i = start; i < end; i++)
	{
		card[i] = i + 1;
	}

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		int a = rand() % 20;
		int b = rand() % 20;

		int temp = card[a];
		card[a] = card[b];
		card[b] = temp;
	}
}

int check_card(int card_1, int card_2)
{
	int check_num = (card_1 + card_2) % 10;

	switch (check_num) {
	case 0:
		if ((card_1 == �ʿ� && card_2 == �ʿ�_) || (card_1 == �ʿ�_ && card_2 == �ʿ�))
			return �嶯;

		else if ((card_1 == ���� && card_2 == ����_) || (card_1 == ����_ && card_2 == ����))
			return ����;

		else if ((card_1 == �Ͽ� && card_2 == ����) || (card_1 == �Ͽ� && card_2 == ����Ư) ||
			(card_1 == ���� && card_2 == �Ͽ�) || (card_1 == ����Ư && card_2 == �Ͽ�) ||
			(card_1 == ���� && card_2 == �Ͽ���) || (card_1 == ����Ư && card_2 == �Ͽ���) ||
			(card_1 == �Ͽ��� && card_2 == ����) || (card_1 == �Ͽ��� && card_2 == ����Ư))
			return ����;

		else if ((card_1 == ��� && card_2 == ����) || (card_1 == ��� && card_2 == ����_) ||
			(card_1 == ���� && card_2 == ���) || (card_1 == ����_ && card_2 == ���) ||
			(card_1 == ���� && card_2 == ���Ư) || (card_1 == ����_ && card_2 == ���Ư) ||
			(card_1 == ���Ư && card_2 == ����) || (card_1 == ���Ư && card_2 == ����_))
			return ����;

		else if ((card_1 == ����� && card_2 == ĥ��Ư) || (card_1 == ĥ��Ư && card_2 == �����))
			return ��ĥ������;

		else
			return ����;

	case 1:
		if ((card_1 == ����� && card_2 == �ȿ���) || (card_1 == �ȿ��� && card_2 == �����))
			return ���ȱ���;

		else if ((card_1 == �Ͽ� && card_2 == �ʿ�) || (card_1 == �Ͽ� && card_2 == �ʿ�_) ||
			(card_1 == �Ͽ��� && card_2 == �ʿ�) || (card_1 == �Ͽ��� && card_2 == �ʿ�_))
			return ���;

		if ((card_1 == ���Ư && card_2 == ĥ��Ư) || (card_1 == ĥ��Ư && card_2 == ���Ư))
			return ������;
		else

			return �Ѳ�;

	case 2:
		if ((card_1 == ���� && card_2 == ����_) || (card_1 == ����_ && card_2 == ����))
			return ����;

		else if ((card_1 == �Ͽ� && card_2 == �Ͽ���) || (card_1 == �Ͽ��� && card_2 == �Ͽ�))
			return �϶�;

		else
			return �β�;

	case 3:
		if ((card_1 == �Ͽ� && card_2 == �̿�) || (card_1 == �Ͽ� && card_2 == �̿�_) ||
			(card_1 == �̿� && card_2 == �Ͽ�) || (card_1 == �̿�_ && card_2 == �Ͽ�) ||
			(card_1 == �Ͽ��� && card_2 == �̿�) || (card_1 == �Ͽ��� && card_2 == �̿�_) ||
			(card_1 == �̿� && card_2 == �Ͽ���) || (card_1 == �̿�_ && card_2 == �Ͽ���))
			return �˸�;

		else if ((card_1 == ���Ư && card_2 == ����Ư) || (card_1 == ����Ư && card_2 == ���Ư))
			return ���ֱ����籸;

		else if ((card_1 == ��� && card_2 == ����) || (card_1 == ��� && card_2 == ����Ư) ||
			(card_1 == ���� && card_2 == ���) || (card_1 == ����Ư && card_2 == ���) ||
			(card_1 == ���Ư && card_2 == ����) || (card_1 == ���� && card_2 == ���Ư))
			return �籸;

		else
			return ����;

	case 4:
		if ((card_1 == ����� && card_2 == �Ͽ���) || (card_1 == �Ͽ��� && card_2 == �����))
			return �ϻﱤ��;

		else if ((card_1 == �̿� && card_2 == �̿�_) || (card_1 == �̿�_ && card_2 == �̿�))
			return �̶�;

		else if ((card_1 == ĥ�� && card_2 == ĥ��Ư) || (card_1 == ĥ��Ư && card_2 == ĥ��))
			return ĥ��;

		else if ((card_1 == ��� && card_2 == �ʿ�) || (card_1 == ��� && card_2 == �ʿ�_) ||
			(card_1 == �ʿ� && card_2 == ���) || (card_1 == �ʿ�_ && card_2 == ���) ||
			(card_1 == �ʿ� && card_2 == ���Ư) || (card_1 == �ʿ�_ && card_2 == ���Ư) ||
			(card_1 == ���Ư && card_2 == �ʿ�) || (card_1 == ���Ư && card_2 == �ʿ�_))
			return ���;

		else
			return �ײ�;

	case 5:
		if ((card_1 == ��� && card_2 == �Ͽ�) || (card_1 == ��� && card_2 == �Ͽ���) ||
			(card_1 == �Ͽ� && card_2 == ���) || (card_1 == �Ͽ��� && card_2 == ���) ||
			(card_1 == �Ͽ� && card_2 == ���Ư) || (card_1 == �Ͽ��� && card_2 == ���Ư) ||
			(card_1 == ���Ư && card_2 == �Ͽ�) || (card_1 == ���Ư && card_2 == �Ͽ���))
			return ����;
		else
			return �ټ���;
	case 6:
		if ((card_1 == �ȿ� && card_2 == �ȿ���) || (card_1 == �ȿ��� && card_2 == �ȿ�))
			return �ȶ�;

		else if ((card_1 == ��� && card_2 == �ȿ���) || (card_1 == ����� && card_2 == ���))
			return �ﶯ;

		else
			return ������;

	case 7:
		return �ϰ���;

	case 8:
		if ((card_1 == ��� && card_2 == ���Ư) || (card_1 == ���Ư && card_2 == ���))
			return �綯;

		else if ((card_1 == ���� && card_2 == ����Ư) || (card_1 == ����Ư && card_2 == ����))
			return ����;

		else
			return ������;

	case 9:
		if ((card_1 == �ȿ��� && card_2 == �Ͽ���) || (card_1 == �Ͽ��� && card_2 == �ȿ���))
			return ���ȱ���;

		else
			return ����;

	default:
		printf("������ ���� �����Դϴ�.\n");
		break;
	}
}

void print_card_name(int card)
{
	switch (card)
	{
	case 1: printf(" �Ͽ� "); break;
	case 2: printf(" �̿� "); break;
	case 3: printf(" ��� "); break;
	case 4: printf(" ��� "); break;
	case 5: printf(" ���� "); break;
	case 6: printf(" ���� "); break;
	case 7: printf(" ĥ�� "); break;
	case 8: printf(" �ȿ� "); break;
	case 9: printf(" ���� "); break;
	case 10: printf(" �ʿ� "); break;
	case 11: printf(" �Ͽ��� "); break;
	case 12: printf(" �̿� "); break;
	case 13: printf(" ����� "); break;
	case 14: printf(" ���Ư "); break;
	case 15: printf(" ���� "); break;
	case 16: printf(" ���� "); break;
	case 17: printf(" ĥ��Ư "); break;
	case 18: printf(" �ȿ��� "); break;
	case 19: printf(" ����Ư "); break;
	case 20: printf(" �ʿ� "); break;

	default:
		printf("������� �ʴ� ī���Դϴ�\n");
		break;
	}
}

void print_jokbo_name(int jokbo)
{
	switch (jokbo)
	{
	case 30: printf(" ����"); break;
	case 31: printf(" �Ѳ�_"); break;
	case 32: printf(" �Ѳ�"); break;
	case 33: printf(" �β�"); break;
	case 34: printf(" ����"); break;
	case 35: printf(" �ײ�"); break;
	case 36: printf(" �ټ���"); break;
	case 37: printf(" ������"); break;
	case 38: printf(" �ϰ���"); break;
	case 39: printf(" ������"); break;
	case 40: printf(" ����"); break;
	case 41: printf(" ����"); break;
	case 42: printf(" ���"); break;
	case 43: printf(" ���"); break;
	case 44: printf(" ����"); break;
	case 45: printf(" ����"); break;
	case 46: printf(" �˸�"); break;
	case 47: printf(" �籸"); break;
	case 48: printf(" �϶�"); break;
	case 49: printf(" �̶�"); break;
	case 50: printf(" �ﶯ"); break;
	case 51: printf(" �綯"); break;
	case 52: printf(" ����"); break;
	case 53: printf(" ����"); break;
	case 54: printf(" ĥ��"); break;
	case 55: printf(" �ȶ�"); break;
	case 56: printf(" ����"); break;
	case 57: printf(" ���ֱ����籸"); break;
	case 58: printf(" ��ĥ������"); break;
	case 59: printf(" �嶯"); break;
	case 60: printf(" ���ȱ���"); break;
	case 61: printf(" �ϻﱤ��"); break;
	case 62: printf(" ������"); break;
	case 63: printf(" ���ȱ���"); break;

	default:
		printf("������ ���� �����Դϴ�.");
		break;
	}
}

int check_jokbo(int jokbo_1, int jokbo_2)
{
	if (jokbo_1 == ������)
	{
		if (jokbo_2 == ���ȱ��� || jokbo_2 <= �嶯)
			jokbo_1 = �Ѳ�_;
	}

	else if (jokbo_1 == ��ĥ������)
	{
		if (jokbo_2 >= �嶯 || jokbo_2 <= �˸�)
			jokbo_1 = ����;
	}

	else if (jokbo_1 == ���ֱ����籸)
	{
		if (jokbo_2 >= �嶯)
			jokbo_1 = ����;
	}

	else if (jokbo_1 == �籸)
	{
		if (jokbo_2 >= �϶�)
			jokbo_1 = ����;
	}

	return jokbo_1;
}