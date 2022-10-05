#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define SIZE 5

void suffle();
void print_bingo_board();
void select_num();

int count_bingo();
int bingo = 0;
int bingo_board[SIZE][SIZE]
= { {1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25} };

int main() {

	suffle();
	while (bingo < 5)
	{
		print_bingo_board(); 
		select_num();
		count_bingo();
	}
	printf("축하합니다!! 빙고 5줄을 완성하였습니다!!\n");
}

void suffle() //숫자 섞기
{
	srand(time(NULL));

	int i = 0;

	while (i < 50)
	{
		int a = rand() % SIZE;
		int b = rand() % SIZE;
		int c = rand() % SIZE;
		int d = rand() % SIZE;

		int temp;

		temp = bingo_board[a][b];
		bingo_board[a][b] = bingo_board[c][d];
		bingo_board[c][d] = temp;

		i++;
	}
}

void print_bingo_board()
{
	system("cls"); 
	
	printf("\n\t\t\t**********BINGO GAME**********\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("\t%d\t", bingo_board[i][j]);
		printf("\n\n");
	}
	printf("현재 %d 빙고 입니다.\n", bingo);
}

void select_num() //선택한순자 0으로
{
	int num = 0;
	printf("숫자를 선택해주세요(1~25) : ");
	scanf_s("%d", &num);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			if (num == bingo_board[i][j])
				bingo_board[i][j] = 0;
	}
}

int count_bingo()
{
	int sum = 1;
	bingo = 0;

	for (int i = 0; i < SIZE; i++) // 가로빙고
	{
		sum = 0;
		for (int j = 0; j < SIZE; j++)
		{
			sum += bingo_board[i][j];
		}
		if (sum == 0)
			bingo++;
	}sum = 0;

	for (int i = 0; i < SIZE; i++) // 세로빙고
	{
		sum = 0;
		for (int j = 0; j < SIZE; j++)
		{
			sum += bingo_board[j][i];
		}
		if (sum == 0)
			bingo++;
	}sum = 0;

	for (int i = 0; i < SIZE; i++) // 대각선빙고 ↘
		sum += bingo_board[i][i];	
	if (sum == 0)
	{
		bingo++;
		sum = 0;
	} sum = 0;

	for (int i = 0; i < SIZE; i++) // 대각선빙고 ↗
		sum += bingo_board[i][SIZE - (i + 1)];
	if (sum == 0)
	{
		bingo++;
		sum = 0;
	}
	print_bingo_board();

	return bingo;
}