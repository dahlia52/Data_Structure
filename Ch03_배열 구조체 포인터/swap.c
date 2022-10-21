# include <stdio.h>

void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
int main() {
	int a = 10, b = 20;
	printf("(1) a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("(2) a = %d, b = %d\n", a, b);
}