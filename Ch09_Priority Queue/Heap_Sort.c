// 힙 구조
# include <stdio.h>
# include <stdlib.h>
# define MAX_ELEMENT 200
# define SIZE 8

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size; // 현재 힙에 저장되어 있는 데이터 개수
} HeapType;

// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

//초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

// 삽입
// 현재 요소의 개수가 heap_size인 힙 h에 item을 삽입
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}

// 삭제
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1]; // 루트 노드
	temp = h->heap[(h->heap_size)--]; // 마지막 노드 값
	parent = 1;
	child = 2; // 왼쪽 자식

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾음. (왼쪽 자식 vs. 오른쪽 자식)
		if ((child < h->heap_size) && (h->heap[child].key) < (h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		h->heap[child] = temp;
		
		parent = child; // 한 층 내려감
		child *= 2; // 왼쪽 자식 노드
	}
	h->heap[parent] = temp;
	return item; // 삭제할 루트 노드 반환
}
// 힙 정렬
void heap_sort(element a[], int n) {
	int i;
	HeapType* h;
	h = create();
	init (h);
	for (int i = 0; i < n; i++)
		insert_max_heap(h, a[i]);
	// max heap을 사용하였으므로 오름차순 정렬을 위해 힙으로 삭제되는 요소들을 배열의 뒤쪽에서 앞쪽으로 채워나감.
	for (i = n - 1; i >= 0; i--)
		a[i] = delete_max_heap(h); 
	free(h);
}

void print_heap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("< %d > ", h->heap[i].key);
	printf("\n----------------------------\n");
}

int main() {
	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}
