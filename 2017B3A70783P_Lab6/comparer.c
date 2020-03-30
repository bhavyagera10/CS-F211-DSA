#include <stdio.h>

#include "merge.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>


int main(){
	int p;
	printf("Number of elements you want to sort\n");
	scanf("%d",&p);

	printf("Generating random element array.\n");

	el rec[p];
	el itarr[p];
	float r1,r2;
	srand(time(0));
	for(int i=0;i<p;i++){
		r1 = rand();
		r2 = rand()/100000000;
		rec[i].cgpa=r1+r2;
		itarr[i].cgpa=r1+r2;
	}


	struct timeval t1, t2;
	double elapsedTime;
	iterspace=0;
	recspace=0;

	gettimeofday(&t1, NULL);
	mergeSortRec(rec, 0,p-1);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Recursive mergeSort %d elements in %lf milliseconds.\n",p,elapsedTime);
	printf("Space used by Recursive MergeSort: %d\n",recspace);

	gettimeofday(&t1, NULL);
	mergeSortIter(itarr,p);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Iterative mergeSort %d elements in %lf milliseconds.\n",p,elapsedTime);
	printf("Space used by Iterative MergeSort: %d\n",iterspace);
}