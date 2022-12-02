// 깊이 우선 탐색 (DFS)
# include <stdio.h>
# include <stdlib.h>
# define MAX_VERTICES 50

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

int visited[MAX_VERTICES]; // 노드 방문 표시

// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(GraphType* g, int v) {
	visited[v] = 1; // 정점 v의 방문 표시
	printf("정점 %d -> ", v); // 방문한 정점 출력
	for (int w = 0; w < g->n; w++) // 인접 정점 탐색
		if (g->adj_mat[v][w] && !visited[w]) // 인접한 노드이고 아직 방문하지 않았다면
			dfs_mat(g, w); // 정점 w에서 DFS 새로 시작
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) // 노드 삽입
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2); insert_edge(g, 0, 3);
	insert_edge(g, 1, 2); insert_edge(g, 2, 3);

	printf("깊이 우선 탐색\n");
	dfs_mat(g, 0); // root 0부터 시작하여 탐색
	printf("\n");
	free(g);
}