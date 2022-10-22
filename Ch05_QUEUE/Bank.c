// 은행 업무 시뮬레이션
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
int main() {
	int minutes = 60; // 총 영업 시간
	int total_wait = 0; // 전체 고객의 대기시간 합계
	int total_customers = 0; // 서비스한 고객 수
	int service_time = 0; // 고객 1명 서비스 시간 (1~3분)
	int service_customer; // 현재 처리중인 고객 번호
	
	element customer;
	QueueType queue;
	init_queue(&queue);
	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) { // 1분 단위로 1시간 수행
		printf("현재시간 = %d\n", clock);
		if ((rand() % 10) < 3) { // 0~9의 숫자로 변환, 고객 도착 상황
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간 = %d분\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) { // 현재 처리 중인 고객이 있다면 1분간 처리
			printf("고객 %d 업무처리중입니다. \n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&queue)) { // 대기 중인 고객이 있다면
				customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("전체 대기 시간 = %d분 \n", total_wait);
	return 0;
}