// 2차원 배열의 동적 할당
# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

int main() {
	int(*p)[7];
	int i, j;

	p = (int(*)[7])malloc(sizeof(int) * 5 * 7);
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++)
			p[i][j] = i * 10 + j;
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++)
			printf("%4d ", p[i][j]);
		printf("\n");
	}
}