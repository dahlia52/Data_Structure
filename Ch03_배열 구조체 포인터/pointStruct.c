# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int x, y;
} point;

int main() {
	point* p;
	p = (point*)malloc(sizeof(point));
	if (p == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1);
	}
	p->x = 10;
	p->y = 20;
	printf("(%d, %d)\n", p->x, p->y);
	free(p);
}