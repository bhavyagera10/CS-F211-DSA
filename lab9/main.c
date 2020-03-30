#include"hasht.h"
#include <locale.h>
int main(int argc,char* argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");
     printf("hi");
    //char s= argv[1];
    // printf("hi %s",s);
    char ** b= (char**)parse("aliceinwonderland.txt");
    profile(b);
    return 0;
}