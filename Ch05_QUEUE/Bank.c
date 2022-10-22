// ���� ���� �ùķ��̼�
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define MAX_QUEUE_SIZE 5

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;

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
int main() {
	int minutes = 60; // �� ���� �ð�
	int total_wait = 0; // ��ü ���� ���ð� �հ�
	int total_customers = 0; // ������ �� ��
	int service_time = 0; // �� 1�� ���� �ð� (1~3��)
	int service_customer; // ���� ó������ �� ��ȣ
	
	element customer;
	QueueType queue;
	init_queue(&queue);
	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) { // 1�� ������ 1�ð� ����
		printf("����ð� = %d\n", clock);
		if ((rand() % 10) < 3) { // 0~9�� ���ڷ� ��ȯ, �� ���� ��Ȳ
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð� = %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) { // ���� ó�� ���� ���� �ִٸ� 1�а� ó��
			printf("�� %d ����ó�����Դϴ�. \n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&queue)) { // ��� ���� ���� �ִٸ�
				customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("��ü ��� �ð� = %d�� \n", total_wait);
	return 0;
}