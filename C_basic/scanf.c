// scanf()의 반환값
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main() {
	int n, a, b, c;
	char ch;

	printf("숫자 3개 입력: ");

	n = scanf("%d %d %d", &a, &b, &c);
	printf("%d개를 읽었습니다.\n", n);

	scanf("%c", &ch);
	printf("다음 글자는 %c였습니다.\n", ch);

	printf("%d %d %d", a, b, c);
}