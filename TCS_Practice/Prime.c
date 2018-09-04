/*
Problem Description:
Write a C program which will check whether a given number N is a Prime or Not
If the Number N is a Prime, then find it's square root and print that value
to the stdout as floating point number with exactly 2 decimal precision.

If the number is not Prime, then print the value 0.00 to stdout.

The given number will be positive non zero integer and it will be passed to the program
as first command line argument.

Other that floating point No other information should be printed to stdout.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
bool isPrime(int n)
{
    if(n<2)
        return false;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main(int argc, char *argv[])
{
    if(argc==1)
    {
        printf("No arguments");
        return 0;
    }
    else
    {
        int n;
        n=atoi(argv[1]);
        float sq=0;
        if(isPrime(n))
        {
            sq=sqrt(n);
            printf("%.2f",sq);
        }
        else
            printf("%.2f",sq);
        return 0;
    }
}
