#include<stdio.h>
#include<string.h>

#define MAX_SIZE 4
#define TRUE 1
#define FALSE 0



typedef struct _queue {
	int front;
	int rear;
	int arr[MAX_SIZE];
} Queue;

void QueueInit(Queue *qp) {
	qp->front = 0; // initialization
	qp->rear = 0; // initialization
}

int IsEmpty(Queue *qp) {
	if (qp->rear == qp->front) return TRUE; // front == rear : empty
	else return FALSE;
}

int IsFull(Queue *qp) {
	if ((qp->rear + 1) % MAX_SIZE == qp->front) {
		printf("Q is Full\n");
		return TRUE; // % caluator is necessary
	}
	else return FALSE;
}

int Push(Queue *qp, int data) {
	if (IsFull(qp) == TRUE) {
		printf("Q is Full (rear : %d, front : %d)\n", qp->rear, qp->front);
		return FALSE; // full means that there is no space to push.
	}
	qp->rear = (qp->rear + 1) % MAX_SIZE;
	
	printf("Push Cmd :: push %d (rear : %d, front : %d)\n", data, qp->rear, qp->front);
	qp->arr[qp->rear] = data; // if there is enough space, add value and increase top.
	
	return TRUE;
}

int Pop(Queue *qp) {
	if (IsEmpty(qp) == TRUE) return FALSE; // empty means that there is no value to pop.

	qp->front = qp->front + 1;
	printf("PoP Cmd :: Pop (rear : %d, front : %d)\n", qp->rear, qp->front % MAX_SIZE);
	return qp->arr[(qp->front) % MAX_SIZE]; // if there is a value to fetch, fetch it and decrement top.
}

int main(void) {
	int i;
	char str[6];
	Queue q;
	int n, num;

	scanf("%d", &n);
	QueueInit(&q);

	for (i = 0; i < n; i++) {
		scanf("%s", str);
		fgetc(stdin);

		if (!strcmp(str, "push")) {
			scanf("%d", &num);
			fgetc(stdin);
			Push(&q, num);
		}
		else if (!strcmp(str, "pop")) {
			printf("%d\n", Pop(&q));
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", IsEmpty(&q));
		}
	}

	return 0;
}