# include <stdio.h>

int main() {
	int a = 10;
	int* p;
	p = &a;
	printf("a = %d\n", *p); // *p�� a�� ��
	printf("%d \n", p); // p�� a�� �ּ�
	printf("%d \n", &a); // &a�� a�� �ּ�
}