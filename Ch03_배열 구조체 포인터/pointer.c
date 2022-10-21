# include <stdio.h>

int main() {
	int a = 10;
	int* p;
	p = &a;
	printf("a = %d\n", *p); // *p는 a의 값
	printf("%d \n", p); // p는 a의 주소
	printf("%d \n", &a); // &a는 a의 주소
}