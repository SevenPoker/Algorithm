#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*
	Hash??
	(Value = key) matching
	ex) for(int i = 0; i< 100; i++)
			arr[i] = i + 100;
		n (key) matches n+100 (value)

	Famous hash algorithm is MD5, SHA

	[Make simple hash algorithm]
	
	#define MAX_SIZE 100
	int has[MAX_SIZE][5];

	void insert(int a[], int n) { // suppose no same value exsist
		for (int i = 0; i < n; i++) {
			if (a[i] >= 0) {
				has[a[i]][0] = 1;
			}
		}
	}

	int search(int X) {
		if (X >= 0) {
			if (has[X][0] == 1) return 1;
			else return 0;
		}
		return 0;
	}

	https://www.geeksforgeeks.org/hashing-set-1-introduction/
*/

// baekjoon 1920 sol
// using Hash Table

#define MAX_SIZE 214749

struct Node {
	int data;
	Node* next;
};

Node* Hash_Table[MAX_SIZE];

int GetKey(int data) {
	if (data < 0) return ((data / 10000) * (-1));
	else return (data / 10000);
}

void Insert(int data) {
	int key = GetKey(data);
	Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	
	Node* origin = Hash_Table[key];
	if (origin == NULL) {
		node->next = NULL;
		Hash_Table[key] = node;
	}
	else { // front input because of runtime
		node->next = Hash_Table[key];
		Hash_Table[key] = node;
	}
}

int Search(int data) {
	int key = GetKey(data);
	if (Hash_Table[key] == NULL) return 0;

	if (Hash_Table[key]->data == data) return 1; // first search found!!
	else {
		Node* tmp = Hash_Table[key];
		while (tmp) {
			if (tmp->data == data) return 1;
			tmp = tmp->next;
		}
	}
	return 0;
}	

int main() {
	int N;
	int A;
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%d",&A);
		Insert(A);
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &A);
		printf("%d\n", Search(A));
	}

	return 0;
}