// 가위바위보

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int user = 0, com = 0 ;
	int win_user = 0, win_com = 0;

	while (1) {
		printf("1.가위 2.바위 3.보 4.종료하기 \n");
		scanf_s(" %d", &user);
		com = rand() % 3 + 1;

		switch (user)
		{
		case 1:
			if (com == 1)
			{
				printf("컴퓨터는 가위! 비겼습니다!\n");
				break;
			}


			else if (com == 2)
			{
				printf("컴퓨터는 바위! 컴퓨터가 이겼습니다!\n");
				win_com++;
				break;
			}

			else
			{
				printf("컴퓨터는 보! 당신이 이겼습니다!\n");
				win_user++;
				break;
			}

		case 2:
			if (com == 1)
			{
				printf("컴퓨터는 가위! 당신이 이겼습니다!\n");
				win_user++;
				break;
			}

			else if (com == 2)
			{
				printf("컴퓨터는 바위! 비겼습니다!\n");
				break;
			}

			else
			{
				printf("컴퓨터는 보! 컴퓨터가 이겼습니다!\n");
				win_com++;
				break;
			}

		case 3:
			if (com == 1)
			{
				printf("컴퓨터는 가위! 컴퓨터가 이겼습니다!\n");
				win_com++;
				break;
			}

			else if (com == 2)
			{
				printf("컴퓨터는 바위! 당신이 이겼습니다!\n");
				win_user++;
				break;
			}

			else
			{
				printf("컴퓨터는 보! 비겼습니다!\n");
				break;
			}

		case 4: 
			break;

		default:
			printf("잘못된 입력입니다 다시입력하세요\n");
			break;

		}

		if (win_com == 3)
		{
			printf("컴퓨터의 승리!\n");
			break;
		}

		if (win_user == 3)
		{
			printf("당신의 승리!\n");
			break;
		}
	}
	return 0;
}