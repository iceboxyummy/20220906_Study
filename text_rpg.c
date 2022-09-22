#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 

typedef struct _Monster
{
	char name[256];
	int hp;
	int atk;
	int exp;
}Monster;

typedef struct 
{
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
}Player;

void rpg();

int main() {
	rpg();
	return 0;
}

void rpg()
{
	Monster monster_table[3] =
	{
		{"���� ��¡��", 100, 50, 100},
		{"����� ����", 50, 150, 200},
		{"��ƹ��� ������",350, 20, 100}
	};
	
	Player p;

	printf("������ ���Ű� ȯ���մϴ�!!\n");

	printf("����� �̸���? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("����� ü�´�? : ");
	scanf_s("%d", &p.hp);

	printf("����� ���ݷ���? : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;
	int place = 0;
	int mode = 0;

	while (1)
	{
		printf("���̵��� �����Ͽ� �ּ���.\n1.Hard 2.Nomal 3.Easy\n");
		scanf_s("%d", &mode);

		switch (mode)
		{
		case 1:
			place = 1;
			break;

		case 2:
			place = 21;
			break;

		case 3:
			place = 41;
			break;

		default:
			printf("��?\n");

			break;
		}
		if(mode==1||mode==2||mode==3)
		{
			break;
		}
	}

	printf("********** Ž�� ���� ********** \n");
	Sleep(1000);
	printf("���� ��ġ :%d\n", place);
	Sleep(1000);

	srand(time(NULL));

	while (1)
	{
		if (p.hp <= 0)
		{
			printf("%s ��� ���� ����...\n", p.name);
			break;
		}
		if (place >= 50) 
		{
			printf("�����մϴ�! %s�� ������ ���� ���� �����Ͽ����ϴ�.\n", p.name);
			break;
		}
		int event_key = rand() % 6;

		switch (event_key)
		{
		case 0: // ��� ȹ��
			printf("%s�� �������� �߰�! ��� +100\n", p.name);
			Sleep(1000);
			p.gold += 100;

			printf("���� %s�� ������ ���� %d��� �Դϴ�.\n", p.name, p.gold);
			Sleep(1000);
			 
			printf("���� ���������� ���ϴ�.\n");
			Sleep(1000);
			place++;

			printf("���� ��ġ :%d\n", place);
			Sleep(1000);
			break;

		case 1: // ü�� ȸ��
			printf("%s�� �Ŀ������� �߰�! HP +100\n", p.name);
			Sleep(1000);
			p.hp += 100;

			printf("���� %s�� ü���� %d�Դϴ�.\n", p.name, p.hp);
			Sleep(1000);

			printf("���� ���������� ���ϴ�.\n");
			Sleep(1000);
			place++;

			printf("���� ��ġ :%d\n", place);
			Sleep(1000);
			break;

		case 2: // ü�°���
			printf("%s�� ������ �������ϴ�. HP -100\n", p.name);
			Sleep(1000);
			p.hp -= 100;
			if (p.hp <= 0)
				break;

			printf("���� %s�� ü���� %d�Դϴ�.\n", p.name, p.hp);
			Sleep(1000);
		
			printf("���� ���������� ���ϴ�.\n");
			Sleep(1000);
			place++;

			printf("���� ��ġ :%d\n", place);
			Sleep(1000);
			break;
			
		case 3: // ����ġ ����
			printf("%s�� ����� ���� �߰�! EXP+100\n", p.name);
			Sleep(1000);
			p.exp += 100;

			if (p.exp >= 300)
			{
				printf("�������� �ʿ��� ����ġ 300�� ��� ��ҽ��ϴ�.\n");
				Sleep(1000);
				printf("LEVEL UP! \n%s�� ü���� 100 ��尡 100 �����մϴ�.\n", p.name);
				Sleep(1000);
				p.exp = 0;
				p.hp += 100;
				p.gold += 100;
				printf("���� %s�� ü���� %d ������ ���� %d����Դϴ�\n", p.name, p.hp, p.gold);
				Sleep(1000);
				printf("���� ���������� ���ϴ�.\n");
				Sleep(1000);
				place++;

				printf("���� ��ġ :%d\n", place);
				Sleep(1000);
				break;
			}

			printf("���� %s�� ����ġ�� %d�Դϴ�.\n", p.name, p.exp);
			Sleep(1000);

			printf("���� ���������� ���ϴ�.\n");;
			Sleep(1000);
			place++;

			printf("���� ��ġ :%d\n", place);
			Sleep(1000);
			break;

		case 4: // ���� ����
		{
			int m_num = rand() % 3;
			Monster m = monster_table[m_num];
			
			printf("%s �εε���! ���� ����!\n", m.name);
			Sleep(1000);

			while (1)
			{
				//�÷��̾��� ����
				int critical_atk = rand() % 3;

				if (critical_atk == 0)
				{
					printf("%s�� �ʻ�⸦ ����մϴ�.", p.name);
					printf("%s�� ����!\n", p.name);
					Sleep(1000);
					printf("%d�� ������!\n",2 * p.atk);
					Sleep(1000);
					printf("%s�� ü�� %d -> %d\n", m.name, m.hp, m.hp -(2 * p.atk));
					Sleep(1000);
					m.hp -= 2*p.atk;
				}
				else
				{
					printf("%s�� ����!\n", p.name);
					Sleep(1000);
					printf("%d�� ������!\n", p.atk);
					Sleep(1000);
					printf("%s�� ü�� %d -> %d\n", m.name, m.hp, m.hp - p.atk);
					Sleep(1000);
					m.hp -= p.atk;
				}

				if (m.hp <= 0)
				{
					printf("%s �¸�! exp + %d\n", p.name, m.exp);
					Sleep(1000);
					p.exp += m.exp;
					if (p.exp >= 300)
					{
						printf("�������� �ʿ��� ����ġ 300�� ��� ��ҽ��ϴ�.\n");
						Sleep(1000);
						printf("LEVEL UP! \n%s�� ü���� 100 ��尡 100 �����մϴ�.\n", p.name);
						Sleep(1000);
						p.exp = 0;
						p.hp += 100;
						p.gold += 100;
						printf("���� %s�� ü���� %d ������ ���� %d����Դϴ�\n", p.name, p.hp, p.gold);
						Sleep(1000);
						printf("���� ���� ������ ���ϴ�.\n");
						Sleep(1000);
						place++;
						printf("���� ��ġ :%d\n", place);
						Sleep(1000);
						break;
					}

					printf("���� %s�� ����ġ�� %d�Դϴ�.\n", p.name, p.exp);
					Sleep(1000);

					printf("���� ���� ������ ���ϴ�.\n");
					Sleep(1000);
					place++;
					printf("���� ��ġ :%d\n", place);
					Sleep(1000);
					break;
				}

				//������ ����
				printf("%s�� ����!\n", m.name);
				Sleep(1000);
				printf("%d�� ������!\n", m.atk);
				Sleep(1000);
				printf("%s�� ü�� %d -> %d\n", p.name, p.hp, p.hp - m.atk);
				Sleep(1000);
				p.hp -= m.atk;

				if (p.hp <= 0)
				{
					printf("%s �й�!\n", p.name);
					Sleep(1000);
					break;
				}
			}
		}
		break;

		case 5: // ����
			printf("�Ͻ����� �߰��Ͽ����ϴ�.\n");

			if (p.gold < 300)
			{
				printf("������ ��尡 �����Ͽ� ���� ���ſ� �����Ͽ����ϴ�.\n");
				Sleep(1000);
				printf("����� 300��� �Դϴ�.\n");
				Sleep(1000);
				printf("���� %s�� ������ ���� %d��� �Դϴ�.\n", p.name, p.gold);
				Sleep(1000);
				printf("���� ���������� ���ϴ�.\n");
				place++;
				printf("���� ��ġ :%d\n", place);
				Sleep(1000);
				break;
			}

			printf("300��带 ����Ͽ� ���󿡸� �ָӴϸ� �����Ͽ� ���ݷ��� 10�����մϴ�.\n");
			Sleep(1000);
			p.gold -= 300; p.atk += 10;
			printf("���� %s�� ���ݷ��� %d, ������ ���� %d����Դϴ�.\n", p.name, p.atk, p.gold);
			Sleep(1000);
			printf("���� ���������� ���ϴ�.\n");
			Sleep(1000);
			place++;
			printf("���� ��ġ :%d\n", place);
			Sleep(1000);
		break;

		default:
			printf("�߸��� Ű �Է��Դϴ�.\n");
			break;
		}
	}
}