// strcmp �����غ���

#include <stdio.h>

int compare(char string1[], char string2[]);

int main(void) {
	char str_1[] = "abc";
	char str_2[] = "abc";
	char str_3[] = "abb";
	char str_4[] = "abd";

	printf("�� ���ڿ��� ���ٸ� 0, �� ���ڿ��� �۴ٸ� ���� ũ�ٸ� ���\n");
    printf("%s�� %s�� �� : %d\n", str_1, str_2, compare(str_1, str_2));
    printf("%s�� %s�� �� : %d\n", str_1, str_3, compare(str_1, str_3));
    printf("%s�� %s�� �� : %d\n", str_1, str_4, compare(str_1, str_4));

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