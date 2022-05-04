#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MINUS -1
#define MAX_SIZE 10000

typedef struct _stack {
	int arr[MAX_SIZE]; // max stack size
	int top; // current stack position
} Stack;

void StackInit(Stack *sp) {
	sp->top = -1; // initialization
}

int IsEmpty(Stack *sp) {
	if (sp->top == -1) return TRUE; // top == -1 : empty
	else return FALSE;
}

int Size(Stack *sp) {
	return sp->top + 1; // top means current stack position. zero base
}

int IsFull(Stack *sp) {
	if (Size(sp) >= MAX_SIZE) return TRUE; // over the max size
	else return FALSE;
}

void Push(Stack *sp, int data) {
	if (IsFull(sp) == TRUE) return; // full means that there is no space to push.
	sp->arr[++(sp->top)] = data; // if there is enough space, add value and increase top.
}

int Pop(Stack *sp) {
	if (IsEmpty(sp) == TRUE) return; // empty means that there is no value to pop.
	return sp->arr[(sp->top)--]; // if there is a value to fetch, fetch it and decrement top.
}

int Peek(Stack *sp) {
	if (IsEmpty(sp) == TRUE) return MINUS;
	return sp->arr[sp->top];
}

int main(void) {
	int i;
	char str[6];
	Stack s;
	int n, num;

	scanf("%d", &n);
	StackInit(&s);

	for (i = 0; i < n; i++) {
		scanf("%s", str);
		fgetc(stdin);

		if (!strcmp(str, "push")) {
			scanf("%d", &num);
			fgetc(stdin);
			Push(&s, num);
		}
		else if(!strcmp(str,"pop")){
			printf("%d\n", Pop(&s));
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", IsEmpty(&s));
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", Size(&s));
		}
		else if (!strcmp(str, "top")) {
			printf("%d\n", Peek(&s));
		}
		
	}

	return 0;
}


