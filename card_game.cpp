#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef enum {
	start,
	일월, 이월, 삼월, 사월, 오월, 육월, 칠월, 팔월, 구월, 십월,
	일월광, 이월_, 삼월광, 사월특, 오월_, 육월_, 칠월특, 팔월광, 구월특, 십월_,
	end = 십월_
}card_num; 

typedef enum {
	망통 = 30, 한끗_, 한끗, 두끗, 세끗, 네끗, 다섯끗, 여섯끗, 일곱끗, 여덟끗, 갑오,
	세륙, 장사, 장삥, 구삥, 독사, 알리, 사구,
	일땡, 이땡, 삼땡, 사땡, 오땡, 육땡, 칠땡, 팔땡, 구땡, 멍텅구리사구, 삼칠땡잡이, 장땡,
	일팔광땡, 일삼광땡, 암행어사, 삼팔광땡
}card_jokbo;

void print_menu();							// 시작화면 출력
void shuffle_card(int card[]);				// 카드섞어서 나누어줌
int check_card(int card_1, int card_2);		// 카드 조합 확인 
void print_card_name(int card);				// 카드 이름 출력
void print_jokbo_name(int jokbo);			// 족보 이름 출력
int check_jokbo(int jokbo_1, int jokbo_2);	// 특수족보 조건확인

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

	while (restart != 'n') //게임 진행 및 승패 확인
	{
	regame:

		shuffle_card(card);

		int user_card_1 = card[0];
		int user_card_2 = card[1];
		int com_card_1 = card[2];
		int com_card_2 = card[3];

		user_jokbo = check_card(user_card_1, user_card_2);
		com_jokbo = check_card(com_card_1, com_card_2);

		printf("당신의 패는 ");
		print_card_name(user_card_1);
		print_card_name(user_card_2);
		print_jokbo_name(user_jokbo);
		printf("입니다.\n");

		printf("도전하시겠습니까?( y / n ) ");
		scanf_s(" %c", &start_game, sizeof(char));

		if (start_game == 'n')
		{
			printf("게임을 종료합니다.\n");
			return 0;
		}

		printf("컴퓨터의 패는 ");
		print_card_name(com_card_1);
		print_card_name(com_card_2);
		print_jokbo_name(com_jokbo);
		printf("입니다.\n");

		user_jokbo = check_jokbo(user_jokbo, com_jokbo);
		com_jokbo = check_jokbo(com_jokbo, user_jokbo);

		Sleep(500);

		if (user_jokbo == 사구 || user_jokbo == 멍텅구리사구 || com_jokbo == 사구 || com_jokbo == 멍텅구리사구)
		{
			printf("\n당신의 패 : ");
			print_jokbo_name(user_jokbo);

			printf("\n컴퓨터의 패 :");
			print_jokbo_name(com_jokbo);

			Sleep(500);

			printf("\n(멍텅구리)사구파토 재경기!!\n");
			printf("재경기하시겠습니까? ( y / n )");
			scanf_s(" %c", &restart, sizeof(char));

			if (restart == 'n')
			{
				printf("게임을 종료합니다.\n");
				return 0;
			}

			else
				printf("재경기를 시작합니다.\n");

			Sleep(1000);

			goto regame;
		}

		else
		{
			if (user_jokbo > com_jokbo)
			{
				printf("\n당신의 패 : ");
				print_jokbo_name(user_jokbo);

				printf("\n컴퓨터의 패 :");
				print_jokbo_name(com_jokbo);

				Sleep(500);

				printf("\n당신의 승리입니다.^0^\n");

				Sleep(500);

				user_win++;
			}

			else if (user_jokbo == com_jokbo)
			{
				printf("\n당신의 패 : ");
				print_jokbo_name(user_jokbo);

				printf("\n컴퓨터의 패 :");
				print_jokbo_name(com_jokbo);

				Sleep(500);

				printf("\n무승부입니다.\n");

				Sleep(500);

				draw++;
			}

			else
			{
				printf("\n당신의 패 : ");
				print_jokbo_name(user_jokbo);

				printf("\n컴퓨터의 패 :");
				print_jokbo_name(com_jokbo);

				Sleep(500);

				printf("\n컴퓨터의 승리입니다.ㅜ0ㅜ\n");

				Sleep(500);

				com_win++;
			}
		}
		Sleep(500);

		printf("\n플레이어 승리 : %d\n무승부 : %d\n컴퓨터 승리 : %d\n", user_win, draw, com_win);
		printf("계속하시겠습니까? ( y / n )");

		scanf_s(" %c", &restart, sizeof(char));
	}
	return 0;
}

void print_menu()
{
	printf("==================================================\n");
	printf("                                                  \n");
	printf("                                                  \n");
	printf("             섯                   다              \n");
	printf("                                                  \n");
	printf("                                                  \n");
	printf("         1.시작하기            2. 종료하기        \n");
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
		printf("잠시후 게임이 시작됩니다.\n");
		Sleep(1000);
	}
}

