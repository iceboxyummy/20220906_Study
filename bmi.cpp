#include <stdio.h>

//bmi 계산기

int main() {
	
	float kg, m, bmi;

	printf("몸무게(kg)를 입력하세요.\n");
	scanf_s("%f", &kg);

	printf("키(m)를 입력하세요.\n");
	scanf_s("%f", &m);

	bmi = kg /(m * m);

	printf("bmi는 %.2f 입니다.\n", bmi);

	return 0;
}