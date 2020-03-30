#include"hasht.h"
#include<ctype.h>
int val;
int hash(char* s,int base,int tsize)
{ 
   // printf("%d\n",base);
   //  printf("%s\n",s);
 int n= strlen(s);
 //printf("%d\n",n);
   int c=0;
   // printf("hicollooo\n");
    for(int i=0;s[i]!='\0';i++)
    {
        c+= s[i];
        //printf("%d\n",s[i]);
        //printf("hicollsss\n");
    }
   // printf("%d\n",c);
    return ((c%base)%tsize);
}

int collcount(char ** str, int base, int tsize)
{
     // int row= sizeof(str)/sizeof(str[0]);
      //printf("%d",row);
   // int col=sizeof(str[0])/sizeof(str[0][0]);
      int arr[tsize];
     // printf("hicoll\n");
      for(int i=0;i<tsize;i++)
      {
          arr[i]=-1;
      }
        char boo[30000][50];
    for(int i=0;i<val;i++)
    {
         
        
        //printf("hicolluu\n");
       //   printf("%s\n",str[i]);
            arr[hash(str[i],base,tsize)]++;
           // printf("hicoll\n");
        
    }
     int b=0;
    for(int i=0;i<tsize;i++)
    { 
       
        if(arr[i]>0)
       { b+=arr[i];
         // printf("%d\n",arr[i]);
       }
    }
    //printf("%d\n",b);
    return b;
}

char** parse(char* fname)
{
     //printf("hi ");
    FILE* f=fopen(fname,"r");
   
    if(f==NULL)
    {
        printf("FILE CANNOT BE OPENED\n");
       exit(0);
    }
    int num=0;
    //char** book;
     int count=10;
    char book[30000][50];
      //printf("hi");
      // book[num]=(char*)malloc(sizeof(char)*count);
      char str[30000];
    while(fscanf(f,"%s\n",str)!=EOF)
    {
        if(num>=count)
        {  count*=2;
           //book=(char **)realloc(book,sizeof(char*)*(count));
        }

       
        
        // printf("hi");
         int n=strlen(str);
         int flg=1;
         for(int i=0;str[i]!='\0';i++)
         {
            // if(!((str[i]>='a'&& str[i]<='z') || (str[i]>='A'&& str[i]<='Z')))
             if(!isalpha(str[i]))
             { 
                 flg=0;
                 break;
                 //free(str);
             }
         }
          

           if(flg==1)
          {  //book[num] = str;
            strcpy(book[num],str);
           num++;
           printf("%s\n",str);
          }
      //free(str);
    }
val=num;
printf("THE BOOK %s has %d lines according to rule\n",fname,num);
fclose(f);
  //printf("%s\n",book[0]);
  char ** books=(char**) malloc(sizeof(char*)*num);
   for(int i=0;i<num;i++)
   {  books[i]=(char*) malloc(sizeof(char)*50);
       books[i]=book[i];
      // printf("%s\n",books[i]);
   }
return  (char **)books;
//free(book);
}

void profile (char** book)
{
      int table[3]={5000,50000,500000};
      int bases[3][6]= {{5903,7211,9277,500077,5348743,6823963},{58391,69997,82571,100057,123479,155833},{500069,567997,734663,1000081,1234577,1567931}};
     // printf("hi\n");
        //printf("%s\n",book[0]);
      int num ,temp=collcount(book,bases[0][0],table[0]),p,q;
  
      for(int i=0;i<3;i++)
      {
          for(int j=0;j<6;j++)
          {
              num=collcount(book,bases[i][j],table[i]);
              printf("FOR %d TABLESIZE AND %d BASE THERE ARE %d COLLISIONS\n",table[i],bases[i][j],num);
              if(num<=temp)
            {  
                temp=num;
                p=table[i];
                q=bases[i][j];
            }
          }
      }
    printf("FOR %d TABLESIZE AND %d BASE THERE ARE MINIMUM %d COLLISIONS\n",p,q,temp);
}