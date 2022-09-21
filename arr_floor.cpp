// 과제 floor 완성
#include <stdio.h>

void floor();

int main() {
	floor();
	return 0;
}
void floor() {
	int floor[4][3] = { 0 };
	int floor_people = 0; // 각 층의 인원수
	int total_people = 0; // 전체 인원수

	for (int i = 0; i < 4; i++) // 인원수 입력
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d층 %d호에 살고있는 인원수를 입력하세요 : ", i + 1, j + 1);
			scanf_s("%d", &floor[i][j]);
		}
	}

	for (int i = 0; i < 4; i++) // 인원수 출력
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d층 %d호에 살고있는 인원은 %d명입니다.\n", i + 1, j + 1,floor[i][j]);
		}
	}
	 
	for (int i = 0; i < 4; i++) // 각 층의 총 인원수 출력
	{
		for (int j = 0; j < 3; j++)
		{
			floor_people += floor[i][j];
		}
		printf("%d층에 살고있는 인원은 %d명입니다.\n", i + 1, floor_people);
		floor_people = 0;
	}

	for (int i = 0; i < 4; i++) // 전체 인원수 출력
	{
		for (int j = 0; j < 3; j++)
		{
			total_people += floor[i][j];
		}
	}
	printf("아파트에 살고있는 인원은 %d명입니다", total_people);
}
