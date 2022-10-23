// 문자 배열과 문자 포인터
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>

int main() {
	char sname1[20]; 
	char sname2[20] = "Kim, Ewha";
	char* sname3 = "Park, Ewha";

	strcpy(sname1, sname2);
	printf("(1) %s\n", sname1);

	strcpy(sname1, sname3); 
	printf("(2) %s\n", sname1);

	strcpy(sname1, "Choi, Ewha");
	printf("(3) %s\n", sname1);
}