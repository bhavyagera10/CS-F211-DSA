#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef EMPhh
#define EMPhh

typedef struct {
	char name[11];
	 int ids;
} emp;
#endif

#ifndef STACKhh
#define STACKhh


struct int_pair_node{
	int left;
	int right;
	struct int_pair_node* next;
};

typedef struct int_pair_node Node;
typedef struct {
	Node* top;
	int size;
	int p;
} Stack;
typedef Stack sstt;

Stack* new_stack();
void push(Stack* stack, int xi, int yi);
Node pop(Stack* stack);
int isFull(Stack * a);

int isEmpty(Stack * a);
#endif