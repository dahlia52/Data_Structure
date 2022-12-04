// 너비 우선 탐색 (BFS) - 인접 행렬 이용
# include <stdio.h>
# include <stdlib.h>
# define MAX_VERTICES 10
# define MAX_QUEUE_SIZE 10

// 큐 코드
typedef int element; // 큐의 요소 타입

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 큐 초기화
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
		error("큐가 포화 상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백 상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


// 그래프 코드
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
	if ((g->n + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
int visited[MAX_VERTICES]; //노드 방문 표시

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q; // 큐 생성

	init_queue(&q);
	visited[v] = 1;
	printf("%d  방문 -> ", v);
	enqueue(&q, v);

	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = 1;
				printf("%d  방문 -> ", w);
				enqueue(&q, w); // 방문한 정점을 큐에 저장
			}
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 6; i++) // 노드 삽입
		insert_vertex(g, i);

	insert_edge(g, 0, 2); insert_edge(g, 2, 1);
	insert_edge(g, 2, 3); insert_edge(g, 0, 4);
	insert_edge(g, 4, 5); insert_edge(g, 1, 5);

	printf("너비 우선 탐색\n");
	bfs_mat(g, 0);
	printf("\n");

	free(g);
}