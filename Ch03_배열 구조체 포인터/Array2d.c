// 2���� �迭�� ���� �Ҵ�
# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

int main() {
	int(*p)[7];
	int i, j;

	p = (int(*)[7])malloc(sizeof(int) * 5 * 7);
	if (p == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
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