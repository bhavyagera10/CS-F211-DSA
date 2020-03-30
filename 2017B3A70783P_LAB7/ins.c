#include"quickins.h"

void insert(emp arr[], int n, emp n_e){  // called by insertionsort!!!
	emp c1 = n_e;
	emp t;
	for(int i=0;i<n;i++){
		if(c1.ids < arr[i].ids || i==n-1){
			t = c1;
			c1 = arr[i];
			arr[i]=t;
		}
	}
}

void insertion_sort(emp arr[],int n){
	for(int i=0;i<n;i++){
		insert(arr,i+1,arr[i]);  // take insert by order 
	}
}