#include"quickins.h"
#include<sys/time.h>
#include<math.h>
// make one and create copies of existing 

void testt(emp arr[], int n, double resabc[]){
	struct timeval t1, t2;
	double elapsedTime;

	

	emp news[n];
	for(int i=0;i<n;i++)
		news[i]=arr[i];

	gettimeofday(&t1, NULL);

	quick_sort(arr,n,0);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	resabc[0]=elapsedTime;

	gettimeofday(&t1, NULL);

	insertion_sort(news,n);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	resabc[1]=elapsedTime;

}

int co1estimate_cut_off(emp arr[], int n){
	double resabc[2];

	emp news[n];

	int min=0;
	int max=n;

	int mid=(min+max)/2;
	int prevmid = -1;

	double resabcleft,resabccenter,resabcright;

	while(mid!= prevmid){
		prevmid = mid;
		fflush(stdout);
		for(int i=0;i<(min+mid)/2;i++){ 
			news[i]=arr[i];
		}
		// find min and  check rest
		testt(news, (min+mid)/2, resabc);
		resabcleft=fabs(resabc[0]-resabc[1]);
		
		for(int i=0;i<mid;i++){ 
			news[i]=arr[i];
		}
		testt(news, mid, resabc);
		resabccenter=fabs(resabc[0]-resabc[1]);
		
		for(int i=0;i<(mid+max)/2;i++){ 
			news[i]=arr[i];
		}
		testt(news, (mid+max)/2, resabc);
		resabcright=fabs(resabc[0]-resabc[1]);

		printf("mid = %d, %lf,%lf,%lf\n",mid,resabcleft,resabccenter,resabcright);

		if(resabccenter<=resabcleft && resabccenter <= resabcright){
			//We've found our minimum
			return mid;
		}
		else{
			if(resabcleft<=resabccenter){
				max = mid; 
			}
			else{
				min = mid;
			}
		}
		mid = (min+max)/2;
	}
	return mid;  
}

 

int main(int argc, char* argv[]){
	FILE* ifile = fopen(argv[1],"r");

	int n=10;
	emp* arr = malloc(sizeof(emp)*n);

	int j=0;
	while(!feof(ifile)){
		fscanf(ifile,"%[^ ] %d\n",arr[j].name,&arr[j].ids);
 
		j++;
		if(j==n-1){
			n*=2;
			arr = realloc(arr, sizeof(emp)*n);
		}
	}

 
	int co1 = co1estimate_cut_off(arr,j);
	printf("%d\n",co1);

	fclose(ifile);

	FILE* ofile = fopen(argv[2],"w");

	struct timeval t1, t2;
	double elapsedTime;	

	gettimeofday(&t1, NULL);

	mixed_sort(arr,j,co1);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	fprintf(ofile, "Time for sorting %d IDs with bothSort cutoff %d= %lf milliseconds.\n",j,co1,elapsedTime);
	printf("Time for sorting %d IDs with bothSort cutoff %d= %lf milliseconds.\n",j,co1,elapsedTime);

	for(int i=0;i<j;i++){
		fprintf(ofile, "%s %d\n",arr[i].name,arr[i].ids);
	}

}