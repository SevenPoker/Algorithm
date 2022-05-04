#include <stdio.h>
#include <string.h>
#include <malloc.h>
// Make single linked list struct
typedef struct NODE {
	int data;
	struct NODE* next;
} Node;

Node* NodeInit(int data) { // Node initialization
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int IsEmpty(Node* node) {
	if (node == NULL) {
		printf("Empty List\n");
		return 1;
	}
	return 0;
}

void AppendNode(Node** head, Node* newNode) {
	if (*head == NULL) *head = newNode;
	else {
		Node* tail = *head;
		while (tail->next != NULL) tail = tail->next;
		tail->next = newNode;
	}
}

Node* SearchNode(Node* list, int data) {
	if (IsEmpty(list)) return NULL;

	while (list != NULL) {
		if (list->data == data) {
			printf("Data Found %d\n", data);
			return list;
		} 
		list = list->next;
	}

	printf("No list\n");
	return NULL;
}

Node* RemoveNode(Node** head, int data) {
	if (IsEmpty(*head)) return NULL; 
	Node* target = SearchNode(*head, data);
	if (target == NULL) return NULL;

	if (*head == target) *head = target->next;
	else {
		Node* current = *head;
		while (current->next != target) {
			current = current->next;
		}
		current->next = target->next;
	}
	target->next = NULL;
	return target;
}

void DestroyNode(Node* target) {
	free(target);
}

void DestroyList(Node** head) { // should do because of malloc
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
	int input, data;

	newNode = NodeInit(100);
	AppendNode(&A, newNode);
	newNode = NodeInit(200);
	AppendNode(&A, newNode);
	newNode = NodeInit(300);
	AppendNode(&A, newNode);
	PrintList(A);

	DestroyNode(RemoveNode(&A, 100));
	PrintList(A);
	DestroyNode(RemoveNode(&A, 200));
	PrintList(A);
	DestroyNode(RemoveNode(&A, 300));
	PrintList(A);

	DestroyList(&A);
	return 0;
}