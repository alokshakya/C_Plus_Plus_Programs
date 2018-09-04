#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    if(argc==1)
    {
        printf("No Arguments");
        return 0;
    }
    else
    {
        int n,sum,temp,rem;
        n=atoi(argv[1]);
        temp=n;
        sum=0;
        while(temp)
        {
            rem=temp%10;
            sum+=rem;
            temp=temp/10;
        }
        printf("%d",sum);
        return 0;
    }
}
