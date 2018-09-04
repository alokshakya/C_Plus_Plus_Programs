#include<stdio.h>
#include<stdlib.h>
int fact(int n)
{
    if(n==0) return 1;
    else
    {
        int i;
        int ans=1;
        for(i=1;i<=n;i++)
            ans=ans*i;
        return ans;
    }
}
int main(int argc, char *argv[])
{
    if(argc==1)
    {
        printf("No Arguments Provided\n");
        return 0;
    }
    else
    {
        int n;
        n=atoi(argv[1]);
        int factorial;
        factorial=fact(n);
        printf("%d\n",factorial);
        return 0;
    }
}
