# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int x, y;
} point;

int main() {
	point* p;
	p = (point*)malloc(sizeof(point));
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}
	p->x = 10;
	p->y = 20;
	printf("(%d, %d)\n", p->x, p->y);
	free(p);
}