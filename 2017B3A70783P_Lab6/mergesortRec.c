#include "merge.h"
void mergeSortRec(el arr[],int l, int r){
	if(r>l){
		int m = (l+r)/2;
		mergeSortRec(arr,l,m);
		mergeSortRec(arr,m+1,r);
		el newarr[r-l+1];

		recspace += sizeof(int)+(r-l+1)*sizeof(el);

		merge(arr+l,m-l+1,arr+m+1,r-m,newarr);
		for(int i=0;i<r-l+1;i++){
			arr[l+i]=newarr[i];
		}

 

	}
}

void mergeSort(el arr[],int n){
	mergeSortRec(arr,0,n-1);
}