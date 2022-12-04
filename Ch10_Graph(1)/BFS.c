// �ʺ� �켱 Ž�� (BFS) - ���� ��� �̿�
# include <stdio.h>
# include <stdlib.h>
# define MAX_VERTICES 10
# define MAX_QUEUE_SIZE 10

// ť �ڵ�
typedef int element; // ť�� ��� Ÿ��

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ť �ʱ�ȭ
void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}
int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ �����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ���� �����Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


// �׷��� �ڵ�
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// �׷��� �ʱ�ȭ
void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// ���� ���� ����
void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ���� ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
int visited[MAX_VERTICES]; //��� �湮 ǥ��

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q; // ť ����

	init_queue(&q);
	visited[v] = 1;
	printf("%d  �湮 -> ", v);
	enqueue(&q, v);

	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = 1;
				printf("%d  �湮 -> ", w);
				enqueue(&q, w); // �湮�� ������ ť�� ����
			}
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 6; i++) // ��� ����
		insert_vertex(g, i);

	insert_edge(g, 0, 2); insert_edge(g, 2, 1);
	insert_edge(g, 2, 3); insert_edge(g, 0, 4);
	insert_edge(g, 4, 5); insert_edge(g, 1, 5);

	printf("�ʺ� �켱 Ž��\n");
	bfs_mat(g, 0);
	printf("\n");

	free(g);
}