// scanf()�� ��ȯ��
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main() {
	int n, a, b, c;
	char ch;

	printf("���� 3�� �Է�: ");

	n = scanf("%d %d %d", &a, &b, &c);
	printf("%d���� �о����ϴ�.\n", n);

	scanf("%c", &ch);
	printf("���� ���ڴ� %c�����ϴ�.\n", ch);

	printf("%d %d %d", a, b, c);
}