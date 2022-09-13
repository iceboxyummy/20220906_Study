#include <stdio.h>

//환율계산기

int main() {

	float won, dollar;

	printf("원화를 입력하세요.\n");
	scanf_s("%f", &won);

	dollar = won * 0.00072;
	printf("%.1f원은 %.3f달러입니다.\n", won, dollar);

	return 0;
}