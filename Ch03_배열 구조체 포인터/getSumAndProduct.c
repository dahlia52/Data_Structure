# include <stdio.h>

void getSumAndProduct(int a, int b, int* sum_ptr, int* prod_ptr) {
	*sum_ptr = a + b;
	*prod_ptr = a * b;
}
int main() {
	int x = 10, y = 20;
	int sum, prod;

	getSumAndProduct(x, y, &sum, &prod);
	printf("ÇÕ°è = %d, °ö = %d", sum, prod);
}