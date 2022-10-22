// 구조체 배열의 동적 할당
# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct {
	int x, y;
}point;
int main() {
	point* p;
	p = (point*)malloc(sizeof(point) * 5); // 크기가 5인 점 배열 할당
	if (p == NULL) {
		fprintf(stderr, "할당 오류");
		exit(1);
	}
	for (int i = 0; i < 5; i++) {
		p[i].x = i; p[i].y = i * 10;
	}
	for (int i = 0; i < 5; i++)
		printf("(%d, %d)\n", p[i].x, p[i].y);
	printf("\n");
	free(p);
}