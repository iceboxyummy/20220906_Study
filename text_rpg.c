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
		{"심해 우징어", 100, 50, 100},
		{"배고픈 우진", 50, 150, 200},
		{"녹아버린 슬라임",350, 20, 100}
	};
	
	Player p;

	printf("던전에 오신걸 환영합니다!!\n");

	printf("당신의 이름은? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("당신의 체력는? : ");
	scanf_s("%d", &p.hp);

	printf("당신의 공격력은? : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;
	int place = 0;
	int mode = 0;

	while (1)
	{
		printf("난이도를 선택하여 주세요.\n1.Hard 2.Nomal 3.Easy\n");
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
			printf("쫄?\n");

			break;
		}
		if(mode==1||mode==2||mode==3)
		{
			break;
		}
	}

	printf("********** 탐험 시작 ********** \n");
	Sleep(1000);
	printf("현재 위치 :%d\n", place);
	Sleep(1000);

	srand(time(NULL));

	while (1)
	{
		if (p.hp <= 0)
		{
			printf("%s 사망 게임 종료...\n", p.name);
			break;
		}
		if (place >= 50) 
		{
			printf("축하합니다! %s가 던전의 깊은 곳에 도착하였습니다.\n", p.name);
			break;
		}
		int event_key = rand() % 6;

		switch (event_key)
		{
		case 0: // 골드 획득
			printf("%s가 보물상자 발견! 골드 +100\n", p.name);
			Sleep(1000);
			p.gold += 100;

			printf("현재 %s가 소지한 골드는 %d골드 입니다.\n", p.name, p.gold);
			Sleep(1000);
			 
			printf("더욱 깊은곳으로 들어갑니다.\n");
			Sleep(1000);
			place++;

			printf("현재 위치 :%d\n", place);
			Sleep(1000);
			break;

		case 1: // 체력 회복
			printf("%s가 파워엘릭서 발견! HP +100\n", p.name);
			Sleep(1000);
			p.hp += 100;

			printf("현재 %s의 체력은 %d입니다.\n", p.name, p.hp);
			Sleep(1000);

			printf("더욱 깊은곳으로 들어갑니다.\n");
			Sleep(1000);
			place++;

			printf("현재 위치 :%d\n", place);
			Sleep(1000);
			break;

		case 2: // 체력감소
			printf("%s가 함정에 빠졌습니다. HP -100\n", p.name);
			Sleep(1000);
			p.hp -= 100;
			if (p.hp <= 0)
				break;

			printf("현재 %s의 체력은 %d입니다.\n", p.name, p.hp);
			Sleep(1000);
		
			printf("더욱 깊은곳으로 들어갑니다.\n");
			Sleep(1000);
			place++;

			printf("현재 위치 :%d\n", place);
			Sleep(1000);
			break;
			
		case 3: // 경험치 증가
			printf("%s가 고대의 유물 발견! EXP+100\n", p.name);
			Sleep(1000);
			p.exp += 100;

			if (p.exp >= 300)
			{
				printf("레벨업에 필요한 경험치 300을 모두 모았습니다.\n");
				Sleep(1000);
				printf("LEVEL UP! \n%s의 체력이 100 골드가 100 증가합니다.\n", p.name);
				Sleep(1000);
				p.exp = 0;
				p.hp += 100;
				p.gold += 100;
				printf("현재 %s의 체력은 %d 소지한 골드는 %d골드입니다\n", p.name, p.hp, p.gold);
				Sleep(1000);
				printf("더욱 깊은곳으로 들어갑니다.\n");
				Sleep(1000);
				place++;

				printf("현재 위치 :%d\n", place);
				Sleep(1000);
				break;
			}

			printf("현재 %s의 경험치는 %d입니다.\n", p.name, p.exp);
			Sleep(1000);

			printf("더욱 깊은곳으로 들어갑니다.\n");;
			Sleep(1000);
			place++;

			printf("현재 위치 :%d\n", place);
			Sleep(1000);
			break;

		case 4: // 몬스터 등장
		{
			int m_num = rand() % 3;
			Monster m = monster_table[m_num];
			
			printf("%s 두두둥장! 전투 시작!\n", m.name);
			Sleep(1000);

			while (1)
			{
				//플레이어의 공격
				int critical_atk = rand() % 3;

				if (critical_atk == 0)
				{
					printf("%s가 필살기를 사용합니다.", p.name);
					printf("%s의 공격!\n", p.name);
					Sleep(1000);
					printf("%d의 데미지!\n",2 * p.atk);
					Sleep(1000);
					printf("%s의 체력 %d -> %d\n", m.name, m.hp, m.hp -(2 * p.atk));
					Sleep(1000);
					m.hp -= 2*p.atk;
				}
				else
				{
					printf("%s의 공격!\n", p.name);
					Sleep(1000);
					printf("%d의 데미지!\n", p.atk);
					Sleep(1000);
					printf("%s의 체력 %d -> %d\n", m.name, m.hp, m.hp - p.atk);
					Sleep(1000);
					m.hp -= p.atk;
				}

				if (m.hp <= 0)
				{
					printf("%s 승리! exp + %d\n", p.name, m.exp);
					Sleep(1000);
					p.exp += m.exp;
					if (p.exp >= 300)
					{
						printf("레벨업에 필요한 경험치 300을 모두 모았습니다.\n");
						Sleep(1000);
						printf("LEVEL UP! \n%s의 체력이 100 골드가 100 증가합니다.\n", p.name);
						Sleep(1000);
						p.exp = 0;
						p.hp += 100;
						p.gold += 100;
						printf("현재 %s의 체력은 %d 소지한 골드는 %d골드입니다\n", p.name, p.hp, p.gold);
						Sleep(1000);
						printf("더욱 깊은 곳으로 들어갑니다.\n");
						Sleep(1000);
						place++;
						printf("현재 위치 :%d\n", place);
						Sleep(1000);
						break;
					}

					printf("현재 %s의 경험치는 %d입니다.\n", p.name, p.exp);
					Sleep(1000);

					printf("더욱 깊은 곳으로 들어갑니다.\n");
					Sleep(1000);
					place++;
					printf("현재 위치 :%d\n", place);
					Sleep(1000);
					break;
				}

				//몬스터의 공격
				printf("%s의 공격!\n", m.name);
				Sleep(1000);
				printf("%d의 데미지!\n", m.atk);
				Sleep(1000);
				printf("%s의 체력 %d -> %d\n", p.name, p.hp, p.hp - m.atk);
				Sleep(1000);
				p.hp -= m.atk;

				if (p.hp <= 0)
				{
					printf("%s 패배!\n", p.name);
					Sleep(1000);
					break;
				}
			}
		}
		break;

		case 5: // 상점
			printf("암시장을 발겼하였습니다.\n");

			if (p.gold < 300)
			{
				printf("소지한 골드가 부족하여 무기 구매에 실패하였습니다.\n");
				Sleep(1000);
				printf("무기는 300골드 입니다.\n");
				Sleep(1000);
				printf("현재 %s가 소지한 골드는 %d골드 입니다.\n", p.name, p.gold);
				Sleep(1000);
				printf("더욱 깊은곳으로 들어갑니다.\n");
				place++;
				printf("현재 위치 :%d\n", place);
				Sleep(1000);
				break;
			}

			printf("300골드를 사용하여 도라에몽 주머니를 구매하여 공격력이 10증가합니다.\n");
			Sleep(1000);
			p.gold -= 300; p.atk += 10;
			printf("현재 %s의 공격력은 %d, 소지한 골드는 %d골드입니다.\n", p.name, p.atk, p.gold);
			Sleep(1000);
			printf("더욱 깊은곳으로 들어갑니다.\n");
			Sleep(1000);
			place++;
			printf("현재 위치 :%d\n", place);
			Sleep(1000);
		break;

		default:
			printf("잘못된 키 입력입니다.\n");
			break;
		}
	}
}