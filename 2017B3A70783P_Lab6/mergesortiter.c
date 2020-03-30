#include "merge.h"
int min(int xi, int yi) { return (xi<yi)? xi :yi; }
int max(int xi, int yi) { return (xi>yi)? xi :yi; } 

 
void mergeSortIter(Element arr[],int st){ 
	int m,r;
	iterspace = 2*sizeof(int);
	for(int cs=1;cs<st;cs*=2){
		for(int start=0;start<st;start+=2*cs){
			m = min(start+cs-1,st-1);
			r = min(start+2*cs-1,st-1);

			Element newarr[r-start+1];
			iterspace += 2*sizeof(int)+(r-start+1)*sizeof(Element);

			merge(arr+start,m-start+1,arr+m+1,r-m,newarr);
			for(int i=0;i<r-start+1;i++){
				arr[start+i]=newarr[i];
			}
		}
	}
}