void shuffle_card(int card[])
{
	system("cls");
	printf("카드를 섞고있습니다.....\n");
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
		if ((card_1 == 십월 && card_2 == 십월_) || (card_1 == 십월_ && card_2 == 십월))
			return 장땡;

		else if ((card_1 == 오월 && card_2 == 오월_) || (card_1 == 오월_ && card_2 == 오월))
			return 오땡;

		else if ((card_1 == 일월 && card_2 == 구월) || (card_1 == 일월 && card_2 == 구월특) ||
			(card_1 == 구월 && card_2 == 일월) || (card_1 == 구월특 && card_2 == 일월) ||
			(card_1 == 구월 && card_2 == 일월광) || (card_1 == 구월특 && card_2 == 일월광) ||
			(card_1 == 일월광 && card_2 == 구월) || (card_1 == 일월광 && card_2 == 구월특))
			return 구삥;

		else if ((card_1 == 사월 && card_2 == 육월) || (card_1 == 사월 && card_2 == 육월_) ||
			(card_1 == 육월 && card_2 == 사월) || (card_1 == 육월_ && card_2 == 사월) ||
			(card_1 == 육월 && card_2 == 사월특) || (card_1 == 육월_ && card_2 == 사월특) ||
			(card_1 == 사월특 && card_2 == 육월) || (card_1 == 사월특 && card_2 == 육월_))
			return 세륙;

		else if ((card_1 == 삼월광 && card_2 == 칠월특) || (card_1 == 칠월특 && card_2 == 삼월광))
			return 삼칠땡잡이;

		else
			return 망통;

	case 1:
		if ((card_1 == 삼월광 && card_2 == 팔월광) || (card_1 == 팔월광 && card_2 == 삼월광))
			return 삼팔광땡;

		else if ((card_1 == 일월 && card_2 == 십월) || (card_1 == 일월 && card_2 == 십월_) ||
			(card_1 == 일월광 && card_2 == 십월) || (card_1 == 일월광 && card_2 == 십월_))
			return 장삥;

		if ((card_1 == 사월특 && card_2 == 칠월특) || (card_1 == 칠월특 && card_2 == 사월특))
			return 암행어사;
		else

			return 한끗;

	case 2:
		if ((card_1 == 육월 && card_2 == 육월_) || (card_1 == 육월_ && card_2 == 육월))
			return 육땡;

		else if ((card_1 == 일월 && card_2 == 일월광) || (card_1 == 일월광 && card_2 == 일월))
			return 일땡;

		else
			return 두끗;

	case 3:
		if ((card_1 == 일월 && card_2 == 이월) || (card_1 == 일월 && card_2 == 이월_) ||
			(card_1 == 이월 && card_2 == 일월) || (card_1 == 이월_ && card_2 == 일월) ||
			(card_1 == 일월광 && card_2 == 이월) || (card_1 == 일월광 && card_2 == 이월_) ||
			(card_1 == 이월 && card_2 == 일월광) || (card_1 == 이월_ && card_2 == 일월광))
			return 알리;

		else if ((card_1 == 사월특 && card_2 == 구월특) || (card_1 == 구월특 && card_2 == 사월특))
			return 멍텅구리사구;

		else if ((card_1 == 사월 && card_2 == 구월) || (card_1 == 사월 && card_2 == 구월특) ||
			(card_1 == 구월 && card_2 == 사월) || (card_1 == 구월특 && card_2 == 사월) ||
			(card_1 == 사월특 && card_2 == 구월) || (card_1 == 구월 && card_2 == 사월특))
			return 사구;

		else
			return 세끗;

	case 4:
		if ((card_1 == 삼월광 && card_2 == 일월광) || (card_1 == 일월광 && card_2 == 삼월광))
			return 일삼광땡;

		else if ((card_1 == 이월 && card_2 == 이월_) || (card_1 == 이월_ && card_2 == 이월))
			return 이땡;

		else if ((card_1 == 칠월 && card_2 == 칠월특) || (card_1 == 칠월특 && card_2 == 칠월))
			return 칠땡;

		else if ((card_1 == 사월 && card_2 == 십월) || (card_1 == 사월 && card_2 == 십월_) ||
			(card_1 == 십월 && card_2 == 사월) || (card_1 == 십월_ && card_2 == 사월) ||
			(card_1 == 십월 && card_2 == 사월특) || (card_1 == 십월_ && card_2 == 사월특) ||
			(card_1 == 사월특 && card_2 == 십월) || (card_1 == 사월특 && card_2 == 십월_))
			return 장사;

		else
			return 네끗;

	case 5:
		if ((card_1 == 사월 && card_2 == 일월) || (card_1 == 사월 && card_2 == 일월광) ||
			(card_1 == 일월 && card_2 == 사월) || (card_1 == 일월광 && card_2 == 사월) ||
			(card_1 == 일월 && card_2 == 사월특) || (card_1 == 일월광 && card_2 == 사월특) ||
			(card_1 == 사월특 && card_2 == 일월) || (card_1 == 사월특 && card_2 == 일월광))
			return 독사;
		else
			return 다섯끗;
	case 6:
		if ((card_1 == 팔월 && card_2 == 팔월광) || (card_1 == 팔월광 && card_2 == 팔월))
			return 팔땡;

		else if ((card_1 == 삼월 && card_2 == 팔월광) || (card_1 == 삼월광 && card_2 == 삼월))
			return 삼땡;

		else
			return 여섯끗;

	case 7:
		return 일곱끗;

	case 8:
		if ((card_1 == 사월 && card_2 == 사월특) || (card_1 == 사월특 && card_2 == 사월))
			return 사땡;

		else if ((card_1 == 구월 && card_2 == 구월특) || (card_1 == 구월특 && card_2 == 구월))
			return 구땡;

		else
			return 여덟끗;

	case 9:
		if ((card_1 == 팔월광 && card_2 == 일월광) || (card_1 == 일월광 && card_2 == 팔월광))
			return 일팔광땡;

		else
			return 갑오;

	default:
		printf("족보에 없는 조합입니다.\n");
		break;
	}
}

