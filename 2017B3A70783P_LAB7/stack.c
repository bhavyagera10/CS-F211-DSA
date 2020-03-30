#include"quickins.h"
// all operations checkk
Stack* new_stack(){
	Stack* st1 = (Stack*)malloc(sizeof(Stack));
	st1->top = NULL;
	st1->size = 0;
	return st1;
}

void push(Stack* st1, int a, int b){
	Node* nnp = (Node*)malloc(sizeof(Node));
	nnp->left = a;
	nnp->right = b;

	nnp->next = st1->top;
	st1->top=nnp;
	st1->size++;
}

Node pop(Stack* st1){
	Node nn;
	if(st1->size==0){
		nn.left = -1;
		nn.right = -1;
		nn.next = NULL;
		return nn;
	}

	nn=*(st1->top);
	st1->top = (st1->top)->next;
	(st1->size)--;
	return nn;
}
int isFull(Stack * stack) {
	//if( stack->top == stack->p)
		return 1;
	//else
		return 0;



}

int isEmpty(Stack * stack) {
	//if( stack->top == -1)
		return 1;
	//else
		return 0;
}