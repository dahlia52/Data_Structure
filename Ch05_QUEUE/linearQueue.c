// 선형 큐
# include <stdio.h>
# include <stdlib.h>
# define MAX_QUEUE_SIZE 5

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
// 큐 출력
void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
// 큐의 포화 상태 검출
int is_full(QueueType* q) {
	if (q->rear == (MAX_QUEUE_SIZE - 1))
		return 1;
	else return 0;
}
// 큐의 공백 상태 검출
int is_empty(QueueType* q) {
	if (q->rear == q->front)
		return 1;
	else return 0;
}
// 큐에 삽입
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화 상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}
// 큐에서 삭제
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백 상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}
int main(void) {
	int item = 0;
	QueueType q;
	init_queue(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q); 
}