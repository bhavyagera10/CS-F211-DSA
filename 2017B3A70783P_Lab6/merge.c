#include"merge.h"
void merge(el Ls1[], int sz1, el Ls2[], int sz2, el Ls[]){
	int ip=0,jp=0,kp=0;

	while(ip<sz1 && jp<sz2){
		if(Ls1[ip].cgpa<Ls2[jp].cgpa){
			Ls[kp++]=Ls1[ip++];
		}
		else{
			Ls[kp++]=Ls2[jp++];
		}
	}

	if(ip==sz1){
		while(jp<sz2){
			Ls[kp++]=Ls2[jp++];		
		}
	}

	if(jp==sz2){
		while(ip<sz1){
			Ls[kp++]=Ls1[ip++];		
		}
	}

}