// strcpy()�� ��ȯ �� ����غ���
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>
int main() {
	char s1[10];
	char s2[] = "��ȭ";
	
	if (strcmp(strcpy(s1, s2), "��ȭ") == 0)
		printf("yes");
	else
		printf("no");
}