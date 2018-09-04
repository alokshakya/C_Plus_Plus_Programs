#include<stdio.h>
#include<stdlib.h>
int power(int x, int n)
{
    if(n==0) return 1;
    else if(n%2==0)
        return power((x*x),n/2);
    else
        return (x*power((x*x),(n-1)/2));
}
int main(int argc, char * argv[])
{
    if(argc==1)
    {
        printf("No arguments ");
        return 0;
    }
    else
    {
        int n,temp,digits;
        n=atoi(argv[1]);
        //printf("number : %d\n",n);
        //calculate digits
        temp=n;
        digits=0;
        while(temp)
        {
            digits++;
            temp/=10;
        }
        //printf("digits : %d\n",digits);
        int sum=0;
        //calculate digit pow digits
        temp=n;
        int lastDigit,po;
        while(temp)
        {
            lastDigit=temp%10;
            //po=power(lastDigit, digits);
            sum+=power(lastDigit,digits);
            temp/=10;
            //printf("last digit %d and pow %d and sum : %d\n",lastDigit,power(lastDigit,digits),sum);
        }
        //printf("sum total : %d\n",sum);
        if(sum==n)
            printf("Yes\n");
        else
            printf("No\n");
        return 0;
    }
}