void print_card_name(int card)
{
	switch (card)
	{
	case 1: printf(" 일월 "); break;
	case 2: printf(" 이월 "); break;
	case 3: printf(" 삼월 "); break;
	case 4: printf(" 사월 "); break;
	case 5: printf(" 오월 "); break;
	case 6: printf(" 육월 "); break;
	case 7: printf(" 칠월 "); break;
	case 8: printf(" 팔월 "); break;
	case 9: printf(" 구월 "); break;
	case 10: printf(" 십월 "); break;
	case 11: printf(" 일월광 "); break;
	case 12: printf(" 이월 "); break;
	case 13: printf(" 삼월광 "); break;
	case 14: printf(" 사월특 "); break;
	case 15: printf(" 오월 "); break;
	case 16: printf(" 육월 "); break;
	case 17: printf(" 칠월특 "); break;
	case 18: printf(" 팔월광 "); break;
	case 19: printf(" 구월특 "); break;
	case 20: printf(" 십월 "); break;

	default:
		printf("사용하지 않는 카드입니다\n");
		break;
	}
}

void print_jokbo_name(int jokbo)
{
	switch (jokbo)
	{
	case 30: printf(" 망통"); break;
	case 31: printf(" 한끗_"); break;
	case 32: printf(" 한끗"); break;
	case 33: printf(" 두끗"); break;
	case 34: printf(" 세끗"); break;
	case 35: printf(" 네끗"); break;
	case 36: printf(" 다섯끗"); break;
	case 37: printf(" 여섯끗"); break;
	case 38: printf(" 일곱끗"); break;
	case 39: printf(" 여덟끗"); break;
	case 40: printf(" 갑오"); break;
	case 41: printf(" 세륙"); break;
	case 42: printf(" 장사"); break;
	case 43: printf(" 장삥"); break;
	case 44: printf(" 구삥"); break;
	case 45: printf(" 독사"); break;
	case 46: printf(" 알리"); break;
	case 47: printf(" 사구"); break;
	case 48: printf(" 일땡"); break;
	case 49: printf(" 이땡"); break;
	case 50: printf(" 삼땡"); break;
	case 51: printf(" 사땡"); break;
	case 52: printf(" 오땡"); break;
	case 53: printf(" 육땡"); break;
	case 54: printf(" 칠땡"); break;
	case 55: printf(" 팔땡"); break;
	case 56: printf(" 구땡"); break;
	case 57: printf(" 멍텅구리사구"); break;
	case 58: printf(" 삼칠땡잡이"); break;
	case 59: printf(" 장땡"); break;
	case 60: printf(" 일팔광땡"); break;
	case 61: printf(" 일삼광땡"); break;
	case 62: printf(" 암행어사"); break;
	case 63: printf(" 삼팔광땡"); break;

	default:
		printf("족보에 없는 조합입니다.");
		break;
	}
}

int check_jokbo(int jokbo_1, int jokbo_2)
{
	if (jokbo_1 == 암행어사)
	{
		if (jokbo_2 == 삼팔광땡 || jokbo_2 <= 장땡)
			jokbo_1 = 한끗_;
	}

	else if (jokbo_1 == 삼칠땡잡이)
	{
		if (jokbo_2 >= 장땡 || jokbo_2 <= 알리)
			jokbo_1 = 망통;
	}

	else if (jokbo_1 == 멍텅구리사구)
	{
		if (jokbo_2 >= 장땡)
			jokbo_1 = 세끗;
	}

	else if (jokbo_1 == 사구)
	{
		if (jokbo_2 >= 일땡)
			jokbo_1 = 세끗;
	}

	return jokbo_1;
}