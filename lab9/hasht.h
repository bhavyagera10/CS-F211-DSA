#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int hash(char* s,int base,int tsize);
int collcount(char ** str, int base, int tsize);
char** parse(char* fname);
void profile (char** book);
