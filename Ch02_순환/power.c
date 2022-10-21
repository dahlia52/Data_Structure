// 거듭제곱 계산 - 순환적 함수

#include <stdio.h>
#define MAX_ELEMNTS 300

double power(double x, int n) {

	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, (n - 1) / 2);
}

int main() {
	printf("%g", power(2.0, 10));
}