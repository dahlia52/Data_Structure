// 2���� ����Ʈ�� ���ϴ� �Լ�
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}
ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

int main() {
	ListNode* head1 = NULL; 
	ListNode* head2 = NULL;
	printf("head1 ����Ʈ ���� ����\n");
	head1 = insert_first(head1, 30); print_list(head1);
	head1 = insert_first(head1, 20); print_list(head1); 
	head1 = insert_first(head1, 10); print_list(head1);

	printf("\nhead2 ����Ʈ ���� ����\n");
	head2 = insert_first(head2, 60); print_list(head2); 
	head2 = insert_first(head2, 50); print_list(head2); 
	head2 = insert_first(head2, 40); print_list(head2);

	printf("\n������ ����Ʈ head1\n");
	head1 = concat_list(head1, head2);
	print_list(head1);
}