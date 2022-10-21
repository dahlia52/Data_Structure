# include <stdio.h>

int main() {
	int x;
	int* p;
	x = 10;
	p = &x;
	
	printf("x=%d \n", x);
	printf("*p=%d \n", *p);
	*p = 20;
	printf("x=%d \n", x);

	*p = *p * 2;
	printf("x=%d \n", x);
}