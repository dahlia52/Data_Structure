// 기수 정렬
#include <stdio.h>
#include <stdlib.h>
# define MAX_QUEUE_SIZE 100

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

// 정렬
# define BUCKETS 10
# define DIGITS 4

void radix_sort(int list[], int n){
    int i, b, d, factor=1;
    QueueType queues[BUCKETS];
    
    // 큐들의 초기화
    for (b=0; b<BUCKETS; b++)
        init_queue(&queues[b]);
    
    for (d=0; d<DIGITS; d++){
        // 데이터를 자릿수에 따라 큐에 입력
        for (i=0; i<n; i++)
            enqueue(&queues[(list[i]/factor)%10], list[i]);
            
        // 버킷에서 꺼내어 리스트로 합치기
        for (b=i=0; b<BUCKETS; b++)
            while(!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor *= 10; // 그 다음 자릿수로 감
    }
}

#define SIZE 10
#include <time.h>

int main(){
    int list[SIZE];
    srand((unsigned)time(NULL));
    
    for (int i=0; i<SIZE; i++)
        list[i] = rand()%100;
    
    radix_sort(list, SIZE); // 기수 정렬 호출
    
    for (int i=0; i<SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}
