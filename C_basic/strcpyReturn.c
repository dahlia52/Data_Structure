// strcpy()의 반환 값 사용해보기
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>
int main() {
	char s1[10];
	char s2[] = "이화";
	
	if (strcmp(strcpy(s1, s2), "이화") == 0)
		printf("yes");
	else
		printf("no");
}