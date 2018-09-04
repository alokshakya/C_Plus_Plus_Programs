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
        int n,reverseNumber,temp,rem;
        n=atoi(argv[1]);
        temp=n;
        reverseNumber=0;
        while(temp)
        {
            rem=temp%10;
            reverseNumber=reverseNumber*10+rem;
            temp=temp/10;
        }
        if(n==reverseNumber)
            printf("Palindrome");
        else
            printf("Not Palindrome");
        return 0;
    }
}
