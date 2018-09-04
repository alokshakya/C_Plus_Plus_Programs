#include<stdio.h>
#include<stdlib.h>
// Function to convert binary to decimal
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while(temp)
    {
        int last_digit = temp % 10;
        temp = temp/10;

        dec_value += last_digit*base;

        base = base*2;
    }

    return dec_value;
}
int main(int argc, char *argv[])
{
    if(argc==1)
    {
        printf("No Arguments ");
        return 0;
    }
    else
    {
        int n;
        //converting string into int type using atoi() function of stdlib.h
        n=atoi(argv[1]);
        int ans=binaryToDecimal(n);
        printf("%d",ans);
        return 0;
    }
}
