#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
    if(argc==1)
    {
        printf("No arguments");
        return 0;
    }
    else
    {
        int a,b,sum;
        a=atoi(argv[1]);
        b=atoi(argv[2]);
        sum=a+b;
        printf("%d",sum);
        return 0;
    }
}
