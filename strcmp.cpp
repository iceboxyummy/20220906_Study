// strcmp 구현해보기

#include <stdio.h>

int compare(char string1[], char string2[]);

int main(void) {
	char str_1[] = "abc";
	char str_2[] = "abc";
	char str_3[] = "abb";
	char str_4[] = "abd";

	printf("두 문자열이 같다면 0, 앞 문자열이 작다면 음수 크다면 양수\n");
    printf("%s와 %s를 비교 : %d\n", str_1, str_2, compare(str_1, str_2));
    printf("%s와 %s를 비교 : %d\n", str_1, str_3, compare(str_1, str_3));
    printf("%s와 %s를 비교 : %d\n", str_1, str_4, compare(str_1, str_4));

	return 0;
}

int compare(char string1[], char string2[]) {

    int i = 0;
   
    while (string1[i] != '\0' || string2[i] != '\0') {
      
        if (string1[i] == string2[i])\
        {
            i++;
            continue;
        }

        else if (string1[i] > string2[i])
            return 1;

        else if (string1[i] < string2[i])
            return -1;

        i++;
    }

    if (string1[i] == string2[i])
        return 0; 

    else if (string1[i] != '\0')
        return 1; 

    else
        return -1;
}