//가위바위보-상대는가위

#include <stdio.h>

int main() {
	int user;

	printf("가위바위보를 시작합니다\n");
	printf("1.가위 2.바위 3.보\n");
	scanf_s("%d", &user);

	switch (user){
	case 1:
		printf("컴퓨터는 가위를 냈습니다.\n");
		printf("비겼습니다.\n");
		break;

	case 2:
		printf("컴퓨터는 가위를 냈습니다.\n");
		printf("이겼습니다.\n");
		break;
		
	case 3:
		printf("컴퓨터는 가위를 냈습니다.\n");
		printf("졌습니다.\n");
		break;

	default:
		printf("잘못된입력입니다.");
		break;
	}
	return 0;
}