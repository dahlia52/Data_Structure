// 원형 연결 리스트
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head; // 자기 자신 노드를 가리킴.
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link - head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return;
	p = head->link; // 첫째 노드
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d", p->data); // 마지막 노드 출력
}
int main() {
	ListNode* head = NULL;
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_last(head, 10);
	print_list(head);
}