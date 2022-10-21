// 동적 메모리 할당
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	int* pi;
	pi = (int*)malloc(sizeof(int));
	if (pi == NULL) {
		fprintf(stderr, "틀림");
		exit(1);
	}
	*pi = 10;
	printf("%d\n", *pi);
	free(pi);
}