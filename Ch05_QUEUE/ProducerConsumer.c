// �������α׷� (������/�Һ���)
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
int main(void) {
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL)); // ù° random number ����

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) { // 5�� ������ �������� (����)
			enqueue(&queue, rand() % 100); // ��ǰ��ȣ�� 2�ڸ����� ����� ����
		}
		queue_print(&queue);
		if (rand() % 10 == 0) { // 10���� ������ �������� (�Һ�)
			dequeue(&queue);
		}
		queue_print(&queue);
	}
	return 0;
}