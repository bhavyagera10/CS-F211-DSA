#include"quickins.h"

void mixed_sort(emp arr[], int n, int s){
	int t;
	int nyc,bg;
	int v;

	quick_sort(arr,n,s);
	insertion_sort(arr,n);
}