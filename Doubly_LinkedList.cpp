#include <stdio.h>
#include <string.h>
#include <malloc.h>
// Make doubly linked list struct

typedef struct NODE {
	int data;
	struct NODE* prev;
	struct NODE* next;
} Node;

Node* NodeInit(int data) { // Node initialization
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

int IsEmpty(Node* node) { // Check node empty
	if (node == NULL) {
		printf("Empty Doubly Linked List\n");
		return 1;
	}
	return 0;
}

void AppendNode(Node** head, Node* newNode) {
	printf("[Append Node]\n");
	if (*head == NULL) *head = newNode;
	else {
		Node* tail = *head;
		while (tail->next != NULL) tail = tail->next;
		tail->next = newNode;
		newNode->prev = tail;
	}
}

void InsertNode(Node** head, Node* newNode, int pos) {
	printf("[InsertNode]\n");
	if (*head == NULL) return;
	else {
		int cnt = 0;
		Node* tmp = *head;
		while (cnt < pos) {
			tmp = tmp->next;
			if (tmp == NULL) {
				printf("Position is over in this List so Last input");
				break;
			}
			cnt++;
		}
		newNode->prev = tmp->prev;
		newNode->next = tmp;
		if (tmp != NULL) {
			tmp->prev->next = newNode;
			tmp->prev = newNode;
		}
	}
}

Node* DataBase_SearchNode(Node* list, int data) {
	printf("[DataBase_SearchNode]\n");
	if (IsEmpty(list)) return NULL;
	int cnt = 1;
	while (list != NULL) {
		if (list->data == data) {
			printf("[%d] Data Found %d\n", cnt, data);
			return list;
		}
		list = list->next;
		cnt++;
	}

	printf("No List\n");
	return NULL;
}

Node* PosBase_SearchNode(Node* head, int pos) {
	printf("[PosBase_SearchNode]\n");
	if (head == NULL) return NULL;
	else {
		int cnt = 0;
		Node* tmp = head;
		while (cnt < pos) {
			tmp = tmp->next;
			if (tmp == NULL) {
				printf("Position is over in this List so Last Node return");
				return tmp;
			}
			cnt++;
		}
		return tmp->prev;
	}
}

void DestroyNode(Node* target) {
	printf("[DestroyNode]\n");
	free(target);
}

void PosBase_RemoveNode(Node** head, int pos) {
	printf("[PosBase_RemoveNode]\n");
	if (IsEmpty(*head)) return;

	int cnt = 0;
	Node* target = *head;
	while (cnt < pos) {
		target = target->next;
		if (target == NULL) {
			printf("Position is over in this List so Last Node return");
			break;
		}
		cnt++;
	}
	//printf("target : %p , head : %p [%d] \n", target, *head, target->data);
	// target -> prev
	//printf("target : %d , head : %d\n", target->prev->next->data, target->next->data);
	target->prev->next = target->next;
	//printf("target : %d , head : %d\n", target->next->prev->data, target->prev->data);
	target->next->prev = target->prev;
	target->next = NULL;
	target->prev = NULL;
	DestroyNode(target);
}

void DestroyList(Node** head) { // should do because of malloc
	printf("[DestroyList]\n");
	Node* remove = *head;
	Node* next = *head;
	while (remove != NULL) {
		next = next->next;
		free(remove);
		remove = next;
	}
	*head = NULL;
}

void PrintList(Node* current) {
	if (!IsEmpty(current)) {
		while (current != NULL) {
			printf("[%p] %d [%p]\n", current, current->data, current->next);
			current = current->next;
		}
	}
}

int main(void) {

	Node* A = NULL;
	Node* newNode = NULL;
	Node* tmpp = NULL;
	int input, data;

	for (int a = 1; a < 21; a++) {
		newNode = NodeInit(a);
		AppendNode(&A, newNode);
	}
	PrintList(A);
	newNode = NodeInit(100);
	InsertNode(&A, newNode, 10);
	PrintList(A);

	newNode = NodeInit(500);
	InsertNode(&A, newNode, 10);
	PrintList(A);

	tmpp = DataBase_SearchNode(A, 100);
	printf("%d\n", tmpp->data);
	tmpp = PosBase_SearchNode(A, 13);
	printf("%d\n", tmpp->data);

	PosBase_RemoveNode(&A, 12);
	PrintList(A);
	PosBase_RemoveNode(&A, 12);
	PrintList(A);
	PosBase_RemoveNode(&A, 1);
	PrintList(A);

	DestroyList(&A);
	PrintList(A);
	return 0;
}