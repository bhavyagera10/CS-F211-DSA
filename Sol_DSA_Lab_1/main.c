#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 int i;
 seqarr seq;
 joblist arr;
 initialize_elements (arr);
 //printjoblist(arr);
 int flag[3] = {0,0,0}; // to check for priorities with no elements
 int len = sizeof(arr)/sizeof(arr[0]);
// printf("%d",len);
 for (i =0; i< len; i ++)
 {
    flag[arr[i].pri] = 1;
 }

 for( i = 0; i < 3; i++){
  //  if (flag[i]==1){
     seq[i] = createlist(flag[i]);
  //  }
  //  else
  //  {
  //    seq[i].head = -1;
  //    seq[i].size = 0;
  //  }
 }

 // we will will use createlist() function when we encounter a new element with a new PRIORITY


 //seq[0] = createlist();
 //seq[1] = createlist();
 //seq[2] = createlist();
 insertelements (arr,seq);
// printseqlist (seq[0]);
// printseqlist (seq[1]);
// printseqlist (seq[2]);
 copy_sorted_ele (seq , arr);
 //printf ("Sorted List\n");
 printjoblist(arr);
}
