




#include"quickins.h"



void swapabc(emp* a, emp* b){
	emp temp = *a;
	*a=*b;
	*b=temp;  // swap by pointers
}

int parts(emp arr[], int low, int r){
	int x = arr[r].ids;
	int i = low-1;
	for(int j=low;j<r;j++){
		if(arr[j].ids<=x){
			i++;
			swapabc(&arr[i],&arr[j]);   // swap to sides partition in progress
		}
	}
	swapabc(&arr[++i],&arr[r]);
	return i;
}

void quick_sort(emp arr[], int n, int s){
	Stack* myStack = new_stack();
	Node temp;
	int low,r,next;
	push(myStack,0,n-1);

	while(myStack->size > 0){   // check size 
		temp = pop(myStack);
		low = temp.left;
		r = temp.right;
		if(r-low>s/*low<r*/){
			next = parts(arr,low,r);
			push(myStack,low,next-1);
			push(myStack,next+1,r);
		}
//	 end quicks non recursive 
	}
}