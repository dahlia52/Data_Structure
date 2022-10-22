// 응용프로그램 (생산자/소비자)
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
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
int main(void) {
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL)); // 첫째 random number 정함

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) { // 5로 나누어 떨어지면 (생산)
			enqueue(&queue, rand() % 100); // 상품번호를 2자리수로 만들어 저장
		}
		queue_print(&queue);
		if (rand() % 10 == 0) { // 10으로 나누어 떨어지면 (소비)
			dequeue(&queue);
		}
		queue_print(&queue);
	}
	return 0;
}