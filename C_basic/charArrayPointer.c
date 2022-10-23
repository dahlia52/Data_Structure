# include <stdio.h>

int main() {
	char name1[] = "Kim, Ewha"; // 문자 배열
	char* name2 = "Kim, Ewha"; // 문자열 상수를 포인터로 가리킴

	printf("%s\n", name1); 
	printf("%s\n", name2);

	name1[2] = '0'; // 문자 배열 - 수정 가능
	printf("%s\n", name1);
	name2[2] = 'X'; // 문자열 상수 - 수정 불가
	printf("%s\n", name2);
}